import json
import os
import pathlib

with open("successful_files.txt", "r") as f:
    successful_files = f.read().splitlines()
with open("failed_files.txt", "r") as f:
    failed_files = f.read().splitlines()

with open("discopop.json", "r") as f:
    input_json = json.load(f)


for root, dirs, files in os.walk("src/benchmarks"):
    if len(dirs) == 0:
        # get last directory name
        example_dir = os.path.basename(root)
        optimized_source = None
        for file_name in successful_files:
            if example_dir == file_name.split(".")[0]:
                with open(f"{root}/generated-code.hpp", "r") as f:
                    optimized_source = f.read()

        for obj in input_json:
            if obj["name"] == example_dir and (optimized_source is not None):
                obj["outputs"] = optimized_source
                print(f"patched {example_dir}")

with open("discopop.json", "w") as f:
    json.dump(input_json, f, indent=2)
