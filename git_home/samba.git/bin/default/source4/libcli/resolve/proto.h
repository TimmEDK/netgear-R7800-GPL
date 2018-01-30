#ifndef __DEFAULT_SOURCE4_LIBCLI_RESOLVE_PROTO_H__
#define __DEFAULT_SOURCE4_LIBCLI_RESOLVE_PROTO_H__

#undef _PRINTF_ATTRIBUTE
#define _PRINTF_ATTRIBUTE(a1, a2) PRINTF_ATTRIBUTE(a1, a2)
/* This file was automatically generated by mkproto.pl. DO NOT EDIT */

/* this file contains prototypes for functions that are private 
 * to this subsystem or library. These functions should not be 
 * used outside this particular subsystem! */


/* The following definitions come from ../source4/libcli/resolve/resolve.c  */


/**
 * Initialize a resolve context
 */
struct resolve_context *resolve_context_init(TALLOC_CTX *mem_ctx);

/**
 * Add a resolve method
 */
bool resolve_context_add_method(struct resolve_context *ctx, resolve_name_send_fn send_fn, 
				resolve_name_recv_fn recv_fn, void *userdata);

/**
  handle completion of one name resolve method
*/
struct composite_context *resolve_name_all_send(struct resolve_context *ctx,
						TALLOC_CTX *mem_ctx,
						uint32_t flags, /* RESOLVE_NAME_FLAG_* */
						uint16_t port,
						struct nbt_name *name,
						struct tevent_context *event_ctx);
NTSTATUS resolve_name_all_recv(struct composite_context *c,
			       TALLOC_CTX *mem_ctx,
			       struct socket_address ***addrs,
			       char ***names);
struct composite_context *resolve_name_ex_send(struct resolve_context *ctx,
					       TALLOC_CTX *mem_ctx,
					       uint32_t flags, /* RESOLVE_NAME_FLAG_* */
					       uint16_t port,
					       struct nbt_name *name,
					       struct tevent_context *event_ctx);
struct composite_context *resolve_name_send(struct resolve_context *ctx,
					    TALLOC_CTX *mem_ctx,
					    struct nbt_name *name,
					    struct tevent_context *event_ctx);
NTSTATUS resolve_name_recv(struct composite_context *c,
			   TALLOC_CTX *mem_ctx,
			   const char **reply_addr);
NTSTATUS resolve_name_multiple_recv(struct composite_context *c,
				    TALLOC_CTX *mem_ctx,
				    const char ***reply_addrs);
NTSTATUS resolve_name_ex(struct resolve_context *ctx,
			 uint32_t flags, /* RESOLVE_NAME_FLAG_* */
			 uint16_t port,
			 struct nbt_name *name,
			 TALLOC_CTX *mem_ctx,
			 const char **reply_addr,
			 struct tevent_context *ev);
void make_nbt_name(struct nbt_name *nbt, const char *name, int type);
void make_nbt_name_client(struct nbt_name *nbt, const char *name);
void make_nbt_name_server(struct nbt_name *nbt, const char *name);
#undef _PRINTF_ATTRIBUTE
#define _PRINTF_ATTRIBUTE(a1, a2)

#endif /* __DEFAULT_SOURCE4_LIBCLI_RESOLVE_PROTO_H__ */

