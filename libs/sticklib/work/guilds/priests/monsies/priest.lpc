#include <servers.h>
inherit NAME_SERVER;

#include "priest_monster.h"

object attacker;
string myname;

void make_titles();

void
create_monster()
{
    set_race("human");
    make_titles();
    set_guild(GN_PRIEST);
    set_gender(G_MALE);
    set_heart_beat(1);
}

make_titles() {
    int a;
    string rank, adj;
    a = random(4) + 1;
    myname = random_name();
    switch(a) {
    case 1 : rank = "curate"; adj = "holy"; break;
    case 2 : rank = "prefect"; adj = "humble"; break;
    case 3 : rank = "canon"; adj = "devoted"; break;
    case 4 : rank = "priest"; adj = "reverent"; break;
    }
    set_name(rank);
    set_id(myname);
    set_short(sprintf("%s the %s of " GOD_NAME,capitalize(myname),rank));
    set_long(sprintf("%s is a %s %s of " GOD_NAME, capitalize(myname), adj, rank));
    set_level(15+a);
    set_ac(10+a);
    set_wc(16+a);
    return;
}

heart_beat()
{
    object ob;

    ::heart_beat();
    if((ob = this_object()->query_attack()))
	if(!attacker || ob != attacker) {
	    attacker = ob;
	    shout(sprintf("%-=78s", capitalize(myname)+
		" shouts: Help! The fraternity is under attack by "+
		capitalize((string)attacker->query_real_name())+
		", that filthy heathen!\n"));
	    SERVER->inform(capitalize((string)attacker->query_real_name())+
	      " seems to be attacking the Holy Order! Perhaps something"+
	      " should be done...");
	}
}



