//      _annihilate.c
//      Mage ability
//      created by Descartes of Borg 18 November 1992

#include <std.h>
#include <common_fun.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;
int spell();
string type() { return "attack"; }

int cmd_annihilate() {
    object *tmp;
    object *attackers;
    int mag, cost, wis;
    int i;

    if (!spell()) {
      return notify_fail("What?\n");
    }
    if (TP->query_busy())
	return notify_fail("You are busy.\n");
    if(TP->query_ghost()) {
	notify_fail("Your voice is hollow.\n");
	return 0;
    }
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
    tmp = ({});
    TP->set_magic_round();
    for(i=0; i<sizeof(attackers); i++) {
	if(!attackers[i]) continue;
	if(member_array(attackers[i], tmp) != -1) continue;
	tmp += ({ attackers[i] });
        mag = BALANCE3_D->get_damage( TP, attackers[i], 1, ({ "magic attack" }),
                                   ({ "intelligence" }) );
       mag = mag * 3 / 4;
       cost = BALANCE3_D->get_cost(mag, 1, "mp");
	if(mag < 1) write(attackers[i]->QCN+" is too powerful for you!");
	if((int)TP->query_mp() < cost) {
	    write(attackers[i]->QCN+": Too low on magic power.");
	    continue;
	}
        TP->add_mp(-cost);
	TP->add_skill_points("magic attack", random(cost/4));
        attackers[i]->do_damage("none", mag, DAMAGE_MAGIC, DAMAGE_BYPASS_ARMOUR, TP);
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
    if (TP->QSC != "black")
      return 0;
    if (TP->query_level() < 10) return 0;
    if (TP->query_skill("magic attack") < 50) return 0;
    return 1;
}
