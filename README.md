# wordninja

c++ version wordninja.
Probabilistically split concatenated words using NLP based on English Wikipedia unigram frequencies.

-----
This project is repackaging the excellent work from here: http://stackoverflow.com/a/11642687/2449774
and python version is here:https://github.com/keredson/wordninja

Usage
-----
you may change the test/test.cpp file,modify the dict path and the test string.:
```
mkdir build
cd build
cmake ..
make -j

```
example:
----
```
inputText:"wethepeopleoftheunitedstatesinordertoformamoreperfectunionestablishjusticeinsuredomestictranquilityprovideforthecommondefencepromotethegeneralwelfareandsecuretheblessingsoflibertytoourselvesandourposteritydoordainandestablishthisconstitutionfortheunitedstatesofamerica"
result:
we   the   people   of   the   united   states   in   order   to   form   a   more   perfect   union   establish   justice   in   sure   domestic   tranquility   provide   for   the   common   defence   promote   the   general   welfare   and   secure   the   blessings   of   liberty   to   ourselves   and   our   posterity   do   ordain   and   establish   this   constitution   for   the   united   states   of   america  
```