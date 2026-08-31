#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("A Dragon");
    set("id", ({ "dragon", "monster", "amun_dragon" }) );
    set_level( 70 );
    set("short", "A Dragon" );
    set("long", "%^BOLD%^%^BLACK%^This dragon is unnaturally large and has %^RED%^red scales %^BLACK%^lining down his back; this must be the reason the Marshes are so quiet. He looks as if he maybe a little tired, maybe there is a way to tame this dragon.%^RESET%^" );
    set("race", "dragon" ); 
    set_gender( "male" );
    set_body_type("dragon");
    set_skill("melee", 100);
    set_class("dragon");
    set_subclass("black");
    set_alignment(-1000);
}
void init() {
    ::init();
    add_action("peace", "peace");
    if( !present("amulet", this_player()) ) {
	this_object()->force_me("kill "+this_player()->query_name());
    }
    else {
	write("The dragon is mesmerized by your amulet.");
	say(this_player()->query_cap_name() + " notices that the dragon seems to be mesmerized by thier amulet.");
    }
}
int peace(string str) {
    write("The dragon's fury will not subside.");
    return 1;
}
