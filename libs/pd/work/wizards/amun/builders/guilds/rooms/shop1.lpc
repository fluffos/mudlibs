#include <std.h>
#include <guild.h>
inherit ROOM;
void init() {
    ::init();
    add_action("read", "read");
}
void create() {
    ::create();
    set_properties( ([ "light": 2, "indoors" : 1, "no attack" : 1, "no magic" : 1]) );
    set_short("Guild Town Bar");
    set_long("%^BOLD%^%^RED%^The GT Bar%^RESET%^\n"
      "%^BOLD%^%^BLACK%^Although it looks like it has not had a customer in years, the bar stands firmly yet well worn. Tables and chairs line the room with an inviting stare as a fire crackles in the corner of the room. There is a small gremlin with a tag reading 'Mick' that is walking around the room as if searching for something. Behind the bar stands a sign for customers to read. %^RESET%^");
    set_items(
      (["bar" : "The bar is very clean and lined with glasses waiting to be used. There is a sign behind the bar for customers to read.",
	"tables" : "The tables are placed perfectly around the room, giving enough space for all races to fit between them.",
	"chairs" : "The chairs are placed snuggly against the tables.",
	"fire" : "The fire crackles softly and gives off a %^BOLD%^%^RED%^warm glow %^RESET%^throughout the room.",
	"menu" : "It looks like a list of drinks. Read it to see what's available."]));
    set_exits( (["south" : GROOM "l_main2"]) );
}
void reset() {
    ::reset();
    /*
	    new("/std/obj/player_list")->move(this_object()); 
    */
    if(!present("mick")) 
	new(GMOB "mick")->move(this_object());
}
int read(string str) {
    object ob;

    ob = present("mick");
    if(!ob) {
	write("You cannot read the menu, as it is splattered with blood.");
	return 1;
    }
    message("info", "The following drinks are served at the GT Bar:",
      this_player());
    message("info",
      "-----------------------------------------------------------", this_player());
    message("info", "Mick's Moonshine\t"+ob->get_price("mick's moonshine")+" gold", this_player());
    message("info", "Boiling Brew\t\t"+ (int)ob->get_price("boiling brew")+" gold", this_player());
    message("info", "Risky Rum\t\t"+(int)ob->get_price("risky rum")+" gold", this_player());
    message("info",
      "-----------------------------------------------------------", this_player());
    message("info", "<buy drink_name> gets you a drink.", this_player());
    return 1;
}
