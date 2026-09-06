#include "../../priest.h"
#include "../../skills.h"

inherit PSKILLS;

pset_cmd(object who, object sym, string str) {
    string sk_name;
    int n,i,p;

    if(!who->query_coder_level() && !who->query_testplayer()) return 0;

    notify_fail("Usage: pset <skill_name/number/all> <0..999>\n");
    if(!str) return 0;
    if(sscanf(str, "%s %D", sk_name, n)!=2)
	return 0;
    if(sscanf(sk_name, "%d", i)) {
	if(i<0 || i>=sizeof(SKILL_NAMES))
	    return notify_fail("No such skill.\n"),0;
    } else {
	if(sk_name == "all") i = -1;
	else if((i = member(SKILL_NAMES, sk_name)) == -1)
	    return notify_fail("No such skill.\n"),0;
    }
    if(n<0 || n>999)
	return notify_fail("The value must be between 0 and 999.\n"),0;

    p = skill2pex(n);
    if(i==-1) {
	for(i=0;i<sizeof(SKILL_NAMES);i++)
	    sym->set_pex(i,p);
    } else sym->set_pex(i, p);
    who->tell_me(sprintf("New skill: %d/%d/%s.", n, p, pex2str(p)));
    return 1;
}

int
clean_up(int arg) {
    destruct(this_object());
    return 0;
}

