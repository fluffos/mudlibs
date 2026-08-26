// Koe, relaxing in the steamroom of the bathhouse.

#include <mudlib.h>
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Koe") ;
    set ("long", wrap("Koe is an asuras: a relatively minor angel.\n"+
	"He sits here, relaxing in the steam, look at you curiously."));
    set ("id", ({ "koe", "asuras"}) ) ;
    set_align("ng");
    set ("chat_chance", 30);
    set ("chat_output", ({
      "Koe fans himself with his wings.\n",
      "Koe wonders who the hell you are.\n",
      "Koe yawns.\n",
      "Koe adjusts his towel.\n",
    }) );                                       
    set_name ("koe") ;
    set ("gender", "male") ;
    set ("race", "asuras");
    enable_commands() ;
    set_living_name("koe") ;
    set ("stat/constitution", 12);
    set ("stat/strength", 16);
    set ("stat/charisma", 7);
    set ("stat/intelligence", 14);
    set ("stat/dexterity", 14);
    set ("stat/wisdom", 21);
    set("armor_class", -2);
    set("base_ac", -2);
    set ("damage", ({ 1,10 }) ) ;
    set ("weapon_name", "claws") ;
    set ("CLASS", "warrior");
    set_verbs( ({ "slash at", "swing at", "swipe at" }) ) ;
    set ("magic_resist", 40);
    set_level(8);
}

/* EOF */
