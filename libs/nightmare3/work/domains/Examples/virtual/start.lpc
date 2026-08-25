/*
// File     :  /domains/Examples/virtual/start.c
// Comment  :  A linking room for all virtual areas.
// 94-05-13 :  Written by Pallando @ Nightmare
*/
#include <std.h>

inherit ROOM;

void create()
{
    ::create();
    set_properties( ([ "light" : 3, "night light" : 1 ]) );
    set_property( "indoors", 1 );
    set_short( "The Nexus" );
    set_long(
	"Neon blue light beams strike off to infinity in all directions "
	"forming a giant 3D lattice against the otherwise featureless void. "
	"This is The Nexus - the focal point of all virtual servers - and the "
	"gateway into the myriad realities supported by them."
    );
    set_listen( "default",
	"You feel in your bones the vibrations from a deep background hum." );
/* These are here to show you how if you want them in your rooms
    set_smell( "mildew", "That really makes you sick!" );
    set_smell( "default", "Mildew fills your lungs, nearly making you sick." );
    set_listen( ({ "floorboards", "floorboard" }),
      "Old and unhappy with your presence, they are crying out." );
*/
    set_items( ([
        ({ "floorboard", "floorboards" }) :
          "Be careful where you walk, they are rotting through in places.",
        "woods" : "The great woods which surround the shack.",
    ]) );
    set_exits( ([
        "exampleA" : "/domains/Examples/virtual/exaA/one.exaA",
	"exampleB" : "/domains/Examples/virtual/exaB/3,1.exaB",
        "down" : "/domains/Desert/room/500,500.d",
    ]) );
//  set_pre_exit_functions( ({ "up" }), ({ "cmd_up"  }) );
}

int cmd_up( string arg )
{
    message("my_action","You grab the lowest branch and pull yourselfup.",
      this_player() );
    message( "other_action",
        this_player()->query_cap_name()+" grabjumps up",
    this_object(), ({ this_player() }) );
    return 1;
}

void init()
{
    ::init();
    add_action( "doclimb", "climb" );
}

void reset()
{
    ::reset();
    set_search("brush", (: "search_brush" :)); 
}

int search_brush(string str) { 
  write( "Foo!" );
  remove_search("brush");
}
