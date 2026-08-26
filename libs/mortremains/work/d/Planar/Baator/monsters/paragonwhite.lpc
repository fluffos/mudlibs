#include <mudlib.h>
#include <config.h>

inherit "/std/monster" ;


void create () {
    ::create() ;
    seteuid(getuid());

    set("stat/dexterity", 20);
    set("stat/strength", 22);
    set("stat/constitution", 25);
    set("armor_class", -19);
    set_size(171);
    set("short", "Huge, Ancient White Dragon");
    set("long", "This is an ancient white dragon, one of Tiamat's spawn\n"+
      "it is a paragon of it's species.\n");
    set("id", ({ "paragonwhite", "dragon", "white", "white dragon" }) );
    set("magic_resist",90);
    set("resist_type", ([ "cold" : 0, "poison" : 50 ]) );
    set("special", 10);
    set("natt", 2);
    set("race", "dragon");
    enable_commands();
    set("damage", ({ 29,44 }) );
    set("weapon_name", "razor sharp claws");
    set("damage_type", "slashing");
    set_verbs( ({ "slash", "slice", "smite" }) );
    set_verbs2( ({ "slashes", "slices", "smites" }) );
    set_name("paragon white dragon");
    set_living_name("paragon white dragon");
    set_level(44);
    set("wealth", (this_object()->query("hit_points")));
}


void special_attack() {
    object ob;
    int sv;   
    ob = this_object()->query_current_attacker();
    if (random(3) == 0) {
	say("The White Dragon engulfs "+ob->query("cap_name")+" in a storm of ice!\n", ob);
	tell_object(ob, "The White Dragon engulfs you in a storm of ice!\n");
	sv = (ob->save_throw(-6));
	if (sv){
	    if ((ob->query_skill("Evasion"))>0){
		tell_object(ob, "You dive out of the way!\n");
	    }else{
		ob->receive_damage((random(52)+34), "cold");
	    }
	}
	if (sv == 0){
	    ob->receive_damage((random(103)+34), "cold");
	}
    }else{
	say("The White Dragon sinks it's teeth into "+ob->query("cap_name")+"!\n", ob);
	tell_object(ob, "The White Dragon sinks it's teeth into your flesh!\n");
	ob->receive_damage((random(46)+18), "slashing", this_object(), 1);
    }

}
