

i=557
while [ $i -gt 0 ]
do
  tar -xvf $i.tar
  i=$[$i-1]
done