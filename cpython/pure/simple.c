//Python.h has all the required function definitions to manipulate the Python objects
#include <Python.h>

 //This is the function that is called from your python code
static PyObject* simple_hello(PyObject* self, PyObject* args){
    char *msg = "Hello Python Pizza Berlin!";
    return Py_BuildValue("s", msg);
}

//This is the docstring that corresponds to our 'add' function.
static char simple_docs[] =
    "hello(): print hello message\n";

/* This table contains the relavent info mapping -
  <function-name in python module>, <actual-function>,
  <type-of-args the function expects>, <docstring associated with the function>
*/
static PyMethodDef simple_funcs[] = {
    {"hello", (PyCFunction)simple_hello, METH_NOARGS, simple_docs},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef simplemodule = {
    PyModuleDef_HEAD_INIT,
    "simple",   /* name of module */
    simple_docs, /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    simple_funcs
};

/*
simple is the module name, and this is the initialization block of the module.
<desired module name>, <the-info-table>, <module's-docstring>
*/
PyMODINIT_FUNC PyInit_simple(void){
    return PyModule_Create(&simplemodule);
}
