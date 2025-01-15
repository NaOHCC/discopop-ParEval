#!/bin/bash
rm -rf build
mkdir build && cd build

cmake -DCMAKE_CXX_COMPILER=/opt/DiscoPoP/build/scripts/CXX_wrapper.sh -DUSE_OMP=ON -DDRIVER_PROBLEM_SIZE=256 -G Ninja ..

# ninja xxx
# cd .discopop
# discopop_explorer
# discopop_patch_generator
# discopop_patch_applicator -a xx yy
