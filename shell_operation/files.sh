#!/bin/bash
for (( num = 1; num<101; num+=5)) 
do    
    touch "$1${num}.txt" #创建txt文件
done

for ((  num = 1; num<101; num++))
do
    if [ -a $1${num}.txt ];then #检测上面新建的文件是否存在，存在则重命名，不存在则新建一个
         echo "File $1${num}.txt exists, rename it to AA${num}.txt!"
         mv $1${num}.txt AA${num}.txt
    else
         echo "File $1${num}.txt is not exist,create $1${num}.txt!"
         touch $1${num}.txt
    fi
done
