#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Inferi Faerie");
    set("id", ({ "monster", "inferi", "faerie" }) );
    set_level( 17 );
    set("short", "Inferi Faerie" );
    set("long", "%^RESET%^%^RED%^These creatures dwell in the %^BOLD%^%^CYAN%^cold %^RESET%^%^RED%^and %^BOLD%^%^BLACK%^darkness%^RESET%^%^RED%^, they fear %^BOLD%^%^YELLOW%^light %^RESET%^%^RED%^and %^BOLD%^%^RED%^warmth%^RESET%^%^RED%^.%^RESET%^" );
    set("race", "faerie" ); 
    set_gender( "female" );
    set_body_type("faerie");
    set_class("rogue");
    set_wielding_limbs( ({ "right hand" }) );
    set_ac("right hand", 5); 
    set_fingers(5); 
    set_skill("melee", 40);
    set("aggressive", 15);
    new(MARSHWEP+"chipped_dagger")->move(this_object());
    new(MARSHARM+"tattered_rags")->move(this_object());
    force_me("wear shirt");
    force_me("wield dagger");
}
