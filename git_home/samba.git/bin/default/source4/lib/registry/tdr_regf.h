/* autogenerated by pidl */
#include "bin/default/source4/lib/registry/regf.h"
#include "lib/tdr/tdr.h"

#ifndef __TDR_regf_HEADER__
#define __TDR_regf_HEADER__
NTSTATUS tdr_pull_regf_hdr (struct tdr_pull *tdr, TALLOC_CTX *mem_ctx, struct regf_hdr *v);
NTSTATUS tdr_push_regf_hdr (struct tdr_push *tdr, struct regf_hdr *v);
NTSTATUS tdr_pull_hbin_block (struct tdr_pull *tdr, TALLOC_CTX *mem_ctx, struct hbin_block *v);
NTSTATUS tdr_push_hbin_block (struct tdr_push *tdr, struct hbin_block *v);
NTSTATUS tdr_pull_nk_block (struct tdr_pull *tdr, TALLOC_CTX *mem_ctx, struct nk_block *v);
NTSTATUS tdr_push_nk_block (struct tdr_push *tdr, struct nk_block *v);
NTSTATUS tdr_pull_sk_block (struct tdr_pull *tdr, TALLOC_CTX *mem_ctx, struct sk_block *v);
NTSTATUS tdr_push_sk_block (struct tdr_push *tdr, struct sk_block *v);
NTSTATUS tdr_pull_lh_block (struct tdr_pull *tdr, TALLOC_CTX *mem_ctx, struct lh_block *v);
NTSTATUS tdr_push_lh_block (struct tdr_push *tdr, struct lh_block *v);
NTSTATUS tdr_pull_li_block (struct tdr_pull *tdr, TALLOC_CTX *mem_ctx, struct li_block *v);
NTSTATUS tdr_push_li_block (struct tdr_push *tdr, struct li_block *v);
NTSTATUS tdr_pull_ri_block (struct tdr_pull *tdr, TALLOC_CTX *mem_ctx, struct ri_block *v);
NTSTATUS tdr_push_ri_block (struct tdr_push *tdr, struct ri_block *v);
NTSTATUS tdr_pull_vk_block (struct tdr_pull *tdr, TALLOC_CTX *mem_ctx, struct vk_block *v);
NTSTATUS tdr_push_vk_block (struct tdr_push *tdr, struct vk_block *v);
NTSTATUS tdr_pull_lf_block (struct tdr_pull *tdr, TALLOC_CTX *mem_ctx, struct lf_block *v);
NTSTATUS tdr_push_lf_block (struct tdr_push *tdr, struct lf_block *v);
#endif /* __TDR_regf_HEADER__ */
