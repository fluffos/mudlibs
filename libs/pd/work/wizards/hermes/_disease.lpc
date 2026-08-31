#include <std.h>
inherit DAEMON;
int spell();
int spell_hit(object ob, tp, int attack);
int rounds;
int cmd_disease(string str) 
{
	object tp, ob;
	int attack, wisdom, skip, which, i;
	string what, *strengths, *weaknesses;
	object *inv;
	if (!spell()) 
	{
		write("What?\n");
		return 1;
	}
	new("/wizards/hermes/nocast")->move(this_player());
	if (this_player()->query_arena()==1)
	{
		return notify_fail("That's not very nice.\n");
	}
	this_player()->set_magic_round(1);
	tp = this_player();
	if(tp->query_ghost()) 
	{
		notify_fail("Your voice is hollow.\n");
		return 0;
	}
	if (this_player()->query_disable())
		return notify_fail("You are busy.\n");
	if(environment(tp)->query_property("no magic")) 
	{
		notify_fail("Something seems to be blocking your concentration.\n");
		return 0;
	}

	if((int)tp->query_mp() < 150) 
	{
		notify_fail("Too low on magic power.\n");
		return 0;
	}

	if(!str) 
	{
		ob = (object)tp->query_current_attacker();
		if(!ob) 
		{
			notify_fail("Who do you wish to infect?\n");
			return 0;
		}
	}

	else 
	{
		ob = present(str, environment(tp));
		if(!ob) 
		{
			sscanf(str, "%s %d", what, which);
			inv = all_inventory(environment(tp));
			for(i=0, skip = 0; i<sizeof(inv) && !ob; i++) 
			{
	  		  if(inv[i]->id(what)) 
	  		  {	
	  		  	skip++;
	        	if(skip == which) ob = inv[i];
	          }
			}
			if(!ob) 
			{
	   		 	notify_fail("No "+str+" here!\n");
	    		return 0;
			}
		}
	}

	if(!living(ob)) 
	{
		notify_fail(ob->query_cap_name()+" is not a living thing!\n");
		return 0;
	}
	if(ob == tp) 
	{
		notify_fail("How horrid.\n");
		return 0;
	}

	if(ob->is_player() && !interactive(ob)) 
	{
		notify_fail("You cannot attack link-dead players.\n");
		return 0;
	}

	if(!this_player()->kill_ob(ob)) 
	{
		write(ob->query_cap_name()+" can't be attacked by you yet.");
		return 1;
	}
	tp->force_me("say %^BLACK%^%^BOLD%^May your skin rot and your bones break!\n");
	tp->set_paralyzed(1, "You are making sure that the infection is complete.");            
	//*************************DAMAGE**********************************
	
	attack = ((int)tp->query_stats("wisdom") + (int)tp->query_skill("faith")*2/3 + (int)tp->query_skill("necromancy")*3/2);
	wisdom = ((int)ob->query_stats("wisdom")/2 + (int)ob->query_skill("magic defense")/3);
	attack -= wisdom;
if (attack > 200)
attack = 200;
	if(attack > 75 && !ob->is_monster())
	attack = 75;

	//*************************DAMAGE**********************************
	write("%^BOLD%^As you hold out your fingers, a stream of %^RESET%^%^GREEN%^green%^RESET%^%^BLUE%^ liquid%^RESET%^%^BOLD%^ is absorbed by " + ob->query_cap_name() + "'s skin turning " + ob->query_possessive() + " face green.");
	rounds = tp->query_level()/5; 

	tell_room(environment(tp), ""+tp->query_cap_name()+" points at "+(string)ob->query_cap_name()+" and a thick, disgusting looking stream of %^GREEN%^green %^BLUE%^liquid%^RESET%^ shoots from "+tp->query_possessive() +" fingers!", 
	({ ob, tp }));
	tell_object(ob, ""+tp->query_cap_name()+
	" points at you and sends a stream of %^GREEN%^green%^BLUE%^ liquid%^RESET%^ at you.  You immediatly feel more sick then you ever have.  Your insides churn as if you're being eaten from the inside out.");
	ob->add_hp(-attack);
	ob->add_poisoning(-attack/8);
	tp->add_skill_points("faith", (attack/20));


	tp->add_skill_points("faith", (attack/20));
	tp->add_alignment(-100);
	tp->add_skill_points("necromancy", (attack/20));
	tp->add_mp(-(250 + random(150)));

	if (rounds > 0)
	{
	--rounds;
	if(!ob) 
	{       
	return 1;
	}
	call_out("spell_hit",2, ob, tp, attack);
	}
	return 1;
	}
	void help() 
	{
	write("Syntax: <disease [(living)]>\n"
	"This spell, used by those of great evil, infects "
	"their victims with a horrible disease."
	"\n");
}
int spell() {
object tp, ob;
tp = this_player();
if (!tp) return 0;
if (tp->query_subclass() != "necromancer" &&
tp->query_subclass() != "kataan") return 0;
if (tp->query_level() < 35) return 0;
return 1;
}
int spell_hit(object ob, tp, attack ) 
{
	if(!ob) 
	{       
	return 1;
	}
	
	if(environment(ob) != environment(tp))
	{
		return 1;
	}
tell_object(ob, "You stumble, trying to keep your balance even as your body churns inside of you.");

tell_room(environment(ob), "%^GREEN%^%^BOLD%^"+ob->query_cap_name()+" falls to one knee, %^BLACK%^coughing%^GREEN%^ up %^RED%^blood%^GREEN%^ as " + ob->query_possessive() + " skin starts to turn a chalky %^WHITE%^white%^GREEN%^ from the ravishings of the disease.");  
ob->add_hp(-attack);


ob->add_hp(-attack);
if (rounds > 0)
{
--rounds;
call_out("spell_hit",2, ob, tp, attack);
}
return 1;
}
