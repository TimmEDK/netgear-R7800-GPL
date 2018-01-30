#ifndef __DEFAULT_SOURCE4_LIBCLI_RAP_PROTO_H__
#define __DEFAULT_SOURCE4_LIBCLI_RAP_PROTO_H__

#undef _PRINTF_ATTRIBUTE
#define _PRINTF_ATTRIBUTE(a1, a2) PRINTF_ATTRIBUTE(a1, a2)
/* This file was automatically generated by mkproto.pl. DO NOT EDIT */

/* this file contains prototypes for functions that are private 
 * to this subsystem or library. These functions should not be 
 * used outside this particular subsystem! */


/* The following definitions come from ../source4/libcli/rap/rap.c  */

struct rap_call *new_rap_cli_call(TALLOC_CTX *mem_ctx, uint16_t callno);
NTSTATUS rap_cli_do_call(struct smbcli_tree *tree,
			 struct rap_call *call);
NTSTATUS smbcli_rap_netshareenum(struct smbcli_tree *tree,
				 TALLOC_CTX *mem_ctx,
				 struct rap_NetShareEnum *r);
NTSTATUS smbcli_rap_netserverenum2(struct smbcli_tree *tree,
				   TALLOC_CTX *mem_ctx,
				   struct rap_NetServerEnum2 *r);
NTSTATUS smbcli_rap_netservergetinfo(struct smbcli_tree *tree,
				     TALLOC_CTX *mem_ctx,
				     struct rap_WserverGetInfo *r);
NTSTATUS smbcli_rap_netprintqenum(struct smbcli_tree *tree,
				  TALLOC_CTX *mem_ctx,
				  struct rap_NetPrintQEnum *r);
NTSTATUS smbcli_rap_netprintqgetinfo(struct smbcli_tree *tree,
				     TALLOC_CTX *mem_ctx,
				     struct rap_NetPrintQGetInfo *r);
NTSTATUS smbcli_rap_netprintjobpause(struct smbcli_tree *tree,
				     TALLOC_CTX *mem_ctx,
				     struct rap_NetPrintJobPause *r);
NTSTATUS smbcli_rap_netprintjobcontinue(struct smbcli_tree *tree,
					TALLOC_CTX *mem_ctx,
					struct rap_NetPrintJobContinue *r);
NTSTATUS smbcli_rap_netprintjobdelete(struct smbcli_tree *tree,
				      TALLOC_CTX *mem_ctx,
				      struct rap_NetPrintJobDelete *r);
NTSTATUS smbcli_rap_netprintqueuepause(struct smbcli_tree *tree,
				       TALLOC_CTX *mem_ctx,
				       struct rap_NetPrintQueuePause *r);
NTSTATUS smbcli_rap_netprintqueueresume(struct smbcli_tree *tree,
					TALLOC_CTX *mem_ctx,
					struct rap_NetPrintQueueResume *r);
NTSTATUS smbcli_rap_netprintqueuepurge(struct smbcli_tree *tree,
				       TALLOC_CTX *mem_ctx,
				       struct rap_NetPrintQueuePurge *r);
NTSTATUS smbcli_rap_netprintjobenum(struct smbcli_tree *tree,
				    TALLOC_CTX *mem_ctx,
				    struct rap_NetPrintJobEnum *r);
NTSTATUS smbcli_rap_netprintjobgetinfo(struct smbcli_tree *tree,
				       TALLOC_CTX *mem_ctx,
				       struct rap_NetPrintJobGetInfo *r);
NTSTATUS smbcli_rap_netprintjobsetinfo(struct smbcli_tree *tree,
				       TALLOC_CTX *mem_ctx,
				       struct rap_NetPrintJobSetInfo *r);
NTSTATUS smbcli_rap_netprintdestenum(struct smbcli_tree *tree,
				     TALLOC_CTX *mem_ctx,
				     struct rap_NetPrintDestEnum *r);
NTSTATUS smbcli_rap_netprintdestgetinfo(struct smbcli_tree *tree,
					TALLOC_CTX *mem_ctx,
					struct rap_NetPrintDestGetInfo *r);
NTSTATUS smbcli_rap_netuserpasswordset2(struct smbcli_tree *tree,
					TALLOC_CTX *mem_ctx,
					struct rap_NetUserPasswordSet2 *r);
NTSTATUS smbcli_rap_netoemchangepassword(struct smbcli_tree *tree,
					 TALLOC_CTX *mem_ctx,
					 struct rap_NetOEMChangePassword *r);
NTSTATUS smbcli_rap_netusergetinfo(struct smbcli_tree *tree,
				   TALLOC_CTX *mem_ctx,
				   struct rap_NetUserGetInfo *r);
NTSTATUS smbcli_rap_netsessionenum(struct smbcli_tree *tree,
				   TALLOC_CTX *mem_ctx,
				   struct rap_NetSessionEnum *r);
NTSTATUS smbcli_rap_netsessiongetinfo(struct smbcli_tree *tree,
				      TALLOC_CTX *mem_ctx,
				      struct rap_NetSessionGetInfo *r);
NTSTATUS smbcli_rap_netuseradd(struct smbcli_tree *tree,
			       TALLOC_CTX *mem_ctx,
			       struct rap_NetUserAdd *r);
NTSTATUS smbcli_rap_netuserdelete(struct smbcli_tree *tree,
				  TALLOC_CTX *mem_ctx,
				  struct rap_NetUserDelete *r);
NTSTATUS smbcli_rap_netremotetod(struct smbcli_tree *tree,
				  TALLOC_CTX *mem_ctx,
				  struct rap_NetRemoteTOD *r);
#undef _PRINTF_ATTRIBUTE
#define _PRINTF_ATTRIBUTE(a1, a2)

#endif /* __DEFAULT_SOURCE4_LIBCLI_RAP_PROTO_H__ */
