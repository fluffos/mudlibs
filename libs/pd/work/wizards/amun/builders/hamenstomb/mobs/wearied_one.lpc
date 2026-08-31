#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Wearied One");
    set("id", ({ "wearied", "monster", "wearied one", "one" }) );
    set_level( 48 );
    set("short", "%^RESET%^%^WHITE%^Wearied One" );
    set("long", "%^RESET%^%^WHITE%^The Wearied one stands before you wearing a gloomy face.%^RESET%^" );
    set("race", "human" ); 
    set_gender( "female" );
    set_body_type("human");
    set_skill("melee", 40);
    set_class("fighter");
    set("aggressive", 40);
    set_emotes(1, ({"%^RESET%^%^WHITE%^The Wearied One cries in the corner."}), 0);
    set_emotes(20, ({"%^RESET%^%^WHITE%^The Wearied One shoots a rock at your head with hits slingshot!"}), 1);
    new(ARM+"dirty_robes")->move(this_object());
    new(ARM+"rusted_armour")->move(this_object());
    new(WEP+"leather_slingshot")->move(this_object());
    force_me("wear robes");
    force_me("wear armour");
    force_me("wield slingshot");
}
