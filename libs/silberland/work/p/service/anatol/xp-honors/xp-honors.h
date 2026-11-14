
/* XP honors' defines
 * __________________________________________(i) Anatol@Silberland (2012) */


#pragma strict_types

#include <properties.h>
#include <ansi.h>
#include <wizlevels.h>

#ifndef _XP-HONORS_H_
#define _XP-HONORS_H_

#define HONOR_XP_NEEDED 2000000000    // Das muss mindestens vorhanden sein.
#define HONOR_XP_COST   1000000000    // Das geht fuer einen Ehrenpunkt weg.


#define HONORS_DIR "/p/service/anatol/xp-honors/"

#define HONORS_MASTER   HONORS_DIR "m/honors"
#define HONORS_CABINET  HONORS_DIR "m/cabinet"
#define HONORS_MEDAL    HONORS_DIR "a/medal"
#define HONORS_SAVEFILE HONORS_DIR "save/xp-honors"
#define HONORS_LOGFILE  HONORS_DIR "log/xp-honors.log"

#define QUERY_XPHONOR( x )      ((int)call_other(HONORS_MASTER,"QueryXPHonorPoints",x))
#define QUERY_XPHONORHIST( x )  ((int)call_other(HONORS_MASTER,"QueryXPHonorHistory",x))

#define MEDAL_CUSTOMIZE         ((int)call_other(HONORS_CABINET,"CustomizeMedal"))
#define MEDAL_RENEW             ((int)call_other(HONORS_CABINET,"RenewMedal"))
#define MAY_INC_XPHONOR( x )    (objectp(call_other(HONORS_MASTER,"MayIncreaseXPHonorPoints",x))?1:0)
#define INC_XPHONOR( x )        ((int)call_other(HONORS_MASTER,"IncreaseXPHonorPoints",x))

#define P_XP_HONORS     "xp_honors"

#endif _XP-HONORS_H_

