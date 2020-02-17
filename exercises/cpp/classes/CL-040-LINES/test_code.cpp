#include <iostream>
#include <cstdio>
#include "textfilereader.hpp"

using std::cout;
using std::endl;
using std::boolalpha;

void test_for_output_text();
void test_call_hasnext_at_end();
void test_empty_file();

int main()
{
    test_for_output_text();
    test_call_hasnext_at_end();
    test_empty_file();
    cout << "testing completed." << endl;
    return 0;
}

void test_for_output_text()
{
    char * path ="test_1.txt";
    TextFileReader f(path);
    cout << boolalpha << "test_1: " << endl << f.get() << " " << f.get() << endl << f.hasNext() << endl;
}

void test_call_hasnext_at_end()
{
    char * path = "test_2.txt";
    TextFileReader f(path);
    cout << "test_2: " << endl << f.get()  << endl << f.hasNext() << endl;
}

void test_empty_file()
{
    char * path = "test_3.txt";
    TextFileReader f(path);
    cout << "test_3: " << endl << f.hasNext()  << endl << f.get() << f.hasNext() << endl;
}