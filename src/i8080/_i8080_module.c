#include "Python.h"
#include "_i8080_module.h"

/* ---------- 
Module Methods
----------  */
static PyObject *
i8080_m_add(PyObject *self, PyObject *args)
{
    uint64_t val_1, val_2;

    // https://docs.python.org/3/c-api/arg.html
    if (!PyArg_ParseTuple(args, "LL", &val_1, &val_2)){
        PyErr_SetString(PyExc_Exception, "Parse error\n");
        return NULL;
    }
    uint64_t result = val_1 + val_2;
    return Py_BuildValue("L", result);
}


/* ---------- 
Module Initialization
---------- */

/* List of functions defined in the module */

// https://docs.python.org/3/c-api/structures.html?highlight=pymethoddef#c.PyMethodDef
static PyMethodDef i8080_module_methods[] = {
    {"add",    (PyCFunction)i8080_m_add, METH_VARARGS, PyDoc_STR("Add two numbers")},
    {NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
"This module is for emulating the Intel 8080 CPU.");

// https://docs.python.org/3/c-api/module.html#c.PyModuleDef
static struct PyModuleDef i8080module = {
    PyModuleDef_HEAD_INIT,  //m_base
    "intel_8080",           //m_name
    module_doc,             //m_doc
    0,                      //m_size
    i8080_module_methods,   //m_methods
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