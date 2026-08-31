/* Omni define file */
#include "/players/nylakoorub/guild/defines.h"
#include "/obj/lw.h"

#define OMNI_CMDS "/players/nylakoorub/guild/obj/omni/lib/cmds/vags/"
#define FIX_OMNI   "/players/nylakoorub/guild/obj/omni/lib/cmds/fixomni/"
#define OMNI_HELP  "/players/nylakoorub/guild/obj/omni/help/"
#define TPE     ENV(TO)
#define ADDHP(x)  reduce_hit_point(-(x))
#define ADDSP(x)   restore_spell_points(x)
#define MAXHP   query_max_hp()
#define MAXSP   query_max_sp()
#define HP      query_hp()
#define item  "omni"
#define SP      query_sp()
#define LEVEL       12*(TPE->QL)
#define WIS         10*(TPE->QW)
#define INT         10*(TPE->QI)
#define STR         10*(TPE->QS)
#define MAXOMNIPOWER  (60+(LEVEL)+(STR)+(WIS)+(INT))
#define TO_RATE   2
#define C   capitalize
#define BONUS   (environment()->QL*5)
#define HOUR_BONUS   (BONUS+(environment()->QL*10))

