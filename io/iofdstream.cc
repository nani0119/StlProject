#include <cstdio>
#include <iostream>
#include <streambuf>
#include <cstring>

// for write
#ifdef _MSC_VER
# include <io.h>
#else
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#endif


using namespace std;


class fdoutbuf: public streambuf
{
    protected:
        static const int bufferSize = 10;
        int fd = -1; // file descriptor
        char buffer[bufferSize];

    public:
        // - one character less to let the bufferSizeth character cause a call of overflow()
        fdoutbuf(int _fd): fd(_fd)
        {
            setp(buffer, buffer+(bufferSize-1));
        }
        fdoutbuf(const string& fileName, int flags): fd(open(fileName.c_str(), flags))
        {
            if(fd == -1)
            {
                throw logic_error("open file fail");
            }
            setp(buffer, buffer+(bufferSize-1));
        }
        ~fdoutbuf()
        {
            sync();
            fd = -1;
        }
    protected:
        // flush the characters in the buffer
        int flushBuffer()
        {
            if(fd == -1)
            {
                return EOF;
            }
            int num = pptr() - pbase();
            if(write(fd, buffer, num) != num)
            {
                return EOF;
            }
            pbump(-num); // reset put pointer accordingly,Adds n to the pptr.
            return num;
        }

        // buffer full
        virtual int_type overflow(int_type c)
        {
            //cout << __func__<<endl;
            if(c != EOF)
            {
                *pptr() = c;
                pbump(1);
            }
            if(flushBuffer() == EOF)
            {
                //ERROR
                return EOF;
            }
            return c;
        }

        // synchronize data with file/destination
        // - flush the data in the buffer
        virtual int sync()
        {
            if(flushBuffer() == EOF)
            {
                // ERROR
                return -1;
            }
            return 0;
        }
};

class fdostream :public ostream{
    protected:
        fdoutbuf buf;
    public:
        fdostream(int fd): std::ostream(0), buf(fd)
        {
            rdbuf(&buf);
        }

};

class fdinbuf: public streambuf 
{
    protected:
        // data buffer:
        // - at most, four characters in putback area plus
        // - at most, six characters in ordinary read buffer
        static const int bufferSize = 10;
        int fd = -1; // file descriptor
        char buffer[bufferSize];

    public:
        // constructor
        // - initialize empty data buffer
        // - no putback area
        // => force underflow()
        fdinbuf(int _fd): fd(_fd)
        {
            setg (  buffer+4, // beginning of putback area
                    buffer+4, // read position
                    buffer+4); // end position
        }
        fdinbuf(const string& fileName, int flags): fd(open(fileName.c_str(), flags))
        {
            if(fd == -1)
            {
                throw logic_error("open file fail");
            }
            setg (  buffer+4, // beginning of putback area
                    buffer+4, // read position
                    buffer+4); // end position
        }
    protected:
        virtual int_type underflow()
        {
            // cout << __func__ << endl;
            // is read position before end of buffer?
            if (gptr() < egptr()) 
            {
                return traits_type::to_int_type(*gptr());
            }
            // process size of putback area
            // - use number of characters read
            // - but at most four
            int numPutback;
            numPutback = gptr() - eback();
            if (numPutback > 4) 
            {
                numPutback = 4;
            }
            // copy up to four characters previously read into
            // the putback buffer (area of first four characters)
            std::memmove (buffer+(4-numPutback), gptr()-numPutback, numPutback);

            // read new characters
            if(fd == -1)
            {
                return EOF;
            }
            int num;
            num = read (fd, buffer+4, bufferSize-4);
            if (num <= 0) 
            {
                // ERROR or EOF
                return EOF;
            }
            // reset buffer pointers
            setg(buffer + (4 - numPutback), // beginning of putback area
                 buffer + 4,                // read position
                 buffer + 4 + num);         // end of buffer
            // return next character
            return traits_type::to_int_type(*gptr());
        }
};

class fdistream :public istream{
    protected:
        fdinbuf buf;
    public:
        fdistream(int fd): std::istream(0), buf(fd)
        {
            rdbuf(&buf);
        }

};
int main(int argc, char const *argv[])
{
    // fdoutbuf fob(1);
    // ostream os(&fob);
    // os << "123456" << endl;

    // fdostream   fos(1);
    // fos << "1234567891234"<<endl;

    fdinbuf fib(0);
    istream in(&fib);

    char c;
    for (int i = 1; i <= 20; i++)
    {
        // read next character (out of the buffer)
        in.get(c);
        // print that character (and flush)
        std::cout << i << ":"<< c << std::endl;
        // after eight characters, put two characters back into the stream
        if (i == 8)
        {
            in.unget();
            in.unget();
        }
    }
    std::cout << std::endl;

    return 0;
}
