#! /bin/bash

export EMCC_DEBUG=1
mkdir -p dist
rm -r dist/*
emcc -O3 src/main.cpp src/myfunc.cpp src/myclass.cpp -Iinclude -o dist/mysqrt.bc
emcc -O3 dist/mysqrt.bc -o dist/mysqrt.js -s EXPORTED_FUNCTIONS='["_mysqrtC", "_mysqrtArrayC", "_createMyClassC", "_deleteMyClassC", "_setMyClassValueC", "_getMyClassAnswerC"]' --memory-init-file 0 --pre-js  wrap/pre.js --post-js wrap/post.js
cp html/* dist/
export EMCC_DEBUG=""