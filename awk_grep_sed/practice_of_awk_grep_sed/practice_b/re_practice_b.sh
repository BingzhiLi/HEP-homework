#!/bin/bash
cat >> test.txt << EOF
/ is the root directory
bin is the system binary directory
usr bin is the user binary directory
home $USER is my home directory
home $USER bin is my binary directory
EOF

cat test.txt|awk '{gsub(/^bin/,"/bin");print}'|awk '{gsub(/usr bin/,"/usr/bin");print}' |awk '{gsub(/^home/,"/home");print}' |awk '{gsub(/ bin/,"/bin");print}'|awk '{gsub(/ '$USER'/,"/'$USER'");print}'

rm test.txt


