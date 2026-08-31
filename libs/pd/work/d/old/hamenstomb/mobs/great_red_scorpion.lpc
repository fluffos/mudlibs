#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Great Red Scorpion");
    set("id", ({ "scorpion", "monster", "red scorpion", "great red scorpion" }) );
    set_level( 50 );
    set("short", "%^BOLD%^%^WHITE%^Great %^RED%^Red %^WHITE%^Scorpion" );
    set("long", "%^BOLD%^%^RED%^The Red Scorpion raises his tail as you come near.%^RESET%^" );
    set("race", "raknid" ); 
    set_gender( "male" );
    set_body_type("raknid");
    set_skill("melee", 40);
    set_class("fighter");
    set("aggressive", 40);
    set_emotes(20, ({"%^BOLD%^%^RED%^The Scorpian jabs you with his tail gushing blood everywhere!"}), 1);
    new(WEP+"tail")->move(this_object());
    force_me("wield tail");
}
