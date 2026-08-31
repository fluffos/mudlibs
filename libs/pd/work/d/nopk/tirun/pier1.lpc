#include <std.h>
#include <tirun.h>

inherit ROOM;



int down() {
    if(!wizardp(this_player())) return notify_fail("The dock has collapsed!\n");
    this_player()->move_player("/d/tirun/loadb");
    return 1;

}

void create()
{
    ::create();
    set_short("Tirun Docks");
    set_long("The pier extends out to the ocean. There are many boats "
      "docked below the pier. The pier creaks from the waves. "
      "There is a stairwell down to the docks where the boats are berthed.");

    set_night_long("The pier extends out to the ocean. There are many boats "
      "docked below the pier. The pier creaks from the waves. "
      "There is a stairwell down to the docks where the boats are berthed.");

    set_listen("default", "The breeze blows on you lightly.");
    set_smell("default", "The strong smell of sea water fills the air.");

    set_exits( ([ "north" : ROOMS "pier",
	"east" : ROOMS "pier2",
        "enter warehouse" : ROOMS "deliv_warehouse",
        "down" : ROOMS "loadb" ]) );
add_exit_alias("enter warehouse", "warehouse");
add_exit_alias("enter warehouse", "delivery");
add_exit_alias("enter warehouse", "enter delivery");
}

int go_down() {
    if(!wizardp(this_player())) {
	write("You may not use the ocean at this time.\n");
	return 0;
    }
    return 1;
}

/*void init() {	*/
/*::init();	*/
/*add_action("walk", "walk");	*/
/*}	*/

/*int walk(string str) {	*/
/*if (!str || str != "the plank")	*/
/*{	*/
/*return notify_fail("Walk on what?\n");	*/
/*}	*/
/*if (this_player()->query_guild() != "blacksails")	*/
/*{	*/
/*return notify_fail("This is not your ship mate\n");	*/
/*}	*/
/*write("You walk on the plank");	*/
/*this_player()->move_player("/d/guilds/blacksails/hall");	*/
/*return 1;	*/
/*}	*/
