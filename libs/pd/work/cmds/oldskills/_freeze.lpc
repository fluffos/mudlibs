//        _freeze.c
//      Mage ability
//      Written 14194 by Bohemund

#include <std.h>
inherit DAEMON;
int spell();

int cmd_freeze(string str) {
    object tp, ob;
    int attack, wisdom, skip, which, i, frozen, level, x;
    string what, *strengths, *weaknesses, oi;
    object *inv;

   if (!spell()) {
      write("What?\n");
      return 1;
   }
    this_player()->set_magic_round();
    tp = this_player();
    level = (int)tp->query_level();
    if(tp->query_ghost()) {
        notify_fail("Your voice is hollow.\n");
        return 0;
    }

    if((string)tp->query_subclass() != "wizard" && tp->query_subclass() !=
"druid" && tp->query_subclass() != "sorceror") {
      write("You mumble in confusion.");
      say(tp->query_cap_name()+" mumbles in confusion.", tp);
      return 1;
    }
    if (this_player()->query_disable())
      return notify_fail("You are busy.\n");

    if(level < 8) {
      notify_fail("You are not sufficiently trained in the "
                  "magical arts to cast this spell.\n");
      return 0;
    }
    if(environment(tp)->query_property("no magic")) {
        notify_fail("Something seems to be blocking your concentration.\n");
        return 0;
    }
    if(tp->query_casting()) return 1;
    if((int)tp->query_mp() < 20) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    if(!str) {
        ob = (object)tp->query_current_attacker();
        if(!ob) {
            notify_fail("Freeze what?\n");
            return 0;
        }
    }
    else {
        ob = present(str, environment(tp));
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
                notify_fail("No "+str+" here!\n");
                return 0;
            }
        }
    }
    if(!living(ob)) {
        notify_fail(ob->query_cap_name()+" is not alive!\n");
        return 0;
    }
    if(ob == tp) {
        notify_fail("Not a very intelligent thing to do.\n");
        return 0;
    }
    if(ob->is_player() && !interactive(ob)) {
        notify_fail("You cannot attack link-dead players.\n");
        return 0;
    }
    if(ob->query_property("no cold")) {
        notify_fail(sprintf("%s is immune to cold attacks.\n", 
          ob->query_cap_name()));
        return 0;
    }
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
    attack = (int)tp->query_skill("magic attack")*2/3 + (int)tp->query_stats("wisdom");
    wisdom = (int)ob->query_stats("wisdom")/2 + (int)ob->query_skill("magic attack")/3;
    attack -= wisdom;
    attack *= 3/2;
    weaknesses = (string *)ob->query_property("weakness");
    if (!pointerp(weaknesses))
        weaknesses = ({ });
    strengths = (string *)ob->query_property("strengths");
    if (!pointerp(strengths))
        strengths = ({ });
    if(member_array("cold", weaknesses) != -1)
        attack += random( (attack/2) + 5 );
    else {
        if(member_array("cold", strengths) != -1)
            attack -= random(wisdom + 5);
    }
    if(member_array("magic", weaknesses) != -1)
        attack += random( (attack/2) + 5 );
    else {
        if(member_array("magic", strengths) != -1)
            attack -= random(wisdom + 5);
    }
    if(!ob->query_property("no paralyze")) 
      frozen = random(10);
    if(attack < 1) attack = 0;
    if((string)tp->query_class() == "mage") attack++;
    write("%^BOLD%^%^CYAN%^You cast freeze!");
    tell_room(environment(tp), "%^CYAN%^%^BOLD%^"+(string)ob->query_cap_name()+
              " screams in agony as "+ob->query_title_gender()+
              " skin starts to frost!\n%^RESET%^", ({ ob, tp }));
    tell_object(ob, "%^CYAN%^%^BOLD%^"+tp->query_cap_name()+
                " makes you shiver.");
    tp->set_casting(attack + random(tp->query_level()/2));
    if(frozen == 1) {
      ob->set_paralyzed(3 + random(2));
      tell_room(environment(tp), "%^CYAN%^%^BOLD%^"+ob->query_cap_name()+
                " is frozen!", ({ob, tp}) );
      tell_object(ob, "%^CYAN%^%^BOLD%^You are frozen!");
      write("%^BOLD%^%^CYAN%^"+ob->query_cap_name()+" is frozen!");
      tp->add_mp(-attack/7);
    }
    x = (int)ob->query_hp();
    tp->set_disable();
    tp->add_skill_points( ((attack + attack)/50 + attack/20) * 5 );
    tp->add_mp(-(random(20)+(attack/25)*2) + random(this_player()->query_level()));
   if ((x - attack) < 1) {
   if ((string)ob->query_gender() == "male") {
    oi = "his";
   } else oi = "her";
    tell_room(environment(tp), "%^BOLD%^%^CYAN%^"+
              (string)ob->query_cap_name()+
              " releases a piercing scream as "+
              oi+
              " body freezes solid!%^RESET%^", ({ ob }));
   }
    return 1;
}

void help() {
    write("Syntax: <freeze [(living)]>\n"
        "This incantation causes your opponents body temperature"
        "to drop. Your opponent has a chance of freezing solid.\n");
}

int spell() {
   object tp;
   tp = this_player();
   if (!tp) return 0;
   if (tp->query_subclass() != "wizard" && tp->query_subclass() != "druid" &&
tp->query_subclass() != "sorceror") return 0;
   if (tp->query_level() < 8) return 0;
   return 1;
}

