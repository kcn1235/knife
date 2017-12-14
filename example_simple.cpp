//
// Created by xf on 2017/12/14.
//

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