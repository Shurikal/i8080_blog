#include "Python.h"
#include "_i8080_module.h"

PyDoc_STRVAR(module_doc,
"This module is for emulating the Intel 8080 CPU.");

// https://docs.python.org/3/c-api/module.html#c.PyModuleDef
static struct PyModuleDef i8080module = {
    PyModuleDef_HEAD_INIT,  //m_base
    "intel_8080",           //m_name
    module_doc,             //m_doc
    0,                      //m_size
    NULL,                   //m_methods
    NULL,                   //m_slots
    NULL,                   //m_traverse
    NULL,                   //m_clear
    NULL                    //m_free
};

/* 
Export function for the module (*must* be called PyInit_xx) 
module name is _i8080, from setup.py Extension
*/

PyMODINIT_FUNC
PyInit__i8080(void)
{
    return PyModuleDef_Init(&i8080module);
}