#ifndef __stub_segment_h
#define __stub_segment_h

#include <api_types.h>
#include <stub/stub.h>

__BEGIN_APPLICATION

class Segment : Stub
{
    friend class Address_Space;
    friend class Task;

private:

    Segment(int object_id) : _object_id(object_id) {}

public:

  Segment(unsigned int bytes, Flags flags = Flags::APP){
    int * m = new int[6] {Class::SEGMENT, Method::Segment::CONSTRUCTOR_1, 0 , 0 , bytes, flags};
    syscall(m);
    _object_id = m[2];
    delete m;
  }

  Segment(Phy_Addr phy_addr, unsigned int bytes, Flags flags = Flags::APP ){
    Phy_Addr param1 = (phy_addr);
    int * m = new int[7] {Class::SEGMENT, Method::Segment::CONSTRUCTOR_2, 0 , 0 , param1, bytes, flags};
    syscall(m);
    _object_id = m[2];
    delete m;
  }

  ~Segment(){
    int * m = new int[4] {Class::SEGMENT, Method::Segment::DESTRUCTOR, _object_id, 0};
    syscall(m);
    delete m;
  }

  unsigned int size(){
    int * m = new int[4] {Class::SEGMENT, Method::Segment::SIZE, _object_id, 0 };
    syscall(m);
    unsigned int size = m[3];
    delete m;
    return size;
  }

  Phy_Addr phy_address(){
    int * m = new int[4] {Class::SEGMENT, Method::Segment::PHY_ADDRESS, _object_id, 0 };
    syscall(m);
    Phy_Addr phy = *reinterpret_cast<Phy_Addr*>(m[3]);
    delete m;
    return phy;
  }

  int resize( int amount ){
    int * m = new int[5] {Class::SEGMENT, Method::Segment::RESIZE, _object_id , 0 , amount};
    syscall(m);
    int retorno = m[3];
    delete m;
    return retorno;
  }

private:
  int _object_id;

};

__END_APPLICATION

#endif
