#define VAG_SHADOWS "/players/nylakoorub/guild/lib/shadows/"
#define STATUS "/players/nylakoorub/guild/lib/status/"
#define INFO    "/players/nylakoorub/guild/lib/vaginfo/"
#define BANISH  "/players/nylakoorub/guild/lib/banish/"
#define CHECKS  "/players/nylakoorub/guild/lib/checks/"
#define NEWS  "/players/nylakoorub/guild/news/"
#define HELP "/players/nylakoorub/guild/help/"
#define LOGS "/players/nylakoorub/guild/lib/logs/"
#define CMDS "/players/nylakoorub/guild/lib/cmds/vags/"
#define LOCKCMDS "/players/nylakoorub/guild/lib/lockcmds/"
#define QINFO "/players/nylakoorub/4th/quest/gq_info.lpc"
#define CAP     capitalize
#define GM      "guild/master"
#define GUILD   "vagabond"
#define MASTER  "nylakoorub"
#define E       environment()
#define TP      this_player()
#define TO    this_object()
#define QRN     query_real_name()
#define VAGSOUL    (present("vagsoul", this_player()))
#define maxstatuschr   20
#define maxtlstatuschr  20
#define maxwherechr   25
#define maxnamechr     12
#define maxlevelchr    13
#define ver   2
#define points 20
#define maxlinechr 6
#define phaselevel  7
#define general maxnamechr+maxlevelchr+maxlinechr
#define omniinfo  ver+points
#define phaseinfo  12
#define ENV     environment
#define QW      query_wis()
#define QI      query_int()
#define QL      query_level()
#define QS      query_str()
#define QC      query_con()
#define QD      query_dex()
#define TPL	TP->query_level()
#define TPLEG   TP->query_legend_level()
#define TPD     this_player()->query_dex()
#define TPW     TP->query_wis()
#define TPI     TP->query_int()
#define TPC     TP->query_cha()
#define TPS     TP->query_str()   
#define CG	if(TP->query_ghost()){ \
		    write("You are a ghost, you cannot do that.\n"); \
		    return 1; \
                }


/* Checks includes */
#include "/players/nylakoorub/guild/lib/checks/attack_check.h"
#include "/players/nylakoorub/guild/lib/checks/check_cost.h"
#include "/players/nylakoorub/guild/lib/checks/check_level.h"


/* Functions include */
#include "/players/nylakoorub/guild/lib/functions/do_vag_log.lpc"
#include "/players/nylakoorub/guild/lib/functions/cal_time.lpc"


/* other includes */
#include "/obj/adjust.h"

/* other defines */
#include "/players/nylakoorub/guild/lib/defines/status.h"
#include "/players/nylakoorub/guild/lib/defines/bendspace.h"


