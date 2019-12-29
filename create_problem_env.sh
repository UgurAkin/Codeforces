#!/bin/bash

# Options:
# -d [dir_name]: Specify a folder name
# -n [contest.div_no (###.#)]: Specify contest # and division
#                             to generate a name
# -l [lang_name]

declare -A ext
ext=(
    ["c":".c"]
    ["c++":".cpp"]
    ["cpp":".cpp"]
    ["python": ".py"]
    ["js": ".js"]
)

soln="source"
ext=".cpp"
dir_name=""
in_file="input.in"
test_out_file="test_out.out"
prv_out_file="out.out"

while [ -n "$1" ]; do 
    case "$1" in
    -d)
    if 
    dir_name="$2"
    ;;        
    *) echo "Option $1 not recognized" ;; # In case you typed a different option other than a,b,c
    esac
    shift

done
