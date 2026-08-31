#include <daemons.h>
#include <std.h>

#define RES "%^RESET%^"
#define COL RES+"%^WHITE%^"
#define COL2 "%^BOLD%^%^WHITE%^"

inherit DAEMON;

int abil();

string type() { return "attack"; }

int cmd_jab(string str) {
    object tp, ob;
    int i, which, skip, attack;
    object *inv;
    string what;

   	if (!abil())
      	return 0;

    tp = this_player();

    if(tp->query_ghost())
        return notify_fail("You emit a ghostly moan.\n");
    
    if (tp->query_disable())
        return notify_fail("You are too busy to jab!\n");
    
    if(environment(tp)->query_property("no attack"))
        return notify_fail("Some strange force prevents your attack.\n");
    
    if(tp->query_magic_round() || tp->query_casting()) return notify_fail("You are casting a spell!");
    
    if(tp->query_sp() < 5) 
        return notify_fail("You are too tired!\n");
    
    if(!str) {
        ob = (object)tp->query_current_attacker();
        if(!ob) {
            return notify_fail("Jab who?\n");
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
    
    if(ob==tp)
        return notify_fail("Jab yourself?\n");

    if(ob->is_player() && !interactive(ob))
        return notify_fail("You cannot attack link-dead players.\n");
    
    if(environment(tp)->query_property("no attack"))
        return notify_fail("Some strange force prevents your attack!\n");

    attack = BALANCE3_D->get_damage( tp, ob, 1, ({ "melee", "attack", "attack" }),
        ({ "dexterity", "strength", "strength" }), ({"dexterity", "strength"}) );
    
    attack *= 0.8;
    if(attack < 10) attack = 10+random(5);
    if(attack > 120) attack = 120 + tp->query_level();
    
    if(!this_player()->kill_ob(ob))
        return notify_fail(ob->query_cap_name()+" can't be attacked by you yet.\n");
    
    message("combat", "You "+COL2+"j"+COL+"a"+COL2+"b"+RES+" "+ob->query_cap_name()+
                      " with your fist!", tp);
    message("combat", tp->query_cap_name()+" "+COL2+"j"+COL+"a"+COL2+"b"+COL+"s"+RES+
                      " you with "+tp->query_possessive()+" fist!", ob);
    message("combat", tp->query_cap_name()+" "+COL2+"j"+COL+"a"+COL2+"b"+COL+"s"+RES+
                      " "+ob->query_cap_name()+" with "+tp->query_possessive()+" fist!",
                        environment(tp), ({tp, ob}) );
    
    ob->do_damage(ob->return_target_limb(), attack);
    
    tp->add_skill_points("attack", attack/20 + 2);
    tp->add_skill_points("melee", attack/20 + 2);
    
    tp->add_sp(-(this_player()->query_skill("attack")/7 + (1+random(this_player()->query_stats("strength")/3))));
    
    tp->set_disable();
    
    return 1;
}
void help() {
    write("Syntax: <jab [(living)]>\n"
        "An attack for those who have not been trained much in "
		"their field. The player will jab at their target with their fists.\n");
}
int abil() {
    object tp;
    tp = this_player();
    if (!tp) return 0;
    if (tp->query_class() == "mage") return 0;
    if (tp->query_class() == "clergy") return 0;
    return 1;
}

