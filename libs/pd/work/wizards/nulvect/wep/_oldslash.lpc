#include <daemons.h>
#include <std.h>
inherit DAEMON;

int abil();
int get_damage(object, object);
void Bmess(object, object, object);

int cmd_oldslash(string str) {
    object tp, ob, wep;
    int i, which, skip, attack;
    object *inv, *wield, *swords;
    string what;    
    swords = ({});

   	if (!abil())
      	return 0;

    tp = this_player();

    if(tp->query_ghost())
        return notify_fail("You emit a ghostly moan.\n");
    
    if (tp->query_disable())
        return notify_fail("You are too busy to perform that move!\n");
    
    if(environment(tp)->query_property("no attack"))
        return notify_fail("Some strange force prevents your attack.\n");
    
    if(tp->query_casting()) return notify_fail("You are casting a spell!");
    
    if(tp->query_sp() < 15) 
        return notify_fail("You are too tired!\n");
    
    if(!str) {
        ob = (object)tp->query_current_attacker();
        if(!ob) {
            return notify_fail("Who?\n");
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
        return notify_fail("Slash yourself?\n");

    if(ob->is_player() && !interactive(ob))
        return notify_fail("You cannot attack link-dead players.\n");

	if(!this_player()->kill_ob(ob))
        return notify_fail(ob->query_cap_name()+" can't be attacked by you yet.\n");
	
	wield = tp->query_wielded();
	
	if(!sizeof(wield))
        return notify_fail("You need a blade to slash with!\n");
    
	i = sizeof(wield);
    while (i--) {
        if(wield[i]->query_type() == "blade")
            swords  += ({ wield[i] });
   	}
   	
	if(!sizeof(swords) )    	
	    return notify_fail("You need blade to slash with!\n");

	wep = swords[0];
	i = sizeof(swords);
	while(i--){
		if(swords[i]->query_wc() > wep->query_wc())
			wep = swords[i];
	}

	attack = get_damage(tp, ob);
    
    if(attack < 10) attack = 15 +random(5);

    attack = attack + (wep->query_wc()*2);

    Bmess(tp, ob, wep);

    ob->damage(attack);
    
    tp->add_sp(-(this_player()->query_skill("attack")/7 + (1+random(this_player()->query_stats("strength")/3))));
    
    tp->set_disable();
    
    return 1;
}

void Bmess(object tp, object ob, object wep)
{
	int blade;
	
	blade = tp->query_skill("blade");
	
    write("%^BOLD%^You %^BLUE%^s%^WHITE%^w%^BLUE%^i%^WHITE%^n%^BLUE%^g%^WHITE%^ your "
    	+wep->query_name()+
    	" at "
    	+ob->query_cap_name()+
    	", %^RED%^s%^RESET%^%^RED%^l%^BOLD%^a%^RESET%^%^RED%^s%^BOLD%^h%^RESET%^%^RED%^i%^BOLD%^n%^RESET%^%^RED%^g%^BOLD%^%^WHITE%^ "
    	+ob->query_objective()+
    	" in the "
    	+ob->return_target_limb()+
    	"!"
	);
	
	message("target", "%^BOLD%^"
		+tp->query_cap_name()+
		" %^BLUE%^s%^WHITE%^w%^BLUE%^i%^WHITE%^n%^BLUE%^g%^WHITE%^s "
		+tp->query_possessive()+
		" "
		+wep->query_name()+
		" at you, %^RED%^s%^RESET%^%^RED%^l%^BOLD%^a%^RESET%^%^RED%^s%^BOLD%^h%^RESET%^%^RED%^i%^BOLD%^n%^RESET%^%^RED%^g%^BOLD%^%^WHITE%^ you in the "
    	+ob->return_target_limb()+
    	"!"				
		,ob);
	
	message("room", "%^BOLD%^"
		+tp->query_cap_name()+
		" %^BLUE%^s%^WHITE%^w%^BLUE%^i%^WHITE%^n%^BLUE%^g%^WHITE%^s "
		+tp->query_possessive()+
		" "
		+wep->query_name()+
		" at "
		+ob->query_cap_name()+
		", %^RED%^s%^RESET%^%^RED%^l%^BOLD%^a%^RESET%^%^RED%^s%^BOLD%^h%^RESET%^%^RED%^i%^BOLD%^n%^RESET%^%^RED%^g%^BOLD%^%^WHITE%^ "
		+ob->query_objective()+
    	" in the "
    	+ob->return_target_limb()+
    	"!"
		, environment(tp), ({tp,ob}));

	if(blade >= 140)	
	{
		write("%^BOLD%^You %^BLACK%^s%^WHITE%^w%^BLACK%^i%^WHITE%^n%^BLACK%^g%^WHITE%^ around and get in another %^RED%^h%^RESET%^%^RED%^i%^BOLD%^t%^WHITE%^!");
		message("target", "%^BOLD%^"
			+tp->query_cap_name()+
			" %^BLACK%^s%^WHITE%^w%^BLACK%^i%^WHITE%^n%^BLACK%^g%^WHITE%^s around and %^RED%^h%^RESET%^%^RED%^i%^BOLD%^t%^RESET%^%^RED%^s%^BOLD%^%^WHITE%^ you again!"
			,ob);
		message("room", "%^BOLD%^"
			+tp->query_cap_name()+
			" %^BLACK%^s%^WHITE%^w%^BLACK%^i%^WHITE%^n%^BLACK%^g%^WHITE%^s around and gets in another %^RED%^h%^RESET%^%^RED%^i%^BOLD%^t%^WHITE%^!"						
			, environment(tp), ({tp,ob}));
	}
	if(blade >= 190 )	
	{
		write("%^BOLD%^You %^BLACK%^s%^WHITE%^w%^BLACK%^i%^WHITE%^n%^BLACK%^g%^WHITE%^ around and get in another %^RED%^h%^RESET%^%^RED%^i%^BOLD%^t%^WHITE%^!");
		message("target", "%^BOLD%^"
			+tp->query_cap_name()+
			" %^BLACK%^s%^WHITE%^w%^BLACK%^i%^WHITE%^n%^BLACK%^g%^WHITE%^s around and %^RED%^h%^RESET%^%^RED%^i%^BOLD%^t%^RESET%^%^RED%^s%^BOLD%^%^WHITE%^ you again!"
			,ob);
		message("room", "%^BOLD%^"
			+tp->query_cap_name()+
			" %^BLACK%^s%^WHITE%^w%^BLACK%^i%^WHITE%^n%^BLACK%^g%^WHITE%^s around and gets in another %^RED%^h%^RESET%^%^RED%^i%^BOLD%^t%^WHITE%^!"						
			, environment(tp), ({tp,ob}));
	}		
	if(blade >= 250)	
	{
		write("%^BOLD%^You %^BLACK%^s%^WHITE%^w%^BLACK%^i%^WHITE%^n%^BLACK%^g%^WHITE%^ around and get in another %^RED%^h%^RESET%^%^RED%^i%^BOLD%^t%^WHITE%^!");
		message("target", "%^BOLD%^"
			+tp->query_cap_name()+
			" %^BLACK%^s%^WHITE%^w%^BLACK%^i%^WHITE%^n%^BLACK%^g%^WHITE%^s around and %^RED%^h%^RESET%^%^RED%^i%^BOLD%^t%^RESET%^%^RED%^s%^BOLD%^%^WHITE%^ you again!"
			,ob);
		message("room", "%^BOLD%^"
			+tp->query_cap_name()+
			" %^BLACK%^s%^WHITE%^w%^BLACK%^i%^WHITE%^n%^BLACK%^g%^WHITE%^s around and gets in another %^RED%^h%^RESET%^%^RED%^i%^BOLD%^t%^WHITE%^!"						
			, environment(tp), ({tp,ob}));
	}		
	if(blade >= 325)	
	{
		write("%^BOLD%^You %^BLACK%^s%^WHITE%^w%^BLACK%^i%^WHITE%^n%^BLACK%^g%^WHITE%^ around and get in another %^RED%^h%^RESET%^%^RED%^i%^BOLD%^t%^WHITE%^!");
		message("target", "%^BOLD%^"
			+tp->query_cap_name()+
			" %^BLACK%^s%^WHITE%^w%^BLACK%^i%^WHITE%^n%^BLACK%^g%^WHITE%^s around and %^RED%^h%^RESET%^%^RED%^i%^BOLD%^t%^RESET%^%^RED%^s%^BOLD%^%^WHITE%^ you again!"
			,ob);
		message("room", "%^BOLD%^"
			+tp->query_cap_name()+
			" %^BLACK%^s%^WHITE%^w%^BLACK%^i%^WHITE%^n%^BLACK%^g%^WHITE%^s around and gets in another %^RED%^h%^RESET%^%^RED%^i%^BOLD%^t%^WHITE%^!"						
			, environment(tp), ({tp,ob}));
	}		
	if(blade >= 500)	
	{
		write("%^BOLD%^You %^BLACK%^s%^WHITE%^w%^BLACK%^i%^WHITE%^n%^BLACK%^g%^WHITE%^ around and get in another %^RED%^h%^RESET%^%^RED%^i%^BOLD%^t%^WHITE%^!");
		message("target", "%^BOLD%^"
			+tp->query_cap_name()+
			" %^BLACK%^s%^WHITE%^w%^BLACK%^i%^WHITE%^n%^BLACK%^g%^WHITE%^s around and %^RED%^h%^RESET%^%^RED%^i%^BOLD%^t%^RESET%^%^RED%^s%^BOLD%^%^WHITE%^ you again!"
			,ob);
		message("room", "%^BOLD%^"
			+tp->query_cap_name()+
			" %^BLACK%^s%^WHITE%^w%^BLACK%^i%^WHITE%^n%^BLACK%^g%^WHITE%^s around and gets in another %^RED%^h%^RESET%^%^RED%^i%^BOLD%^t%^WHITE%^!"						
			, environment(tp), ({tp,ob}));
	}		
}

int get_damage(object tp, object ob)
{
	string subskill = "valor";
	int attack = 0;
	int blade;
	blade = tp->query_skill("blade");
	
	if(tp->query_subclass() == "paladin")
		subskill = "valor";
	if(tp->query_subclass() == "warrior")
		subskill = "discipline";	
	if(tp->query_subclass() == "ranger")
		subskill = "discipline";
	if(tp->query_subclass() == "berserker")
		subskill = "ferocity";
	if(tp->query_subclass() == "antipaladin")
		subskill = "ferocity";
		
	if(tp->query_level() < 10)
	{
    	attack = BALANCE2_D->get_Pdamage( tp, ob, 1, 
			({ "blade", "attack", subskill }),
        	({ "dexterity", "strength", "strength" }), 
			({ "dexterity", "strength" }) );
		attack = attack * 1.1;
	    if(attack > 200) attack = 200 + tp->query_level();
	}
	if(tp->query_level() >= 10 && tp->query_level() < 20)	
	{
    	attack = BALANCE2_D->get_Pdamage( tp, ob, 1, 
			({ "blade", "attack", subskill }),
        	({ "dexterity", "strength", "strength" }), 
			({ "dexterity", "strength" }) );
		attack = attack * 1.2;
	    if(attack > 150) attack = 150 + tp->query_level();
	}
	if(blade >=100 && blade < 140)	
	{
    	attack = BALANCE2_D->get_Pdamage( tp, ob, 2, 
			({ "blade", "attack", subskill }),
        	({ "dexterity", "strength", "strength" }), 
			({ "dexterity", "strength" }) );
	}	
	if(blade >= 140 && blade < 190)	
	{
    	attack = BALANCE2_D->get_Pdamage( tp, ob, 2, 
			({ "blade", "attack", subskill }),
        	({ "dexterity", "strength", "strength" }), 
			({ "dexterity", "strength" }) );
		attack = attack * 1.1;
	}
	if(blade >= 190 && blade < 250)	
	{
    	attack = BALANCE2_D->get_Pdamage( tp, ob, 2, 
			({ "blade", "attack", subskill }),
        	({ "dexterity", "strength", "strength" }), 
			({ "dexterity", "strength" }) );
		attack = attack * 1.2;
	}
	if(blade >= 250 && blade < 325)	
	{
    	attack = BALANCE2_D->get_Pdamage( tp, ob, 2, 
			({ "blade", "attack", subskill }),
        	({ "dexterity", "strength", "strength" }), 
			({ "dexterity", "strength" }) );
		attack = attack * 1.3;
	}
	if(blade >= 325 && blade < 500)	
	{
    	attack = BALANCE2_D->get_Pdamage( tp, ob, 2, 
			({ "blade", "attack", subskill }),
        	({ "dexterity", "strength", "strength" }), 
			({ "dexterity", "strength" }) );
		attack = attack * 1.4;
	}
	if(blade >= 500)	
	{
    	attack = BALANCE2_D->get_Pdamage( tp, ob, 2, 
			({ "blade", "attack", subskill }),
        	({ "dexterity", "strength", "strength" }), 
			({ "dexterity", "strength" }) );
		attack = attack * 1.5;
	}
	
	tp->add_skill_points("attack", attack/20 + 2);
    tp->add_skill_points("blade", attack/20 + 2);
    tp->add_skill_points(subskill, attack/20 + 2);

	return attack;
}

void help() {
    write("Syntax: <slash [(living)]>\n"
        "Those trained in the skill of blades can "
		"slash at their target with their sword.\n");
}
int abil() {
    object tp;
    tp = this_player();
    if (!tp) return 0;
    if (tp->query_skill("attack") < 25) return 0;
    if (tp->query_skill("blade") < 25) return 0;
    
    return 1;
}

