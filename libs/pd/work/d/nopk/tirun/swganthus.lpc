#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
    ::create();
    set_short("Southwest Ganthus Circle.");
    set_long(
      "Ganthus Road is a lightly-traveled road that circles around the heart of Tirun.  Because it leads through a rich neighborhood the road is as well guarded as the market.  The stones underfoot are well kept and the road is clean.  Large houses line the road to the west and south.  ");
    set_night_long( "Ganthus Road is deserted and peaceful at night.  To the west and south, the shadows coalesce into buildings.  The stones underfoot are hard to make out in the darkness.  The road leads off into the darkness to the east and north.  ");
    set_exits(([
	"north" : ROOMS"sganthus2",
	"east"  : ROOMS"wganthus2",
        "enter fighter hall" : ROOMS "sparroom",
       "enter weaponsmith shop" : ROOMS "weaponsmith_shop",
      ]) );
add_exit_alias("enter fighter hall", "fighter hall");
add_exit_alias("enter fighter hall", "fighter");
add_exit_alias("enter fighter hall", "hall");
add_exit_alias("enter fighter hall", "enter hall");
add_exit_alias("enter fighter hall", "west");
add_exit_alias("enter weaponsmith shop", "weaponsmith shop");
add_exit_alias("enter weaponsmith shop", "weaponsmith");
add_exit_alias("enter weaponsmith shop", "shop");
add_exit_alias("enter weaponsmith shop", "enter shop");
add_exit_alias("enter weaponsmith shop", "south");
    set_property("light", 3);
    set_property("night light", 1);
    set_items(
      (["road" : "Ganthus Road runs through the heart of Tirun.",
	"houses" : "Large two story brownstone houses."]) );
}
