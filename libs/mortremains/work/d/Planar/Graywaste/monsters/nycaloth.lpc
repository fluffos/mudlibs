#include <mudlib.h>

inherit MONSTER ;

void create () {

    object ob1, ob2 ;

    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Nycaloth") ;
    set ("long", "A broad dog-faced demon with leathery wings.\n") ;
    set ("id", ({ "nycaloth", "yugoloth" }) ) ;
    set("lore", wrap(
	"Little is known of this species of demon, except that "+
	"its claws cause horrible wounds which bleed "+
	"uncontrollably until healed."
      ) );
    set_size(9);
    set_name ("nycaloth") ;
    set ("race", "yugoloth");
    set ("gender", "male") ;
    enable_commands() ;
    set_living_name("nycaloth") ;
    set("resist_type",([  "poison":0, "acid":0, "cold":200, "fire":0]));
    set("magic_resist", 70);
    set("stat/strength", 20);
    set("stat/constitution", 20);
    set("damage_type", "slashing");
    set("weap_resist", 2);
    set ("base_ac", -6);
    set ("armor_class", -6);
    set("natt", 2);
    set("CLASS", "warrior");
    set("thac0", 6);
    set_skill("Axes", 2, "Strength");
    set ("damage", ({ 9,16 }) ) ;
    set ("weapon_name", "wicked claws") ;
    set_verbs( ({ "rip", "slash at", "swipe at" }) ) ;
    set("special", 5);
    set_level(17);
}

int hit_func(object ob, int damage) {
    //this is the spell function for raw excessive damage
    object wounds;
    int sv; 
    string target;

    if (!query("summoned")) {
	wounds = clone_object("/d/Ancients/obj/wound_ob");
	wounds->set("woundlevel", random(6)+1);
	wounds->move(ob);
    }

    return damage;
}



