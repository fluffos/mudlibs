//    _annihilate.c
//      Mage ability
//      created by Descartes of Borg 18 November 1992

#include <std.h>
#include <common_fun.h>
inherit DAEMON;
int spell();

int cmd_annihilate() {
    object *tmp;
    object *attackers;
    int mag, cost, wis;
    int i;

    if (!spell()) {
	write("What?\n");
	return 1;
    }
    TP->set_magic_round();
    if(TP->query_ghost()) {
	notify_fail("Your voice is hollow.\n");
	return 0;
    }
    if (TP->query_disable())
	return notify_fail("You are busy.\n");
    if(TP->query_casting()) return 1;
    if(ENV(TP)->QPP("no attack")) {
	notify_fail("A magic force prevents you from casting your spell.\n");
	return 0;
    }
    if(ENV(TP)->QPP("no magic")) {
	notify_fail("A magic force prevents your spell.\n");
	return 0;
    }
    attackers = (object *)TP->query_attackers();
    if(!attackers || !sizeof(attackers)) {
	notify_fail("You are not in battle!\n");
	return 0;
    }
    mag = (int)TP->QSK("magic attack");
    if(mag < 50) {
	notify_fail("You are not at all skilled enough for such a power spell.\n");
	return 0;
    }
    tmp = ({});
    TP->set_disable();
    for(i=0; i<sizeof(attackers); i++) {
	if(!attackers[i]) continue;
	if(member_array(attackers[i], tmp) != -1) continue;
	tmp += ({ attackers[i] });
	wis = (int)attackers[i]->QST("wisdom")/2;
	wis += (int)attackers[i]->QSK("magic defense")/2;
	mag += (int)TP->QST("wisdom");
	mag -= wis;
	cost = mag/14;
	if(mag < 1) write(attackers[i]->QCN+" is too powerful for you!");
	if((int)TP->query_mp() < cost) {
	    write(attackers[i]->QCN+": Too low on magic power.");
	    continue;
	}
	TP->add_mp(-cost*i);
	TP->add_skill_points("magic attack", random(cost/4));
	attackers[i]->add_hp(-((mag)/2));
	TP->set_casting((mag)/2);
	TP->set_magic_round(2);
	TP->set_disable();
	write("%^MAGENTA%^%^BOLD%^A spell of annihilation rips through "
	  +attackers[i]->QCN+".");
	say("%^MAGENTA%^%^BOLD%^"+TP->QCN+"'s spell of annihilation rips through "+attackers[i]->QCN+".", TP);
    }
    return 1;
}

void help() {
    write("Syntax: <annihilate>\n\n"+
      "This spell does massive damage to all of your attackers. "
      "It also drains a lot of magic power.\n");
}

int spell() {
    if (!TP) return 0;
    if (TP->QSC != "wizard" &&
      TP->QSC != "sorceror" &&
      TP->QSC != "black" &&
      TP->QSC != "necromancer") return 0;
    if (TP->query_level() < 10) return 0;
    return 1;
}
