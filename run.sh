#!/bin/bash

if [ $# -ne 1 ]; then
  echo "Usage: $0 <filename>"
  exit 1
fi

filename=$1

if [ ! -x "$filename" ]; then
  echo "$filename is not an executable file."
  exit 1
fi

input_file="${filename}.input"

if [ ! -f "$input_file" ]; then
  echo "$input_file does not exist."
  exit 1
fi

./$filename < $input_file
