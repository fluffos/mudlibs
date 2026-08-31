#include <daemons.h>
#include <std.h>
inherit DAEMON;

int abil();
string type() { return "attack"; }
int get_damage(object, object);
void Bmess(object, object);

int cmd_headbutt(string str) {
    object tp, ob, wep;
    int i, which, skip, attack;
    object *inv, *wield, *melees;
    string what;    
    melees = ({});

   	if (!abil())
      	return 0;

    tp = this_player();

    if(tp->query_ghost())
        return notify_fail("You emit a ghostly moan.\n");
    
    if (tp->query_disable() || tp->query_magic_round())
        return notify_fail("You are too busy to perform that move!\n");
    
    if(environment(tp)->query_property("no attack"))
        return notify_fail("Some strange force prevents your attack.\n");
    
    if(tp->query_casting()) return notify_fail("You are casting a spell!");

    if (tp->query_rest_type())
      return notify_fail("You must stand up first.\n");
    
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
        return notify_fail("Headbutt yourself?\n");

    if(ob->is_player() && !interactive(ob))
        return notify_fail("You cannot attack link-dead players.\n");

	if(!this_player()->kill_ob(ob))
        return notify_fail(ob->query_cap_name()+" can't be attacked by you yet.\n");

	attack = get_damage(tp, ob);
    
    if(attack < 10) attack = 15 +random(5);

    Bmess(tp, ob);

    ob->damage(attack);
    
    tp->add_sp(-(this_player()->query_skill("attack")/7 + (1+random(this_player()->query_stats("strength")/3))));
    
    tp->set_disable();
    
    return 1;
}

void Bmess(object tp, object ob)
{	
    write("%^BOLD%^You %^RED%^g%^WHITE%^ra%^RED%^b%^WHITE%^ "
    	+ob->query_cap_name()+
    	" and %^RED%^smash%^WHITE%^ "
    	+ob->query_objective()+
    	" with a %^BLACK%^h%^YELLOW%^e%^BLACK%^a%^YELLOW%^d%^BLACK%^b%^YELLOW%^u%^BLACK%^t%^YELLOW%^t%^WHITE%^!"
	);
	
	message("target", "%^BOLD%^"
		+tp->query_cap_name()+
		" %^RED%^g%^WHITE%^r%^RED%^a%^WHITE%^b%^RED%^s%^WHITE%^ "
		+ob->query_cap_name()+
		" and %^RED%^smashes%^WHITE%^ "
		+ob->query_objective()+
		" with a %^BLACK%^h%^YELLOW%^e%^BLACK%^a%^YELLOW%^d%^BLACK%^b%^YELLOW%^u%^BLACK%^t%^YELLOW%^t%^WHITE%^!"
		, environment(tp), ({tp,ob}));

	
	message("room", "%^BOLD%^"
		+tp->query_cap_name()+
		" %^RED%^g%^WHITE%^r%^RED%^a%^WHITE%^b%^RED%^s%^WHITE%^ you and %^BLACK%^h%^YELLOW%^e%^BLACK%^a%^YELLOW%^d%^BLACK%^b%^YELLOW%^u%^BLACK%^t%^YELLOW%^t%^BLACK%^s%^WHITE%^ you fiercly!"
		,ob);

}

int get_damage(object tp, object ob)
{
	string subskill = "valor";
	int attack = 0;
	int melee;
	melee = tp->query_skill("melee");
	
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
			({ "melee", "attack", subskill }),
        	({ "dexterity", "strength", "strength" }), 
			({ "dexterity", "strength" }) );
		attack = attack * 1.1;
	    if(attack > 200) attack = 200 + tp->query_level();
	}
	if(tp->query_level() >= 10 && tp->query_level() < 20)	
	{
    	attack = BALANCE2_D->get_Pdamage( tp, ob, 1, 
			({ "melee", "attack", subskill }),
        	({ "dexterity", "strength", "strength" }), 
			({ "dexterity", "strength" }) );
		attack = attack * 1.2;
	    if(attack > 200) attack = 200 + tp->query_level();
	}
	if(melee >=100 && melee < 140)	
	{
    	attack = BALANCE2_D->get_Pdamage( tp, ob, 2, 
			({ "melee", "attack", subskill }),
        	({ "dexterity", "strength", "strength" }), 
			({ "dexterity", "strength" }) );
	}	
	if(melee >= 140 && melee < 190)	
	{
    	attack = BALANCE2_D->get_Pdamage( tp, ob, 1, 
			({ "melee", "attack", subskill }),
        	({ "dexterity", "strength", "strength" }), 
			({ "dexterity", "strength" }) );
		attack = attack * 1.1;
	}
	if(melee >= 190 && melee < 250)	
	{
    	attack = BALANCE2_D->get_Pdamage( tp, ob, 1, 
			({ "melee", "attack", subskill }),
        	({ "dexterity", "strength", "strength" }), 
			({ "dexterity", "strength" }) );
		attack = attack * 1.2;
	}
	if(melee >= 250 && melee < 325)	
	{
    	attack = BALANCE2_D->get_Pdamage( tp, ob, 1, 
			({ "melee", "attack", subskill }),
        	({ "dexterity", "strength", "strength" }), 
			({ "dexterity", "strength" }) );
		attack = attack * 1.3;
	}
	if(melee >= 325 && melee < 500)	
	{
    	attack = BALANCE2_D->get_Pdamage( tp, ob, 1, 
			({ "melee", "attack", subskill }),
        	({ "dexterity", "strength", "strength" }), 
			({ "dexterity", "strength" }) );
		attack = attack * 1.4;
	}
	if(melee >= 500)	
	{
    	attack = BALANCE2_D->get_Pdamage( tp, ob, 1, 
			({ "melee", "attack", subskill }),
        	({ "dexterity", "strength", "strength" }), 
			({ "dexterity", "strength" }) );
		attack = attack * 1.5;
	}
	
	tp->add_skill_points("attack", attack/20 + 2);
    tp->add_skill_points("melee", attack/20 + 2);
    tp->add_skill_points(subskill, attack/20 + 2);

	return attack;
}

void help() {
    write("Syntax: <headbutt [(living)]>\n"
        "Someone skilled in physical combat can unleash "
        "a furious headbutt on the target.\n");
}
int abil() {
    object tp;
    tp = this_player();
    if (!tp) return 0;
    if (tp->query_skill("attack") < 25) return 0;
    if (tp->query_skill("melee") < 25) return 0;
    
    return 1;
}

