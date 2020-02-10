# Digital Voting Based on Blockchain 
 This is a demo project showing how blockchain technology can be used in voting system . 
 
 ## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes .

### Prerequisites

What things you need to install the software and how to install them

```
Visual Studio 
Successfully installed MYSQL
Database server (XAMPP , WAMPP)


```


### Installing
A step by step series of examples that tell you how you can set up development env running on you machine



```
Install visual studio (latest version)
```

```
Download and install Xampp as a web server . Open Xampp Control Panel and click Start button for Apache and MySQL modules, wait until they start. To check if Xampp is working correctly, from your Web Browser, go to http://localhost/dashboard/ to see if Welcome text comes or not, it you see Welcome to XAMPP then its fine. 

```



```
Download Windows (x86, 32-bit), MSI Installer

Next run MySQL Installer (mysql-installer-web-community-5.7.17.0.msi), and in installation process choose Custom, then add MySQL Server 5.7.17 - X86 ( not all of its components, only check the Development Components and its Client C API library ). Also add Connector/C++ 1.1.8 - X86.
```

```
. Using MySQL Installer install:
 a. MySQL Community Server 8.0.11
 b. MySQL Connector/C++ version 8.0.11
. Update the relevant include and lib directories in Visual Studio Community 2017
 a. C:\Program Files\MySQL\Connector C++ 1.1\include
 b. C:\Program Files\MySQL\MySQL Server 8.0\include
 c. C:\Program Files\MySQL\Connector C++ 1.1\lib\opt
 d. C:\Program Files\MySQL\MySQL Server 8.0\lib
 e. mysqlcppconn.lib
 f. libmysql.lib
. Code, build, run
 a. Copy libmysql.dll from C:\Program Files\MySQL\MySQL Server 8.0\lib 
  to the executable directory
 b. Copy libeay32.dll and ssleay32.dll from 
  C:\Program Files\MySQL\MySQL Server 8.0\bin to the executable directory
  ```



```
run ConsoleApplication1.cpp
```


## Acknowledgments

*  [okdshin](https://github.com/okdshin/PicoSHA2/blob/master/example/hasher.cpp)
*  [Savjee](https://www.youtube.com/channel/UCnxrdFPXJMeHru_b4Q_vTPQ)




