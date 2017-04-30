for mcfile in P4f_=ww_=h_=LR P4f_=zz_=h_=LR P4f_=zzorww_=h_=LR P4f_=Higgs_=h_=LR
do
echo $mcfile > tmp1.txt
cat tmp1.txt | cut -f1-3 -d"_" > tmp2.txt
cat tmp2.txt | sed 's/=//g' > tmp3.txt
cat tmp3.txt | sed 's/$/_PR/'
done

#本代码用一个循环，对mcfile变量进行更改，先以“_”为界去掉“_=LR”，再将“=”换为“”，最后在结尾加上“_PR”完成更改
