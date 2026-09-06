//
//  _session.c -- Session kills/exp/status
//
//  01/96  - Alcal:
//      Took it from player object.
//      Did some changes (in logic).
//      Added total and average to kills.
//  19-jan-96 - Doomdark:
//      Removed 7 funcs handling session stats from player object and
//      replaced them with 1... Thus, needed to recode this command too.
//   5-Sep-98 / Graah:
//	Fixed for stick-dist



#include <player_defs.h>
#include <mud_name.h>
#include <macros.h>
#include <std_lib>
#include <cmd.h>

#define CODERLVL(x) ((int)x->query_coder_level())
#define WRITE(x) tp->tell_me(x)

#define KILLS 1
#define EXP   2
#define MONEY 4
#define TIME  8
#define ALL   KILLS+EXP+MONEY+TIME

mapping param;

int
session_cmd(string arg)
{
    string *list, tmp, *session_kills;
    int i, t, s, h, m, c, ltime, kills, *session_knum, session_exp;
    object tp;

    tp=this_player();

    if (!param) param = ([ 'k':KILLS, 'e':EXP+TIME, 'm':MONEY, 's':ALL ]);

    if (arg) c = param[lower_case(arg)[0]];
    if (!arg || !c)
	return notify_fail("Usage: session <exp/kills/status>\n"), 0;

    // Was: query_session_kills();
    session_kills=(string*)tp->session("query", "kill");
    // Was: query_session_knums();
    session_knum=(int*)tp->session("query", "knum");
    // Was: query_session_exp();
    session_exp=(int)tp->session("query", "exp");
    t = (int)tp->query(PLR_CONNECT_TIME);
    ltime = (int)tp->query(PLR_LOGIN_TIME);
    if (t < 1) {
	WRITE("Can't get the time of your login.");
	return 1;
    }

    h = t / 3600;
    m = (t - h * 3600) / 60;
    s = t % 60;

    if ((c & TIME) == TIME) {
	tmp = sprintf(
	  "You logged into "+MUD_NAME+" (or, came back from link-death) at %s.\
 You have now been in the mud for", ctime(ltime));
	list = ({ });
	if (h) list += ({ sprintf("%d hour%s",h,(h>1?"s":"")) });
	if (m) list += ({ sprintf("%d minute%s",m,(m>1?"s":"")) });
	if (s) list += ({ sprintf("%d second%s",s,(s>1?"s":"")) });
	WRITE(sprintf("%s %s.", tmp, implode(list, ", ", " and ")));
    }

    if ((c & KILLS) == KILLS) {
	if (!session_kills) {
	    WRITE("You have not killed anyone during this session.");
	} else {

	    kills = 0;
	    for (i = sizeof(session_kills)-1; i >= 0; i--) {
		if (c == KILLS) WRITE(sprintf("%4d of %s",
			session_knum[i], session_kills[i]));
		kills += session_knum[i];
	    }
	    WRITE(sprintf("You have killed total %d being%s. Which makes an\
 average of %d kill%s per hour, during this session.",
		kills, (1==kills?"":"s"), kills = ((kills * 3600) / t), (kills == 1 ? "" : "s")));
	}
    }

    if ((c & EXP) == EXP) {
	if (!session_exp) WRITE("You haven't collected any experience during this session.");
	else if (t > 0)
	    WRITE(sprintf("You have collected as much as %d experience points,\
 which makes an average of %d experience per hour, during this session.",
		session_exp, (session_exp * 36) / t * 100));
    }

    if (c == MONEY) {
	if (!CODERLVL(tp)) return 0;
	t = (int)tp->query_money();
	if (!t) WRITE("You have no money.");
	else {
	    WRITE(sprintf("You have %d gold coins in your purse.", t));
	}
    }

    return 1;
}
