rm -rf bin/*

var1='y'
var2='Y'

read -n 1 -p "do you want to cmake again? [Y/N] " opt

echo -e "\n\nbuild your code\n------------------------------------------------------------------" #-e用来支持c的换行
cd  build

if [ "$opt" = "$var1" ]; then

cmake ..
fi

if [ "$opt" = "$var2" ]; then
cmake ..
fi

make
cd ..
echo -e "\n\nrun your code\n------------------------------------------------------------------" #-e用来支持c的换行
./bin/test