//      _fireball.c
//      Mage ability
//      Written 131092 by Descartes of Borg
#include <std.h>
inherit DAEMON;
int spell();
int cmd_fireball(string str) {
    object tp, ob;
    int attack, wisdom, skip, which, i;
    string what, *strengths, *weaknesses;
    object *inv;
   if (!spell()) {
      notify_fail("What?\n");
      return 0;
   }
    this_player()->set_magic_round();
    tp = this_player();
    if(tp->query_ghost()) {
        notify_fail("Your voice is hollow.\n");
        return 0;
    }
    if((string)tp->query_class() != "mage") {
        write("You mumble in confusion.");
        say(tp->query_cap_name()+" mumbles in confusion.", tp);
        return 1;
    }
    if(environment(tp)->query_property("no magic")) {
        notify_fail("Something seems to be blocking your concentration.\n");
        return 0;
    }
    if (this_player()->query_disable())
       return notify_fail("You are busy.\n");
    if((int)tp->query_mp() < 20) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    if(!str) {
        ob = (object)tp->query_current_attacker();
        if(!ob) {
            notify_fail("Fireball what?\n");
            return 0;
        }
    }
    else {
        ob = present(str, environment(this_player()));
        if(!ob) {
            sscanf(str, "%s %d", what, which);
            inv = all_inventory(environment(tp));
            for(i=0, skip = 0; i<sizeof(inv) && !ob; i++) {
                if(inv[i]->id(what)) {
                    skip++;
                    if(skip == which) ob = inv[i];
                }
            }
            if(!ob) {
                notify_fail("You do not see "+str+" here.\n");
                return 0;
            }
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
    if(ob->query_property("no magic")) {
        notify_fail(sprintf("%s is immune to your magic.\n",
          ob->query_cap_name()));
        return 0;
    }
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
    attack = (int)tp->query_skill("magic attack")*2/3 + (int)tp->query_stats("wisdom");
    wisdom = (int)ob->query_stats("wisdom")/2 + (int)ob->query_skill("magic defense")/3;
    attack -= wisdom;
    weaknesses = (string *)ob->query_property("weakness");
    if (!pointerp(weaknesses))
        weaknesses = ({ });
    strengths = (string *)ob->query_property("strengths");
    if (!pointerp(strengths))
        strengths = ({ });
    if(member_array("fire", weaknesses) != -1)
        attack += random( (attack/2) + 5 );
    else {
        if(member_array("fire", strengths) != -1)
            attack -= random(wisdom + 5);
    }
    if(member_array("magic", weaknesses) != -1)
        attack += random( (attack/2) + 5 );
    else {
        if(member_array("magic", strengths) != -1)
            attack -= random(wisdom + 5);
    }
if(this_player()->query_name()=="simic") write("Attack: "+attack);
    if(attack < 1) attack = 0;
    if((string)tp->query_class() == "mage") attack++;
    write("%^RED%^%^BOLD%^You cast a fireball at "+
          (string)ob->query_cap_name());
    tell_room(environment(tp), "%^RED%^%^BOLD%^"+tp->query_cap_name()+
              " casts a fireball at "+(string)ob->query_cap_name()+".", 
              ({ ob, tp }));
    tell_object(ob, "%^RED%^%^BOLD%^"+tp->query_cap_name()+
                " casts a fireball at you.");
    tp->set_casting((attack) + random(tp->query_level()/2));
    tp->add_skill_points("magic attack", random(20));
    tp->add_mp(-attack/7);
    tp->set_disable();
    return 1;
}
void help() {
    write("Syntax: <fireball [(living)]>\n"
        "Casts a fireball at the living object named, or, if in "
        "battle and no arguments are used, at your current opponent.\n");
}
int spell() {
   object tp;
   tp = this_player();
   if (!tp) return 0;
   if (tp->query_class() != "mage") return 0;
   if (tp->query_level() < 4) return 0;
   return 1;
}
