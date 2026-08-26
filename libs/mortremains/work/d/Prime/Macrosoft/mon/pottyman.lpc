// The guy in the men's bathroom.

#include "macrosoft.h"

inherit MONSTER;

void create() {
    ::create();
    set("short", "some guy trying to take a crap in peace");
    set("long", wrap("This is some poor dwarf trying to take a "+
	"crap when you rudlely walked in n him.\n"
      ) );
    set("id", ({ "guy", "man", "bathroom guy" }) );
    set_name("bathroom guy");
    set("attrib1", "angry");
    set("attrib2", "embarassed");
    set("race", "dwarf");
    set("weapon_name", "fists");
    set_verbs( ({ "swing at" }) );
    set_level(3);
    set("prevent_summon", 1);
}

void init() {
    ::init();
    command("say Hey! Get outta here!\n");
    if (userp(TP))
	command("kill "+TP->query("name"));
}

/* EOF */
