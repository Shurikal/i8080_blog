#include "Python.h"
#include "_i8080_module.h"
#include "_i8080_object.h"
#include "_i8080_constants.h"

static PyObject*
i8080o_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
	#ifdef DEBUG
	printf("Creating new i8080 object\n");
	#endif
	i8080oObject *self;
	self = (i8080oObject *)type->tp_alloc(type, 0);
	if (self != NULL) {
		self->x_attr = PyLong_FromLong(0);
		if (self->x_attr == NULL) {
			Py_DECREF(self);
			return NULL;
		}
	}

	// Set the default values
    self->memory = malloc(MEMORY_SIZE);

    if (self->memory == NULL){
        PyErr_SetString(PyExc_MemoryError, "Could not allocate memory\n");
        return NULL;
    }

	return (PyObject *)self;
}


// deallocate method
static void
i8080o_dealloc(i8080oObject *self)
{
    #ifdef DEBUG
    printf("Deallocating i8080oObject\n");
    #endif
    // free the memory
    if(self->memory != NULL){
        free(self->memory);
    }

    Py_XDECREF(self->x_attr);

    PyObject_Free(self);
}


// https://docs.python.org/3/c-api/typeobj.html
// not static because it is used in the module init function
PyTypeObject i8080o_Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "_i8080.i8080uC",
    .tp_basicsize = sizeof(i8080oObject),
    .tp_dealloc = (destructor)i8080o_dealloc,
	.tp_new = i8080o_new
};