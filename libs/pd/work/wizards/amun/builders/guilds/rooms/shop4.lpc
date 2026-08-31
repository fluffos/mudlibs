#include <std.h>
#include <guild.h>
inherit ROOM;

void init() {
    ::init();
    add_action("go_east", "east");
}

void create() {
    ::create();
    set_properties(([ "light" : 2, "indoors" : 1, "no bump" : 1, "no attack" : 1, "no magic" : 1 ]));
    set_short("The Guild Town Armour Shop");
    set_long("%^BOLD%^%^CYAN%^The GT Armour Shop%^RESET%^\n"
      "%^BOLD%^%^CYAN%^Bringing color into the shop, the walls that were just painted have left fumes. The armour Mistress sits behind the counter in hopes of buying goods from customers and selling them at an overpriced rate. There is nothing really special about the shop. There is a list for all to read."
    );
    set_items(([
	"shop" : "The shop is clean and newly painted.",
	"counter" : "There is a list for all to look at on the counter.",
	"walls" : "%^BOLD%^%^CYAN%^The walls were just painted.%^RESET%^"
      ]));
    set_exits(([
	"north" : GROOM"r_main2"
      ]));
}

void reset() {
    ::reset();
    if(!present("gretchen")) 
	new(GMOB"gretchen")->move(this_object());
}

int go_east() {
    if(!wizardp(this_player())) {
	message("my_action", "That would surely be against the law.",
	  this_player());
	message("other_action", (string)this_player()->query_cap_name()+
	  " begins to leave east then thinks better of it.",
	  this_object(), ({ this_player() }));
	return 1;
    }
    this_player()->move_player(GROOM"armstorage", "east");
    return 1;
}
