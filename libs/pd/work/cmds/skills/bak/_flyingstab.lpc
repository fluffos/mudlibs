#include <std.h>
#include <rest.h>
#include <daemons.h>

inherit DAEMON;

int abil();

string type() { return "attack"; }

int cmd_flyingstab(string str) {
    object victim, rm, tp;
    object startroom;
    string dir, mob, *dirlist;
    int i, tmp;
	object *wield, *knives;    
    knives = ({});
    
    if (!abil()) 
        return notify_fail("What?\n");

	tp = this_player();
	
    if(!str)
        return notify_fail("Flyingstab whom?\n");
        
    if(!sizeof(dirlist = environment(tp)->query_exits()))
    	return notify_fail("There is no way out of here!.\n");

    if(sscanf(str, "%s %s" , mob, dir ) != 2)
		return notify_fail("Syntax: flyingstab <target> <direction>\n");	
    
   	if(member_array(dir, dirlist) == -1)
		return notify_fail("That is not a direction!\n");
    
    if(dir != "north" && dir != "northeast" && dir != "east"
    	&& dir != "southeast" && dir != "south" && dir != "southwest"
    	&& dir != "west" && dir != "northwest")
			return notify_fail("You can not jump in that direction!\n");	
	
	if(!(rm = find_object(environment(tp)->query_exit(dir))))
      	return notify_fail("You cannot jump in that direction.\n");

	if(!(victim = present(mob, rm)))
		return notify_fail("That doesn't seem to be "+dir+".\n");

    if (tp->query_rest_type())
        return notify_fail("You are not in a position to perform that action\n");

    if(tp->query_ghost())
        return notify_fail("You appear to be dead.\n");

    if(tp->query_disable()) 
		return notify_fail("You are busy.\n");
    
    if(environment(tp)->query_property("no attack"))
        return notify_fail("Some mystical force prevents you from that.\n");

    if(tp->query_sp() < 25)
        return notify_fail("You are too tired to jump to the next room.\n");
        
    if(victim == tp)
        return notify_fail("This seems impossible, tell an imm.\n");

    if(!living(victim))
        return notify_fail("You can not stab that.\n");
	
	wield = tp->query_wielded();
	
	if(!wield)
        return notify_fail("You need a weapon to slice with!\n");
    
	i = sizeof(wield);
    while (i--) {
        if(wield[i]->query_type() == "knife")
            knives  += ({ wield[i] });
   	}
	if(sizeof(knives) < 2)    	
	    return notify_fail("You need two knives to perform this move with!\n");

	
	/*
    if(member_array(victim, (object *)this_player()->query_hunted()) != -1 ||
        member_array(victim, (object *)this_player()->query_attackers())!=-1) {
            return notify_fail("You have lost the element of surprise!\n");
    }
    Leaving this out for now.
    */
    
    if(tp->query_current_attacker())
        return notify_fail("You are already in combat with something else!\n");
    
    if(victim->is_player() && !interactive(victim)) return 0;
    
    tp->set_disable();

    startroom=environment(tp);
    
    tp->set_paralyzed(2,"You are concentrating on your jump.");
    
    write("%^BOLD%^You start running to the %^GREEN%^"+dir+"%^RESET%^!%^RESET%^");
    message("room", "%^BOLD%^"+tp->query_cap_name()+
    	" sprints to the %^GREEN%^"+dir+"%^RESET%^!%^RESET%^", environment(tp), tp);
    
    call_out("do_jump", 1, ({victim, tp, rm, dir, knives, startroom}) );
    
    return 1;
}

int do_jump(mixed *args)
{

  object victim=args[0];
  object tp=args[1];
  object rm=args[2];
  string dir=args[3];
  object *knives=args[4];
  object startroom=args[5];

	if(!tp)
		return 1;
	if(!victim)
		return notify_fail("Your target seems to be gone!\n");
	if(!rm)
		return notify_fail("Umm..... the room is gone.... tell an imm.");
		
	write("%^BOLD%^You jump off the ground and fly to the %^GREEN%^"+dir+"%^RESET%^!%^RESET%^\n");
	message("room", "%^BOLD%^"+tp->query_cap_name()+
		" jumps off the ground and flys to the %^GREEN%^"+dir+"%^RESET%^!%^RESET%^"
		, environment(tp), tp);
	call_out("do_dmg", 1, ({victim, tp, rm, knives, startroom}) );
}


int do_dmg(mixed *args) {
    int i, tmp, dex;
    string tt, tk;
    int j, spUse;

  object victim=args[0];
  object tp=args[1];
  object rm=args[2];
  object *knives=args[3];
  object startroom=args[4];
    
    if(!rm)
    	return notify_fail("Umm..... the room is gone.... tell an imm.");
    	
  if (environment(tp) != startroom) {
    message("room","Your jump attack was interrupted.",tp);
    return 1;
  }

    tp->move(rm);

    
    write("%^BOLD%^You %^BLUE%^fly%^WHITE%^ into the room!%^RESET%^");
    message("room", "%^BOLD%^" +tp->query_cap_name()+
    	" comes %^BLUE%^flying%^WHITE%^ into the room!", environment(tp), tp);
    
    if (!victim)
        return notify_fail("Your target is gone.");
    
    if (environment(tp) != environment(victim))
        return notify_fail("Your target is not here!\n");
    
    if(environment(tp)->query_property("no attack") 
		|| environment(tp)->query_property("safe"))
    {
		write("You fall to the ground!");
		message("room", tp->query_cap_name()+ " falls to the ground!", environment(tp), tp);	
		return 1;
	}
    
    if(tp->query_attackers())
    {
		for(int q = 0; q < sizeof(tp->query_attackers()); q++)
		{
			if(victim == tp->query_attackers()[q])
			{
		        write("%^BOLD%^You miss your stab!%^RESET%^");
        		message("room","%^BOLD%^"+tp->query_cap_name()+" misses an attempt to stab "
            		+(string)victim->query_cap_name()+"!%^RESET%^", environment(tp),({tp,victim}));
		        tell_object(victim, "%^BOLD%^"+tp->query_cap_name()+" misses an attempt to stab you!");
        		return 1;	
			}	
		}	
	}
    
    if(!tp->kill_ob(victim)) 
	{
        write(victim->query_cap_name()+" can't be attacked by you yet.");
        return 1;
    }
    
    if (random(victim->query_stats("dexterity")/2) +
            (victim->query_stats("dexterity")/2) >
            tp->query_stats("dexterity") + 5 ) 
    {
        write("%^BOLD%^You miss your stab!%^RESET%^");
        message("room","%^BOLD%^"+tp->query_cap_name()+" misses an attempt to stab "
            +(string)victim->query_cap_name()+"!%^RESET%^", environment(tp),({tp,victim}));
        tell_object(victim, "%^BOLD%^"+tp->query_cap_name()+" misses an attempt to stab you!");
        return 1;
    }
    
    tt = victim->return_target_limb();
    
    write("%^BOLD%^You %^RED%^l%^RESET%^%^RED%^a%^BOLD%^n%^RESET%^%^RED%^d%^BOLD%^%^WHITE%^ your %^YELLOW%^stab%^WHITE%^ on "+victim->query_cap_name()+", %^RED%^p%^RESET%^%^RED%^u%^BOLD%^n%^RESET%^%^RED%^c%^BOLD%^t%^RESET%^%^RED%^u%^BOLD%^r%^RESET%^%^RED%^i%^BOLD%^n%^RESET%^%^RED%^g%^BOLD%^%^WHITE%^ "
		+victim->query_objective()+
		" in the "
		+victim->return_target_limb()+
		"!%^RESET%^");

    message("room","%^BOLD%^"+tp->query_cap_name() +" %^RED%^l%^RESET%^%^RED%^a%^BOLD%^n%^RESET%^%^RED%^d%^BOLD%^s%^WHITE%^ a %^BLACK%^d%^WHITE%^e%^BLACK%^a%^WHITE%^d%^BLACK%^l%^WHITE%^y %^RED%^stab%^WHITE%^ on "+victim->query_cap_name()+
    	", %^RED%^p%^RESET%^%^RED%^u%^BOLD%^n%^RESET%^%^RED%^c%^BOLD%^t%^RESET%^%^RED%^u%^BOLD%^r%^RESET%^%^RED%^i%^BOLD%^n%^RESET%^%^RED%^g%^BOLD%^%^WHITE%^ "
		+victim->query_objective()+
		" in the "
		+victim->return_target_limb()+
		"!%^RESET%^"
		, environment(tp), ({tp,victim}));
		
    tell_object(victim, "%^BOLD%^"
		+tp->query_cap_name()+
		" lands a %^BLACK%^d%^WHITE%^e%^BLACK%^a%^WHITE%^d%^BLACK%^l%^WHITE%^y %^RED%^stab%^WHITE%^ on you, %^RED%^p%^RESET%^%^RED%^u%^BOLD%^n%^RESET%^%^RED%^c%^BOLD%^t%^RESET%^%^RED%^u%^BOLD%^r%^RESET%^%^RED%^i%^BOLD%^n%^RESET%^%^RED%^g%^BOLD%^%^WHITE%^ you in the "
		+victim->return_target_limb()+
		"!%^RESET%^"
		);

    /****( Damage: )***********************************************/

	 j = BALANCE2_D->get_Pdamage( this_player(), victim, 1, ({ "attack", "perception", "perception", "knife" }),
            ({ "dexterity", "dexterity", "strength" }), ({"dexterity"}) );    
	 j = j * 2;
    /**************************************************************/

    if(j < 1) j = 1;

    j = j + (knives[0]->query_wc()*2) + (knives[1]->query_wc()*2);

	if(tp->query_subclass() != "scout")
		j = 2*j/3;

    tp->add_skill_points("attack", j/20);
    tp->add_skill_points("perception", j/20);
    tp->add_skill_points("knife", j/20);
	    
    victim->damage(j);
    
	tp->add_sp(-(tp->query_skill("perception")/5 + (1+random(tp->query_stats("dexterity")/3))));
    
    if(victim->query_hp() < 0)
        victim->heart_beat();
    return 1;
}

void help() {
    write("Syntax: flyingstab <enemy> <direction>\n\n"
      "Someone aware of their surroundings can leap at an enemy "
	  "from another area, landing a deadly stab if timed right.\n"
    );
}

int abil() {
    object tp;
    tp = this_player();
    if (tp->query_subclass() != "scout") return 0;
    if(tp->query_skill("perception") < 156) return 0;
    if(tp->query_skill("attack") < 130) return 0;
    if(tp->query_skill("knife") < 156) return 0;
    
    return 1;
}
