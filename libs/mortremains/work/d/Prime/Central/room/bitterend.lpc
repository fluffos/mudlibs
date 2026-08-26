// A room in the starting area, as yet unnamed.
// Blame goes to Cyanide, 22 May 1999
// 10 June 99  Cyanide added the bands.

inherit PUB;

#include "central.h"

int band_int;

string band_str();

void create() {
    band_int = random(13);
    ::create();
    set("author", "cyanide");
    set("light", 1);
    set("short", "The Bitter End");
    set("long", wrap(
	"Welcome to the Bitter End, a dark, smoky beerhall with "+
	"one thing: lots of alcohol. "+band_str()+"\nTonight we "+
	"have:\n"+list()+"\nIf you like, you may <buy> something,"+
	" or see the <menu>"
	+"\nThe plaque of the Top Players is here."
      ) );
    set("exits", ([
      "east" : M_ROOM+"road0_-1",
    ]) );
   set("item_func", ([
    "plaque" : "query_plaque", 
    ]) );
    set("safe", 1);
}

string drink(string str) {
    switch(lower_case(str)) {
    case "beer" : str = "You slam a beer like a true pro.\n"; break;
    case "wine" : str = "You drink a decent quality cabernet.\n"; break;
    case "tequila" : str = wrap("Lick the salt, slam the drink, suck"+
	  " the lemon..."); break;
    case "coffee" : str = "You cringe. The coffee here is awful.\n";
	break;
    case "cappaccino" : str = "More foam than coffee, but damn "+
	"good stuff.\n"; break;
    case "espresso" : str = "You leap as the buzz hits.\n"; break;
    default : str = "Damn, thats good.\n";
    }

    return str;
}

string band_str() {
    string band = "The entertainment tonight is ";

    switch(band_int) {
    case 0..1 : band += "'Tin Foil Hat', playing something "+
	"unidentifiable, yet throughly trippy."; break;
    case 2..3 : band += "nothing but a jukebox. There is no band "+
	"tonight."; break;
    case 4 : band += "'I Hear Footprints', an acoustic folk group.";
	break;
    case 5 : band += "'The Rubber Band', doing some nice bluesey "+
	"rock."; break;
    case 6 : band += "'The Wizard of Oz', performing some "+
	"brilliant Ozzy covers."; break;
    case 7 : band += "'King', an all girl Queen cover band."; break;
    case 8 : band += "the fucked-up blues jazz rock of 'Colonel "+
	"Bruce Hampton and the Aquarium Rescue Unit'"; break;
    case 9 : band += "'Rubber Soul', doing flawless covers of "+
	"the later Beatles tunes."; break;
    case 10 : band += "the funky sounds of 'Dump Truck' greet you "+
	"as you come in."; break;
    case 11 : band += "a punk-ska band named 'Slam Suzanne', "+
	"doing their local favorite: \"I Like To Say Fuck\"."; break;
    case 12 : band += "'Arrogant Worms', doing their version "+
	"of 'Happy Birthday'."; break;
    default : band = "The stage is empty. The band isn't here yet."; 
	break;
    }

    return band;
}

string query_plaque() {
    TP->more("/log/topusers/topusers") ;
     say(TPN+" checks out the Top Players Plaque.\n") ;
  return ;
}

/* EOF */
