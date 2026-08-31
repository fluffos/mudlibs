#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Inferi Ferrel");
    set("id", ({ "monster", "inferi", "ferrel" }) );
    set_level( 30 );
    set("short", "Inferi Ferrel" );
    set("long", "%^RESET%^%^RED%^These creatures dwell in the %^BOLD%^%^CYAN%^cold %^RESET%^%^RED%^and %^BOLD%^%^BLACK%^darkness%^RESET%^%^RED%^, they fear %^BOLD%^%^YELLOW%^light %^RESET%^%^RED%^and %^BOLD%^%^RED%^warmth%^RESET%^%^RED%^." );
    set("race", "ferrel" ); //
    set_gender( "male" );
    set_body_type("ferrel");
    set_wielding_limbs( ({ "left hand" }) );
    set_ac("left hand", 5); // 
    set_skill("melee", 100);
    set_class("rogue");
    set("aggressive", 25);
    set_moving(1); 
    set_speed(60);
    new(MARSHWEP+"chipped_dagger")->move(this_object());
    new(MARSHARM+"tattered_rags")->move(this_object());
    force_me("wear shirt");
    force_me("wield dagger");
}
