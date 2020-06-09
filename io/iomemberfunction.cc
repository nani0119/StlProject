#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <string.h>
using namespace std;


void testInputFunction()
{
    cout << "===================" << __func__<<  "=====================" << endl;
    char array[7] = {'a', 'a', 'a', 'a', 'a', 'x',  0};
    char array1[7] = {0};
    int ich;
    char ch;
#if 0
    cout << "test funtion - get():" << endl;
    while((ich = cin.get()) != EOF)
    {
        cout.put(static_cast<char>(ich));
    }
    
    cout << "test function - get(char& c)"<<endl;
    while(cin.get(ch))
    {
        cout.put(ch);
    }
    
    cout << "test function - get(char* str,streamsize count, char delim):"<<endl;
    // append '\0' at the end
    // quit: lenth(str) > n-1 or meet delim
    // delim is not read
    cin.get(array, 5, 'q');
    printf("%s", array);


    cout << "test function - getline(char* str, streamsize count):" << endl;
    // append '\0' at the end
    // quit:  meet delim ;if lenth(str) > n -1 return error
    // delim (newline) is read
    if(!cin.getline(array,5))
    {
        cout << "getline fail" << endl;
    }
    else
    {
        printf("%s", array);
    }

    cout << "test function - read(char* str, streamsize count):"<<endl;
    // Reads count characters, not append '\0' at the end
    // quit:  read count characters
    if(!cin.read(array, 5))
    {
        cout << "getline fail" << endl;
    }
    else
    {
        printf("%s", array);
    }
    
  
    // Reads up to count characters into the string str.
    // Returns the number of characters read
    // The string in str is not terminated automatically with a (terminating) null character
    // readsome() reads all available characters of the stream buffer, using the in_avail() member function of the buffer
    cout << "test function - readsome(char* str, streamsize count):" << endl;
    streamsize size = cin.readsome(array, 5);
    cout << "size:" << size << endl;
    printf("%s", array);

    cout << "test function - gcount():" << endl;
    cin.getline(array, 5);
    cout << "read count:" << cin.gcount() << endl;

    cout << "test function - ignore():"<< endl;
    cin.get(array, 5, 'p');
    cin.ignore();
    // The following call discards the rest of the line
    // cin.ignore(numeric_limits<std::streamsize>::max(),’\n’);
    // The following call discards the complete remainder of cin
    // cin.ignore(numeric_limits<std::streamsize>::max());
    cin.get(array1, 4);
    printf("%s", array1);
    

    cout << "test function - peek():" << endl;
    cin.get(array, 5, 'p');
    cout << static_cast<char>(cin.peek())<< endl;
    cin.get(array1,7);
    cout << array1 << endl;

    cout << "test function - unget():" << endl;
    cin.get(ch);
    cout << "ch:" << ch << endl;
    cin.unget();
    cin.get(array, 5, 'p');
    cout << array << endl;

    cout << "test function - putback(char c):"<< endl;
    cin.get(ch);
    cout << "ch:" << ch << endl;
    cin.putback(ch + 1);
    if(cin.bad())
    {
        cout << "putback fail" << endl;
    }
    cin.get(array, 5, 'p');
    cout << array << endl;
#endif
}

void testOutputFunction()
{
    cout << "===================" << __func__<<  "=====================" << endl;
    char ch = 'a';
    char* str = "123456";

    cout.put(ch);
    cout << endl;
    cout.write(str, sizeof(str));
    cout.flush();
    cout << endl;

}

int main(int argc, char const *argv[])
{
    testInputFunction();
    testOutputFunction();
    return 0;
}
