#include <iostream>
#include <string>

using namespace std;


template<typename charT, typename traits>
inline std::basic_ostream<charT, traits>& funcDelimManipulator(std::basic_ostream<charT, traits>&strm)
{
    strm << " | ";
    return strm;
}

template<typename charT, typename traits>
inline std::basic_ostream<charT, traits>& 
operator << (std::basic_ostream<charT, traits>& strm, 
                    std::basic_ostream<charT, traits>&(* op)(std::basic_ostream<charT, traits>&) )
{
    return (*op)(strm);
}

class ClassDelimManipulator
{
    public:
        ClassDelimManipulator():delim(" | ")
        {}
        ClassDelimManipulator(string str):delim(str)
        {}
        
        template<typename charT, typename traits>
        std::basic_ostream<charT, traits>& operator() (std::basic_ostream<charT, traits>& strm)
        {
            strm << delim;
            return strm;
        }
        
        template<typename charT, typename traits>
        friend std::basic_ostream<charT, traits>& operator << (std::basic_ostream<charT, traits>& strm, ClassDelimManipulator c)
        {
            //return c(strm);

            strm << c.delim;
            return strm;
        }
    private:
      string delim; 
};

void testManipulator()
{
    cout << funcDelimManipulator << "add a delim with function" << funcDelimManipulator << endl;
    cout << ClassDelimManipulator() << "add a delim with class " << ClassDelimManipulator() << endl;
    cout << ClassDelimManipulator(" // ") << "add a delim with class " << ClassDelimManipulator(" // ") << endl;
}

int main(int argc, char const *argv[])
{
    testManipulator();
    return 0;
}
