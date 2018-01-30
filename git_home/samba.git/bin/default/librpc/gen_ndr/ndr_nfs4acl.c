/* parser auto-generated by pidl */

#include "includes.h"
#include "bin/default/librpc/gen_ndr/ndr_nfs4acl.h"

#include "librpc/gen_ndr/ndr_misc.h"
#include "librpc/gen_ndr/ndr_security.h"
static enum ndr_err_code ndr_push_nfs4ace(struct ndr_push *ndr, int ndr_flags, const struct nfs4ace *r)
{
	{
		uint32_t _flags_save_STRUCT = ndr->flags;
		ndr_set_flags(&ndr->flags, LIBNDR_FLAG_BIGENDIAN);
		NDR_PUSH_CHECK_FLAGS(ndr, ndr_flags);
		if (ndr_flags & NDR_SCALARS) {
			NDR_CHECK(ndr_push_align(ndr, 4));
			NDR_CHECK(ndr_push_uint16(ndr, NDR_SCALARS, r->e_type));
			NDR_CHECK(ndr_push_uint16(ndr, NDR_SCALARS, r->e_flags));
			NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->e_mask));
			NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->e_id));
			{
				uint32_t _flags_save_string = ndr->flags;
				ndr_set_flags(&ndr->flags, LIBNDR_FLAG_STR_UTF8|LIBNDR_FLAG_STR_NULLTERM);
				NDR_CHECK(ndr_push_string(ndr, NDR_SCALARS, r->e_who));
				ndr->flags = _flags_save_string;
			}
			{
				uint32_t _flags_save_DATA_BLOB = ndr->flags;
				ndr_set_flags(&ndr->flags, LIBNDR_FLAG_ALIGN4);
				NDR_CHECK(ndr_push_DATA_BLOB(ndr, NDR_SCALARS, r->_pad));
				ndr->flags = _flags_save_DATA_BLOB;
			}
			NDR_CHECK(ndr_push_trailer_align(ndr, 4));
		}
		if (ndr_flags & NDR_BUFFERS) {
		}
		ndr->flags = _flags_save_STRUCT;
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_nfs4ace(struct ndr_pull *ndr, int ndr_flags, struct nfs4ace *r)
{
	{
		uint32_t _flags_save_STRUCT = ndr->flags;
		ndr_set_flags(&ndr->flags, LIBNDR_FLAG_BIGENDIAN);
		NDR_PULL_CHECK_FLAGS(ndr, ndr_flags);
		if (ndr_flags & NDR_SCALARS) {
			NDR_CHECK(ndr_pull_align(ndr, 4));
			NDR_CHECK(ndr_pull_uint16(ndr, NDR_SCALARS, &r->e_type));
			NDR_CHECK(ndr_pull_uint16(ndr, NDR_SCALARS, &r->e_flags));
			NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->e_mask));
			NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->e_id));
			{
				uint32_t _flags_save_string = ndr->flags;
				ndr_set_flags(&ndr->flags, LIBNDR_FLAG_STR_UTF8|LIBNDR_FLAG_STR_NULLTERM);
				NDR_CHECK(ndr_pull_string(ndr, NDR_SCALARS, &r->e_who));
				ndr->flags = _flags_save_string;
			}
			{
				uint32_t _flags_save_DATA_BLOB = ndr->flags;
				ndr_set_flags(&ndr->flags, LIBNDR_FLAG_ALIGN4);
				NDR_CHECK(ndr_pull_DATA_BLOB(ndr, NDR_SCALARS, &r->_pad));
				ndr->flags = _flags_save_DATA_BLOB;
			}
			NDR_CHECK(ndr_pull_trailer_align(ndr, 4));
		}
		if (ndr_flags & NDR_BUFFERS) {
		}
		ndr->flags = _flags_save_STRUCT;
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_nfs4ace(struct ndr_print *ndr, const char *name, const struct nfs4ace *r)
{
	ndr_print_struct(ndr, name, "nfs4ace");
	if (r == NULL) { ndr_print_null(ndr); return; }
	{
		uint32_t _flags_save_STRUCT = ndr->flags;
		ndr_set_flags(&ndr->flags, LIBNDR_FLAG_BIGENDIAN);
		ndr->depth++;
		ndr_print_uint16(ndr, "e_type", r->e_type);
		ndr_print_uint16(ndr, "e_flags", r->e_flags);
		ndr_print_uint32(ndr, "e_mask", r->e_mask);
		ndr_print_uint32(ndr, "e_id", r->e_id);
		ndr_print_string(ndr, "e_who", r->e_who);
		ndr_print_DATA_BLOB(ndr, "_pad", r->_pad);
		ndr->depth--;
		ndr->flags = _flags_save_STRUCT;
	}
}

_PUBLIC_ enum ndr_err_code ndr_push_nfs4acl(struct ndr_push *ndr, int ndr_flags, const struct nfs4acl *r)
{
	uint32_t cntr_ace_0;
	{
		uint32_t _flags_save_STRUCT = ndr->flags;
		ndr_set_flags(&ndr->flags, LIBNDR_FLAG_BIGENDIAN);
		NDR_PUSH_CHECK_FLAGS(ndr, ndr_flags);
		if (ndr_flags & NDR_SCALARS) {
			NDR_CHECK(ndr_push_align(ndr, 4));
			NDR_CHECK(ndr_push_uint8(ndr, NDR_SCALARS, r->a_version));
			NDR_CHECK(ndr_push_uint8(ndr, NDR_SCALARS, r->a_flags));
			NDR_CHECK(ndr_push_uint16(ndr, NDR_SCALARS, r->a_count));
			NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->a_owner_mask));
			NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->a_group_mask));
			NDR_CHECK(ndr_push_uint32(ndr, NDR_SCALARS, r->a_other_mask));
			for (cntr_ace_0 = 0; cntr_ace_0 < (r->a_count); cntr_ace_0++) {
				NDR_CHECK(ndr_push_nfs4ace(ndr, NDR_SCALARS, &r->ace[cntr_ace_0]));
			}
			NDR_CHECK(ndr_push_trailer_align(ndr, 4));
		}
		if (ndr_flags & NDR_BUFFERS) {
		}
		ndr->flags = _flags_save_STRUCT;
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ enum ndr_err_code ndr_pull_nfs4acl(struct ndr_pull *ndr, int ndr_flags, struct nfs4acl *r)
{
	uint32_t size_ace_0 = 0;
	uint32_t cntr_ace_0;
	TALLOC_CTX *_mem_save_ace_0 = NULL;
	{
		uint32_t _flags_save_STRUCT = ndr->flags;
		ndr_set_flags(&ndr->flags, LIBNDR_FLAG_BIGENDIAN);
		NDR_PULL_CHECK_FLAGS(ndr, ndr_flags);
		if (ndr_flags & NDR_SCALARS) {
			NDR_CHECK(ndr_pull_align(ndr, 4));
			NDR_CHECK(ndr_pull_uint8(ndr, NDR_SCALARS, &r->a_version));
			NDR_CHECK(ndr_pull_uint8(ndr, NDR_SCALARS, &r->a_flags));
			NDR_CHECK(ndr_pull_uint16(ndr, NDR_SCALARS, &r->a_count));
			NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->a_owner_mask));
			NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->a_group_mask));
			NDR_CHECK(ndr_pull_uint32(ndr, NDR_SCALARS, &r->a_other_mask));
			size_ace_0 = r->a_count;
			NDR_PULL_ALLOC_N(ndr, r->ace, size_ace_0);
			_mem_save_ace_0 = NDR_PULL_GET_MEM_CTX(ndr);
			NDR_PULL_SET_MEM_CTX(ndr, r->ace, 0);
			for (cntr_ace_0 = 0; cntr_ace_0 < (size_ace_0); cntr_ace_0++) {
				NDR_CHECK(ndr_pull_nfs4ace(ndr, NDR_SCALARS, &r->ace[cntr_ace_0]));
			}
			NDR_PULL_SET_MEM_CTX(ndr, _mem_save_ace_0, 0);
			NDR_CHECK(ndr_pull_trailer_align(ndr, 4));
		}
		if (ndr_flags & NDR_BUFFERS) {
		}
		ndr->flags = _flags_save_STRUCT;
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_nfs4acl(struct ndr_print *ndr, const char *name, const struct nfs4acl *r)
{
	uint32_t cntr_ace_0;
	ndr_print_struct(ndr, name, "nfs4acl");
	if (r == NULL) { ndr_print_null(ndr); return; }
	{
		uint32_t _flags_save_STRUCT = ndr->flags;
		ndr_set_flags(&ndr->flags, LIBNDR_FLAG_BIGENDIAN);
		ndr->depth++;
		ndr_print_uint8(ndr, "a_version", r->a_version);
		ndr_print_uint8(ndr, "a_flags", r->a_flags);
		ndr_print_uint16(ndr, "a_count", r->a_count);
		ndr_print_uint32(ndr, "a_owner_mask", r->a_owner_mask);
		ndr_print_uint32(ndr, "a_group_mask", r->a_group_mask);
		ndr_print_uint32(ndr, "a_other_mask", r->a_other_mask);
		ndr->print(ndr, "%s: ARRAY(%d)", "ace", (int)r->a_count);
		ndr->depth++;
		for (cntr_ace_0 = 0; cntr_ace_0 < (r->a_count); cntr_ace_0++) {
			ndr_print_nfs4ace(ndr, "ace", &r->ace[cntr_ace_0]);
		}
		ndr->depth--;
		ndr->depth--;
		ndr->flags = _flags_save_STRUCT;
	}
}

static enum ndr_err_code ndr_push_nfs4acl_test(struct ndr_push *ndr, int flags, const struct nfs4acl_test *r)
{
	NDR_PUSH_CHECK_FN_FLAGS(ndr, flags);
	if (flags & NDR_IN) {
		NDR_CHECK(ndr_push_nfs4acl(ndr, NDR_SCALARS, &r->in.acl));
	}
	if (flags & NDR_OUT) {
		NDR_CHECK(ndr_push_NTSTATUS(ndr, NDR_SCALARS, r->out.result));
	}
	return NDR_ERR_SUCCESS;
}

static enum ndr_err_code ndr_pull_nfs4acl_test(struct ndr_pull *ndr, int flags, struct nfs4acl_test *r)
{
	NDR_PULL_CHECK_FN_FLAGS(ndr, flags);
	if (flags & NDR_IN) {
		NDR_CHECK(ndr_pull_nfs4acl(ndr, NDR_SCALARS, &r->in.acl));
	}
	if (flags & NDR_OUT) {
		NDR_CHECK(ndr_pull_NTSTATUS(ndr, NDR_SCALARS, &r->out.result));
	}
	return NDR_ERR_SUCCESS;
}

_PUBLIC_ void ndr_print_nfs4acl_test(struct ndr_print *ndr, const char *name, int flags, const struct nfs4acl_test *r)
{
	ndr_print_struct(ndr, name, "nfs4acl_test");
	if (r == NULL) { ndr_print_null(ndr); return; }
	ndr->depth++;
	if (flags & NDR_SET_VALUES) {
		ndr->flags |= LIBNDR_PRINT_SET_VALUES;
	}
	if (flags & NDR_IN) {
		ndr_print_struct(ndr, "in", "nfs4acl_test");
		ndr->depth++;
		ndr_print_nfs4acl(ndr, "acl", &r->in.acl);
		ndr->depth--;
	}
	if (flags & NDR_OUT) {
		ndr_print_struct(ndr, "out", "nfs4acl_test");
		ndr->depth++;
		ndr_print_NTSTATUS(ndr, "result", r->out.result);
		ndr->depth--;
	}
	ndr->depth--;
}

static const struct ndr_interface_call nfs4acl_interface_calls[] = {
	{
		"nfs4acl_test",
		sizeof(struct nfs4acl_test),
		(ndr_push_flags_fn_t) ndr_push_nfs4acl_test,
		(ndr_pull_flags_fn_t) ndr_pull_nfs4acl_test,
		(ndr_print_function_t) ndr_print_nfs4acl_test,
		{ 0, NULL },
		{ 0, NULL },
	},
	{ NULL, 0, NULL, NULL, NULL }
};

static const char * const nfs4acl_interface_endpoint_strings[] = {
	"ncacn_np:[\\pipe\\nfs4acl_interface]", 
};

static const struct ndr_interface_string_array nfs4acl_interface_endpoints = {
	.count	= 1,
	.names	= nfs4acl_interface_endpoint_strings
};

static const char * const nfs4acl_interface_authservice_strings[] = {
	"host", 
};

static const struct ndr_interface_string_array nfs4acl_interface_authservices = {
	.count	= 1,
	.names	= nfs4acl_interface_authservice_strings
};


const struct ndr_interface_table ndr_table_nfs4acl_interface = {
	.name		= "nfs4acl_interface",
	.syntax_id	= {
		{0x18763978,0x8625,0xabc3,{0x54,0xca},{0x98,0x92,0xba,0xcd,0xf3,0x21}},
		NDR_NFS4ACL_INTERFACE_VERSION
	},
	.helpstring	= NDR_NFS4ACL_INTERFACE_HELPSTRING,
	.num_calls	= 1,
	.calls		= nfs4acl_interface_calls,
	.endpoints	= &nfs4acl_interface_endpoints,
	.authservices	= &nfs4acl_interface_authservices
};

