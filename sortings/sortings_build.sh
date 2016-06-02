#!/bin/bash

declare -a sortings=("Bubble" "Insertion" "Merge")
sorting_suffix="Sort"

cmake_algo_options=()
cmake_algo_option_name="-DALGO_DEFINITION"
for algo in "${sortings[@]}"
do
    algo_option=$cmake_algo_option_name=$algo$sorting_suffix
    cmake_algo_options+=($algo_option)
done

cwd="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cmake_binary_dir=$cwd"/build"
rm -rf $cmake_binary_dir
mkdir $cmake_binary_dir

cmake_tempdir=$cmake_binary_dir"/tmp"
rm -rf $cmake_tempdir

debug_dir=$cmake_binary_dir"/Debug"

echo "$debug_dir"
rm -rf $debug_dir
mkdir $debug_dir

build_type_opt="-DCMAKE_BUILD_TYPE"
bin_output_dir_opt="-DBIN_OUTPUT_DIR"
mkdir $cmake_tempdir
for option in "${cmake_algo_options[@]}"
do
    echo "Algo option: $option"
    cd $cmake_tempdir
    cmake $option $build_type_opt=Debug $bin_output_dir_opt=$debug_dir $cwd
    cmake_files="$(find ./ -maxdepth 1 ! -name "." ! -name ".")"
    make
    for file in $cmake_files
    do
        rm -rf $cmake_tempdir/$file
    done
    mv ./* $debug_dir
done
rm -rf $cmake_tempdir
