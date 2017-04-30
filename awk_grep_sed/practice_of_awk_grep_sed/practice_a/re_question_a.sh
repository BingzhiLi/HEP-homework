for mcfile in P4f_=ww_=h_=LR P4f_=zz_=h_=LR P4f_=zzorww_=h_=LR P4f_=Higgs_=h_=LR
do
echo "$mcfile"|awk '{gsub(/=/,"");print}'|awk '{gsub(/L/,"P");print}'
done
