for number in 0 1 2 3
do
cat > test${number}.txt << EOF
this is the $number txt file generated
EOF
sed -i 's/0/first/' test${number}.txt
sed -i 's/1/second/' test${number}.txt
sed -i 's/2/third/' test${number}.txt
sed -i 's/3/forth/' test${number}.txt
cat test${number}.txt
cat test${number}.txt >> testcopy.txt
done
echo
cat testcopy.txt
rm test${number}.txt
rm testcopy.txt
