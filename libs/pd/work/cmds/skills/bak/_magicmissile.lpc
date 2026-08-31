//      _missile.c
//      Mage ability
//      Written 131092 by Descartes of Borg
//      Remade by Daboura into _magicmissile.c

#include <daemons.h>
#include <std.h>
inherit DAEMON;
int spell();
string type() { return "attack"; }
int cmd_magicmissile(string str) {
    object tp, ob;
    int i, which, skip, attack;
    object *inv;
    string what;

   if (!spell()) {
      return 0;
   }

    this_player()->set_magic_round();

    tp = this_player();

    if(tp->query_ghost()) {
        notify_fail("You emit a ghostly moan.\n");
        return 0;
    }
    
    if (tp->query_disable())
        return notify_fail("You are too busy to cast this spell.\n");
    
    if(environment(tp)->query_property("no magic")
       || environment(tp)->query_property("no attack")) {
        notify_fail("Something seems to be blocking your concentration.\n");
        return 0;
    }
    
    if(tp->query_casting()) return notify_fail("You are already casting a spell!");
    
    if((int)tp->query_mp() < 9) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    
    if(!str) {
        ob = (object)tp->query_current_attacker();
        if(!ob) {
            return notify_fail("Missile what?\n");
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
        notify_fail(ob->query_cap_name()+" is not a living thing!\n");
        return 0;
    }
    
    if(ob==tp) {
        notify_fail("Cast magic missile on yourself?\n");
        return 0;
    }
    if(ob->is_player() && !interactive(ob)) {
        notify_fail("You cannot attack link-dead players.\n");
        return 0;
    }
    if(ob->query_property("no missile")) {
      notify_fail(sprintf("%s is immune to such magic.\n",
                  ob->query_cap_name()));
      return 0;
    }
    attack = BALANCE3_D->get_damage( tp, ob, 1, ({ "magic attack" }),
                                   ({ "intelligence" }) );
    
    if(attack < 10) attack = 10+random(5);
    if(attack > 200) attack = 200 + tp->query_level();
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
    
    write("%^CYAN%^%^BOLD%^You send a %^YELLOW%^beam of light%^CYAN%^%^BOLD%^ at " +ob->query_cap_name()+"!%^RESET%^");
    
    message("room","%^CYAN%^%^BOLD%^"+tp->query_cap_name()+ " sends a %^YELLOW%^beam of light%^CYAN%^%^BOLD%^ at "
        +ob->query_cap_name()+"!%^RESET%^", environment(tp), ({tp,ob}));            
    
    message("ob", "%^CYAN%^%^BOLD%^"+tp->query_cap_name()+
                " sends a %^YELLOW%^beam of light%^CYAN%^%^BOLD%^ flying at you!%^RESET%^",ob);
    
    tp->set_casting(attack);
    
    tp->add_skill_points("magic attack", attack/20 + 2);
    
    tp->add_mp(-(this_player()->query_skill("magic attack")/8 + (1+random(this_player()->query_stats("intelligence")/4))));
    
    tp->set_disable();
    
    return 1;
}
void help() {
    write("Syntax: <magicmissile [(living)]>\n"
        "Casts a magic missile at the living object named, or, if in "
        "battle and no arguments are used, at your current opponent.\n");
}
int spell() {
    object tp;
    tp = this_player();
    if (!tp) return 0;
    //if (tp->query_class() != "mage") return 0;
    if(tp->query_subclass() == "wizard") return 1;
    
   return 0;
}
