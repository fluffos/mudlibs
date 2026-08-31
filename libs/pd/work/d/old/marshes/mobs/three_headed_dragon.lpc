#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Three Headed Dragon");
    set("id", ({ "dragon", "monster", "amun_dragon" }) );
    set_level( 110 );
    set("short", "Three Headed Dragon" );
    set("long", "%^BOLD%^%^BLACK%^This dragon is ungodfully huge and has three heads!  This must be the reason the Marshes are so quiet!  Maybe if you play him a song, he will fall asleep." );
    set("race", "dragon" ); 
    set_gender( "male" );
    set_body_type("dragon");
    set_skill("melee", 100);
    set_class("dragon");
    set_subclass("black");
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
