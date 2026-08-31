#include <std.h>
#include <amun.h>
inherit ROOM;
void init() {
    ::init();
    add_action("read", "read");
}
void create() {
    ::create();
    set_properties( ([ "light": 2, "indoors" : 1, "no attack" : 1, "no magic" : 1]) );
    set_short("The Drowning Fish Tavern.");
    set_long("%^BOLD%^%^BLACK%^Bloated Pub\n"
      "%^BOLD%^%^BLACK%^The Pub is quiet and dark.  There are pictures of the dead hanging on each wall around the room.  This room gives off a very uneasy feeling, it might be best to just grab some drinks and go. ");
    set_items(
      (["pub" : "The pub is dead.",
	"bar" : "You see the head of an imp sittin on the corner of the bar, the rest of it is filled with glasses and weird looking bottles.",
	"menu" : "It looks like a list of drinks. Read it to see what's available."]));
    set_exits( (["northwest" : MARSHROOM "marsh_square"]) );
    set_listen( "default", "You hear screaming coming from the back of the bar." );
}
void reset() {
    ::reset();
    /*
	    new("/std/obj/player_list")->move(this_object()); 
    */
    if(!present("rosie")) 
	new(MARSHMON "rosie")->move(this_object());
}
int read(string str) {
    object ob;

    ob = present("rosie");
    if(!ob) {
	write("You cannot read the menu, as it is splattered with blood.");
	return 1;
    }
    message("info", "The following drinks are served at the Bloated Pub:",
      this_player());
    message("info",
      "-----------------------------------------------------------", this_player());
    message("info", "A marsh mallow\t\t"+ob->get_price("marsh mallow")+" gold", this_player());
    message("info", "A murky water\t\t"+ (int)ob->get_price("murky water")+" gold", this_player());
    message("info", "A frozen mist\t\t"+(int)ob->get_price("frozen mist")+" gold", this_player());
    message("info",
      "-----------------------------------------------------------", this_player());
    message("info", "<buy drink_name> gets you a drink.", this_player());
    return 1;
}
