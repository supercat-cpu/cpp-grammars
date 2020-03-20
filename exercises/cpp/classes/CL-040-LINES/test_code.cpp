#include <iostream>
#include <cstdio>
#include "textfilereader.hpp"

using std::cout;
using std::endl;
using std::boolalpha;

bool test_for_output_text();
bool test_call_hasnext_at_end();
bool test_empty_file();

int main()
{
    cout << std::boolalpha << "1 test (output text): " <<  test_for_output_text() << endl;
    cout << "2 test (test hasNext at end): " << test_call_hasnext_at_end() << endl;
    cout << "3 test (empty file: " << test_empty_file() << endl;

    cout << "testing completed." << endl;
    return 0;
}

bool test_for_output_text()
{
    const char * path = "test_1.txt";
    TextFileReader f(path);
    return ("1_line" == f.get()) && ("2_line" == f.get()) && (f.hasNext() == true);
}

bool test_call_hasnext_at_end()
{
    const char * path = "test_2.txt";
    TextFileReader f(path);
    return ("1_line" == f.get()) && (f.hasNext() == false);
}

bool test_empty_file()
{
    const char * path = "test_3.txt";
    TextFileReader f(path);
    return (f.hasNext() == false);
}
