#ifndef _PLAYER_DEFS_H
#define	_PLAYER_DEFS_H

#ifndef _LIVING_DEFS_H
#include "living_defs.h"
#endif

#include "race.h"
#include "gender.h"
#include "alignment.h"
#include "attack.h"
#include "stats.h"

#define	PLR_INFO_ON		2001
#define	PLR_INFO_OFF		-2001
#define	PLR_BUSY_KILL_ON	2002
#define	PLR_BUSY_KILL_OFF	-2002
#define	PLR_WIZ_ON		2003
#define	PLR_WIZ_OFF		-2003
#define	PLR_FIZ_ON		2004
#define	PLR_FIZ_OFF		-2004
#define	PLR_TIME_TO_HEAL	2005
#define	PLR_HPSP_REPORT_ON	2006
#define	PLR_HPSP_REPORT_OFF	-2006
#define	PLR_LOGIN_TIME		2007
#define	PLR_USED_WIMPY		2008
#define	PLR_ALLOW_SUMMON	2009
#define	PLR_PREVENT_SUMMON	-2009
#define	PLR_TIME_TO_SAVE	2010
#define	PLR_LICH_ON		2011
#define	PLR_LICH_OFF		-2011
#define PLR_AWIZ_ON            2012
#define PLR_AWIZ_OFF           -2012
#define PLR_SHOW_WHERE_ON    2013
#define PLR_SHOW_WHERE_OFF  -2013

#define	PLR_VERSION		2100
#define	PLR_STAT_CLOSURE	2101
#define	PLR_CONNECT_TIME	2102
#define	PLR_COMBAT_QUEUE	2103
#define	PLR_FULL_COMBAT_QUEUE	2104
#define	PLR_COMBAT_QUEUE_OPTIONAL	2105
#define	PLR_COMBAT_QUEUE_CLEAR	2106

#define	PLAYER_FILE		"/lib/player"

#endif
