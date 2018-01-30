/* client functions auto-generated by pidl */

#include "includes.h"
#include <tevent.h>
#include "lib/util/tevent_ntstatus.h"
#include "bin/default/librpc/gen_ndr/ndr_backupkey.h"
#include "bin/default/librpc/gen_ndr/ndr_backupkey_c.h"

/* backupkey - client functions generated by pidl */

struct dcerpc_bkrp_BackupKey_r_state {
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_bkrp_BackupKey_r_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_bkrp_BackupKey_r_send(TALLOC_CTX *mem_ctx,
	struct tevent_context *ev,
	struct dcerpc_binding_handle *h,
	struct bkrp_BackupKey *r)
{
	struct tevent_req *req;
	struct dcerpc_bkrp_BackupKey_r_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_bkrp_BackupKey_r_state);
	if (req == NULL) {
		return NULL;
	}

	state->out_mem_ctx = talloc_new(state);
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	subreq = dcerpc_binding_handle_call_send(state, ev, h,
			NULL, &ndr_table_backupkey,
			NDR_BKRP_BACKUPKEY, state->out_mem_ctx, r);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_bkrp_BackupKey_r_done, req);

	return req;
}

static void dcerpc_bkrp_BackupKey_r_done(struct tevent_req *subreq)
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

NTSTATUS dcerpc_bkrp_BackupKey_r_recv(struct tevent_req *req, TALLOC_CTX *mem_ctx)
{
	struct dcerpc_bkrp_BackupKey_r_state *state =
		tevent_req_data(req,
		struct dcerpc_bkrp_BackupKey_r_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_bkrp_BackupKey_r(struct dcerpc_binding_handle *h, TALLOC_CTX *mem_ctx, struct bkrp_BackupKey *r)
{
	NTSTATUS status;

	status = dcerpc_binding_handle_call(h,
			NULL, &ndr_table_backupkey,
			NDR_BKRP_BACKUPKEY, mem_ctx, r);

	return status;
}

struct dcerpc_bkrp_BackupKey_state {
	struct bkrp_BackupKey orig;
	struct bkrp_BackupKey tmp;
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_bkrp_BackupKey_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_bkrp_BackupKey_send(TALLOC_CTX *mem_ctx,
					      struct tevent_context *ev,
					      struct dcerpc_binding_handle *h,
					      struct GUID *_guidActionAgent /* [in] [ref] */,
					      uint8_t *_data_in /* [in] [ref,size_is(data_in_len)] */,
					      uint32_t _data_in_len /* [in]  */,
					      uint8_t **_data_out /* [out] [ref,size_is(,*data_out_len)] */,
					      uint32_t *_data_out_len /* [out] [ref] */,
					      uint32_t _param /* [in]  */)
{
	struct tevent_req *req;
	struct dcerpc_bkrp_BackupKey_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_bkrp_BackupKey_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;

	/* In parameters */
	state->orig.in.guidActionAgent = _guidActionAgent;
	state->orig.in.data_in = _data_in;
	state->orig.in.data_in_len = _data_in_len;
	state->orig.in.param = _param;

	/* Out parameters */
	state->orig.out.data_out = _data_out;
	state->orig.out.data_out_len = _data_out_len;

	/* Result */
	ZERO_STRUCT(state->orig.out.result);

	state->out_mem_ctx = talloc_named_const(state, 0,
			     "dcerpc_bkrp_BackupKey_out_memory");
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = dcerpc_bkrp_BackupKey_r_send(state, ev, h, &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_bkrp_BackupKey_done, req);
	return req;
}

static void dcerpc_bkrp_BackupKey_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct dcerpc_bkrp_BackupKey_state *state = tevent_req_data(
		req, struct dcerpc_bkrp_BackupKey_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = dcerpc_bkrp_BackupKey_r_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (tevent_req_nterror(req, status)) {
		return;
	}

	/* Copy out parameters */
	*state->orig.out.data_out = *state->tmp.out.data_out;
	*state->orig.out.data_out_len = *state->tmp.out.data_out_len;

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS dcerpc_bkrp_BackupKey_recv(struct tevent_req *req,
				    TALLOC_CTX *mem_ctx,
				    WERROR *result)
{
	struct dcerpc_bkrp_BackupKey_state *state = tevent_req_data(
		req, struct dcerpc_bkrp_BackupKey_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possible out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_bkrp_BackupKey(struct dcerpc_binding_handle *h,
			       TALLOC_CTX *mem_ctx,
			       struct GUID *_guidActionAgent /* [in] [ref] */,
			       uint8_t *_data_in /* [in] [ref,size_is(data_in_len)] */,
			       uint32_t _data_in_len /* [in]  */,
			       uint8_t **_data_out /* [out] [ref,size_is(,*data_out_len)] */,
			       uint32_t *_data_out_len /* [out] [ref] */,
			       uint32_t _param /* [in]  */,
			       WERROR *result)
{
	struct bkrp_BackupKey r;
	NTSTATUS status;

	/* In parameters */
	r.in.guidActionAgent = _guidActionAgent;
	r.in.data_in = _data_in;
	r.in.data_in_len = _data_in_len;
	r.in.param = _param;

	/* Out parameters */
	r.out.data_out = _data_out;
	r.out.data_out_len = _data_out_len;

	/* Result */
	ZERO_STRUCT(r.out.result);

	status = dcerpc_bkrp_BackupKey_r(h, mem_ctx, &r);
	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	/* Return variables */
	*_data_out = *r.out.data_out;
	*_data_out_len = *r.out.data_out_len;

	/* Return result */
	*result = r.out.result;

	return NT_STATUS_OK;
}

