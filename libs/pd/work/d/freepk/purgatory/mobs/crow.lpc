#include <std.h>
#include <purgatory.h>
inherit MONSTER;

void create() {
    ::create();
    set_name("Crow");
    set_short("Crow");
    set_id(({"monster", "crow"}));
    set_long("This crow looks to be sitting on a headstone of some long forgotten being. Its watchful eyes stare are you to see what you are doing.");
    set_level(65+random(10));
    set("aggressive", 12+random(10));
    if(random(2)) set_gender("male"); else set_gender("female");
    set_race("crow");
    set_class("fighter");
    set_subclass("warrior");
    set_body_type("fowl");
    set_emotes(2,({ "The eerie call of a crow echos from nearby.", "Flapping wings draw your eyes to a crow." }),0);

}

