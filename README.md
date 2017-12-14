# knife
  Knife is A Simple, Elegant, Very Convenient C++ Syntactic-Sugar Library, for Multi-thread Speedup, and Hybrid programming with Python, SQLite and Bash  
  Knife 是一个简单，优雅，非常好用的C++语法糖库，用于多线程加速，以及与Python，SQLite，Bash的混合编程
  
## Outline 概述
  Knife 使用 $py、$sql 和 $bash 进行混合编程，使用knife::speedup<N>进行多线程加速  
  例如：
```
$bash("echo $(pwd)");
```
  相当于在当前bash环境下执行一句 echo $(pwd) 同样地
```
$py("import numpy as np");
$py("print (np.zeros(3))");

```
  相当于在Python环境下引入np，并打印3维零向量，Python环境在编译时指定，可以设置为Conda
```
$sql("CREATE TABLE Foo(ID INTEGER, Msg TEXT);");
```
  相当于在SQLite环境下的默认数据库里，创建一张表
   
```
   knife::speedup<32>(1000, [] {printf("hello");}, "task-foo");
```
  相当于使用32线程，执行 ```{printf("hello");}``` 共1000遍
## Usage: $sql
```C
   
#include <knife.hpp>

int main() {

    $sql("CREATE TABLE Foo(ID INTEGER, Msg TEXT);");

    // variables which have the 'same' names with cols
    // can insert into DB very easily and elegantly
    int ID;
    const char *Msg;

    ID = 1;
    Msg = "hello";
    $sql.insert_easily("Foo", ID, Msg);

    ID = 2;
    Msg = "world";
    $sql.insert_easily("Foo", ID, Msg);

    $sql("SELECT * FROM Foo");
    std::cout << $sql.query_result()[0][1] << std::endl;
    std::cout << $sql.query_result()[1][1] << std::endl;

    $sql("DROP TABLE Foo;");
}
   
```