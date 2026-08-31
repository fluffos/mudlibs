#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("A Dragon");
    set("id", ({ "dragon", "monster", "amun_dragon" }) );
    set_level( 70 );
    set("short", "A Dragon" );
    set("long", "%^BOLD%^%^BLACK%^This dragon is unnaturally large and has %^RED%^red scales %^BLACK%^lining down his back.  This must be the reason the Marshes are so quiet.  He looks as if he maybe a little tired.  Maybe there is a way to tame this dragon." );
    set("race", "dragon" ); 
    set_gender( "male" );
    set_body_type("dragon");
    set_skill("melee", 100);
    set_class("dragon");
    set_subclass("black");
    set_max_hp(10000);
    set_exp(220000);
}
void init() {
    ::init();
    add_action("peace", "peace");
    if( !present("amun_amulet", this_player()) ) {
	this_object()->force_me("kill "+this_player()->query_name());
    }
    else {
	write("The dragon is mesmorized by your amulet.");
	say(this_player()->query_cap_name() + " notices that the dragon seems to be mesmorized by thier amulet.");
    }
}
int peace(string str) {
    write("The dragon's fury will not subside.");
    return 1;
}
