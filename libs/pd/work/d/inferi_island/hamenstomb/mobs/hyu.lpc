#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Hyu");
    set("id", ({ "hyu", "monster" }) );
    set_level( 70 );
    set("short", "%^BOLD%^%^YELLOW%^Hyu" );
    set("long", "%^BOLD%^%^BLACK%^Short and stout, this man looks hidious and vicious.%^RESET%^" );
    set("race", "gremlin" ); 
    set_gender( "male" );
    set_body_type("human");
    set_wielding_limbs( ({ "right hand" }) );
    set_ac("right hand", 7);  
    set_fingers(5); 
    set_class("fighter");
    set("aggressive", 40);
    set("aggressive", 40);
    new(ARM+"round_shield")->move(this_object());
    force_me("wear shield");
}
