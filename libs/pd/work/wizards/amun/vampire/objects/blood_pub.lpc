#include <std.h>
#include <purgatory.h>
#include <vampq.h>
inherit ROOM;
void init() {
    ::init();
    add_action("read", "read");
}
void create() {
    ::create();
    set_properties( ([ "light": 2, "indoors" : 1, "no attack" : 1, "no magic" : 1]) );
    set_short("%^BOLD%^%^RED%^Blood Pub%^RESET%^");
    set_long("%^BOLD%^%^RED%^The blood pub is a new addition to the area, but it looks like it has been here for centuries. The Vampire standing behind the counter has blood dripping from the corners of his mouth and just behind him a foot can be seen. There is blood everywhere in the pub, even over the sign ontop of the counter.%^RESET%^");
    set_items(
      (["counter" : "%^BOLD%^%^RED%^The counter is covered in blood.%^RESET%^",
	"menu" : "It looks like a list of drinks. Read it to see what's available."]));
    set_exits( (["southeast" : ROOMS"beach4"]) );
}

void reset() {
    ::reset();
    new("/std/obj/player_list")->move(this_object());
    if(!present("blood thirsty vampire")) 
	new(VM"blood_thirsty_vampire")->move(this_object());
    new(VO"blood_basin")->move(this_object());
}

int read(string str) {
    object ob;

    ob = present("blood thirsty vampire");
    if(!ob) {
	write("You cannot read the menu, as it is splattered with blood.");
	return 1;
    }
    message("info", "We have one drink at the Blood Pub:",
      this_player());
    message("info",
      "-----------------------------------------------------------", this_player());
    message("info", "Blood\t\t"+ob->get_price("blood")+" gold", this_player());
    message("info",
      "-----------------------------------------------------------", this_player());
    message("info", "<buy drink_name> gets you a drink.", this_player());
    return 1;
}
