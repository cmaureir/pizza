#include <pybind11/pybind11.h>

char* hello() {
   char *msg = "Hello Python Pizza Berlin!";
   return msg;
}

PYBIND11_MODULE(simple, m) {
    m.def("hello", &hello, "A function that print a message");
}
