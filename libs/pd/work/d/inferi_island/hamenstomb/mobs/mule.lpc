#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Mule");
    set("id", ({ "mule", "monster" }) );
    set_level( 50 );
    set("short", "%^BOLD%^%^BLACK%^Mule" );
    set("long", "%^BOLD%^%^BLACK%^The Mule kicks his hind legs as you approach it.%^RESET%^" );
    set("race", "mule" ); 
    set_gender( "male" );
    set_body_type("horse");
    set_skill("melee", 40);
    set_class("fighter");
    set("aggressive", 40);
    set_emotes(1, ({"%^BOLD%^%^BLACK%^The Mule kicks his hind legs as you approach it."}), 0);
    set_emotes(20, ({"%^BOLD%^%^BLACK%^The Mule kicks you with his back legs!"}), 1);
}
