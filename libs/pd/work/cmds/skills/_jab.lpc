#include <daemons.h>
#include <std.h>
#include <damage_types.h>
#include <damage.h>

#define RES "%^RESET%^"
#define COL RES+"%^WHITE%^"
#define COL2 "%^BOLD%^%^WHITE%^"
#define COLC COL2+"%^B_RED%^"

inherit DAEMON;

string *classes = ({ "child", "fighter", "rogue", "wanderer" });
string *subclasses = ({ "monk" });

int abil() {
    object tp;
    tp = this_player();
    if (!tp) return 0;
    if (member_array(tp->query_class(), classes) != -1 ||
        member_array(tp->query_subclass(), subclasses) != -1)
          return 1;
    return 0;
}

void help() {
  message("help",
    "Syntax: <jab [opponent]>\n\n"
    "A very simple punch attack for those with only minimal training.",
    this_player() );
}

string type() { return "attack"; }

int cmd_jab(string str) {
    object tp, ob;
    int i, which, skip, attack;
    object *inv;
    string what;
    string extra = "";
    int perc;

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
    
    if (str) ob = present(str, environment(tp));
    else ob = tp->query_current_attacker();

    if (!ob) return notify_fail("Jab who?\n");
    
    if(!living(ob)) {
        notify_fail(ob->query_cap_name()+" is not a living thing!\n");
        return 0;
    }
    
    if(ob==tp)
        return notify_fail("Jab yourself?\n");

    if(ob->is_player() && !interactive(ob))
        return notify_fail("You cannot attack link-dead players.\n");
    
    if(environment(tp)->query_property("no attack"))
        return notify_fail("Some force prevents your violence.\n");

    attack = BALANCE3_D->get_damage( tp, ob, 1, ({ "melee", "attack", "attack" }),
        ({ "dexterity", "strength", "strength" }), ({"dexterity", "strength"}) );
    
    attack = attack*7/10;
    if(attack < 10) attack = 10+random(5);
    if(attack > 120) attack = 120 + tp->query_level();

    if(!this_player()->kill_ob(ob))
        return notify_fail(ob->query_cap_name()+" can't be attacked by you yet.\n");
    
    if (tp->query_subclass() == "monk") {
      perc = COMBAT_D->combo(tp, "jab");
      attack = attack * perc / 100;
      if (perc > 100)
        extra = " "+COLC+"swiftly"+RES;
    }
    
    message("combat", "You "+COL2+"j"+COL+"a"+COL2+"b"+RES+" "+ob->query_cap_name()+
                      extra+" with your fist!", tp);
    message("combat", tp->query_cap_name()+" "+COL2+"j"+COL+"a"+COL2+"b"+COL+"s"+RES+
                      " you"+extra+" with "+tp->query_possessive()+" fist!", ob);
    message("combat", tp->query_cap_name()+" "+COL2+"j"+COL+"a"+COL2+"b"+COL+"s"+RES+
                      " "+ob->query_cap_name()+extra+" with "+tp->query_possessive()+" fist!",
                        environment(tp), ({tp, ob}) );
    
    ob->do_damage("target", attack, tp->query_unarmed_damage_type(), tp->query_unarmed_damage_flags(), tp);
    
    tp->add_skill_points("attack", attack/20 + 2);
    tp->add_skill_points("melee", attack/20 + 2);
    
//    tp->add_sp(-(this_player()->query_skill("attack")/7 + (1+random(this_player()->query_stats("strength")/3))));
    tp->add_sp(-1 * BALANCE3_D->get_cost(attack, 1, "sp"));
    
    tp->set_disable();
    
    return 1;
}

