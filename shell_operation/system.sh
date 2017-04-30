#!/bin/bash
echo 
echo "logged user and username(当前登录用户和用户名):"
who 
echo 

echo "logged number of users(当前登录的用户数量):"
who | wc -l 
echo

echo "shell name(当前shell的名字):"
echo $SHELL
echo
 
echo "Home directory(主目录):"
echo $HOME
echo 

echo "Operating system type(操作系统类型):"
uname 
echo 

echo "path setting(当前路径):"
echo $PATH
echo

echo "working directory(工作目录):"
pwd
echo

echo "Linux version,release number,kernel version(Linux版本,版本号码,内核版本):"
uname -a
echo

echo "CPU info(CPU信息):"
cat /proc/cpuinfo
echo

echo "Memory information（内存信息）:"
cat /proc/meminfo
echo

echo "File system（文件系统）:"
df
echo


