// a dungeonware.net production based on freeze.c
// coded for Primal Darkness     
#include <std.h>
inherit DAEMON;
int spell();
int cmd_solidify(string str) {
    object tp, ob;
    int attack, wisdom, skip, which, i, solid, level, x;
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
    if((string)tp->query_class() != "mage") {
        write("You mumble in confusion.");
        say(tp->query_cap_name()+" mumbles in confusion.", tp);
        return 1;
    }
    if((string)tp->query_subclass() != "sorceror") {
      write("You mumble in confusion.");
      say(tp->query_cap_name()+" mumbles in confusion.", tp);
      return 1;
    }
    if (this_player()->query_disable())
      return notify_fail("You are busy.\n");
    if(level < 10) {
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
            notify_fail("Solidify what?\n");
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
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
    attack = (int)tp->query_skill("magic attack")/2 + (int)tp->query_stats("wisdom");
    attack += (int)tp->query_skill("psionics")/2;
    wisdom = (int)ob->query_stats("intelligence")*2/3 + (int)ob->query_skill("magic defense")/2;
    attack -= wisdom;
    attack *= 3/2;
    weaknesses = (string *)ob->query_property("weakness");
    if (!pointerp(weaknesses))
        weaknesses = ({ });
    strengths = (string *)ob->query_property("strengths");
    if (!pointerp(strengths))
        strengths = ({ });
    if(member_array("magic", weaknesses) != -1)
        attack += random( (attack/2) + 5 );
    else {
        if(member_array("magic", strengths) != -1)
            attack -= random(wisdom + 5);
    }
    if(!ob->query_property("no paralyze")) 
      solid = random(10);
    if(attack < 1) attack = 0;
    if((string)tp->query_class() == "mage") attack++;
    write("%^ORANGE%^You cast solidify!");
    tell_room(environment(tp), "%^ORANGE%^"+(string)ob->query_cap_name()+" screams in agony as "+ob->query_title_gender()+" skin begins to solidify!\n%^RESET%^", ({ ob, tp }));
    tell_object(ob, "%^ORANGE%^"+tp->query_cap_name()+" causes you to stiffen.");
    tp->set_casting(attack + random(tp->query_level()/2));
    if(solid == 1) {
      ob->set_paralyzed(5 + random(6));
      tell_room(environment(tp), "%^ORANGE%^"+ob->query_cap_name()+" is solid!", ({ob, tp}) );
      tell_object(ob, "%^ORANGE%^You are solid!");
      write("%^ORANGE%^"+ob->query_cap_name()+" is solid!");
      tp->add_mp(-(random(level)));
    }
    x = (int)ob->query_hp();
    tp->set_disable();
    tp->add_skill_points( ((attack + attack)/50 + attack/20) * 5 );
    tp->add_mp(-attack/7);
   if ((x - attack) < 1) {
   if ((string)ob->query_gender() == "male") {
    oi = "his";
   } else oi = "her";
    tell_room(environment(tp), "%^ORANGE%^"+(string)ob->query_cap_name()+" releases a piercing scream as "+oi+" body turns to stone!%^RESET%^", ({ ob }));
   }
    return 1;
}
void help() {
    write("Syntax: <solidify [(living)]>\n"
        "This incantation causes your opponents body to turn to stone. "
        "Your opponent may become solid stone from this spell.\n");
}
int spell() {
   object tp;
   tp = this_player();
   if (!tp) return 0;
   if (tp->query_class() != "mage") return 0;
   if (tp->query_subclass() != "sorceror") return 0;
   if (tp->query_level() < 25) return 0;
   return 1;
}
