/*
  Example for move_semantics or
  how to avoid superflous copies;
  g++ -g --std=c++17 string.cpp
*/

#include <iostream>

void memcpy(char* dest, const char* src, size_t len){
  while (len--) *dest++ = *src++;
  /* len-- a copy of prev len is created under the hood
     returns previous value and len -= 1
     --len len -= 1 and returns value */
}

size_t strlen(const char* src){
   size_t l = 0;
   while(*(src++)){
     ++l; /*no copy of prev len is created*/
   }
   return l;
}


class String{

private:
  size_t m_size;
  char* m_data;

public:

  String(const char* data){
    std::cout << "Created: ";
    m_size = strlen(data);
    m_data = new char[m_size];
    memcpy(m_data,data,m_size);
    for(uint i = 0; i< m_size; i++) std::cout << *(m_data+i);
    std::cout << std::endl;
  }
  
  String(const String& data){
    std::cout << "Copied\n";
    m_size = data.m_size;
    m_data = new char[m_size];
  }
  
  String(String&& data){
    std::cout << "Moved\n";
    m_size = data.m_size;
    m_data = data.m_data;
    data.m_size = 0;
    data.m_data = nullptr;
  }
  
  ~String(){
    std::cout << "Deleted";
    if(m_data == nullptr) std::cout << " nullptr";
    delete m_data;
    std::cout << std::endl;
  }
};

class Name{
  /*Just to use String*/
private:
  String m_name;

public:
  Name() = default;
  Name(String&& id):
    m_name(std::move(id)){
  };

};


int main(){

  Name me(String("Dev")); /*Created, Moved, Deleted*/
  Name you = String("User"); /*Created, Moved*/
  return 0;
}
