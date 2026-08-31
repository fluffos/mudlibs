#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Camel");
    set("id", ({ "camel", "monster" }) );
    set_level( 50 );
    set("short", "%^RESET%^%^ORANGE%^Camel" );
    set("long", "%^RESET%^%^ORANGE%^The Camel stands eating and spitting.%^RESET%^" );
    set("race", "camel" ); 
    set_gender( "male" );
    set_body_type("horse");
    set_skill("melee", 40);
    set_class("fighter");
    set("aggressive", 40);
    set_emotes(1, ({"Camel spits at you."}), 0);
    set_emotes(20, ({"%^RESET%^%^ORANGE%^The Camel digs his teeth into you!"}), 1);
}
