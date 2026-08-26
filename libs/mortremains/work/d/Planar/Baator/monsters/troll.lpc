#include <mudlib.h>

inherit MONSTER ;

void create () {
    object ob1;

    ::create() ;
    set("author", "ilzarion");
    seteuid(getuid()) ;
    set("short", "Hell Troll");
    set ("long", "The much feared, regenerating denizens of the swamps.\n") ;
    set ("id", ({ "troll" }) ) ;
    set_name ("troll") ;
    set ("race", "troll");
    set ("gender", "male") ;
    enable_commands() ;
    set("stat/constitution", 25);
    set("special", 3);
    set_living_name("troll") ;
    set("time_to_heal", 1);
    set ("base_ac", 4);
    set ("armor_class", 4);
    set("CLASS", "warrior");
    set ("damage", ({ 5,8 }) ) ;
    set("damage_type", "slashing");
    set ("weapon_name", "claws") ;
    set_verbs( ({ "rip", "slash at", "swipe at" }) ) ;
    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
    set("resist_type", ([ "fire":0 ]));
    ob1 = clone_object ("/d/Ancients/obj/wound_ob") ;
    ob1 -> move (this_object()) ;

    set_level(12);
}



void special_attack() {
    //this is the spell function for raw excessive damage
    object ob;
    int sv; 
    string target;

    ob = query_current_attacker();
    if (this_object()->query_hit(ob)) {	

	ob->receive_damage(((random(13)+5)), "piercing");
	tell_object(ob, "You are bitten by the troll!\n");
	say("The troll bite's "+ob->query("cap_name")+"!\n");
	return;
    }else{
	tell_object(ob, "The troll misses you with it's bite!\n");
	say("The troll misses "+ob->query("cap_name")+" with it's bite!\n");
	return;
    }
}

void heart_beat(){
    heal_up();
    ::heart_beat();
}

varargs int receive_damage(int damage, string type, object camel, int weap){
    object wounds;

    wounds = present("#WOUND_OB#", this_object());
    if (type == "acid")
	wounds->set("woundlevel" , (wounds->query("woundlevel") + damage) );
    return ::receive_damage(damage, type, camel, weap);

}

