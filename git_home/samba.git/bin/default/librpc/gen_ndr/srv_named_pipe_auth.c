/*
 * Unix SMB/CIFS implementation.
 * server auto-generated by pidl. DO NOT MODIFY!
 */

#include "includes.h"
#include "ntdomain.h"
#include "bin/default/librpc/gen_ndr/srv_named_pipe_auth.h"


/* Tables */
static const struct api_struct api_named_pipe_auth_cmds[] = 
{
};

const struct api_struct *named_pipe_auth_get_pipe_fns(int *n_fns)
{
	*n_fns = sizeof(api_named_pipe_auth_cmds) / sizeof(struct api_struct);
	return api_named_pipe_auth_cmds;
}

NTSTATUS rpc_named_pipe_auth_init(const struct rpc_srv_callbacks *rpc_srv_cb)
{
	return rpc_srv_register(SMB_RPC_INTERFACE_VERSION, "named_pipe_auth", "named_pipe_auth", &ndr_table_named_pipe_auth, api_named_pipe_auth_cmds, sizeof(api_named_pipe_auth_cmds) / sizeof(struct api_struct), rpc_srv_cb);
}

NTSTATUS rpc_named_pipe_auth_shutdown(void)
{
	return rpc_srv_unregister(&ndr_table_named_pipe_auth);
}
