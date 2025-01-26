import os
import pathlib
import subprocess
from pathlib import Path

successful_files = []
failed_files = []

current_dir = os.getcwd()

# iterate src/code
import concurrent.futures


def process_file(file):
    if file.endswith(".cpp"):
        build_home = pathlib.Path("build") / file
        RM_BUILD = f"rm -rf {str(build_home)}"
        MK_BUILD = f"mkdir -p {str(build_home)}"

        subprocess.run(RM_BUILD, shell=True)
        subprocess.run(MK_BUILD, shell=True)

        # configure cmake
        CMAKE_CONFIG = f"cmake -DCMAKE_CXX_COMPILER=/opt/DiscoPoP/build/scripts/CXX_wrapper.sh -DUSE_OMP=ON -DDRIVER_PROBLEM_SIZE=256 -G Ninja {current_dir}"
        subprocess.run(CMAKE_CONFIG, shell=True, cwd=str(build_home))

        # build the example
        file_name = os.path.basename(file)
        example_name = file_name.split(".")[0]
        BUILD_EXAMPLE = f"ninja {example_name}"
        subprocess.run(BUILD_EXAMPLE, shell=True, cwd=str(build_home))

        # run the example
        RUN_EXAMPLE = f"bin/{example_name}"
        subprocess.run(str(RUN_EXAMPLE), shell=True, cwd=str(build_home))

        # run discopop_explorer
        discopop_home = build_home / ".discopop"
        DISCOPOP_EXPLORER = "discopop_explorer"

        subprocess.run(DISCOPOP_EXPLORER, shell=True, cwd=str(discopop_home))

        # run discopop_patch_generator
        DISCOPOP_PATCH_GENERATE = "discopop_patch_generator"
        subprocess.run(DISCOPOP_PATCH_GENERATE, shell=True, cwd=str(discopop_home))

        # collect the ids of the generated patches
        ids = []
        for root, dirs, patch_files in os.walk(discopop_home / "patch_generator"):
            for patch_file in patch_files:
                with open(Path(root) / patch_file, "r") as f:
                    content = f.read()
                    if "generated-code.hpp" in content:
                        id = root.split("/")[-1]
                        ids.append(id)

        # apply the patches
        if len(ids) == 0:
            print(f"No patches found for {file}")
            failed_files.append(file)
            return None
        args = " ".join(ids)
        DISCOPOP_PATCH_APPLY = f"discopop_patch_applicator -a {args}"
        subprocess.run(DISCOPOP_PATCH_APPLY, shell=True, cwd=str(discopop_home))
        print(f"Successfully applied patches for {file}")
        return file
    return None


with concurrent.futures.ThreadPoolExecutor(max_workers=64) as executor:
    futures = []
    total_files = sum(len(files) for _, _, files in os.walk("src/code"))
    processed_files = 0

    for root, dirs, files in os.walk("src/code"):
        for file in files:
            futures.append(executor.submit(process_file, file))

    for future in concurrent.futures.as_completed(futures):
        result = future.result()
        if result:
            successful_files.append(result)
        processed_files += 1
        print(f"Progress: {processed_files}/{total_files} files processed")

print(f"Successfully applied patches for {len(successful_files)} files")
with open("successful_files.txt", "w") as f:
    for file in successful_files:
        f.write(file + "\n")

print(f"Failed to apply patches for {len(failed_files)} files")
with open("failed_files.txt", "w") as f:
    for file in failed_files:
        f.write(file + "\n")

exit(0)
