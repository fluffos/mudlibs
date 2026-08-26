
#include <mudlib.h>

inherit MONSTER ;

void create () {

    ::create() ;
    seteuid(getuid()) ;
    set ("short", "a kyton") ;
    set ("long", @EndLong
One of the bizarre inhabitants of the town Jangling Hiter. This poor soul
is punished for all eternity by being forced to wear physically the chains
which bound him in life. His entire body is covered with rusty chains,
showing only eyes filled with fear, pain, and hatred.
EndLong
    );
    set("lore", wrap("Legend has it that the Kytons are what becomes of the "+
	"souls of men whose particular brand of evil is by twisting the law by "+
	"following too closely its letter, and not its spitit.") );
    set ("id", ({ "kyton", "it" }) ) ;
    set_size(6);
    set_name ("kyton") ;
    set("author", "cyanide");
    set ("race", "kyton");
    set ("gender", "male") ;
    enable_commands() ;
    set_living_name("kyton") ;
    set("resist_type",([ "cold":0, "poison":0]));
    set("magic_resist", 25);
    set("weap_resist", 2);
    set("special", 1); // Healing
    set ("base_ac", 2);
    set ("armor_class", 2);
    set("CLASS", "warrior");
    set ("damage", ({ 1,12 }) ) ;
    set ("weapon_name", "chains") ;
    set_skill("Unarmed", 3, "strength");
    set_verbs( ({ "rip", "slash at", "swipe at" }) ) ;
    set_level(12);
}


int heart_beat(){
    ::heart_beat();
    heal_up();
    return 1;
}
