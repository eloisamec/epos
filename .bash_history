ls
svn co https://epos.lisha.ufsc.br/svn/teaching/ine5424 epos
sudo apt-get install subversion
sudo su
svn co https://epos.lisha.ufsc.br/svn/teaching/ine5424 epos
svn co https://epos.lisha.ufsc.br/svn/teaching/ine5424 --username eloisamec epos
ls
tar -xf ia32-gcc-4.4.4.tar.gz 
ls
sudo mv gcc-4.4.4/ /usr/local/ia32
ls
cd /usr/local/ia32
ls
sudo mkdir gcc-4.4.4
ls
mv bin gcc-4.4.4/
sudo mv bin gcc-4.4.4/
sudo mv BUILD gcc-4.4.4/
sudo mv i686-elf gcc-4.4.4/
sudo mv include/ gcc-4.4.4/
sudo mv info gcc-4.4.4/
sudo mv lib gcc-4.4.4/
sudo mv libexec/ gcc-4.4.4/
sudo mv man gcc-4.4.4/
sudo mv share gcc-4.4.4/
ls
cd gcc-4.4.4/
ls
cd /home/maria.eloisa
cd epos
make
sudo make
sudo apt-get install ia32-libs
sudo apt-get install lib32z1 lib32ncurses5 lib32bz2-1.0
sudo apt-get install lib32stdc++6
sudo apt-get install libc6-i386
sudo apt-get install libc6-dev-i386
sudo apt-get update
sudo apt-get install libc6-dev-i386
sudo apt-get install bin86
sudo apt-get install dev86
make
sudo apt-get install build-essential
make

sudo apt-get install bc
sudo apt-get install qemu
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
cd app
ls
vi philosophers_dinner_traits.h 
vi philosophers_dinner.cc
make APPLICATION=philosophers_dinner
make veryclean
cd ..
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
cd app
cd ..
vi /app/philosophers_dinner.cc
ls
cd app
ls
vi philosophers_dinner.cc
cd ..
make APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
cd app
vi philosophers_dinner.cc
cd ..
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
cd app
vi philosophers_dinner.cc
cd ..
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
ls
cd include/
ls
cd synchronizer.h 
vi synchronizer.h 
cd ..
make veryclean
make APPLICATION=philosophers_dinner
cd include/
vi synchronizer.h 
cd ..
make veryclean
make APPLICATION=philosophers_dinner
cd include/
vi synchronizer.h 
cd ..
make APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
cd include/
vi synchronizer.h 
cd ..
make veryclean
make APPLICATION=philosophers_dinner
cd include/
vi synchronizer.h 
cd ..
make veryclean
make APPLICATION=philosophers_dinner
cd include/
vi synchronizer.h 
cd ..
make veryclean
make APPLICATION=philosophers_dinner
cd include/
vi synchronizer.h 
cd ..
make veryclean
make APPLICATION=philosophers_dinner
cd include/
ls
vi mutex.h 
vi semaphore.h 
cd .. /src/abstraction
ls
cd src
ls
cd abstraction/
ls
vi synchronizer_test.cc 
vi semaphore.cc
vi mutex.cc
vi semaphore.cc
vi mutex.cc
ls
cd ../..
cd include/
cd synchronizer.h 
ls
vi mutex.h 
vi synchronizer.h 
cd ..
make veryclean
make APPLICATION=philosophers_dinner
cd include/
vi synchronizer.h 
cd ..
make veryclean
make APPLICATION=philosophers_dinner
cd include/
vi synchronizer.h 
cd ..
make veryclean
make APPLICATION=philosophers_dinner
cd include/
vi synchronizer.h 
cd ..
make veryclean
make APPLICATION=philosophers_dinner
cd include/
vi synchronizer.h 
cd ..
make veryclean
make APPLICATION=philosophers_dinner
cd include/
vi synchronizer.h 
cd ..
make veryclean
make APPLICATION=philosophers_dinner
cd include/
vi synchronizer.h 
cd ..
make veryclean
make APPLICATION=philosophers_dinner
cd include/
vi synchronizer.h 
cd ..
make veryclean
make APPLICATION=philosophers_dinner
cd include/
vi synchronizer.h 
cd ..
make veryclean
make APPLICATION=philosophers_dinner
cd include/
vi synchronizer.h 
cd ..
make veryclean
make APPLICATION=philosophers_dinner
cd include/
vi synchronizer.h 
cd ..
make veryclean
make APPLICATION=philosophers_dinner
cd include/
vi synchronizer.h 
cd ..
make veryclean
make APPLICATION=philosophers_dinner
cd include/
vi synchronizer.h 
cd ..
make veryclean
make APPLICATION=philosophers_dinner
cd include/
vi synchronizer.h 
cd ..
make veryclean
make APPLICATION=philosophers_dinner
cd epos
cd include/
vi synchronizer.h 
cd ..
make veryclean
make APPLICATION=philosophers_dinner
cd include/
vi synchronizer.h 
cd epos
ls
cd include/
vi synchronizer.h 
make veryclean
cd ..
make veryclean
make APPLICATION=philosophers_dinner
cd include/
vi synchronizer.h 
vin synchronizer.h 
gedit synchronizer.h 
cd ,,
cd ../..
sudo apt-get install gedit
cd epos/include/
gedit synchronizer.h 
cd ..
make veryclean
make APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
make APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
cd include/
vi synchronizer.h 
cd ..
make veryclean
make APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
exit
cd epos
make veryclean
make APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
/home/maria.eloisa/epos/lib/libsys_ia32.a(semaphore.o): In function `EPOS::S::Semaphore::p()':
semaphore.cc:(.text._ZN4EPOS1S9Semaphore1pEv+0x3f): undefined reference to `operator new(unsigned long)'
make[2]: *** [philosophers_dinner] Error 1
make[2]: Leaving directory `/home/maria.eloisa/epos/app'
make[1]: *** [app] Error 2
make[1]: Leaving directory `/home/maria.eloisa/epos'
make: *** [all] Error 2
make APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
cd epos
make veryclean
make APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
exit
cd epos
make veryclean
make APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
svn diff
svn diff > diff.txt
ls
cd app
ls
vi philosophers_dinner.cc
cd ..
svn diff > diff.txt
make APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
lsb_release -a
cd aap
cd app
vi philosophers_dinner.xx
ls
vi philosophers_dinner.cc
cd ..
svn diff > diff.txt
exit
cd epos
cd app
vi philosophers_dinner.cc
cd ..
make veryclean
make APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
svn diff > changes.diff
cd app
vi philosophers_dinner.cc
cd ..
cd..
cd ..
svn co https://epos.lisha.ufsc.br/svn/teaching/ine5424 epos
cd epos
svn diff > teste.diff
cd ..
rm -r epos
ls
svn diff > teste.diff
svn co https://epos.lisha.ufsc.br/svn/teaching/ine5424 epos
cd epois
cd epos
ls
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
cd app
ls
vi philosophers_dinner.cc
cd ..
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
cd epos
make veryclean
make run APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
svn diff > changes.diff
cd app
vi philosophers_dinner.cc
cd ..
make veryclean
make APPLICATION=philosophers_dinner
cd app
vi philosophers_dinner.cc
cd ..
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
svn diff > changes.diff
exit
cd epos
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
svn diff > changes.diff
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
cd app
vi philosophers_dinner.cc
exit
tar -zcvf epos1.tar.gz /home/maria.eloisa/epos
cd epos
svn update https://epos.lisha.ufsc.br/svn/teaching/ine5424
svn update
make
cd include/
vi semaphore.h 
cd ..
ls
cd src
ls
cd abstraction/
ls
vi semaphore.cc
cd ..
cd app
ls
vi philosophers_dinner.cc
cd ..
make
make run
cd epos
make veryclean
make APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
cd epos
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
cd epos
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
cd epos
make veryclean
make APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
cd epos
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
cd epos
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
cd epos
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
cd epos
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
cd epos
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
cd epos
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
cd epos
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
cd epos
make run APPLICATION=philosophers_dinner
cd epos
make veryclean
cd epos
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
cd epos
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
cd epos
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
sudo apt-get install git
cd epos
git init
ls
cd ./git
git add -A
git commit -m 'Epos'
ls
cd ..
ls
cd epos
ls
git config --global user.email "eloisa.mec@gmail.com"
git config --global user.name "eloisamec"
git commit -m 'Epos'
git push -u origin master
git remote add origin https://github.com/eloisamec/epos.git
git push -u origin master
ls -a
ls -latr
cd app
ls
cd ..
make veryclean
make APPLICATION=thread_test
make run APPLICATION=thread_test
cd epos
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
cd /home/maria.eloisa/epos
echo $PWD'>'
cd app
cd epos
cd app
ls
vi philosophers_dinner.cc
cd ..
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
make debug APPLICATION=philosophers_dinner
exit
cd /home/maria.eloisa/epos
make
make APPLICATION=philosophers_dinner
make debug APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
cd /home/maria.eloisa/epos
cd /home/maria.eloisa/epos
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
cd /home/maria.eloisa/epos
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
cd /home/maria.eloisa/epos
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
cd /home/maria.eloisa/epos
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
cd /home/maria.eloisa/epos
make run APPLICATION=philosophers_dinner
cd epos
git status
git add src/abstraction/thread.cc
git commit -m "Testes gerais"
git push
cd /home/maria.eloisa/epos
cd /home/maria.eloisa/epos
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
cd epos
make debug APPLICATION=philosophers_dinner
make veryclean
make debug APPLICATION=philosophers_dinner
qemu-system-i386: -s: Failed to bind socket: Address already in use
qemu-system-i386: -s: chardev: opening backend "socket" failed
make APPLICATION=philosophers_dinner
make runAPPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
killall qemu-system-i386
sudo apt-get install psmisc
killall qemu-system-i386
ls
make debug APPLICATION=philosophers_dinner
sudo apt-get install xterm
make debug APPLICATION=philosophers_dinner
killall qemu-system-i386
make debug APPLICATION=philosophers_dinner
ssh -X maria.eloisa@soii.maria.eloisa.vms.ufsc.br env
make debug APPLICATION=philosophers_dinner
cd epos
make debug APPLICATION=philosophers_dinner
killall qemu-system-i386
make debug APPLICATION=philosophers_dinner
exit
cd epos
make debug APPLICATION=philosophers_dinner
killall qemu-system-i386
make debug APPLICATION=philosophers_dinner
grep X11Forwarding sshd_config
ls
cd ..
ls
cd ..
ls
cd etc
ls
cd ssh
ls
grep X11Forwarding sshd_config
xclock
cd ..
xclock
sudo apt-get install xorg-x11-apps.x86_64
sudo apt-get provides */xclock
sudo apt-get install xorg-x11-apps
sudo apt-get install xorg-x11-fonts-base xorg-x11-fonts-misc xorg-x11-font-utils xorg-x11-fonts-Type1 
ls
cd home
ls
cd maria.eloisa/
ls
sudo apt-get install xorg-x11-fonts-base xorg-x11-fonts-misc xorg-x11-font-utils xorg-x11-fonts-Type1 
Unable to locate package xorg-x11-fonts-base
sudo add-apt-repository ppa:ubuntu-x-swat/x-updates
sudo apt-get update
sudo apt-get install xorg-x11-fonts-base xorg-x11-fonts-misc xorg-x11-font-utils xorg-x11-fonts-Type1 
sudo apt-get install xserver-xorg-input-mtrack
sudo apt-get install xorg-x11-fonts-base xorg-x11-fonts-misc xorg-x11-font-utils xorg-x11-fonts-Type1 
sudo aptitude install yum
sudo apt-get install yum
yum groupinstall "X Window System"
yum repolist all
yum-config-manager --enable
yum yum-config-manager --enable
yum install xorg-x11-fonts-base xorg-x11-fonts-misc xorg-x11-font-utils xorg-x11-fonts-Type1
sudo yum install xorg-x11-fonts-base xorg-x11-fonts-misc xorg-x11-font-utils xorg-x11-fonts-Type1
yum yum-config-manager --enable all
yum yum-config-manager --enablerepo all
yum yum-config-manager --enablerepo
yum yum-config-manager repolist
yum repolist
sudo yum install xclock 
yum yum-config-manager --enablerepo xclock
cd epos
make debug APPLICATION=philosophers_dinner
killall qemu-system-i386
make debug APPLICATION=philosophers_dinner
DISPLAY=:0 xterm
export DISPLAY=localhost:10.0
make debug APPLICATION=philosophers_dinner
killall qemu-system-i386
make debug APPLICATION=philosophers_dinner
killall qemu-system-i386
cd epos
make veryclean
make APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
make APPLICATION=philosophers_dinner
cd app
vi philosophers_dinner.cc
epos
cd epos
cd app
ls
vi philosophers_dinner.cc
cd ..
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
git status
git add include/thread.h 
git add src/abstraction/thread.cc
git commit -m 'Funcionando'
git push
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
svn diff > changes.diff
cd app
ls
vi philosophers_dinner.cc
cd ..
svn diff > changes.diff
git status
fi add Grupo\ 01\ -\ E2\ Blocking\ Thread\ Joining.pdf 
git add Grupo\ 01\ -\ E2\ Blocking\ Thread\ Joining.pdf 
git add src/abstraction/thread.cc
git add changes.diff
git add include/thread.h
git commit -m "Relatório e versão estável"
git push
cd epos
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
svn diff > changes1.diff
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
cd epos
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
ps aux
cat /proc/meminfo
free -m
sudo sysctl -w vm.drop_caches=3
sudo sync && echo 3 | sudo tee /proc/sys/vm/drop_caches
cd epos
make veryclean
free -m
make APPLICATION=philosophers_dinner
free -m
make run APPLICATION=philosophers_dinner
svn diff > changes2.diff
exit
cd epos
make debug APPLICATION=philosophers_dinner
killall qemu-i386
killall qemu-system-i386
cd epos
make debug APPLICATION=philosophers_dinner
killall qemu-system-i386
make debug APPLICATION=philosophers_dinner
echo $DISPLAY
xterm
svn update
sudo apt-get install zip
zip -r epos2.zip epos
rm -r epos
rm -rf epos
ls
svn co https://epos.lisha.ufsc.br/svn/teaching/ine5424 epos
svn update
svn co https://epos.lisha.ufsc.br/svn/teaching/ine5424 epos2
ls
cd epos2
cd ,,
cd ..
gzip -dc epos1.tar.gz | tar xf -
ls
cd home
ls
cd maria eloisa
cd ,,
cd ..
rm -rf home
ls
gzip -dc epos1.tar.gz | tar xf -
ls
cd home
cd maria.eloisa/
ls
mv epos /home/maria.eloisa/
ks
ls
cd ..
ls
rm -rf home
ls
sudo apt-get install gdb
cd epos\ exercicio\ 3/
make veryclean
mv /home/maria.eloisa/epos\ exercicio\ 3/ /home/maria.eloisa/epos
cd ..
ls
cd epos
ls
cd ..
ls
cd epos
make veryclean
make APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
cd epos
cd app
vi philosophers_dinner.cc
cd ..
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
cd epos
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
cd epos
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
git status
cd ..
git status
ls
git iniy
git init
git commit -m "Adicionando todas as versoes do EPOS"
git add *
git commit -m "Adicionando todas as versoes do EPOS"
git remote add origin https://github.com/eloisamec/epos.git
git push -u origin master
make APPLICATION=philosophers_dinner
cd epos
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
cd epos
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
cd epos
svn diff > changes.diff
cd ..
git status
git add epos/changes.diff 
git add epos/Grupo\ 01\ -\ E3\ Idle\ Thread.tar.gz 
git commit -m "Relatorio pronto"
git push
exit
ls
mv /home/maria.eloisa/epos /home/maria.eloisa/epos /exercicio /3
mv /home/maria.eloisa/epos /home/maria.eloisa/"epos exercicio 3"
ls
svn co https://epos.lisha.ufsc.br/svn/teaching/ine5424 epos
ls
cd epos
ls
make veryclean
ls
cd include/
ls
cd u
cd utility/
ls
vi queue.h 
cd ..
cd abs
cd architecture/
ls
cd ..
ls
cd src
ls
cd abstraction/
ls
vi alarm_test.cc 
cd ..
ls
cd include
cd ..
cd src
ls
cd abstraction/
ls
cd ..
cd abstraction/
vi alarm.cc
cd ..
ls
cd utility/
ls
cd ..
ls
cd ..]
cd ..
cd include/
ls
cd utility/
ls
vi handler.h 
exit
cd epos
ls
cd ..
ls
cd epos
make veryclean
make APPLICATION=alarm_test
clear
make APPLICATION=alarm_test
clear
make APPLICATION=alarm_test
clear
make APPLICATION=alarm_test
clear
make APPLICATION=alarm_test
clear
make APPLICATION=alarm_test
make veryclean
make APPLICATION=alarm_test
clear
make APPLICATION=alarm_test
make veryclean
make APPLICATION=alarm_test
make veryclean
make APPLICATION=alarm_test
alarm_test.cc:22: error: no matching function for call to 'EPOS::S::Alarm::Alarm(int, void (*)(), const int&)'
/home/maria.eloisa/epos/include/alarm.h:36: note: candidates are: EPOS::S::Alarm::Alarm(const long unsigned int&, EPOS::S::U::Handler*, int)
clear
/home/maria.eloisa/epos/include/alarm.h:36: note: candidates are: EPOS::S::Alarm::Alarm(const long unsigned int&, EPOS::S::U::Handler*, int)
make APPLICATION=alarm_test
clear
make veryclean
make APPLICATION=alarm_test
make veryclean
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
cd ..
ks
ls
cd "epos exercicio 1"
ls
make veryclean
cd app
ls
cd ..
ls
cd epos
make veryclean
ls
make veryclean
make APPLICATION=alarm_test
ks
ls
cd app
ls
make
make APPLICATION=alarm_test
cd ..
make APPLICATION=alarm_test
ls
make veryclean
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
cd epos
svn diff > changes.diff
cd epos
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
cd epos
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
cd epos
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
cd epos
make veryclean
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
svn diff > changes.diff
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
cd epos
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
cd epos
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
cd epos
make veryclean
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
cd epos
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
cd epos
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
make veryclean
make APPLICATION=alarm_test
make veryclean
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
cd epos
make veryclean
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
make veryclean
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
make APPLICATION=alarm_test
make veryclean
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
make veryclean
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
cd epos
make veryclean
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
cd epos
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
make veryclean
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
make veryclean
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
make veryclean
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
cd epos
make veryclean
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
cd epos
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
git status
cd ..
git status
git add --all
git commit -m "exercicio 4"
git push
git reset --soft HEAD^1
git reset --soft HEAD~1
git status
git add ia32-gcc-4.4.4.tar.gz 
git add "epos exercicio 1"
git add "epos exercicio 2"
git add "epos exercicio 3"
git add "epos"
git status
git reset "epos exercicio 1/.svn"
git status
git reset "epos exercicio 2/.svn"
git status
git commit -m "corrigindo o git"
git push --force
ls -latr
rm .git
rm -r .git
rm -rf .git
ls -latr
git init
git status
git add "epos exercicio 1"
git add "epos exercicio 2"
git add "epos exercicio 3"
git reset "epos exercicio 1/.svn"
git reset "epos exercicio 2/.svn"
git reset "epos exercicio 3/.svn"
ls
git status
git add ia32-gcc-4.4.4.tar.gz 
git add epos
git reset epos/.vn
git reset epos/.svn
git status
git commit -m "correção do repositorio"
git push -u origin epos
git push -u https://github.com/eloisamec epos
git push -u https://github.com/eloisamec/epos
git push --force -u https://github.com/eloisamec/epos
ls
cd epos
ls
cd include/
ls
cd architecture/
ls
cd ..
cd utility/
ls
vi queue.h 
cd ..
make APPLICATION=alarm_test
make run APPLICATION=alarm_test
svn co https://epos.lisha.ufsc.br/svn/teaching/ine5424 epos
git status
git status
git add "epos exercicio 4"
git reset "epos exercicio 4/.svn"
ls
git status
git commit -m "novo exercicio"
git push
cd epos
make veryclean
svn diff > changes.diff
cd ,,
cd ..
rm -rf epos
ls
cd epos
svn diff > changes.diff
cd ..
rm -rf epos
ls
cd epos
svn diff > changes.diff
cd ..
rm -rf epos
cd epos
svn diff > changes.diff
cd ..
rm -rf epos
cd epos
svn diff > changes.diff
cd ..
rm -rf epos
cd epos
svn diff > changes.diff
cd ..
rm -rf epos
cd epos
svn diff > changes.diff
cd ..
rm -rf epos
cd epos
svn diff > changes.diff
cd ..
cd eposEx5.1/
svn diff > changes.diff
cd ..
cd eposEx4
svn diff > changes.diff
cd ..
cd eposEx3
svn diff > changes.diff
cd epos
svn diff > changes.diff
cd ..
git status
git add epos
git status
git reset epos/.svn
git status
git commit -m "exercicio 5"
git push
exit
ls
rm -rf eposEx3
rm -rf eposEx4
rm -rf eposEx5.1
ls
rm -rf epos
ls
cd epos
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
svn co http://smi-protege.stanford.edu/repos/protege/owl/trunk/ protege
ls
cd protege
ls
exitr
git status
git add "epos exercicio 5"
git reset "epos exercicio 5/.svn"
git status
git commit -m "versão 5 entregue"
git push
svn co https://epos.lisha.ufsc.br/svn/teaching/ine5424 epos
ls
git status
rm -rf epos
svn co https://epos.lisha.ufsc.br/svn/teaching/ine5424 epos
cd epos/app
ls
cd ..
make veryclean
make APPLICATION=segment_test
make run APPLICATION=segment_test
exit
ls
cd ~/
ls -latr
cd epos
make veryclean
make run APPLICATION=segment_test
make APPLICATION=segment_test
make run APPLICATION=segment_test
cd epos
make APPLICATION=segment_test
cd epos
make veryclean
make APPLICATION=segment_test
cd ..
ls
cd ine
cd INE5424-master/
svn diff > changes.diff
cd ..
ls
cd maria.eloisa/
ls
cd epos
make APPLICATION=segment_test
make eun APPLICATION=segment_test
make run APPLICATION=segment_test
cd ..
ls
cd eposEx6-bkp/
svn diff > changes.diff
cd epos
make APPLICATION=segment_test
make veryclean
make APPLICATION=segment_test
make veryclean
make APPLICATION=segment_test
make veryclean
make APPLICATION=segment_test
make veryclean
make APPLICATION=segment_test
make veryclean
make APPLICATION=segment_test
make veryclean
make APPLICATION=segment_test
make veryclean
make APPLICATION=segment_test
make veryclean
make APPLICATION=segment_test
make run APPLICATION=segment_test
make veryclean
make APPLICATION=segment_test
make run APPLICATION=segment_test
make APPLICATION=segment_test
make run APPLICATION=segment_test
make veryclean
make APPLICATION=segment_test
make veryclean
make APPLICATION=segment_test
make run APPLICATION=segment_test
svn diff > changes.diff
cd include
ls
cd ..
make veryclean
make APPLICATION=segment_test
make run APPLICATION=segment_test
svn diff > changes.diff
ls
git status
git add "epos exercicio 6"
git reset "epos exercicio 6/.svn"
git status
git add "epos exercicio 6/Grupo 01 - E6 Multiple Specialized Heaps.pdf" 
git commit -m "Exercicio 6"
git push
ls
svn co https://epos.lisha.ufsc.br/svn/teaching/ine5424 epos
git add epos
ls
git add "epos"
git status
git add --force "epos"
git add --all "epos"
git status
git reset "epos/.svn"
git commit -m "iniciando exercicio 7"
git push
ls
cd epos
ls
cd include/
ls
vi thread.h 
cd ..
cd scr
cd src
ls
cd utility/
ls
cd ..
cd system/
ls
cd ..
cd abstraction/
ls
vi thread.cc
vi alarm.cc 
cd ../..
cd include/
vi thread.h 
exit
cd epos
ls
make veryclean
cd ..
rm -rf epos
git pull
git status
rm -rf epos
ls
svn co https://epos.lisha.ufsc.br/svn/teaching/ine5424 epos
ls
cd epos
make veryclean
make APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
cd ..
git status
git add "epos"
git add --all "epos"
git status
git reset "epos/.svn"
git status
git commit -m "EPOS 7"
git push
cd epos
make veryclean
cd ..
rm -rf epos
svn co https://epos.lisha.ufsc.br/svn/teaching/ine5424 epos
cd epos
make veryclean
cd include/
ls
cd ..
make APPLICATION=philosophers_dinner
cd ..
cd epos
make veryclean
make APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
make veryclean
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
svn diff > changes.diff
exit
git status
mv epos "epos exercicio 7"
ls
git add "epos exercicio 7"
git status
git reset "epos exercicio 7/.svn"
ls
git status
git add "epos exercicio 7/E7 - Scheduler Isolation.pdf" 
git commit -m "Resolucao exercicio 7"
git push
ls
svn co https://epos.lisha.ufsc.br/svn/teaching/ine5424 epos
git add epos
git add --all epos
git reset epos/.svn
git status
git commit -m "Epos limpo"
git push
exit
ls
rm -rf epos
svn co https://epos.lisha.ufsc.br/svn/teaching/ine5424 epos
ls
cd epos
nm -C app/task_test
cd app
ls
cd ..
cd app
ls -latr
cd ..
nm -C app/task_test
make APPLICATION=task_test
exit
ls
cd epos
cd app
ls
cd ..
nm -C app/segment_test
make APPLICATION=segment_test
nm -C app/segment_test
nm -C app/segment_test > segment_test.out
man nm
nm -C -n app/segment_test > segment_test.out
exit
cd epos
make APPLICATION=segment_test
make run APPLICATION=segment_test
clear
make run APPLICATION=segment_test
make run APPLICATION=segment_test > test1.out
nm -C -n app/segment_test > segment_test2.out
make run APPLICATION=segment_test
make APPLICATION=segment_test
make run APPLICATION=segment_test
make APPLICATION=segment_test
make run APPLICATION=segment_test
make run APPLICATION=segment_test > test2.out
cd app
vi segment_test_traits.h 
cd ..
make run APPLICATION=segment_test > test2.out
make APPLICATION=segment_test
make run APPLICATION=segment_test > test2.out
make APPLICATION=segment_test
make run APPLICATION=segment_test
make APPLICATION=segment_test
make run APPLICATION=segment_test
cd epos
ls
vi segment_test2.out
vi test2.out
ls
cd cd include/
cd include/
ls
newfile
:> task.h
ls
vi system.h
cd ..
svn log
cd epos
cd src
cd system/
ls
nm -C -n pc_system 
nm -C -n pc_system > epos/pc_system.out
nm -C -n pc_system > pc_system.out
ls
nm -C -n pc_system > ../../system.sym
ls
rm pc_system.out
ls
cd ..
ls
git status
git add epos
git status
git reset epos/.svn
git status
git commit -m "Inicio de codigo P1"
git push
exit
cd epos
ls
make run APPLICATION=segment_test
cd epos
make APPLICATION=segment_test
cd app
ls
cd ..
make veryclean
make APPLICATION=task_test
make run APPLICATION=task_test
make APPLICATION=task_test
make run APPLICATION=task_test
make veryclean
make APPLICATION=task_test
make run APPLICATION=task_test
make APPLICATION=task_test
make run APPLICATION=task_test
make APPLICATION=task_test
make run APPLICATION=task_test
make APPLICATION=task_test
make run APPLICATION=task_test
make APPLICATION=task_test
make run APPLICATION=task_test
svn diff > changes.diff
exit
ls
svn status
cd epos
svn status
svn add --all
svn add 
svn help
svn add help
svn help add
svn add -A
svn add .
svn add *
svn diff > changes.diff
make APPLICATION=task_test
make APPLICATION=task_test > makeLibrary.out
make veryclean
make APPLICATION=task_test > makeLibrary.out
make run APPLICATION=task_test
cd epos
make veryclean
make APPLICATION=task_test > library.out
make veryclean
make APPLICATION=task_test > builtin.out
svn add *
svn diff > changes.diff
svn delete --keep-local builtin.out
ls
svn delete --keep-local library.out
ls
svn delete --keep-local segment_test2.out
svn delete --keep-local segment_test.out
svn delete --keep-local test1.out
svn delete --keep-local test2.out
svn delete --keep-local system.sim
svn delete --keep-local system.sym
ls
svn diff > changes.diff
cd epos
ls
make veryclean
make APPLICATION=task_test
make run APPLICATION=task_test
svn status
svn add app/
svn diff > changes.diff
svn add src/
svn diff > changes.diff
svn add src/abstraction/task.cc
svn add src/abstraction/task_
svn status
snv add src/abstraction/task_init.cc
svn add src/abstraction/task_init.cc
svn add src/abstraction/system_init.cc
svn add *
svn status
svn delete --keep-local system.sym
svn delete --keep-local segment_test.out
svn delete --keep-local segment_test2.out
svn delete --keep-local builtin.out
svn delete --keep-local library.out 
svn delete --keep-local test1.out
svn delete --keep-local test2.out
svn diff > changes.diff
make veryclean
make APPLICATION=task_test
make run APPLICATION=task_test
make run APPLICATION=task_test > task_test.out
nm -C -n app/task_test
nm -C -n app/task_test > task_test_builtin.sym
nm -C -n src/system/pc_system
nm -C -n src/system/pc_system > system_builtin.sym
nm -C -n app/task_test
nm -C -n src/system/pc_system
exit
cd epos
ls
rm -rf eposProj1_v4/
ls
make veryclean
make APPLICATION=task_test
cd ..
ls
cd epos
make APPLICATION=task_test
make veryclean
make APPLICATION=task_test
make run APPLICATION=task_test
cd ..
rm -rf eposAlterado/
rm -rf protege
rm -rf eposEx6-bkp/
ls
cd epos
svn add --all
svn add *
svn diff > changes.diff
svn add help
svn help
svn help add
svn add --force *
svn diff > changes.diff
vi app/philosophers_dinner.cc 
ls
cd app
ls
vi philosophers_dinner.cc 
vi fork.cc
cd ,,
cd ..
cd "epos P1"/
ls
cd app
ls
vi philosophers_dinner.cc 
cd ..
make veryclean
cd ..
exit
svn co https://epos.lisha.ufsc.br/svn/teaching/ine5424 epos
git status
git add "epos P1"
git reset "epos P1/.svn"
git status
git add epos
git commit -m "Projeto 1"
git push
git add "epos P1/Grupo 10 - Projeto 1.pdf" 
git st
git status
git add epos
git add --force epos
git add --all epos
git reset epos/.svn
git status
git commit -m "Projeto 2"
git push
cd epos
ls
cd ..
ls
cd epos
make veryclean
cd app
ls
cd ,,
cd ..
make APPLICATION=fork
cd epos
make APPLICATION=semaphore_test
make run APPLICATION=semaphore_test
exit
cd epos
ls
svn diff > changes.digg
svn diff > changes.diff
cd ..
cd "epos P2
~" 
cd "epos P2"
ls
cd app
ls
vi philosophers_dinner.cc 
cd ..
cd ../epos
ls
cd app
vi philosophers_dinner.cc 
cd ../../"epos P1"
cd ..
git status
cd "epos P1"
cd app
ls
cd ..
cd src/abstraction/
ls
vi semaphore_test.cc
cd ..
rm -rf epos
cd epos
ls
make veryclean
make APPLICATION=semaphore_test
make run APPLICATION=semaphore_test
cd epos
make veryclean
make APPLICATION=semaphore_test
make veryclean
make APPLICATION=semaphore_test
make veryclean
make APPLICATION=semaphore_test
make veryclean
make APPLICATION=semaphore_test
make run APPLICATION=semaphore_test
make run APPLICATION=fork
git st
git status
git add epos
git status
git reset epos/.svn
git commit -m "Projeto 2 andamento"
git push
cd epos
make run APPLICATION=semaphore_test
cd epos
make veryclean
make APPLICATION=semaphore_test
cd ..
svn co https://epos.lisha.ufsc.br/svn/teaching/ine5424 epos
git status
rm -rf epos
git status
git add epos
git add --all epos
git reset epos/.svn
git commit -m "bosta'
"
git push
git status
git add --all epos
git reset epos/.svn
git push
git commit -m "skeleton.h"
git push
cd epos
make APPLICATION=semaphore_test
make run APPLICATION=semaphore_test
cd epos
make run APPLICATION=semaphore_test
cd epos
make veryclean
make APPLICATION=semaphore_test
make run APPLICATION=semaphore_test
make veryclean
make APPLICATION=semaphore_test
make run APPLICATION=semaphore_test
make APPLICATION=semaphore_test
make run APPLICATION=philosophers_dinner
make run APPLICATION=semaphore_test
make APPLICATION=semaphore_test
make veryclean
make APPLICATION=semaphore_test
make run APPLICATION=semaphore_test
cd epos
make run APPLICATION=semaphore_test
cd epos
make veryclean
make APPLICATION=philosophers_dinner
vi app/philosophers_dinner.cc
make APPLICATION=semaphore_test
make run APPLICATION=semaphore_test
cd epos
make APPLICATION=semaphore_test
make run APPLICATION=semaphore_test
cd epos
make APPLICATION=semaphore_test
make run APPLICATION=semaphore_test
cd epos
make veryclean
make APPLICATION=semaphore_test
make run APPLICATION=semaphore_test
cd epos
make veryclean
make APPLICATION=semaphore_test
make run APPLICATION=semaphore_test
cd epos
make run APPLICATION=semaphore_test
cd epos
make APPLICATION=semaphore_test
make run APPLICATION=semaphore_test
cd epos
vi app/philosophers_dinner.cc 
make APPLICATION=philosophers_dinner
make run APPLICATION=philosophers_dinner
