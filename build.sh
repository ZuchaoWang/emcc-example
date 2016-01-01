#! /bin/bash

mkdir -p dist
rm -r dist/*
emcc -O2 src/main.cpp src/mysqrt.cpp -Iinclude -o dist/mysqrt.bc
emcc -O2 dist/mysqrt.bc -o dist/mysqrt.js -s EXPORTED_FUNCTIONS='["_mysqrtc"]' --memory-init-file 0 --pre-js  wrap/pre.js --post-js wrap/post.js
cp html/* dist/