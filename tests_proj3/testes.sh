#! /bin/bash

chmod +x testes.sh

echo 'Nossa! Estou vivo! Vou testar o projecto cara!'

echo 'test1'
./proj3 <st1.in> out1.out
diff st1.out out1.out
echo 'valgrind \n\n\n'
valgrind ./proj3 <st1.in> out1.out

echo '\n\n\n\n\n'
echo 'test2'
./proj3 <st2.in> out2.out
diff st2.out out2.out
echo 'valgrind \n\n\n'
valgrind ./proj3 <st2.in> out2.out

echo '\n\n\n\n\n'
echo 'test3'
./proj3 <st3.in> out3.out
diff st3.out out3.out
echo 'valgrind \n\n\n'
valgrind ./proj3 <st3.in> out3.out

echo '\n\n\n\n\n'
echo 'test4'
./proj3 <st4.in> out4.out
diff st4.out out4.out
echo 'valgrind \n\n\n'
valgrind ./proj3 <st4.in> out4.out


echo '\n\n\n\n\n'
echo 'test5'
./proj3 <st5.in> out5.out
diff st5.out out5.out
echo 'valgrind \n\n\n'
valgrind ./proj3 <st5.in> out5.out

