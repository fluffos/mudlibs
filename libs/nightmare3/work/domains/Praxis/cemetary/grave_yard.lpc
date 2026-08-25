#include <std.h>

inherit ROOM;

void create() {
  ::create();
    set_property("light", 2);
    set_exits( 
	      (["west" : "/domains/Praxis/east_road2",
		"east" : "/domains/Praxis/cemetary/grave_yard2"]) );
    set_short("Cemetary Entrance");
    set_long(
	"You stand between the gates of an ancient, nearly "
	"forgotten cemetary. The air is very still here, and "
	"preternaturally quiet.  You feel uneasy and look over "
	"your shoulder.  No one comes here anymore for some reason. "
	"You see a headstone off to the east. ");
   set_items(
       (["headstone" : "The headstone is too far away to read.",
	 "gates" : "The gates are antiques.  No one makes gates "
	 "like these anymore."]) );
}

