#ifndef __stub_ostream_h
#define __stub_ostream_h

#include <api_types.h>
#include <stub/stub.h>

__BEGIN_APPLICATION

class OStream : Stub

{
public:

    OStream() {
        int * m = new int[3] {Class::OSTREAM, Method::OStream::CONSTRUCTOR, 0};
        syscall(m);
        _object_id = m[2];
        delete  m;

    }

    ~OStream() {
        int * m = new int[3] {Class::OSTREAM, Method::OStream::DESTRUCTOR, _object_id};
        syscall(m);
        delete  m;
    }

    OStream & operator<< (const char * s) {
        int param1 = reinterpret_cast<int>(s);
        int * m = new int[5] {Class::OSTREAM, Method::OStream::CHAR_PTR, _object_id , 0 , param1 };
        syscall(m);
        delete m;
        return *this;
    }

    OStream & operator<< (const Begl &) {
        int * m = new int[5] {Class::OSTREAM, Method::OStream::BEGL, _object_id , 0 };
        syscall(m);
        delete m;
        return *this;
    }

    OStream & operator<< (const Endl & endl) {
        int * m = new int[3] {Class::OSTREAM, Method::OStream::ENDL, _object_id };
        syscall(m);
        delete m;
        return *this;
    }

    OStream & operator<< (const Hex &) {
        int * m = new int[3] {Class::OSTREAM, Method::OStream::HEX, _object_id };
        syscall(m);
        delete m;
        return *this;

    }
    OStream & operator<< (const Dec &) {
        int * m = new int[3] {Class::OSTREAM, Method::OStream::DEC, _object_id};
        syscall(m);
        delete m;
        return *this;
    }
    OStream & operator<<(const Oct &) {
        int * m = new int[3] {Class::OSTREAM, Method::OStream::OCT, _object_id};
        syscall(m);
        delete m;
        return *this;
    }
    OStream & operator<<(const Bin &) {
        int * m = new int[3] {Class::OSTREAM, Method::OStream::BIN, _object_id};
        syscall(m);
        delete m;
        return *this;
    }

    OStream operator<<(const Err &) {
        int * m = new int[3] {Class::OSTREAM, Method::OStream::ERR, _object_id };
        syscall(m);
        delete m;
        return *this;
    }

    OStream operator<< (const char c) {
        int param1 = (int)(c);
        int * m = new int[5] {Class::OSTREAM, Method::OStream::CHAR, _object_id , 0 , param1};
        syscall(m);
        delete m;
        return *this;
    }

    OStream & operator<< (unsigned char c) {
        int param1 = (int)(c);
        int * m = new int[5] {Class::OSTREAM, Method::OStream::UCHAR, _object_id , 0 , param1};
        syscall(m);
        delete m;
        return *this;
    }

    OStream & operator<< (int i) {
        int * m = new int[5] {Class::OSTREAM, Method::OStream::INT, _object_id , 0 , i};
        syscall(m);
        delete m;
        return *this;
    }

    OStream & operator<< (short s) {
        int param1 = (int)(s);
        int * m = new int[5] {Class::OSTREAM, Method::OStream::SHORT, _object_id , 0 , param1};
        syscall(m);
        delete m;
        return *this;
    }

    OStream & operator<< (long l) {
        int param1 = (int)l;
        int * m = new int[5] {Class::OSTREAM, Method::OStream::LONG, _object_id , 0 , param1};
        syscall(m);
        delete m;
        return *this;
    }

    OStream & operator<< (unsigned int u) {
        int param1 = (int)u;
        int * m = new int[5] {Class::OSTREAM, Method::OStream::UINT, _object_id , 0 , param1};
        syscall(m);
        delete m;
        return *this;
    }

    OStream & operator<< (unsigned short s) {
        int param1 = (int)s;
        int * m = new int[5] {Class::OSTREAM, Method::OStream::USHORT, _object_id , 0 , param1};
        syscall(m);
        delete m;
        return *this;
    }

    OStream & operator<< (unsigned long l)
    {
        int param1 = (int)l;
        int * m = new int[5] {Class::OSTREAM, Method::OStream::ULONG, _object_id , 0 , param1};
        syscall(m);
        delete m;
        return *this;
    }

    OStream & operator<< (long long int u)
    {
        int param1 = (int)u;
        int * m = new int[5] {Class::OSTREAM, Method::OStream::LLINT, _object_id , 0 , param1};
        syscall(m);
        delete m;
        return *this;
    }

    OStream & operator<< (unsigned long long int u)
    {
        int param1 = (int)u;
        int * m = new int[5] {Class::OSTREAM, Method::OStream::ULLINT, _object_id, 0, param1};
        syscall(m);
        delete m;
        return *this;
    }

    OStream & operator<< (void * p) {
        int param1 = reinterpret_cast<int>(p);
        int * m = new int[5] {Class::OSTREAM, Method::OStream::VOID_PTR, _object_id, 0, param1};
        syscall(m);
        delete m;
        return *this;
    }

    OStream & operator<< (float f) {
        int param1 = reinterpret_cast<int>(&f);
        int * m = new int[5] {Class::OSTREAM, Method::OStream::FLOAT, _object_id, 0, param1};
        syscall(m);
        delete m;
        return *this;
    }

private:
    int _object_id;
};

__END_APPLICATION


#endif // OSTREAM_H
