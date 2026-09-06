#include <player_defs.h>
#include "../../priest.h"


status
priest_info_cmd(object who, object sym, string s) {
    int i, *pexes, c_time, c_pex, s_time, s_pex;
    object pl, pls;
    string str;
    mixed tmp;
    string *log, name, c_name;

    if(!who->query_coder_level()) return 0;

    if(!s) {
	str = "Priest Guild Info:\n";
	if(VOTING_D->query_voting())
	    str += "Elections are open.\n";
	if(tmp = VESPER_D->query_vespers())
	    str += sprintf("The Holy Order is called to %s.\n", tmp);
	if((tmp = SHIELD_D->query_players()) && (tmp = sizeof(tmp)))
	    str += sprintf("%d players are using shield.\n", tmp);
	if((tmp = SLAVE_D->query_data()) && (tmp = sizeof(tmp)))
	    str += sprintf("%d players are controlling pets.\n", tmp);
	name = 0;
    }
    else {
	pl = find_player(s);
	str = sprintf("Info for '%s':\n", s);
	if(tmp = OFFICER_D->my_rank(s))
	    str += sprintf("Rank: %s\n", OFFICER_D->get_office(tmp));
	if(pl) {
	    if(!IS_PRIEST(pl)) return notify_fail("Not a priest.\n"),0;

	    name = capitalize(pl->query_real_name());
	    pls = pl->query_guild_object();
	    str += sprintf("Faith: %d\n", pls->query_faith());
	    str += sprintf("Order: %d\n", pls->query_order());
	    str += sprintf("Coef: %d\n", pls->query_coef());
	    str += sprintf("Mixing: %d, casting: %d\n", pls->query_mixing(),
	      pls->query_casting());
	    str += sprintf("Satiation: %d\n", pls->query_satiation());
	}
	else {
	    name = capitalize(s);
	    str += "(Player is not on.)\n";
	}
    }
    if(file_size(PEXLOG)>=0) {
	log = explode(read_file(PEXLOG),"\n");
	i = sizeof(log);
	while(--i>=0) {
	    if(sscanf(log[i], "%s %d %d", c_name, c_pex, c_time) == 3) {
		if(!name || (c_name == name)) {
		    s_time += c_time;
		    s_pex += c_pex;
		}
	    }
	}
	if(s_time) {
	    str += sprintf("Total pex: %d.\n", s_pex);
	    str += "Done in ";
	    if(s_time / 3600) str += sprintf("%d hours ", s_time/3600);
	    if((s_time / 60)%24) str += sprintf("%d minutes ", (s_time/60)%24);
	    str += sprintf("%d seconds.\n", s_time%60);
	    str += sprintf("Making pex rate: %d pex/h", 3600*s_pex/s_time);
	}
	else str += "No pexrate info found.";
    }
    else str += "Pex log is empty.";

    who->tell_me(str);
    return 1;
}
