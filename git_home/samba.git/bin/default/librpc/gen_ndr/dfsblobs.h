/* header auto-generated by pidl */

#ifndef _PIDL_HEADER_dfsblobs
#define _PIDL_HEADER_dfsblobs

#include <stdint.h>

#include "libcli/util/ntstatus.h"

#include "librpc/gen_ndr/misc.h"
#ifndef _HEADER_dfsblobs
#define _HEADER_dfsblobs

/* bitmap DFS_HEADER_FLAG */
#define DFS_HEADER_FLAG_REFERAL_SVR ( 0x00000001 )
#define DFS_HEADER_FLAG_STORAGE_SVR ( 0x00000002 )
#define DFS_HEADER_FLAG_TARGET_BCK ( 0x00000004 )

enum DFS_SERVER_TYPE
#ifndef USE_UINT_ENUMS
 {
	DFS_SERVER_NON_ROOT=(int)(0x0000),
	DFS_SERVER_ROOT=(int)(0x0001)
}
#else
 { __do_not_use_enum_DFS_SERVER_TYPE=0x7FFFFFFF}
#define DFS_SERVER_NON_ROOT ( 0x0000 )
#define DFS_SERVER_ROOT ( 0x0001 )
#endif
;

enum DFS_FLAGS_REFERRAL
#ifndef USE_UINT_ENUMS
 {
	DFS_FLAG_REFERRAL_DOMAIN_RESP=(int)(0x0002),
	DFS_FLAG_REFERRAL_FIRST_TARGET_SET=(int)(0x0004)
}
#else
 { __do_not_use_enum_DFS_FLAGS_REFERRAL=0x7FFFFFFF}
#define DFS_FLAG_REFERRAL_DOMAIN_RESP ( 0x0002 )
#define DFS_FLAG_REFERRAL_FIRST_TARGET_SET ( 0x0004 )
#endif
;

struct dfs_referral_v1 {
	uint16_t size;
	uint16_t server_type;
	uint16_t entry_flags;
	const char * share_name;/* [flag(LIBNDR_FLAG_STR_NULLTERM|LIBNDR_FLAG_ALIGN2),unique] */
};

struct dfs_referral_v2 {
	uint16_t size;
	enum DFS_SERVER_TYPE server_type;
	enum DFS_FLAGS_REFERRAL entry_flags;
	uint32_t proximity;
	uint32_t ttl;
	const char * DFS_path;/* [flag(LIBNDR_FLAG_STR_NULLTERM|LIBNDR_FLAG_ALIGN2),relative_short] */
	const char * DFS_alt_path;/* [flag(LIBNDR_FLAG_STR_NULLTERM|LIBNDR_FLAG_ALIGN2),relative_short] */
	const char * netw_address;/* [flag(LIBNDR_FLAG_STR_NULLTERM|LIBNDR_FLAG_ALIGN2),relative_short] */
};

struct dfs_normal_referral {
	const char * DFS_path;/* [flag(LIBNDR_FLAG_STR_NULLTERM|LIBNDR_FLAG_ALIGN2),relative_short] */
	const char * DFS_alt_path;/* [flag(LIBNDR_FLAG_STR_NULLTERM|LIBNDR_FLAG_ALIGN2),relative_short] */
	const char * netw_address;/* [flag(LIBNDR_FLAG_STR_NULLTERM|LIBNDR_FLAG_ALIGN2),relative_short] */
};

struct dfs_domain_referral {
	const char * special_name;/* [flag(LIBNDR_FLAG_STR_NULLTERM|LIBNDR_FLAG_ALIGN2),relative_short] */
	uint16_t nb_expanded_names;
	const char ** expanded_names;/* [flag(LIBNDR_FLAG_REMAINING|LIBNDR_FLAG_STR_NULLTERM),relative_short,subcontext(0)] */
};

union dfs_referral {
	struct dfs_normal_referral r1;/* [case(0)] */
	struct dfs_domain_referral r2;/* [case(2)] */
}/* [nodiscriminant] */;

union dfs_padding {
	uint8_t value[16];/* [case(16)] */
}/* [nodiscriminant] */;

struct dfs_referral_v3 {
	uint16_t size;
	enum DFS_SERVER_TYPE server_type;
	enum DFS_FLAGS_REFERRAL entry_flags;
	uint32_t ttl;
	union dfs_referral referrals;/* [switch_is(entry_flags&DFS_FLAG_REFERRAL_DOMAIN_RESP)] */
	union dfs_padding service_site_guid;/* [switch_is(size-18)] */
}/* [flag(LIBNDR_FLAG_NOALIGN)] */;

union dfs_referral_version {
	struct dfs_referral_v1 v1;/* [case] */
	struct dfs_referral_v2 v2;/* [case(2)] */
	struct dfs_referral_v3 v3;/* [case(3)] */
	struct dfs_referral_v3 v4;/* [case(4)] */
}/* [nodiscriminant] */;

struct dfs_referral_type {
	uint16_t version;
	union dfs_referral_version referral;/* [switch_is(version)] */
}/* [flag(LIBNDR_FLAG_NOALIGN),relative_base] */;

struct dfs_referral_resp {
	uint16_t path_consumed;
	uint16_t nb_referrals;
	uint32_t header_flags;
	struct dfs_referral_type *referral_entries;
}/* [public] */;

struct dfs_GetDFSReferral_in {
	uint16_t max_referral_level;
	const char * servername;/* [flag(LIBNDR_FLAG_STR_NULLTERM|LIBNDR_FLAG_ALIGN2)] */
}/* [public] */;


struct dfs_GetDFSReferral {
	struct {
		struct dfs_GetDFSReferral_in req;
	} in;

	struct {
		struct dfs_referral_resp *resp;/* [ref] */
	} out;

};

#endif /* _HEADER_dfsblobs */
#endif /* _PIDL_HEADER_dfsblobs */