#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Androsphinx");
    set("id", ({ "androsphinx", "sphinx", "monster" }) );
    set_level( 65 );
    set("short", "%^RESET%^%^ORANGE%^Androsphinx" );
    set("long", "%^ORANGE%^The Sphinx is sharpening her claws.%^RESET%^" );
    set("race", "Weimic" ); 
    set_gender( "female" );
    set_body_type("centaur");
    set_wielding_limbs( ({ "right hand" }) );
    set_ac("right hand", 7);  
    set_fingers(5); 
    set_skill("melee", 40);
    set_class("fighter");
    set("aggressive", 40);
    set_emotes(1, ({"The Sphinx is sharpening her claws."}), 0);
    new(WEP+"sphinx_claws")->move(this_object());
    new(WEP+"sphinx_claws")->move(this_object());
    force_me("wield claw");
    force_me("wield claw 2");
}
