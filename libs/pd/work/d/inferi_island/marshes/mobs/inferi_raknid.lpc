#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Inferi Raknid");
    set("id", ({ "monster", "inferi", "raknid" }) );
    set_level( 30 );
    set("short", "Inferi Raknid" );
    set("long", "%^RESET%^%^RED%^These creatures dwell in the %^BOLD%^%^CYAN%^cold %^RESET%^%^RED%^and %^BOLD%^%^BLACK%^darkness%^RESET%^%^RED%^, they fear %^BOLD%^%^YELLOW%^light %^RESET%^%^RED%^and %^BOLD%^%^RED%^warmth%^RESET%^%^RED%^.%^RESET%^" );
    set("race", "raknid" ); 
    set_gender( "male" );
    set_body_type("raknid");
    set_wielding_limbs( ({ "first hand" }) );
    set_ac("first hand", 5); 
    set_skill("melee", 100);
    set_class("fighter");
    set("aggressive", 25);
    new(MARSHWEP+"great_sword")->move(this_object());
    force_me("wield sword");
}
