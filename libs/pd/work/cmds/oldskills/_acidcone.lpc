//    based on _annihilate.c
//    stormy
#include <std.h>
#include <common_fun.h>
inherit DAEMON;
int spell();
int cmd_acidcone() {
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
        wis = (int)attackers[i]->QST("wisdom");
        wis += (int)attackers[i]->QSK("magic defense")/2;
        mag += (int)TP->QSK("wizardry")*2/3;
        mag += (int)TP->QST("wisdom");
        mag -= wis;
        mag *= 3/2;
        if(mag < 10) write(attackers[i]->QCN+" is too powerful for you!");
        cost = mag/7;
        if((int)TP->query_mp() < cost) {
            write(attackers[i]->QCN+": Too low on magic power.");
            continue;
        }
        TP->add_mp(-cost*i);
        TP->add_skill_points("magic attack", random(mag/25));
        TP->add_skill_points("wizardry", random(mag/25));
        attackers[i]->damage(mag, "acid");
        TP->set_magic_round(2);
        TP->set_disable();
        write("%^GREEN%^%^BOLD%^A cone of acid seers the flesh of "+attackers[i]->QCN+".");
        say("%^GREEN%^%^BOLD%^"+TP->QCN+"'s cone of acid seers the flesh of "+attackers[i]->QCN+".", TP);
    }
    return 1;
}
void help() {
    write("Syntax: <acidcone>\n\n"+
        "This spell shoots a cone of acid from the casters hand hitting all attackers.\n");
}
int spell() {
   if (!TP) return 0;
   if (TP->QSC != "wizard") return 0;
    if (TP->query_level() < 25) return 0;
   return 1;
}
