/*
	Well, here goes nuffin.  First attempt at codin in months.
	Hope it werks.
*/
#include <mudlib.h>
#include <config.h>

inherit MONSTER;

void create(){
	::create();
	seteuid(getuid());
	set("author", "sebastian");
	set("stat/dexterity", 18);
	set("stat/strength",17);
	set("stat/constitution",16);
	set("armor_class", -2);
	set("prevent_summon", 1);
	set_size(56);
	set("short", "a White Dragon");
	set("long", "This is a white dragon, it's scales are the color\n"+
	"of the purest snow.  It's eyes, however, are the color\n"+
	"of freshly spilled blood.\n");
	set("id", ({"dragon", "white dragon", "animal", "white"}));
	set("magic_resist", 40);
	set("resist_type", (["cold": 0]));
	set("special", 1);
	set("race", "dragon");
	set("lore_type", "Monster");
	enable_commands();
	set("damage", ({5, 15}));
	set("weapon_name", "frost-tipped talons");
	set("damage_type", "slashing");
	set_verbs(({"slash", "slice", "slaughter"}));
	set_verbs2(({"slashes", "slices", "slaughters"}));
	set_name("white dragon");
	set_living_name("white dragon");
	set_level(21);
     set("wealth", (this_object()->query("hit_points")));
}

void special_attack(){
	object ob;
	int sv;
	ob=this_object()->query_current_attacker();
	if(random(3)==0){
		say("The White Dragon spews forth a blast of ice at"+ob->query("cap_name")+"!\n", ob);
      tell_object(ob, "The White Dragon spews ice at you!\n");
	sv = (ob->save_throw(-6));
		if (sv){
		if ((ob->query_skill("Evasion"))>0){
                tell_object(ob, "You dive out of the way!\n");
            }else{
	ob->recieve_damage((random(24)+12), "cold");
	}
}
        if (sv == 0){
	ob->recieve_damage((random(61)+23), "cold");
	}
    }else{
  say("The White Dragon sinks it's teeth into "+ob->query("cap_name")+"!\n", ob);
        tell_object(ob, "The White Dragon sinks it's teeth into your flesh!\n");
	ob->recieve_damage((random(15)+13), "slashing", this_object(),1);
 	}
}
