#!/usr/bin/env bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
mkdir -v $DIR/solutions/Page$1/$2
touch $DIR/solutions/Page$1/$2/mod.cpp
