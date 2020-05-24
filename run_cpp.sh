#!/bin/bash
#set -x
function run(){
	CC=g++
	CFLAGS=-O
	input_file=$1
	shift # pull off first arg
	args="$*"
	filename=${input_file%%.cpp}

	echo "Compiling!"
	$CC -o ./exe $CFLAGS $input_file
	rc=$?

	if [[ $rc -eq 0 ]]; then
	   echo "Ready!"
	   ./exe $args
	fi
}
alias run="run"
