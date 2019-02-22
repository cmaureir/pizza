char const* hello()
{
   return "Hello Python Pizza Berlin!";
}

#include <boost/python.hpp>

BOOST_PYTHON_MODULE(simple)
{
    using namespace boost::python;
    def("hello", hello);
}
