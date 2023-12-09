#!/bin/bash

cd libsrc
make clean
make
cd ../examples
make clean
make
cd ..
#x64 examples/project.prg
#x64 -cart16 examples/project.bin
