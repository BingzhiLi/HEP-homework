#!/bin/bash
for (( num = 1; num<101; num++)) 
do
     #自动生成100个txt格式文件
     touch "file${num}.txt"
     echo "hello world,I am num${num} txt">a${num}.txt
     
     #复制这100个文件
     #cp a${num}.txt b${num}.txt
    
     #设置运行参数控制文件名称
     #touch "$1${num}.txt"
     
     #文件名为c001到c100
     #touch "c`printf "%03d" ${num}`.txt"

done




