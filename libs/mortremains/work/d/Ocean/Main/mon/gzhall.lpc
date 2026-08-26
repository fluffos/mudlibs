#include "ocean.h"

inherit MONSTER;

void create() 
{
    ::create();
    set("author", "gasman");
    set("short", "Gzhall");
    set("long", wrap(
	"Standing before you is Gzhall. He is an ominous looking figure "+
	"dressed in black. He looks very powerful. Although he is large, he "+
	"appears to be quite fast."
      ));
    set("id", ({ "gzhall" }) );
    set("prevent_summon", 1);
    set_name("gzhall");
    set("race", "human");
    set("weapon_name", "fists");
    set_verbs( ({ "swing at", "pound", "pummel" }) );
    set("damage" , ({ 3, 10}) );
    set("damage_type" , "bludgeoning");
    credit(random(140) + 10);
    set("gender", "male");
    set("size", 7);
    enable_commands() ;

    /*
	set("stat", ([
	  "strength" : 15,
	  "intelligence" : 18,
	  "dexterity" : 21,
	  "constitution" : 16,
	  "charisma" : 12
	]));
	set("wimpy", 45);
	set("pursuing",1);
	set("moving", 1);  
    */
    set_level(20);
}

void heart_beat()
{
    string att_name;
    object ob, objarm;
    int hp, mhp;

    ::heart_beat();

    hp = query("hit_points");
    mhp = query("max_hp");

    if (query_current_attacker())     
    {
	att_name = query_current_attacker()->query("cap_name");
	ob = query_current_attacker();

	switch(random(10))
	{
	case 1 .. 3 :
	    say(wrap(query("cap_name")+" whips around and devestates "+att_name+" with a back kick!\n"));
	    write(wrap(query("cap_name")+" whips around and levels you with a back kick\n"));
	    ob->receive_damage(random(32)+9);
	    break;
	case 4 .. 6 :
	    say(wrap(query("cap_name")+" sweeps "+att_name+" to the ground.\n"));
	    write(wrap(query("cap_name")+" sweeps you to the ground.\n"));
	    ob->receive_damage(random(10)+9);
	    break;
	case 7 .. 10 :
	    break;
	}

	if(hp <= mhp /2)
	{
	    cease_all_attacks();
	    ob->cease_all_attacks();

	    write(wrap("\n\nWith one swift move, "+query("cap_name")+" severs your "+
		"left arm and hands it to you!\n\n"));
	    say(wrap("\n\nWith one swift move, "+query("cap_name")+" severs "+
		att_name+"'s left arm and hands it to "+objective(ob->query("gender"))+"!\n\n"+
		"You might want to go to the hospital and have that looked at.\n"));
	    objarm = clone_object(O_OBJ+"arm");
	    objarm->move(ob); 

	    receive_healing(mhp);
	    say(wrap(query("cap_name")+ " bows his head and begins to pray."+
		"He is begining to heal!\n"));
	}
    }
}
