// The girl in the men's bathroom.

#include "macrosoft.h"

inherit MONSTER;

void create() {
    ::create();
    set("short", "a really surprised elven woman");
    set("long", wrap("This is some elven just looking for "+
	"a few minutes of privacy.\n"
      ) );
    set("id", ({ "girl", "woman", "bathroom girl" }) );
    set_name("bathroom girl");
    set("attrib1", "really pissed");
    set("gender", "female");
    set("damage", ({ 1, 4 }) );
    set("race", "elf");
    set("weapon_name", "fists");
    set_verbs( ({ "swing at" }) );
    set_level(3);
    set("prevent_summon", 1); 
}

void init() {
    ::init();
    command("say YOU FUCKING PERVERT!!\n");
    if (userp(TP))
	command("kill "+TP->query("name"));
}

/* EOF */
