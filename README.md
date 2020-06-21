# Crawler: a c++ approach

### I. Devlopment platform: Ubuntu 18.04

### II. API installation

***simplified version***
1. bash ./install.sh
2. install C++ connector manually
     1.  go to [c++ connector page](https://dev.mysql.com/downloads/connector/cpp/) install c++ connector
     2. after install c++ connector through the instruction of the page please do command `sudo cp libmysqlcppconn8.so.2 /usr/lib`
     
***if the simplified version is not working, install manually***

***1. X DevAPI***
 * install mysql version 8: follow the instruction in [this link](https://www.sqlshack.com/how-to-install-mysql-on-ubuntu-18-04/): look at the part that teach installing mysql8)
     * remember to set username: root
     * password: cht123456

***2. C++ connector***
 1.  go to [c++ connector page](https://dev.mysql.com/downloads/connector/cpp/) install c++ connector
 2.  `sudo cp libmysqlcppconn8.so.2 /usr/lib`

***3. libcurl***
```
sudo apt-get install -y libcurl-dev
```

***4. tidy***
choos e proper binary installer from [here](http://binaries.html-tidy.org/)

***5. c++ boost***
```
sudo apt-get install libboost-all-dev
```
***6.C++ connector***
     1.  go to [c++ connector page](https://dev.mysql.com/downloads/connector/cpp/) install c++ connector
     2. after install c++ connector through the instruction of the page please do command `sudo cp libmysqlcppconn8.so.2 /usr/lib`

### III. Build
under the project ***IanAndHenry** directory
```
cd crawlerNew/cpp
make
cd ../
```

### IV. Run the application
```
./crawler [ettoday | storm | head]
```
websites currently is limited to [ettoday](https://www.ettoday.net/), [storm](https://www.storm.mg/), [head](https://newtalk.tw/)

### V. things to note
* After you run the crawler, result would show under ***ettoday.rec, sotrm.rec or head.rec***, depending on the website you have crawled
