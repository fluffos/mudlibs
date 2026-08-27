/*
 * mbs.h
 *
 * Board reading soul defines.
 *
 * Mrpr, 1995
 *
 */

#include "macros.h"
#include "std.h"
#include "stdproperties.h"

/* **************************************************************
 * Make changes to your local copy in the following file
 */
#include "/config/sys/mbs2.h"

/* **************************************************************
 * Making changes below this level is a genuinly bad idea, as it
 * probably will wreck the mbs. Hands off, boys and girls.
 */

/* The max length of descriptions and names (categories and boards) */
#define DESC_LEN	30
#define NAME_LEN	11

/* Definitions for ordering of data */
#define ORDER_NONE	-1
#define ORDER_CAT	0
#define ORDER_DOMAIN	1
#define ORDER_GROUP	2

/* Error messages */
#define MBM_NO_ERR	0
#define MBM_BAD_CALL	1
#define MBM_NO_AUTH	2
#define MBM_NO_CMD	3
#define MBM_WRONG_ARGS	4
#define MBM_BASE_ADMIN	5
#define MBM_NO_WIZ	6
#define MBM_IS_ADMIN	7
#define MBM_NO_ADMIN	8
#define MBM_CAT_EXISTS	9
#define MBM_STR_LONG	10
#define MBM_NO_CAT	11
#define MBM_BASE_CAT	12
#define MBM_CAT_IN_USE	13
#define MBM_BAD_BPATH	14
#define MBM_BOARD_EXISTS	15
#define MBM_BOARD_IN_USE	16
#define MBM_NUM_BOARDS	17
#define MBM_BAD_ORDER	18
#define MBM_NO_DOMAIN	19
#define MBM_NO_BOARD	20
#define MBM_ENTRY_USED	21

#define MBS_NO_ERR	0
#define MBS_NO_AUTH	1
#define MBS_NO_CMD	2
#define MBS_BAD_CALL	3
#define MBS_BAD_ORDER	4
#define MBS_BAD_DOMAIN	5
#define MBS_BAD_CAT	6
#define MBS_BAD_SEL	7
#define MBS_NO_GROUP	8
#define MBS_NO_BOARD	9
#define MBS_SUBSCRIBE	10
#define MBS_NO_SPEC	11
#define MBS_NO_SUB	12
#define MBS_SPEC_AMBIG	13
#define MBS_GRP_EXIST	14
#define MBS_GRP_NONE	15
#define MBS_NO_CURR	16
#define MBS_NO_RACC	17
#define MBS_NO_DACC	18
#define MBS_NO_WACC	19
#define MBS_STR_LONG	20
#define MBS_BAD_BOARD	21
#define MBS_BAD_NNUM	22
#define MBS_WRONG_ARGS	23
#define MBS_SCRAPPED	24
#define MBS_NUM_ZERO	25

/* Mail warnings/notifications */
#define M_E_REMOVED	0
#define M_B_UNUSED	1
#define M_B_UN_REMOVED	2
#define M_B_BROKEN	3
#define M_B_BR_REMOVED	4

/* Indexes for the BbpMap mapping */
#define BBP_BOARD	0
#define BBP_CAT		1
#define BBP_DOMAIN	2
#define BBP_DESC	3
#define BBP_SPATH	4
#define BBP_RPATH	5
#define BBP_LNOTE	6
#define BBP_PNOTE	7
#define BBP_RNOTE	8

/* Indexes for the BobMap mapping */
#define BOB_O		0
#define BOB_R		1
#define BOB_W		2
#define BOB_D		3

/* Days To Seconds */
#define DTS(days)	((days) * 86400)

/* Defines used by mbs to keep track of selection criteria */
#define SB_CAT		0
#define SB_DOMAIN	1
#define SB_GROUP	2
#define SB_BOARD	3
#define SB_SPATH	4
#define SB_LNOTE	5

/* Some nifty defines I tend to use */
#define NF(message)	notify_fail(message)
#define TP		this_player()
#define TI		this_interactive()
#define TO		this_object()
#define PO		previous_object()
#define LC(str)		lower_case((str))
#define UC(str)		capitalize(lower_case((str)))

/* A check to see who is calling */
#define CALL_CHECK	(function_exists("get_soul_id", PO) != MBS && \
			 function_exists("create", PO) != MC)
#define MBM_ARG_CHECK(a, b)	if (sizeof(a) < (b)) { mbm_error(MBM_WRONG_ARGS); break; }
#define MBS_ARG_CHECK(a, b)	if (sizeof(a) < (b)) { mbs_error(MBS_WRONG_ARGS); break; }
#define ADM_CHECK(a)	if ((a) == 0) { mbm_error(MBM_NO_AUTH); break; }
#define LORD_CHECK(lvl)	if ((lvl) < WIZ_LORD) { mbm_error(MBM_NO_AUTH); break; }

