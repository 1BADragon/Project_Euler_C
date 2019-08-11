#!/usr/bin/env bash

if [ ! -d "./build/"]; then 
    mkdir -p ./build
fi

rustc ./tests/test$1.rs -o ./build/test$1 && ./build/test$1
