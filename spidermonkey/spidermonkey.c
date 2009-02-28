
#include <Python.h>

#include "context.h"
#include "runtime.h"

static PyMethodDef spidermonkey_methods[] = {
    {NULL}
};

#ifndef PyMODINIT_FUNC
#define PyMODINIT_FUNC void
#endif
PyMODINIT_FUNC
initspidermonkey(void)
{
    PyObject* m;
    
    if(PyType_Ready(&RuntimeType) < 0)
    {
        return;
    }
   
    if(PyType_Ready(&ContextType) < 0)
    {
        return;
    }
    
    m = Py_InitModule3("spidermonkey", spidermonkey_methods,
            "The Python-Spidermonkey bridge.");

    if(m == NULL)
    {
        return;
    }

    Py_INCREF(&RuntimeType);
    PyModule_AddObject(m, "Runtime", (PyObject*) &RuntimeType);

    Py_INCREF(&ContextType);
    PyModule_AddObject(m, "Context", (PyObject*) &ContextType);
}
