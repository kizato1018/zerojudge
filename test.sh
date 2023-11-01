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
answer_file="${filename}.ans"
output_file="${filename}.out"

if [ ! -f "$input_file" ]; then
  echo "$input_file does not exist."
  exit 1
fi

./$filename < $input_file > $output_file

if diff -wbB "$output_file" "$answer_file" &> /dev/null; then
  echo -e "\033[1;32mAC\033[0m"   # 输出绿色粗体的 "AC"
else
  echo -e "\033[1;31mWA\033[0m"   # 输出红色粗体的 "WA"
  echo "Expected output:"
  cat "$answer_file"
  echo "Your output:"
  cat "$output_file"
fi
