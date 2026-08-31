//     A rogue/fighter physical attack
//     Written by Forlock for the Nightmare lib.

#include <std.h>
#include <daemons.h>
int abil();
inherit DAEMON;

int cmd_whirl (string str) {


    int attack;
    object ob;
    object pyr;
    object room;
    object *a;
    int i;
    int x;

    pyr = (object)this_player();
    room = environment(pyr);
    a = all_inventory(room);

    if (!abil())
    {
	return 0;
    }

    if(!sizeof((object *)this_player()->query_wielded())) {
	notify_fail("You need a weapon to whirl with!\n");
	return 0;
    }

    if (this_player()->query_level() < 49)
    {

	if(!str)
	    ob = (object)this_player()->query_current_attacker();
	else {
	    ob = present(str, environment(this_player()));
	    if(!ob) ob = parse_objects(environment(this_player()), str);
	}
    }

    if (this_player()->query_level() < 49)
    {
	if(!ob || !living(ob)) {
	    notify_fail("That is not here as such.\n");
	    return 0;
	}
    }

    if (this_player()->query_level() < 49)
    {
	if(ob == this_player())
	    return notify_fail("Why would you want to do a thing like that?\n");
    }

    if(this_player()->query_ghost()) {
	notify_fail("You cannot attack without a body.\n");
	return 0;
    }

    if (this_player()->query_disable())
    {
	write("You are not balanced enough to whirl.");
	return 1;
    }

    if (this_player()->query_level() < 49)
    {
	if(this_player()->query_casting()) return 1;
	if(!this_player()->kill_ob(ob)) {
	    write(ob->query_cap_name()+" can't be attacked by you yet.");
	    return 1;
	}
    }

    if(environment(this_player())->query_property("no attack")) {
	notify_fail("A magic force prevents you from doing your attack.\n");
	return 0;
    }

    if((int)this_player()->query_sp() < 20) {
	notify_fail("You are too tired.\n");
	return 0;
    }

    this_player()->set_disable();
    this_player()->set_casting();

    // Edit by Venenum, adding extra hits to whirl.

    if (this_player()->query_level() < 49) 
    {
	x = (this_player()->query_level()/10) - 5; //Player gets +1 extra whirls for every 10 levels after 50. IE 60 gets 1 extra whirl, 70 gets two, etc.
	if (x > sizeof(a)) 
	{
	    x = sizeof(a);
	}
	for(i=0; i<x; i++) {
	    if (a[i]->query_name() != this_player()->query_name() && a[i]->is_living())
	    {
		if (i==0) 
		{
		    message("info", this_player()->query_cap_name()+" whirls at "+a[i]->query_cap_name()+".", this_player());
		    message("info", this_player()->query_cap_name()+" whirls at you.", this_player());
		    message("info", "You whirl at "+a[i]->query_cap_name()+"!", this_player());
		    attack = BALANCE_D->get_damage(this_player(), a[i], 1, ({ "attack" }),({ "strength" }) );
		    attack = attack -100;
		    this_player()->add_skill_points("attack", attack/20 + 5);
		    this_player()->add_sp(-(attack/8));
		}
		else
		{
		    message("info", this_player()->query_cap_name()+" nicks "+a[i]->query_cap_name()+".",room, a[i]);
		    message("info", this_player()->query_cap_name()+" nicks you.",a[i]);
		    message("info", "You nick "+a[i]->query_cap_name(),this_player());
		    attack = BALANCE_D->get_damage(this_player(), a[i], 1, ({ "attack" }),({ "strength" }) );
		    attack = (attack -100) / (i + 1);
		    this_player()->add_skill_points("attack", attack/20 + 5);
		    this_player()->add_sp(-(attack/8));
		}
		a[i]->damage(attack);
		this_player()->kill_ob(a[i]);
	    }
	}
    }
    else
    {
	write("You whirl at "+ob->query_cap_name()+"!\n");
	attack = BALANCE_D->get_damage( this_player(), ob, 1, ({ "attack" }),({ "strength" }) );
	if (attack < 5)
	    return notify_fail("You miss your whirl attempt!\n");
	tell_room(environment(this_player()), this_player()->query_cap_name()+ "whirls at "+(string)ob->query_cap_name() + "\n", ({ob, this_player()}));
	tell_object(ob, this_player()->query_cap_name()+" whirls at you.\n");
	this_player()->add_skill_points("attack", attack/20 + 5);
	this_player()->add_sp(-(attack/8));
	ob->damage(attack);
	return 1;
    }
}



int abil() {

    if (this_player()->query_level() < 2) return 0;

    if (this_player()->query_class()=="fighter") return 1; 
    if (this_player()->query_name()=="venenum") return 1;
}



void help() {

    write("Syntax: <whirl [(living)]> or <whirl>\n\n"
      "A fighter attack command that causes you to whirl at the object named. At higher levels this move doesn't require a parameter and hits one or more creatures in the room.\n");
}
