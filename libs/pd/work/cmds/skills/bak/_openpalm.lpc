#include <std.h>
#include <daemons.h>
inherit DAEMON;
int abil();
string type() { return "attack"; }
int cmd_openpalm(string str) {
    object tp, ob;
    int faith;
    int healing;
    int attack, wisdom;
   if (!abil()) {
      return 0;
   }
    tp = this_player();
    if(tp->query_ghost()) {
        notify_fail("You have no chi in your current state.\n");
        return 0;
    }
    if(environment(tp)->query_property("no attack")) {
        notify_fail("Something seems to be blocking your concentration.\n");
        return 0;
    }
    if((int)tp->query_sp() < 25) {
        notify_fail("You are to tired.\n");
        return 0;
    }
    if (this_player()->query_busy())
       return notify_fail("You are busy.\n");
    if(!str) {
        ob = (object)tp->query_current_attacker();
        if(!ob) {
            notify_fail("Palm what?\n");
            return 0;
        }
    }
    else {
        ob = present(str, environment(tp));
        if(!ob) ob = parse_objects(environment(tp), str);
        if(!ob) {
                notify_fail("No "+str+" here!\n");
                return 0;
        }
    }
    if(!living(ob)) {
        notify_fail(ob->query_cap_name()+" is not a living thing!\n");
        return 0;
    }
    if(ob == tp) {
        notify_fail("Not a very bright thing to do.\n");
        return 0;
    }
    if(ob->is_player() && !interactive(ob)) {
        notify_fail("You cannot attack link-dead players.\n");
        return 0;
    }
    if(tp->query_ghost())
        return notify_fail("You have no palms as a ghost.\n");
    attack = BALANCE_D->get_damage( tp, ob, 1, ({ "melee", "attack" }),
                                   ({ "dexterity" }) );
    if(attack < 1) attack = 0;
    if(tp->query_skill("melee") < 25) {
        notify_fail("You are not skilled enough for that.\n");
        return 0;
    }
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
    write("You concentrate the chi energy in your palm and strike!\n");
    tell_room(environment(tp), tp->query_cap_name()+" concentrates and strikes with an open palm!\n", ({ tp, ob }) );
    tell_object(ob, tp->query_cap_name()+" strikes you with "+tp->query_possessive()+" open palm!\n");
    tp->set_casting(attack);
    tp->add_sp(-attack/7);
    tp->add_skill_points("attack", attack/40);
    tp->add_skill_points("melee", attack/20);
//    tp->set_disable();
    return 1;
}
void help() {
    write("Syntax: <openpalm [(living)]>\n"+
        "A monk concentrates the chi energy in their palm and strikes out\n"+
        "hitting their opponent. If in battle, no argument is needed.\n");
}
int abil() {
   object j;
   j = this_player();
   if (!j) return 0;
   if (j->query_subclass() != "monk") return 0;
   if (j->query_level() < 5) return 0;
   return 1;
}
