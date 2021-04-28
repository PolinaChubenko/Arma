#!/bin/bash
if [ ! -d "build" ]; then
  mkdir build
fi
cd build
cmake ..
make
cd ../ && cd bin
./Arma
