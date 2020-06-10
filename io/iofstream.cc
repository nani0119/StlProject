#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iterator>
#include <sstream>


using namespace std;


fstream writeToFile(const string& fileName)
{
    cout <<"======"<< __func__<<"====="<<endl;
    fstream outFile(fileName, std::ios::in|std::ios::out|std::ios::trunc);
    istream_iterator<string> in (cin);
    istream_iterator<string> end;
    ostream_iterator<string> out(outFile,"\n");
    std::copy(in, end, out);
    outFile.flush();
    return outFile;
}

void modifyFile(fstream&& inOut)
{
    cout <<"======"<< __func__<<"====="<<endl;
    if (inOut.is_open())
    {
        cout << "output steam is opend" << endl;
        std::ios::pos_type pos;
        std::ios::off_type offset(0);
        inOut.seekp(offset, std::ios::end);
        pos = inOut.tellp();
        cout << "file size:" << pos << endl;
        cout << "append begin and end tag"<< endl;

        string s;
        stringstream ss(s, std::ios::in|std::ios::out);
        inOut.seekp(std::ios::beg);
        ss << "------------begin----------------------" << endl;
        ss << inOut.rdbuf();
        ss << "------------end------------------------" << endl;
        
        ss.seekp(std::ios::beg);
        // cout << "ss.str():" << ss.str()<< endl;
        inOut.seekp(std::ios::beg);
        std::copy(istream_iterator<string>(ss), istream_iterator<string>(), ostream_iterator<string>(inOut,"\n"));
        inOut.flush();
    }
    else
    {
        cout << "output stream is not opened" << endl;
    }
}


void outputFile(const string& fileName)
{
    cout <<"======"<< __func__<<"====="<<endl;
    ifstream inputFile(fileName);
    istream_iterator<string> in (inputFile);
    istream_iterator<string> end;
    ostream_iterator<string> out (cout, "\n");
    std::copy(in, end, out);
}

void testIOFstream(const string& fileName)
{
    cout <<"======"<< __func__<<"====="<<endl;
    fstream io(fileName,std::ios::out|std::ios::in| std::ios::ate);
    cout << "current position:" << io.tellp()<<"\t" << io.tellg() << endl;
    io << "---------------------------------------"<<endl;
    cout << "new current position:" << io.tellp()<<"\t" << io.tellg() << endl;
    io.seekp(std::ios::beg);
    std::copy(istream_iterator<string>(io), istream_iterator<string>(), ostream_iterator<string>(cout, "\n"));
}


int main(int argc, char const *argv[])
{
    string fileName("temp.txt"); 
    fstream outFile = writeToFile(fileName);
    modifyFile(std::move(outFile));
    outputFile(fileName);
    testIOFstream(fileName);
    return 0;
}
