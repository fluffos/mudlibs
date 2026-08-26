#include <config.h>
#include <mudlib.h>

inherit OBJECT;

void init() {
    
    add_action("climb", "climb");
    add_action("swim", "swim");
}


int climb(string str) {
    if(!str) {
	write("Climb where?\n");
	return 1;
    }

    if (str=="in") {
	say(TPN+" climbs down the ladder, and gets into the bubbling water.\n");
	write(
	  "As you climb into the hottub, the warm water surrounds "+
	  "you leaving goosebumps on your exposed skin!\n");
    }
    else if (str=="up" || str=="out") {
	say(TPN+" Climbs up the ladder and exits from hottub.\n");
	write(
	  "You climb up the ladder and exit the hottub.\n"+
	  "You shiver from the cold air hitting your heated skin.\n");
    }
    else return 0;
    return 1;
}


int swim(string str) {
    say(TPN+" swims in the hottub and crooks a finger inviting you in.\n");
    write(wrap(
	"You swim in the bubbling warm water that soothes\n"+
	"your aching muscles immediately."));
    return 1;
}
void create()
{
    seteuid( getuid() );
    set("light", 1);
    set("author", "shya");
    set("name" , "hottub");    
    set ("id", ({ "hottub", "hot tub" }) ) ;
    set("short", "hottub" );
    set("long",@EndText 
You find this hottub taking up most of the room.
In the shape of a heart, with just enough seats for one special person.
You feel tempted to relax a little. Climb down the ladder and relax.
EndText
    );
    set( "item_desc", ([
      "water" : "The water is hot and bubbling. You feel the urge to relax...",      
      "ladder" : "A small hottub ladder. You can either climb in to get into the hottub, or climb out to get out."
    ]) );
}


