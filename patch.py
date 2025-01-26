import os


def traverse_benchmarks(directory):
    subdirectories = []
    for entry in os.listdir(directory):
        if os.path.isdir(os.path.join(directory, entry)):
            subdirectories.append(entry)

    if len(subdirectories) > 0:
        with open(f"{directory}/CMakeLists.txt", "w") as f:
            for subdirectory in subdirectories:
                f.write(f"add_subdirectory({subdirectory})\n")
    else:
        parent_directory = os.path.basename(directory)
        content = f"""\
if(EXISTS ${{CMAKE_CURRENT_SOURCE_DIR}}/generated-code.hpp)
    add_executable({parent_directory} cpu.cc)
    target_include_directories({parent_directory} PRIVATE ${{CMAKE_CURRENT_SOURCE_DIR}})
    target_link_libraries({parent_directory} driver OpenMP::OpenMP_CXX)
    file(APPEND "${{CMAKE_BINARY_DIR}}/executable.txt" "{parent_directory}\n")
endif()
    """
        with open(f"{directory}/CMakeLists.txt", "w") as f:
            f.write(content)

    for subdirectory in subdirectories:
        traverse_benchmarks(f"{directory}/{subdirectory}")


def copy_to_dir(directory, source_code_dir):
    source_files = []
    for root, dirs, files in os.walk(source_code_dir):
        for file in files:
            source_files.append(os.path.join(root, file))

    for root, dirs, files in os.walk(directory):
        if len(dirs) == 0:
            for file in source_files:
                example_name = os.path.basename(root)
                if example_name in file:
                    with open(file, "r") as f:
                        content = f.read()
                    content = (
                        f"""\
#pragma once
#include "utilities.hpp"
"""
                        + content
                    )
                    file_name = "generated-code.hpp"
                    with open(f"{root}/{file_name}", "w") as f:
                        f.write(content)


if __name__ == "__main__":
    benchmarks_directory = "src/benchmarks"
    source_code_dir = "src/code"
    traverse_benchmarks(benchmarks_directory)
    copy_to_dir(benchmarks_directory, source_code_dir)
