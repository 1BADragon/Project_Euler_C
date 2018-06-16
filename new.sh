#!/usr/bin/env bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"1
mkdir -p $DIR/Path$1/solutions/$2
touch $DIR/Path$1/solutions/$2/mod.c
