#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Falcon");
    set("id", ({ "falcon", "monster", "bird" }) );
    set_level( 55 );
    set("short", 
      "%^RESET%^%^ORANGE%^F%^BOLD%^WHITE%^a%^RESET%^%^ORANGE%^lc%^BOLD%^%^WHITE%^o%^RESET%^%^ORANGE%^n" );
    set("long", "%^RESET%^%^ORANGE%^The %^RESET%^%^ORANGE%^F%^BOLD%^WHITE%^a%^RESET%^%^ORANGE%^lc%^BOLD%^%^WHITE%^o%^RESET%^%^ORANGE%^n screeches and circles above you." );
    set("race", "fowl" ); 
    set_gender( "female" );
    set_body_type("fowl");
    set_skill("melee", 40);
    set_class("fighter");
    set("aggressive", 40);
    set_emotes(2, ({"%^RESET%^%^ORANGE%^The %^RESET%^%^ORANGE%^F%^BOLD%^WHITE%^a%^RESET%^%^ORANGE%^lc%^BOLD%^%^WHITE%^o%^RESET%^%^ORANGE%^n screeches and circles above you."}), 0);
    set_emotes(20, ({"%^BOLD%^%^BLACK%^The Falcon %^RED%^Digs %^BLACK%^his claws into you %^RED%^ripping your flesh%^BLACK%^!"}), 1);
}
