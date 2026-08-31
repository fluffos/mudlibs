#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Black Vulture");
    set("id", ({ "vulture", "monster", "black vulture" }) );
    set_level( 50 );
    set("short", "%^BOLD%^%^BLACK%^Black V%^WHITE%^u%^BLACK%^lture" );
    set("long", "%^BOLD%^%^BLACK%^The vulture eyes you as you move awaiting your death.%^RESET%^" );
    set("race", "vulture" ); 
    set_gender( "female" );
    set_body_type("fowl");
    set_skill("melee", 40);
    set_class("fighter");
    set("aggressive", 40);
    set_emotes(2, ({"%^BOLD%^%^BLACK%^Circles around you waiting for death."}), 0);
    set_emotes(20, ({"%^BOLD%^%^BLACK%^The Vulture pecks at your eyes!"}), 1);
}
