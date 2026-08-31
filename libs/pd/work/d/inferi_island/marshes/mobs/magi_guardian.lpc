#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("magi guardian");
    set("id", ({ "magi", "monster", "guardian" }) );
    set_level( 50 );
    set("short", "%^BOLD%^%^BLACK%^Magi Guardian%^RESET%^" );
    set("long", "%^BOLD%^%^BLACK%^Wearing all black, the Magi Guardian looks %^RESET%^%^RED%^firece %^BOLD%^%^BLACK%^and ready to %^WHITE%^protect %^BLACK%^the %^YELLOW%^eye %^BLACK%^with his %^WHITE%^life%^BLACK%^.%^RESET%^" );
    set("race", "human" ); 
    set_gender( "male" );
    set_body_type("human");
    set_skill("melee", 40);
    set_skill("attack", 40);
    set_class("mage");
    set_subclass("wizard");
    set_spell_chance(75);
    set_spells( ({ "fog", "manabolt", "pressure", "coalesce" }) );
    set_skill("wizardry", 50*6);
    set_skill("magic attack", 50*5);
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
