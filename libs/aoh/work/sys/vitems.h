/*--------------------------------------------------------------------------
 * /sys/vitems.h -- Headerfile for vitem specific properties
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 * All string-defines must be in the form "V..." to enable builtin vitem
 * properties.
 */

#ifndef _VITEMS_H_
#define _VTIEMS_H_

/* -------------------------------------------------------------------------
 * Generic vitem specific properties
 * -------------------------------------------------------------------------
 */

#define PV_SURFACE            "VSurface"

/* -------------------------------------------------------------------------
 * virtual windows
 * -------------------------------------------------------------------------
 */

#define WINDOW_STATE_CLOSED    1
#define WINDOW_STATE_OPEN      0
#define WINDOW_STATE_SMASHED   -1

#define WINDOW_CHECK_OK        0
#define WINDOW_CHECK_FAIL      1

#define WINDOW_ALWAYS_TRANS    -1

#define WINDOW_ACTION_OPEN     "open"
#define WINDOW_ACTION_CLOSE    "close"
#define WINDOW_ACTION_CLEAN    "clean"
#define WINDOW_ACTION_SMASH    "smash"
#define WINDOW_ACTION_CLIMB    "climb"
#define WINDOW_ACTION_LOOK     "look"

#define PV_WINDOW_SHORT        "VWindowShort"
#define PV_WINDOW_LONG         "VWindowLong"
#define PV_WINDOW_OTHERLONG    "VWindowOtherLong"
#define PV_WINDOW_DIRTYMSG     "VWindowDirtyMsg"
#define PV_WINDOW_REPAIRMSG    "VWindowRepairMsg"
#define PV_WINDOW_PATH         "VWindowPath"
#define PV_WINDOW_CHECKFUN     "VWindowCheckFun"

#define PV_WINDOW_STATE        "VWindowState"
#define PV_WINDOW_TRANS        "VWindowTrans"
#define PV_WINDOW_ISWINDOW     "VWindowIsWindow"
#define PV_WINDOW_OTHERID      "VWindowOtherId"

#endif
