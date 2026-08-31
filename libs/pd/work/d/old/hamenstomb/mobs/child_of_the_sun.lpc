#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Child of the Sun");
    set("id", ({ "child", "monster" }) );
    set_level( 46 );
    set("short", "%^BOLD%^%^%^WHITE%^Child of the %^YELLOW%^Sun" );
    set("long", "%^BOLD%^%^YELLOW%^The Child is throwing his rock up and catching it.%^RESET%^" );
    set("race", "human" ); 
    set_gender( "male" );
    set_body_type("human");
    set_skill("melee", 40);
    set_class("fighter");
    set("aggressive", 40);
    set_emotes(1, ({"%^BOLD%^%^YELLOW%^The child picks up a rock to add to his collection."}), 0);
    set_emotes(20, ({"%^BOLD%^%^YELLOW%^The child throws a rock at your head cutting it open!"}), 1);
    new(ARM+"ragged_robes")->move(this_object());
    new(WEP+"jagged_rock")->move(this_object());
    force_me("wear robes");
    force_me("wield rock");
}
