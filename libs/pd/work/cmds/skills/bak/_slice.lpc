#include <daemons.h>
#include <std.h>
inherit DAEMON;

int abil();

string type() { return "attack"; }

int cmd_slice(string str) {
    object tp, ob;
    int i, which, skip, attack;
    object *inv, *wield, *knives;
    string what;    
    knives = ({});


   	if (!abil())
      	return 0;

    tp = this_player();

    if(tp->query_ghost())
        return notify_fail("You emit a ghostly moan.\n");
    
    if (tp->query_disable())
        return notify_fail("You are too busy to slice your opponent!\n");
    
    if(environment(tp)->query_property("no attack"))
        return notify_fail("Some strange force prevents your attack.\n");
    
    if(tp->query_casting()) return notify_fail("You are casting a spell!");
    
    if(tp->query_sp() < 15) 
        return notify_fail("You are too tired!\n");
    
    if(!str) {
        ob = (object)tp->query_current_attacker();
        if(!ob) {
            return notify_fail("Slice who?\n");
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
        return notify_fail("Slice yourself? But you have so much to live for!\n");

    if(ob->is_player() && !interactive(ob))
        return notify_fail("You cannot attack link-dead players.\n");
    
    if(environment(tp)->query_property("no attack"))
        return notify_fail("Some strange force prevents your attack!\n");
	
	wield = tp->query_wielded();
	
	if(!wield)
        return notify_fail("You need a weapon to slice with!\n");
    
	i = sizeof(wield);
    while (i--) {
        if(wield[i]->query_type() == "knife")
            knives  += ({ wield[i] });
   	}
	if(sizeof(knives) < 2)    	
	    return notify_fail("You need two knives to slice with!\n");

    attack = BALANCE2_D->get_Pdamage( tp, ob, 1, 
		({ "knife", "perception", "double wielding", "attack" }),
        ({ "dexterity", "dexterity", "strength" }), 
		({ "dexterity", "strength" }) );
    
    attack = attack * 1.1;
    
    if(attack < 10) attack = 15 +random(5);
    if(attack > 150) attack = 150 + tp->query_level();

    attack = attack + (knives[0]->query_wc()*3/2) + (knives[1]->query_wc()*3/2);
    
    if(!this_player()->kill_ob(ob))
        return notify_fail(ob->query_cap_name()+" can't be attacked by you yet.\n");
    
    write("%^BOLD%^You %^CYAN%^swing%^WHITE%^ your "
		+knives[0]->query_name()+
		" at "
		+ob->query_cap_name()+
		", %^BLUE%^spin%^WHITE%^ around and %^RED%^s%^RESET%^%^RED%^l%^BOLD%^%^RED%^i%^RESET%^%^RED%^c%^BOLD%^%^RED%^e%^WHITE%^ "
		+ob->query_objective()+
		" with your "
		+knives[1]->query_name()+
	 	"!%^RESET%^");
    
    message("room","%^BOLD%^"+tp->query_cap_name()+
		" %^CYAN%^swings%^WHITE%^ "
		+tp->query_possessive()+
		" "
		+knives[0]->query_name()+
		" at "
		+ob->query_cap_name()+
		", %^BLUE%^spins%^WHITE%^ around and %^RED%^s%^RESET%^%^RED%^l%^BOLD%^%^RED%^i%^RESET%^%^RED%^c%^BOLD%^%^RED%^e%^RESET%^%^RED%^s%^BOLD%^%^WHITE%^ "
		+ob->query_objective()+
		" with "
		+tp->query_possessive()+
		" "
		+knives[1]->query_name()+
		"!%^RESET%^", environment(tp), ({tp,ob}));            
    
    message("ob", "%^BOLD%^"+tp->query_cap_name()+ 
		" %^CYAN%^swings%^WHITE%^ at you with "
	    +tp->query_possessive()+
    	" "
	    +knives[0]->query_name()+
    	", %^BLUE%^spins%^WHITE%^ around and %^RED%^s%^RESET%^%^RED%^l%^BOLD%^%^RED%^i%^RESET%^%^RED%^c%^BOLD%^%^RED%^e%^RESET%^%^RED%^s%^BOLD%^%^WHITE%^ you with "
		+tp->query_possessive()+
    	" "
	    +knives[1]->query_name()+   
    	"!%^RESET%^",ob);
    
    ob->damage(attack);
    
    tp->add_skill_points("attack", attack/20 + 2);
    tp->add_skill_points("knife", attack/20 + 2);
    tp->add_skill_points("perception", attack/20 + 2);
    tp->add_skill_points("double wielding", attack/20 + 2);
    
    tp->add_sp(-(this_player()->query_skill("attack")/7 + (1+random(this_player()->query_stats("strength")/3))));
    
    tp->set_disable();
    
    return 1;
}
void help() {
    write("Syntax: <slice [(living)]>\n"
        "Someone skilled with knives, and aware of their surroundings "
        "can slice at their opponent with both of their knives.\n");
}
int abil() {
    object tp;
    tp = this_player();
    if (!tp) return 0;
    if (tp->query_class() != "rogue") return 0;
    if (tp->query_skill("double wielding") < 18) return 0;
    if (tp->query_skill("knife") < 18) return 0;
    if (tp->query_skill("perception") < 18) return 0;
    return 1;
}

