#include <std.h>

inherit DAEMON;

int get_damage(object tp, object ob, int rank, string *skills, string *stats,
  string *mstats) {

    int ret, i, tmp;
    if(!mstats)
	mstats = ({});

    if(rank == 1) {
	ret = 15;
	tmp = 0;

	i = sizeof(stats);
	while(i--)
	    tmp += tp->query_stats(stats[i]);
	tmp = tmp / sizeof(stats);
	tmp = tmp;
	ret += tmp;
	tmp = 0;
	i = sizeof(skills);
	while(i--)
	    tmp += tp->query_skill(skills[i]);
	tmp = tmp / sizeof(skills);
	ret += (int)(3*tmp/2);
	ret += random(tp->query_level());
    }
    else if(rank == 2) {
	ret = 0;
	tmp = 0;
	i = sizeof(stats);
	while(i--)
	    tmp += tp->query_stats(stats[i]);
	tmp = tmp / sizeof(stats);
	tmp = tmp;
	ret += tmp*2;
	tmp = 0;
	i = sizeof(skills);
	while(i--)
	    tmp += tp->query_skill(skills[i]);
	tmp = tmp / sizeof(skills);
	ret += (int)(3*tmp/2);
	ret += random(tp->query_level());
    }
    else if(rank == 3) {
	ret = 0;
	tmp = 0;
	i = sizeof(stats);
	while(i--)
	    tmp += tp->query_stats(stats[i]);
	tmp = tmp / sizeof(stats);
	tmp = tmp;
	ret += tmp*2;
	tmp = 0;
	i = sizeof(mstats);
	while(i--)
	    tmp += tp->query_stats(mstats[i]);
	if(sizeof(mstats) > 0)
	    tmp = tmp / sizeof(mstats);
	tmp = tmp / 2;
	ret += tmp;
	tmp = 0;
	i = sizeof(skills);
	while(i--)
	    tmp += tp->query_skill(skills[i]);
	tmp = tmp / sizeof(skills);
	ret += (int)(3*tmp/2);
	ret += random(tp->query_level());
    }
    else if(rank == 4) {
	ret = 0;
	tmp = 0;
	i = sizeof(stats);
	while(i--)
	    tmp += tp->query_stats(stats[i]);
	tmp = tmp / sizeof(stats);
	ret += tmp*2;
	tmp = 0;
	i = sizeof(mstats);
	while(i--)
	    tmp += tp->query_stats(mstats[i]);
	if(sizeof(mstats) > 0)
	    tmp = tmp / sizeof(mstats);
	ret += tmp;
	tmp = 0;
	i = sizeof(skills);
	while(i--)
	    tmp += tp->query_skill(skills[i]);
	tmp = tmp / sizeof(skills);
	ret += (int)(3*tmp/2);
	ret += random(tp->query_level());
    }
    else {
	message("info", "This ability/spell has an invalid rank.  "
	  "Please inform an admin or use the <bug> command to report it.",
	  tp);
	return 0; // yes, that means it will do 0 damage.
    }


    if(tp->query_level() < 5) {
	if(member_array("wisdom", stats) != -1 &&
	  member_array("intelligence", stats) != -1)
	    ret -= ob->query_skill("magic defense")/6;
	else
	    ret -= ob->query_skill("defense")/6;
    }
    else if(tp->query_level() < 20) {
	if(member_array("wisdom", stats) != -1 &&
	  member_array("intelligence", stats) != -1)
	    ret -= ob->query_skill("magic defense")/4;
	else
	    ret -= ob->query_skill("defense")/4;
    }
    else if(tp->query_level() < 45) {
	if(member_array("wisdom", stats) != -1 &&
	  member_array("intelligence", stats) != -1)
	    ret -= ob->query_skill("magic defense")/2;
	else
	    ret -= ob->query_skill("defense")/2;
	ret -= ob->query_stats("dexterity") / 4;
    }
    else {
	ret -= ob->query_stats("dexterity")/2;
	if(member_array("wisdom", stats) != -1 &&
	  member_array("intelligence", stats) != -1) {
	    ret -= ob->query_skill("magic defense")/2;
	    ret -= ob->query_stats("wisdom")/2;
	}
	else {
	    ret -= ob->query_skill("defense")/2;
	    ret -= ob->query_stats("constitution")/2;
	}
    }

    if(wizardp(tp))
    {
        message("info", "Damage return for balance 2 = "+(3*ret/2)+"\n", tp);
    }
    return (int)(3*ret/2);

}
