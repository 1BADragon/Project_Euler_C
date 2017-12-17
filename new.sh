#!/usr/bin/env bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"1
mkdir $DIR/solutions/$1
touch $DIR/solutions/$1/mod.c
