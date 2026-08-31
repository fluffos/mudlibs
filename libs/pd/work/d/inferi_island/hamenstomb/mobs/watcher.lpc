#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Watcher");
    set("id", ({ "watcher", "monster" }) );
    set_level( 60 );
    set("short", "%^BOLD%^%^BLACK%^Watcher" );
    set("long", "%^ORANGE%^Standing tall, the watcher gazes at you with suspicion.%^RESET%^" );
    set("race", "human" ); 
    set_gender( "male" );
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_ac("right hand", 7);  
    set_fingers(5); 
    set_skill("melee", 60*3);
    set_class("clergy");
    set_subclass("cleric");
    set_spell_chance(50);
    set_spells( ({ "lifewarp", "pain", "wound" }) );
    set("aggressive", 40);
    set_emotes(1, ({"The Watcher eyes you wearily."}), 0);
    new(ARM+"bronze_shield")->move(this_object());
    new(ARM+"stone_ring")->move(this_object());
    force_me("wear shield");
    force_me("wear ring");
}
