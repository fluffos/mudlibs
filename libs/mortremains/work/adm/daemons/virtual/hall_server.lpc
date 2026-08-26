// conf_server.c
// The virtual hallway server for the TMI-2 conference facility.
// Rooms with y coord 0 are hallways, others are side rooms.
// Written by Mobydick.
// Bug deveolped (create_doors() not defined).  Pallando made it inherit DOORS

#include <config.h>
#include <mudlib.h>

inherit DOORS;
inherit ROOM;
inherit "/std/virtual/compile";

#define BASE "/d/Conf/room/"
#define SUFFIX ".hall"

void initialize(string arg)
{
    int x, y, i ;
    string north, south, east, west ;

	room::create() ;
    sscanf(arg,"%d,%d",x,y) ;
    south = BASE + (x - 1) +  "," + y       + SUFFIX ;
    east  = BASE + x       +  "," + (y + 1) + SUFFIX ;
    north = BASE + (x + 1) +  "," + y       + SUFFIX ;
    west =  BASE + x       +  "," + (y - 1) + SUFFIX ;
    set ("light", 1) ;
    if (y==0) {
	set ("short", "Long hallway") ;
	set ("long", "You are in a long hallway with doors on both sides.\n") ;
	set ("exits", ([
	"west" : west ,
	"east" : east,
	"south" : south,
	"north" : north
	]) ) ;
	create_door("east", "west", "A wooden door", "open") ;
	create_door("west", "east", "A wooden door", "open") ;
    } else {
	set ("short", "A small room") ;
	set ("long", "This is a small room where you could sit around and chat a while.\n") ;
	if (y==1) {
		set ("exits", ([ "west" : west ]) ) ;
		create_door ("west", "east", "A wooden door", "open") ;
	} else {
		set ("exits", ([ "east": east ]) ) ;
		create_door ("east", "west", "A wooden door", "open") ;
	}
    }
}
