//       _liquify.c
//      Conjurer starting spell
//      Written by the Inferno
//      base upon _burn.c
#include <daemons.h>
#include <std.h>
inherit DAEMON;
int spell();
string type() { return "attack"; }
int cmd_liquify(string str) {
    object tp, ob;
    int attack, wisdom, skip, which, i, conjur, x;
    string what, oi;
    object *inv;
   if (!spell()) {
      return 0;
   }
    tp = this_player();
    if(tp->query_ghost()) {
        notify_fail("Your voice is hollow.\n");
        return 0;
    }
    if (tp->query_skill("magic attack") < 10) {
       write("Your magic is not strong enough!");
       return 1;
    }
    if (tp->query_level() < 15) {
       write("Your magic is not strong enough!");
       return 1;
    }
    if ((string)tp->query_subclass() != "sorceror") {
        notify_fail("You mumble in confusion.\n");
        return 0;
    }
    if(environment(tp)->query_property("no magic") ||
       environment(tp)->query_property("no attack")) {
        notify_fail("Something seems to be blocking your concentration.\n");
        return 0;
    }
    if (this_player()->query_busy())
       return notify_fail("You are busy.\n");
    if((int)tp->query_mp() < 20) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    if(!str) {
        ob = (object)tp->query_current_attacker();
        if(!ob) {
            notify_fail("Liquify what?\n");
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
                notify_fail("You do not see "+str+" here.\n");
                return 0;
            }
        }
    }
    if(!living(ob)) {
        notify_fail(ob->query_cap_name()+" is not a living thing!\n");
        return 0;
    }
    if(ob==tp) {
        notify_fail("That would surely be suicide!\n");
        return 0;
    }
    if(ob->is_player() && !interactive(ob)) {
        notify_fail("You cannot attack link-dead players.\n");
        return 0;
    }
    attack = BALANCE_D->get_damage( tp, ob, 2, ({ "magic attack", "psionics" }),
                                   ({ "wisdom" }) );
    if(attack < 1) attack = 1;
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
    this_player()->set_magic_round();
    write("%^BOLD%^%^BLUE%^You attempt to liquify your opponent!%^RESET%^");
    tell_room(environment(tp), "%^BOLD%^%^BLUE%^"+(string)ob->query_cap_name()+
              " screams in agony as "+ob->query_title_gender()+
              " skin turns to liquid!\n%^RESET%^", ({ ob, tp }));
    tell_object(ob, "%^BOLD%^%^BLUE%^"+tp->query_cap_name()+
                " turns your skin into a liquid then back!%^RESET%^");
    x = (int)ob->query_hp();
   tp->set_casting(attack);
   tp->set_disable();
   tp->add_skill_points("psionics", attack/25); 
   tp->add_mp(-attack/5);
   if ((x - attack) < 1) {
   if ((string)ob->query_gender() == "male") {
    oi = "his";
   } else oi = "her";
    tell_room(environment(tp), "%^BOLD%^%^BLUE%^"+
              (string)ob->query_cap_name()+
              " releases a piercing scream as "+
              oi+
              " body turns into water, splashes against the ground "+
              "and forms into a corpse.%^RESET%^", ({ ob }));
   }
    return 1;
}
void help() {
    write("Syntax: <liquify [(living)]>\n"
        "This spells power grows as the caster becomes stronger. "
        "When cast, the caster attempts to liquify the target's "
        "body or skin. This process causes a great deal of pain "
        "for the victim. This spell is used by sorcerors.");
}
int spell() {
   object a;
   a = this_player();
   if (a->query_level() < 15) return 0;
   if (a->query_subclass() == "sorceror")
     return 1;
   return 0;
}
