#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Inferi Nymph");
    set("id", ({ "monster", "inferi", "nymph" }) );
    set_level( 30 );
    set("short", "Inferi Nymph" );
    set("long", "%^RESET%^%^RED%^These creatures dwell in the %^BOLD%^%^CYAN%^cold %^RESET%^%^RED%^and %^BOLD%^%^BLACK%^darkness%^RESET%^%^RED%^, they fear %^BOLD%^%^YELLOW%^light %^RESET%^%^RED%^and %^BOLD%^%^RED%^warmth%^RESET%^%^RED%^.%^RESET%^" );
    set("race", "nymph" );
    set_gender( "female" );
    set_body_type("nymph");
    set_wielding_limbs( ({ "right hand" }) );
    set_ac("right hand", 5);
    set_skill("melee", 100);
    set_class("fighter");
    set("aggressive", 25);
    new(MARSHWEP+"frayed_whip")->move(this_object());
    new(MARSHARM+"tattered_rags")->move(this_object());
    new(MARSHARM+"decaying_pants")->move(this_object());
    force_me("wear shirt");
    force_me("wear pants");
    force_me("wield whip");
}
