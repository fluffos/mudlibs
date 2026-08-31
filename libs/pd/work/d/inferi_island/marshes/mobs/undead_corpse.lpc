#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Undead Corpse");
    set("id", ({ "monster", "undead", "corpse" }) );
    set_level( 35 );
    set("short", "Undead Corpse" );
    set("long", "%^BOLD%^%^BLACK%^The half rotted corpse of what looks to be a man is here with a %^BOLD%^%^RED%^blood thirsty %^BLACK%^look of %^RESET%^%^GREEN%^revenge %^BOLD%^%^BLACK%^in his e%^RESET%^%^RED%^y%^BOLD%^%^BLACK%^e.%^RESET%^" );
    set("race", "human" ); 
    set_gender( "male" );
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_ac("right hand", 5); 
    set_fingers(5); 
    set_skill("melee", 120);
    set_class("fighter");
    set("aggressive", 25);
    new(MARSHARM+"bloody_shirt")->move(this_object());
    new(MARSHWEP+"bloody_spear")->move(this_object());
    new(MARSHARM+"bloody_pants")->move(this_object());
    force_me("wear pants");
    force_me("wear shirt");
    force_me("wield spear");
    set_alignment(-200);
    set_undead(1);
}
