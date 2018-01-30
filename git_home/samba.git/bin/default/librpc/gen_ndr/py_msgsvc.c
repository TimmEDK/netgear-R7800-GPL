
/* Python wrapper functions auto-generated by pidl */
#define PY_SSIZE_T_CLEAN 1 /* We use Py_ssize_t for PyArg_ParseTupleAndKeywords */
#include <Python.h>
#include "includes.h"
#include <pytalloc.h>
#include "librpc/rpc/pyrpc.h"
#include "librpc/rpc/pyrpc_util.h"
#include "bin/default/librpc/gen_ndr/ndr_msgsvc.h"
#include "bin/default/librpc/gen_ndr/ndr_msgsvc_c.h"

/*
 * These functions are here to ensure they can be optimized out by
 * the compiler based on the constant input values
 */

static inline unsigned long long ndr_sizeof2uintmax(size_t var_size)
{
	switch (var_size) {
	case 8:
		return UINT64_MAX;
	case 4:
		return UINT32_MAX;
	case 2:
		return UINT16_MAX;
	case 1:
		return UINT8_MAX;
	}

	return 0;
}

static inline long long ndr_sizeof2intmax(size_t var_size)
{
	switch (var_size) {
	case 8:
		return INT64_MAX;
	case 4:
		return INT32_MAX;
	case 2:
		return INT16_MAX;
	case 1:
		return INT8_MAX;
	}

	return 0;
}

static inline PyObject *ndr_PyLong_FromLongLong(long long v)
{
	if (v > LONG_MAX || v < LONG_MIN) {
		return PyLong_FromLongLong(v);
	} else {
		return PyInt_FromLong(v);
	}
}

static inline PyObject *ndr_PyLong_FromUnsignedLongLong(unsigned long long v)
{
	if (v > LONG_MAX) {
		return PyLong_FromUnsignedLongLong(v);
	} else {
		return PyInt_FromLong(v);
	}
}

static PyTypeObject msgsvc_InterfaceType;

static PyTypeObject msgsvcsend_InterfaceType;

void initmsgsvc(void);static PyTypeObject *ClientConnection_Type;
static PyTypeObject *ndr_syntax_id_Type;

const struct PyNdrRpcMethodDef py_ndr_msgsvc_methods[] = {
	{ NULL }
};

static PyObject *interface_msgsvc_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return py_dcerpc_interface_init_helper(type, args, kwargs, &ndr_table_msgsvc);
}

#define PY_DOC_MSGSVC "Messaging Service"
static PyTypeObject msgsvc_InterfaceType = {
	PyObject_HEAD_INIT(NULL) 0,
	.tp_name = "msgsvc.msgsvc",
	.tp_basicsize = sizeof(dcerpc_InterfaceObject),
	.tp_doc = "msgsvc(binding, lp_ctx=None, credentials=None) -> connection\n"
"\n"
"binding should be a DCE/RPC binding string (for example: ncacn_ip_tcp:127.0.0.1)\n"
"lp_ctx should be a path to a smb.conf file or a param.LoadParm object\n"
"credentials should be a credentials.Credentials object.\n\n"PY_DOC_MSGSVC,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_new = interface_msgsvc_new,
};

static PyObject *syntax_msgsvc_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return py_dcerpc_syntax_init_helper(type, args, kwargs, &ndr_table_msgsvc.syntax_id);
}

#define PY_DOC_MSGSVC_SYNTAX "Messaging Service"
static PyTypeObject msgsvc_SyntaxType = {
	PyObject_HEAD_INIT(NULL) 0,
	.tp_name = "msgsvc.msgsvc_abstract_syntax",
	.tp_doc = "msgsvc_abstract_syntax()\n"PY_DOC_MSGSVC_SYNTAX,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_new = syntax_msgsvc_new,
};


const struct PyNdrRpcMethodDef py_ndr_msgsvcsend_methods[] = {
	{ NULL }
};

static PyObject *interface_msgsvcsend_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return py_dcerpc_interface_init_helper(type, args, kwargs, &ndr_table_msgsvcsend);
}

static PyTypeObject msgsvcsend_InterfaceType = {
	PyObject_HEAD_INIT(NULL) 0,
	.tp_name = "msgsvc.msgsvcsend",
	.tp_basicsize = sizeof(dcerpc_InterfaceObject),
	.tp_doc = "msgsvcsend(binding, lp_ctx=None, credentials=None) -> connection\n"
"\n"
"binding should be a DCE/RPC binding string (for example: ncacn_ip_tcp:127.0.0.1)\n"
"lp_ctx should be a path to a smb.conf file or a param.LoadParm object\n"
"credentials should be a credentials.Credentials object.\n\n",
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_new = interface_msgsvcsend_new,
};

static PyObject *syntax_msgsvcsend_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return py_dcerpc_syntax_init_helper(type, args, kwargs, &ndr_table_msgsvcsend.syntax_id);
}

static PyTypeObject msgsvcsend_SyntaxType = {
	PyObject_HEAD_INIT(NULL) 0,
	.tp_name = "msgsvc.msgsvcsend_abstract_syntax",
	.tp_doc = "msgsvcsend_abstract_syntax()\n",
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_new = syntax_msgsvcsend_new,
};

static PyMethodDef msgsvc_methods[] = {
	{ NULL, NULL, 0, NULL }
};

void initmsgsvc(void)
{
	PyObject *m;
	PyObject *dep_samba_dcerpc_base;
	PyObject *dep_samba_dcerpc_misc;

	dep_samba_dcerpc_base = PyImport_ImportModule("samba.dcerpc.base");
	if (dep_samba_dcerpc_base == NULL)
		return;

	dep_samba_dcerpc_misc = PyImport_ImportModule("samba.dcerpc.misc");
	if (dep_samba_dcerpc_misc == NULL)
		return;

	ClientConnection_Type = (PyTypeObject *)PyObject_GetAttrString(dep_samba_dcerpc_base, "ClientConnection");
	if (ClientConnection_Type == NULL)
		return;

	ndr_syntax_id_Type = (PyTypeObject *)PyObject_GetAttrString(dep_samba_dcerpc_misc, "ndr_syntax_id");
	if (ndr_syntax_id_Type == NULL)
		return;

	msgsvc_InterfaceType.tp_base = ClientConnection_Type;

	msgsvc_SyntaxType.tp_base = ndr_syntax_id_Type;
	msgsvc_SyntaxType.tp_basicsize = pytalloc_BaseObject_size();

	msgsvcsend_InterfaceType.tp_base = ClientConnection_Type;

	msgsvcsend_SyntaxType.tp_base = ndr_syntax_id_Type;
	msgsvcsend_SyntaxType.tp_basicsize = pytalloc_BaseObject_size();

	if (PyType_Ready(&msgsvc_InterfaceType) < 0)
		return;
	if (PyType_Ready(&msgsvc_SyntaxType) < 0)
		return;
	if (PyType_Ready(&msgsvcsend_InterfaceType) < 0)
		return;
	if (PyType_Ready(&msgsvcsend_SyntaxType) < 0)
		return;
	if (!PyInterface_AddNdrRpcMethods(&msgsvc_InterfaceType, py_ndr_msgsvc_methods))
		return;

	if (!PyInterface_AddNdrRpcMethods(&msgsvcsend_InterfaceType, py_ndr_msgsvcsend_methods))
		return;

#ifdef PY_MSGSVC_PATCH
	PY_MSGSVC_PATCH(&msgsvc_InterfaceType);
#endif
#ifdef PY_MSGSVC_ABSTRACT_SYNTAX_PATCH
	PY_MSGSVC_ABSTRACT_SYNTAX_PATCH(&msgsvc_SyntaxType);
#endif
#ifdef PY_ABSTRACT_SYNTAX_PATCH
	PY_ABSTRACT_SYNTAX_PATCH(&msgsvc_SyntaxType);
#endif
#ifdef PY_MSGSVCSEND_PATCH
	PY_MSGSVCSEND_PATCH(&msgsvcsend_InterfaceType);
#endif
#ifdef PY_MSGSVCSEND_ABSTRACT_SYNTAX_PATCH
	PY_MSGSVCSEND_ABSTRACT_SYNTAX_PATCH(&msgsvcsend_SyntaxType);
#endif

	m = Py_InitModule3("msgsvc", msgsvc_methods, "msgsvc DCE/RPC");
	if (m == NULL)
		return;

	Py_INCREF((PyObject *)(void *)&msgsvc_InterfaceType);
	PyModule_AddObject(m, "msgsvc", (PyObject *)(void *)&msgsvc_InterfaceType);
	Py_INCREF((PyObject *)(void *)&msgsvc_SyntaxType);
	PyModule_AddObject(m, "msgsvc_abstract_syntax", (PyObject *)(void *)&msgsvc_SyntaxType);
	Py_INCREF((PyObject *)(void *)&msgsvc_SyntaxType);
	PyModule_AddObject(m, "abstract_syntax", (PyObject *)(void *)&msgsvc_SyntaxType);
	Py_INCREF((PyObject *)(void *)&msgsvcsend_InterfaceType);
	PyModule_AddObject(m, "msgsvcsend", (PyObject *)(void *)&msgsvcsend_InterfaceType);
	Py_INCREF((PyObject *)(void *)&msgsvcsend_SyntaxType);
	PyModule_AddObject(m, "msgsvcsend_abstract_syntax", (PyObject *)(void *)&msgsvcsend_SyntaxType);
#ifdef PY_MOD_MSGSVC_PATCH
	PY_MOD_MSGSVC_PATCH(m);
#endif

}
