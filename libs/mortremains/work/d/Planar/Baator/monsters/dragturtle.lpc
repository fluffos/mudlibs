#include <mudlib.h>
#include <config.h>

inherit MONSTER;


void create () {
    ::create() ;
    seteuid(getuid());

    set("stat/strength", 23);
    set("stat/constitution", 20);
    set("armor_class", -8);
    set_size(30);
    set("short", "Dragon Turtle");
    set("long", "A Beast of nightmares which makes it's home in the stinking bogs of minauros.\n");
    set("id", ({ "dragon", "turtle", "dragon turtle" }) );
    set("magic_resist", 0 );
    set("resist_type", ([ "dehydration" : 0, "poison" : 50 ]) );
    set("special", 11);
    set("race", "dragon");
    enable_commands();
    set("damage_type", "slashing");
    set("damage", ({ 2,12 }) );
    set("weapon_name", "razor sharp claws");
    set_verbs( ({ "slash", "slice", "smite" }) );
    set_verbs2( ({ "slashes", "slices", "smites" }) );
    set_name("dragon turtle");
    set_living_name("dragon turtle");
    set_level(17);
}


void special_attack() {
    object ob;
    int sv;   
    ob = this_object()->query_current_attacker();
    if (random(3) == 0) {
	say("The Dragon Turtle engulfs "+ob->query("cap_name")+" in steam!\n", ob);
	tell_object(ob, "The Dragon Turtle engulfs you in steam!\n");
	sv = (ob->save_throw());
	if (sv){
	    if ((ob->query_skill("Evasion"))>0){
		tell_object(ob, "You dive out of the way!\n");
	    }else{
		ob->receive_damage((random(100)+21), "fire");
	    }
	}
	if (sv == 0){
	    ob->receive_damage((random(50)+11), "fire");
	}
    }else{
	say("The Dragon Turtle sinks it's teeth into "+ob->query("cap_name")+"!\n", ob);
	tell_object(ob, "The Dragon Turtle sinks it's teeth into your flesh!\n");
	ob->receive_damage((random(27)+5), "slashing", this_object(), 1);
    }

}
