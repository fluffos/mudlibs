#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Sekhmet");
    set("id", ({ "sekhmet", "monster" }) );
    set_level( 56 );
    set("short", "%^RESET%^%^ORANGE%^sekhmet" );
    set("long", "%^ORANGE%^Destruction follows this terrifying woman more commonly called 'her'." );
    set("race", "Sekhmet" ); 
    set_gender( "female" );
    set_body_type("sekhmet");
    set_wielding_limbs( ({ "right hand" }) );
    set_ac("right hand", 7);  
    set_fingers(5); 
    set_skill("melee", 40);
    set_class("fighter");
    set("aggressive", 40);
    new(WEP+"ancient_hatchet")->move(this_object());
    force_me("wield axe");
}
