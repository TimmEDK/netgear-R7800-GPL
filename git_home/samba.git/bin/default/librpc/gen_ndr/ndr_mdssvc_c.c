/* client functions auto-generated by pidl */

#include "includes.h"
#include <tevent.h>
#include "lib/util/tevent_ntstatus.h"
#include "bin/default/librpc/gen_ndr/ndr_mdssvc.h"
#include "bin/default/librpc/gen_ndr/ndr_mdssvc_c.h"

/* mdssvc - client functions generated by pidl */

struct dcerpc_mdssvc_open_r_state {
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_mdssvc_open_r_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_mdssvc_open_r_send(TALLOC_CTX *mem_ctx,
	struct tevent_context *ev,
	struct dcerpc_binding_handle *h,
	struct mdssvc_open *r)
{
	struct tevent_req *req;
	struct dcerpc_mdssvc_open_r_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_mdssvc_open_r_state);
	if (req == NULL) {
		return NULL;
	}

	state->out_mem_ctx = talloc_new(state);
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	subreq = dcerpc_binding_handle_call_send(state, ev, h,
			NULL, &ndr_table_mdssvc,
			NDR_MDSSVC_OPEN, state->out_mem_ctx, r);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_mdssvc_open_r_done, req);

	return req;
}

static void dcerpc_mdssvc_open_r_done(struct tevent_req *subreq)
{
	struct tevent_req *req =
		tevent_req_callback_data(subreq,
		struct tevent_req);
	NTSTATUS status;

	status = dcerpc_binding_handle_call_recv(subreq);
	TALLOC_FREE(subreq);
	if (tevent_req_nterror(req, status)) {
		return;
	}

	tevent_req_done(req);
}

NTSTATUS dcerpc_mdssvc_open_r_recv(struct tevent_req *req, TALLOC_CTX *mem_ctx)
{
	struct dcerpc_mdssvc_open_r_state *state =
		tevent_req_data(req,
		struct dcerpc_mdssvc_open_r_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_mdssvc_open_r(struct dcerpc_binding_handle *h, TALLOC_CTX *mem_ctx, struct mdssvc_open *r)
{
	NTSTATUS status;

	status = dcerpc_binding_handle_call(h,
			NULL, &ndr_table_mdssvc,
			NDR_MDSSVC_OPEN, mem_ctx, r);

	return status;
}

struct dcerpc_mdssvc_open_state {
	struct mdssvc_open orig;
	struct mdssvc_open tmp;
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_mdssvc_open_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_mdssvc_open_send(TALLOC_CTX *mem_ctx,
					   struct tevent_context *ev,
					   struct dcerpc_binding_handle *h,
					   uint32_t *_device_id /* [in,out] [ref] */,
					   uint32_t *_unkn2 /* [in,out] [ref] */,
					   uint32_t *_unkn3 /* [in,out] [ref] */,
					   const char *_share_mount_path /* [in] [charset(UTF8),size_is(1025)] */,
					   const char *_share_name /* [in] [charset(UTF8),size_is(1025)] */,
					   const char *_share_path /* [out] [charset(UTF8),size_is(1025)] */,
					   struct policy_handle *_handle /* [out] [ref] */)
{
	struct tevent_req *req;
	struct dcerpc_mdssvc_open_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_mdssvc_open_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;

	/* In parameters */
	state->orig.in.device_id = _device_id;
	state->orig.in.unkn2 = _unkn2;
	state->orig.in.unkn3 = _unkn3;
	state->orig.in.share_mount_path = _share_mount_path;
	state->orig.in.share_name = _share_name;

	/* Out parameters */
	state->orig.out.device_id = _device_id;
	state->orig.out.unkn2 = _unkn2;
	state->orig.out.unkn3 = _unkn3;
	state->orig.out.share_path = _share_path;
	state->orig.out.handle = _handle;

	state->out_mem_ctx = talloc_named_const(state, 0,
			     "dcerpc_mdssvc_open_out_memory");
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = dcerpc_mdssvc_open_r_send(state, ev, h, &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_mdssvc_open_done, req);
	return req;
}

static void dcerpc_mdssvc_open_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct dcerpc_mdssvc_open_state *state = tevent_req_data(
		req, struct dcerpc_mdssvc_open_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = dcerpc_mdssvc_open_r_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (tevent_req_nterror(req, status)) {
		return;
	}

	/* Copy out parameters */
	*state->orig.out.device_id = *state->tmp.out.device_id;
	*state->orig.out.unkn2 = *state->tmp.out.unkn2;
	*state->orig.out.unkn3 = *state->tmp.out.unkn3;
	{
		size_t _copy_len_share_path;
		_copy_len_share_path = ndr_charset_length(state->tmp.out.share_path, CH_UNIX);
		if (_copy_len_share_path > 1025) {
			tevent_req_nterror(req, NT_STATUS_INVALID_NETWORK_RESPONSE);
			return;
		}
		if (state->orig.out.share_path != state->tmp.out.share_path) {
			memcpy(discard_const_p(uint8_t *, state->orig.out.share_path), state->tmp.out.share_path, _copy_len_share_path * sizeof(*state->orig.out.share_path));
		}
	}
	*state->orig.out.handle = *state->tmp.out.handle;

	/* Reset temporary structure */
	ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS dcerpc_mdssvc_open_recv(struct tevent_req *req,
				 TALLOC_CTX *mem_ctx)
{
	struct dcerpc_mdssvc_open_state *state = tevent_req_data(
		req, struct dcerpc_mdssvc_open_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possible out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_mdssvc_open(struct dcerpc_binding_handle *h,
			    TALLOC_CTX *mem_ctx,
			    uint32_t *_device_id /* [in,out] [ref] */,
			    uint32_t *_unkn2 /* [in,out] [ref] */,
			    uint32_t *_unkn3 /* [in,out] [ref] */,
			    const char *_share_mount_path /* [in] [charset(UTF8),size_is(1025)] */,
			    const char *_share_name /* [in] [charset(UTF8),size_is(1025)] */,
			    const char *_share_path /* [out] [charset(UTF8),size_is(1025)] */,
			    struct policy_handle *_handle /* [out] [ref] */)
{
	struct mdssvc_open r;
	NTSTATUS status;

	/* In parameters */
	r.in.device_id = _device_id;
	r.in.unkn2 = _unkn2;
	r.in.unkn3 = _unkn3;
	r.in.share_mount_path = _share_mount_path;
	r.in.share_name = _share_name;

	/* Out parameters */
	r.out.device_id = _device_id;
	r.out.unkn2 = _unkn2;
	r.out.unkn3 = _unkn3;
	r.out.share_path = _share_path;
	r.out.handle = _handle;

	status = dcerpc_mdssvc_open_r(h, mem_ctx, &r);
	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	/* Return variables */
	*_device_id = *r.out.device_id;
	*_unkn2 = *r.out.unkn2;
	*_unkn3 = *r.out.unkn3;
	{
		size_t _copy_len_share_path;
		_copy_len_share_path = ndr_charset_length(r.out.share_path, CH_UNIX);
		if (_copy_len_share_path > 1025) {
			return NT_STATUS_INVALID_NETWORK_RESPONSE;
		}
		if (_share_path != r.out.share_path) {
			memcpy(discard_const_p(uint8_t *, _share_path), r.out.share_path, _copy_len_share_path * sizeof(*_share_path));
		}
	}
	*_handle = *r.out.handle;

	/* Return result */

	return NT_STATUS_OK;
}

struct dcerpc_mdssvc_unknown1_r_state {
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_mdssvc_unknown1_r_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_mdssvc_unknown1_r_send(TALLOC_CTX *mem_ctx,
	struct tevent_context *ev,
	struct dcerpc_binding_handle *h,
	struct mdssvc_unknown1 *r)
{
	struct tevent_req *req;
	struct dcerpc_mdssvc_unknown1_r_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_mdssvc_unknown1_r_state);
	if (req == NULL) {
		return NULL;
	}

	state->out_mem_ctx = talloc_new(state);
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	subreq = dcerpc_binding_handle_call_send(state, ev, h,
			NULL, &ndr_table_mdssvc,
			NDR_MDSSVC_UNKNOWN1, state->out_mem_ctx, r);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_mdssvc_unknown1_r_done, req);

	return req;
}

static void dcerpc_mdssvc_unknown1_r_done(struct tevent_req *subreq)
{
	struct tevent_req *req =
		tevent_req_callback_data(subreq,
		struct tevent_req);
	NTSTATUS status;

	status = dcerpc_binding_handle_call_recv(subreq);
	TALLOC_FREE(subreq);
	if (tevent_req_nterror(req, status)) {
		return;
	}

	tevent_req_done(req);
}

NTSTATUS dcerpc_mdssvc_unknown1_r_recv(struct tevent_req *req, TALLOC_CTX *mem_ctx)
{
	struct dcerpc_mdssvc_unknown1_r_state *state =
		tevent_req_data(req,
		struct dcerpc_mdssvc_unknown1_r_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_mdssvc_unknown1_r(struct dcerpc_binding_handle *h, TALLOC_CTX *mem_ctx, struct mdssvc_unknown1 *r)
{
	NTSTATUS status;

	status = dcerpc_binding_handle_call(h,
			NULL, &ndr_table_mdssvc,
			NDR_MDSSVC_UNKNOWN1, mem_ctx, r);

	return status;
}

struct dcerpc_mdssvc_unknown1_state {
	struct mdssvc_unknown1 orig;
	struct mdssvc_unknown1 tmp;
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_mdssvc_unknown1_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_mdssvc_unknown1_send(TALLOC_CTX *mem_ctx,
					       struct tevent_context *ev,
					       struct dcerpc_binding_handle *h,
					       struct policy_handle _handle /* [in]  */,
					       uint32_t _unkn1 /* [in]  */,
					       uint32_t _device_id /* [in]  */,
					       uint32_t _unkn3 /* [in]  */,
					       uint32_t _unkn4 /* [in]  */,
					       uint32_t _uid /* [in]  */,
					       uint32_t _gid /* [in]  */,
					       uint32_t *_status /* [out] [ref] */,
					       uint32_t *_flags /* [out] [ref] */,
					       uint32_t *_unkn7 /* [out] [ref] */)
{
	struct tevent_req *req;
	struct dcerpc_mdssvc_unknown1_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_mdssvc_unknown1_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;

	/* In parameters */
	state->orig.in.handle = _handle;
	state->orig.in.unkn1 = _unkn1;
	state->orig.in.device_id = _device_id;
	state->orig.in.unkn3 = _unkn3;
	state->orig.in.unkn4 = _unkn4;
	state->orig.in.uid = _uid;
	state->orig.in.gid = _gid;

	/* Out parameters */
	state->orig.out.status = _status;
	state->orig.out.flags = _flags;
	state->orig.out.unkn7 = _unkn7;

	state->out_mem_ctx = talloc_named_const(state, 0,
			     "dcerpc_mdssvc_unknown1_out_memory");
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = dcerpc_mdssvc_unknown1_r_send(state, ev, h, &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_mdssvc_unknown1_done, req);
	return req;
}

static void dcerpc_mdssvc_unknown1_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct dcerpc_mdssvc_unknown1_state *state = tevent_req_data(
		req, struct dcerpc_mdssvc_unknown1_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = dcerpc_mdssvc_unknown1_r_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (tevent_req_nterror(req, status)) {
		return;
	}

	/* Copy out parameters */
	*state->orig.out.status = *state->tmp.out.status;
	*state->orig.out.flags = *state->tmp.out.flags;
	*state->orig.out.unkn7 = *state->tmp.out.unkn7;

	/* Reset temporary structure */
	ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS dcerpc_mdssvc_unknown1_recv(struct tevent_req *req,
				     TALLOC_CTX *mem_ctx)
{
	struct dcerpc_mdssvc_unknown1_state *state = tevent_req_data(
		req, struct dcerpc_mdssvc_unknown1_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possible out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_mdssvc_unknown1(struct dcerpc_binding_handle *h,
				TALLOC_CTX *mem_ctx,
				struct policy_handle _handle /* [in]  */,
				uint32_t _unkn1 /* [in]  */,
				uint32_t _device_id /* [in]  */,
				uint32_t _unkn3 /* [in]  */,
				uint32_t _unkn4 /* [in]  */,
				uint32_t _uid /* [in]  */,
				uint32_t _gid /* [in]  */,
				uint32_t *_status /* [out] [ref] */,
				uint32_t *_flags /* [out] [ref] */,
				uint32_t *_unkn7 /* [out] [ref] */)
{
	struct mdssvc_unknown1 r;
	NTSTATUS status;

	/* In parameters */
	r.in.handle = _handle;
	r.in.unkn1 = _unkn1;
	r.in.device_id = _device_id;
	r.in.unkn3 = _unkn3;
	r.in.unkn4 = _unkn4;
	r.in.uid = _uid;
	r.in.gid = _gid;

	/* Out parameters */
	r.out.status = _status;
	r.out.flags = _flags;
	r.out.unkn7 = _unkn7;

	status = dcerpc_mdssvc_unknown1_r(h, mem_ctx, &r);
	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	/* Return variables */
	*_status = *r.out.status;
	*_flags = *r.out.flags;
	*_unkn7 = *r.out.unkn7;

	/* Return result */

	return NT_STATUS_OK;
}

struct dcerpc_mdssvc_cmd_r_state {
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_mdssvc_cmd_r_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_mdssvc_cmd_r_send(TALLOC_CTX *mem_ctx,
	struct tevent_context *ev,
	struct dcerpc_binding_handle *h,
	struct mdssvc_cmd *r)
{
	struct tevent_req *req;
	struct dcerpc_mdssvc_cmd_r_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_mdssvc_cmd_r_state);
	if (req == NULL) {
		return NULL;
	}

	state->out_mem_ctx = talloc_new(state);
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	subreq = dcerpc_binding_handle_call_send(state, ev, h,
			NULL, &ndr_table_mdssvc,
			NDR_MDSSVC_CMD, state->out_mem_ctx, r);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_mdssvc_cmd_r_done, req);

	return req;
}

static void dcerpc_mdssvc_cmd_r_done(struct tevent_req *subreq)
{
	struct tevent_req *req =
		tevent_req_callback_data(subreq,
		struct tevent_req);
	NTSTATUS status;

	status = dcerpc_binding_handle_call_recv(subreq);
	TALLOC_FREE(subreq);
	if (tevent_req_nterror(req, status)) {
		return;
	}

	tevent_req_done(req);
}

NTSTATUS dcerpc_mdssvc_cmd_r_recv(struct tevent_req *req, TALLOC_CTX *mem_ctx)
{
	struct dcerpc_mdssvc_cmd_r_state *state =
		tevent_req_data(req,
		struct dcerpc_mdssvc_cmd_r_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_mdssvc_cmd_r(struct dcerpc_binding_handle *h, TALLOC_CTX *mem_ctx, struct mdssvc_cmd *r)
{
	NTSTATUS status;

	status = dcerpc_binding_handle_call(h,
			NULL, &ndr_table_mdssvc,
			NDR_MDSSVC_CMD, mem_ctx, r);

	return status;
}

struct dcerpc_mdssvc_cmd_state {
	struct mdssvc_cmd orig;
	struct mdssvc_cmd tmp;
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_mdssvc_cmd_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_mdssvc_cmd_send(TALLOC_CTX *mem_ctx,
					  struct tevent_context *ev,
					  struct dcerpc_binding_handle *h,
					  struct policy_handle _handle /* [in]  */,
					  uint32_t _unkn1 /* [in]  */,
					  uint32_t _device_id /* [in]  */,
					  uint32_t _unkn3 /* [in]  */,
					  uint32_t _unkn4 /* [in]  */,
					  uint32_t _flags /* [in]  */,
					  struct mdssvc_blob _request_blob /* [in]  */,
					  uint32_t _unkn5 /* [in]  */,
					  uint32_t _max_fragment_size1 /* [in]  */,
					  uint32_t _unkn6 /* [in]  */,
					  uint32_t _max_fragment_size2 /* [in]  */,
					  uint32_t _unkn7 /* [in]  */,
					  uint32_t _unkn8 /* [in]  */,
					  uint32_t *_status /* [out] [ref] */,
					  struct mdssvc_blob *_response_blob /* [out] [ref] */,
					  uint32_t *_unkn9 /* [out] [ref] */)
{
	struct tevent_req *req;
	struct dcerpc_mdssvc_cmd_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_mdssvc_cmd_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;

	/* In parameters */
	state->orig.in.handle = _handle;
	state->orig.in.unkn1 = _unkn1;
	state->orig.in.device_id = _device_id;
	state->orig.in.unkn3 = _unkn3;
	state->orig.in.unkn4 = _unkn4;
	state->orig.in.flags = _flags;
	state->orig.in.request_blob = _request_blob;
	state->orig.in.unkn5 = _unkn5;
	state->orig.in.max_fragment_size1 = _max_fragment_size1;
	state->orig.in.unkn6 = _unkn6;
	state->orig.in.max_fragment_size2 = _max_fragment_size2;
	state->orig.in.unkn7 = _unkn7;
	state->orig.in.unkn8 = _unkn8;

	/* Out parameters */
	state->orig.out.status = _status;
	state->orig.out.response_blob = _response_blob;
	state->orig.out.unkn9 = _unkn9;

	state->out_mem_ctx = talloc_named_const(state, 0,
			     "dcerpc_mdssvc_cmd_out_memory");
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = dcerpc_mdssvc_cmd_r_send(state, ev, h, &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_mdssvc_cmd_done, req);
	return req;
}

static void dcerpc_mdssvc_cmd_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct dcerpc_mdssvc_cmd_state *state = tevent_req_data(
		req, struct dcerpc_mdssvc_cmd_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = dcerpc_mdssvc_cmd_r_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (tevent_req_nterror(req, status)) {
		return;
	}

	/* Copy out parameters */
	*state->orig.out.status = *state->tmp.out.status;
	*state->orig.out.response_blob = *state->tmp.out.response_blob;
	*state->orig.out.unkn9 = *state->tmp.out.unkn9;

	/* Reset temporary structure */
	ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS dcerpc_mdssvc_cmd_recv(struct tevent_req *req,
				TALLOC_CTX *mem_ctx)
{
	struct dcerpc_mdssvc_cmd_state *state = tevent_req_data(
		req, struct dcerpc_mdssvc_cmd_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possible out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_mdssvc_cmd(struct dcerpc_binding_handle *h,
			   TALLOC_CTX *mem_ctx,
			   struct policy_handle _handle /* [in]  */,
			   uint32_t _unkn1 /* [in]  */,
			   uint32_t _device_id /* [in]  */,
			   uint32_t _unkn3 /* [in]  */,
			   uint32_t _unkn4 /* [in]  */,
			   uint32_t _flags /* [in]  */,
			   struct mdssvc_blob _request_blob /* [in]  */,
			   uint32_t _unkn5 /* [in]  */,
			   uint32_t _max_fragment_size1 /* [in]  */,
			   uint32_t _unkn6 /* [in]  */,
			   uint32_t _max_fragment_size2 /* [in]  */,
			   uint32_t _unkn7 /* [in]  */,
			   uint32_t _unkn8 /* [in]  */,
			   uint32_t *_status /* [out] [ref] */,
			   struct mdssvc_blob *_response_blob /* [out] [ref] */,
			   uint32_t *_unkn9 /* [out] [ref] */)
{
	struct mdssvc_cmd r;
	NTSTATUS status;

	/* In parameters */
	r.in.handle = _handle;
	r.in.unkn1 = _unkn1;
	r.in.device_id = _device_id;
	r.in.unkn3 = _unkn3;
	r.in.unkn4 = _unkn4;
	r.in.flags = _flags;
	r.in.request_blob = _request_blob;
	r.in.unkn5 = _unkn5;
	r.in.max_fragment_size1 = _max_fragment_size1;
	r.in.unkn6 = _unkn6;
	r.in.max_fragment_size2 = _max_fragment_size2;
	r.in.unkn7 = _unkn7;
	r.in.unkn8 = _unkn8;

	/* Out parameters */
	r.out.status = _status;
	r.out.response_blob = _response_blob;
	r.out.unkn9 = _unkn9;

	status = dcerpc_mdssvc_cmd_r(h, mem_ctx, &r);
	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	/* Return variables */
	*_status = *r.out.status;
	*_response_blob = *r.out.response_blob;
	*_unkn9 = *r.out.unkn9;

	/* Return result */

	return NT_STATUS_OK;
}

struct dcerpc_mdssvc_close_r_state {
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_mdssvc_close_r_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_mdssvc_close_r_send(TALLOC_CTX *mem_ctx,
	struct tevent_context *ev,
	struct dcerpc_binding_handle *h,
	struct mdssvc_close *r)
{
	struct tevent_req *req;
	struct dcerpc_mdssvc_close_r_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_mdssvc_close_r_state);
	if (req == NULL) {
		return NULL;
	}

	state->out_mem_ctx = talloc_new(state);
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	subreq = dcerpc_binding_handle_call_send(state, ev, h,
			NULL, &ndr_table_mdssvc,
			NDR_MDSSVC_CLOSE, state->out_mem_ctx, r);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_mdssvc_close_r_done, req);

	return req;
}

static void dcerpc_mdssvc_close_r_done(struct tevent_req *subreq)
{
	struct tevent_req *req =
		tevent_req_callback_data(subreq,
		struct tevent_req);
	NTSTATUS status;

	status = dcerpc_binding_handle_call_recv(subreq);
	TALLOC_FREE(subreq);
	if (tevent_req_nterror(req, status)) {
		return;
	}

	tevent_req_done(req);
}

NTSTATUS dcerpc_mdssvc_close_r_recv(struct tevent_req *req, TALLOC_CTX *mem_ctx)
{
	struct dcerpc_mdssvc_close_r_state *state =
		tevent_req_data(req,
		struct dcerpc_mdssvc_close_r_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_mdssvc_close_r(struct dcerpc_binding_handle *h, TALLOC_CTX *mem_ctx, struct mdssvc_close *r)
{
	NTSTATUS status;

	status = dcerpc_binding_handle_call(h,
			NULL, &ndr_table_mdssvc,
			NDR_MDSSVC_CLOSE, mem_ctx, r);

	return status;
}

struct dcerpc_mdssvc_close_state {
	struct mdssvc_close orig;
	struct mdssvc_close tmp;
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_mdssvc_close_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_mdssvc_close_send(TALLOC_CTX *mem_ctx,
					    struct tevent_context *ev,
					    struct dcerpc_binding_handle *h,
					    struct policy_handle _in_handle /* [in]  */,
					    uint32_t _unkn1 /* [in]  */,
					    uint32_t _device_id /* [in]  */,
					    uint32_t _unkn2 /* [in]  */,
					    uint32_t _unkn3 /* [in]  */,
					    struct policy_handle *_out_handle /* [out] [ref] */,
					    uint32_t *_status /* [out] [ref] */)
{
	struct tevent_req *req;
	struct dcerpc_mdssvc_close_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_mdssvc_close_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;

	/* In parameters */
	state->orig.in.in_handle = _in_handle;
	state->orig.in.unkn1 = _unkn1;
	state->orig.in.device_id = _device_id;
	state->orig.in.unkn2 = _unkn2;
	state->orig.in.unkn3 = _unkn3;

	/* Out parameters */
	state->orig.out.out_handle = _out_handle;
	state->orig.out.status = _status;

	state->out_mem_ctx = talloc_named_const(state, 0,
			     "dcerpc_mdssvc_close_out_memory");
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = dcerpc_mdssvc_close_r_send(state, ev, h, &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_mdssvc_close_done, req);
	return req;
}

static void dcerpc_mdssvc_close_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct dcerpc_mdssvc_close_state *state = tevent_req_data(
		req, struct dcerpc_mdssvc_close_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = dcerpc_mdssvc_close_r_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (tevent_req_nterror(req, status)) {
		return;
	}

	/* Copy out parameters */
	*state->orig.out.out_handle = *state->tmp.out.out_handle;
	*state->orig.out.status = *state->tmp.out.status;

	/* Reset temporary structure */
	ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS dcerpc_mdssvc_close_recv(struct tevent_req *req,
				  TALLOC_CTX *mem_ctx)
{
	struct dcerpc_mdssvc_close_state *state = tevent_req_data(
		req, struct dcerpc_mdssvc_close_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possible out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_mdssvc_close(struct dcerpc_binding_handle *h,
			     TALLOC_CTX *mem_ctx,
			     struct policy_handle _in_handle /* [in]  */,
			     uint32_t _unkn1 /* [in]  */,
			     uint32_t _device_id /* [in]  */,
			     uint32_t _unkn2 /* [in]  */,
			     uint32_t _unkn3 /* [in]  */,
			     struct policy_handle *_out_handle /* [out] [ref] */,
			     uint32_t *_status /* [out] [ref] */)
{
	struct mdssvc_close r;
	NTSTATUS status;

	/* In parameters */
	r.in.in_handle = _in_handle;
	r.in.unkn1 = _unkn1;
	r.in.device_id = _device_id;
	r.in.unkn2 = _unkn2;
	r.in.unkn3 = _unkn3;

	/* Out parameters */
	r.out.out_handle = _out_handle;
	r.out.status = _status;

	status = dcerpc_mdssvc_close_r(h, mem_ctx, &r);
	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	/* Return variables */
	*_out_handle = *r.out.out_handle;
	*_status = *r.out.status;

	/* Return result */

	return NT_STATUS_OK;
}

