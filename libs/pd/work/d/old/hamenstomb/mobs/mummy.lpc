#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Mummy");
    set("id", ({ "mummy", "monster" }) );
    set_level( 50 );
    set("short", "%^RESET%^%^WHITE%^Mummy" );
    set("long", "%^RESET%^%^WHITE%^The Mummy stretches his arms at you and moans.%^RESET%^" );
    set("race", "human" ); 
    set_gender( "male" );
    set_body_type("human");
    set_skill("melee", 40);
    set_class("fighter");
    set("aggressive", 40);
    set_emotes(1, ({"%^RESET%^%^WHITE%^Trips over his wraps."}), 0);
    set_emotes(20, ({"%^RESET%^%^WHITE%^The mummy wraps his wraps around your neck choking you!", "%^RESET%^%^WHITE%^The mummy %^BOLD%^%^RED%^STABS %^RESET%^%^WHITE%^you with his knife!"}), 1);
    new(ARM+"mummy_wraps")->move(this_object());
    new(WEP+"flint_knife")->move(this_object());
    new(WEP+"flint_knife")->move(this_object());
    force_me("wear wraps");
    force_me("wield knife");
    force_me("wield knife 2");
}
