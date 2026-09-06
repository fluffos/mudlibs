#include "../priest.h"
#include "../skills.h"

inherit PSKILLS;

string
print_1_skill(int n, int pex, status is_coder) {
    string tmp;

    tmp = sprintf("\n%-21s: %-18s",
      SKILL_NAMES[n], capitalize(pex2str(pex)));
    if(is_coder)
	tmp += sprintf("(%d/%d, %d)", to_int(pex2skill(pex)), pex,
	  ORDER_BONUSES[n]);
    return tmp;
}

mixed
get_pexes(object who, string s) {
    object pl, sym;
    string tmp, *strs;
    int *pexes, t1, t2, t3;

    if(s && who->query_coder_level()) {
	if(pl = find_player(s)) {
	    if(!IS_PRIEST(pl))
		return notify_fail("That player isn't a priest.\n"),0;
	    sym = pl->query_guild_object();
	    who->tell_me(sprintf("*** %s's skills: ***", 
		capitalize(pl->query_real_name())));
	}
	else {
	    tmp = SKILL_SAVER->query_my_data(s);
	    if(!tmp)
		return notify_fail("No saved data for that player.\n"),0;
	    if(sscanf(tmp, "%d&%d&%d&%s", t1, t2, t3, tmp) != 4)
		return notify_fail("Error in skill saver's data.\n"),0;
	    strs = explode(tmp, "#");
	    pexes = allocate(sizeof(strs));
	    for(t1=0; t1<sizeof(strs); t1++)
		pexes[t1] = to_int(strs[t1]);
	    who->tell_me(sprintf("*** %s's skills from back-up file: ***", 
		capitalize(s)));
	    return pexes;
	}
    }
    else sym = who->query_guild_object();
    return sym->query_pexes();
}
