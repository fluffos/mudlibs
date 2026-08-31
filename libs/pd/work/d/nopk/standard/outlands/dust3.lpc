#include <std.h>

inherit "std/room";

void dagger();
void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set("short", "the east end of Outlands Road");
    set("long",
      "You are at the far east end of the outlaw town of Outland. "
      "A small path leads south, deep into the jungle, while the "
      "center of town lies off to the west. "
      "Bushes and scrub line both sides of the path.");
    set_items(
      (["jungle" : "A path leads south into the heart of it.",
	"town" : "Outland is run by rogues.",
	"road" : "Outlands Road is the main road of Outland.",
	"path" : "It is does not look highly travelled."]) );
    set_exits( 
      (["west" : "/d/nopk/standard/outlands/dust2",
	"northeast" : "/d/forest/nwvforest1/wrooms/room1",
	"south" : "/d/nopk/standard/outlands/jungle1"]) );
}

void reset() {
    ::reset();
    set_search("default", (: dagger :) );
    set_search("bushes", (: dagger :) );
}

void dagger() {
    object ob;
    write("You find a strange dagger.");
    say(this_player()->query_cap_name()+" finds something.");
    remove_search("default");
    remove_search("bushes");
    ob = new("/d/nopk/standard/obj/weapon/knife");
    ob->move(this_player());
}

