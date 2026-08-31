#define STATUS "/players/nylakoorub/guild/lib/status/"
#define BANISH  "/players/nylakoorub/guild/lib/banish/"
#define CHECKS  "/players/nylakoorub/guild/lib/checks/"
#define HELP "/players/nylakoorub/guild/help/"
#define LOGS "/players/nylakoorub/guild/lib/logs/"
#define CMDS "/players/nylakoorub/guild/lib/cmds/vags/"
#define LOCKCMDS "/players/nylakoorub/guild/lib/lockcmds/"
#define CAP     capitalize
#define GM      "guild/master"
#define GUILD   "vagabond"
#define MASTER  "nylakoorub"
#define E       environment()
#define TP      this_player()
#define TO    this_object()
#define QRN     query_real_name()
#define maxstatuschr   20
#define maxtlstatuschr  20
#define maxwherechr   25
#define maxnamechr     12
#define maxlevelchr    13
#define ver   5
#define points  15
#define memberslevel  8
#define maxlinechr 6
#define phaselevel  7
#define general maxnamechr+memberslevel+maxlinechr
#define omniinfo  ver+points
#define phaseinfo  12
#define QL      query_level()
#define ENV     environment
#define QW      query_wis()
#define QI      query_int()
#define QL      query_level()
#define QS      query_str()
#define QC      query_con()
#define QD      query_dex()
#define TPL	TP->query_level()
#define TPD     this_player()->query_dex()
#define TPW     TP->query_wis()
#define TPI     TP->query_int()
#define TPC     TP->query_cha()
#define TPS     TP->query_str()   
#define CG	if(TP->query_ghost()){ \
		    write("You are a ghost, you cannot do that.\n"); \
		    return 1; \
                }

#include "/players/nylakoorub/guild/lib/checks/check_attack.h"
#include "/players/nylakoorub/guild/lib/checks/check_cost.h"
#include "/players/nylakoorub/guild/lib/defines/bend.h"
#include "/obj/adjust.h"


