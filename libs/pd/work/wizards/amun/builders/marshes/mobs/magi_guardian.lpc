#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("magi guardian");
    set("id", ({ "magi", "monster", "guardian" }) );
    set_level( 100 );
    set("short", "%^BOLD%^%^BLACK%^Magi Guardian" );
    set("long", "%^BOLD%^%^BLACK%^Wearing all black, the Magi Guardian looks %^RESET%^%^RED%^firece %^BOLD%^%^BLACK%^and ready to %^WHITE%^protect %^BLACK%^the %^YELLOW%^eye %^BLACK%^with his %^WHITE%^life%^BLACK%^." );
    set("race", "human" ); //
    set_gender( "male" );
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_ac("right hand", 7); // 
    set_fingers(5); 
    set_skill("melee", 40);
    set_class("fighter");
    set("aggressive", 50);
    new(ARM+"leather_pants")->move(this_object());
    new(ARM+"leather_shirt")->move(this_object());
    new(ARM+"horn_ring")->move(this_object());
    new(ARM+"leather_pouch")->move(this_object());
    new(WEP+"magi_bow")->move(this_object());
    new(MARSHARM+"guardians_eye")->move(this_object());
    force_me("wear pants");
    force_me("wear shirt");
    force_me("wear ring");
    force_me("wear pouch");
    force_me("wield bow");
}
