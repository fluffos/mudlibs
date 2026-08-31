#include <std.h>

inherit VIRTUALSERVER;

void create() {
    ::create();
    set_how_long(3);
    set_day_sentances( ({
	"All sense of direction is lost as everything appears to be the same.",
	"A light breeze blows through here blowing the leaves in the trees.",
	"There seems to be something in the forest watching everything "
	"that happens in the forest.",
	"There are small shrubs lining the path.",
	"Twigs and branches lay atop of the path.",
      }) );
    set_night_sentances( ({
	"The darkness seems to overpower even the greatest light.",
      }) ); 
    set_item_list(([ "trees":"The trees are just the same as the ones around it.",
      ]));
    set_properties( ([ "light" : 1,
	"night light" : 1,
	"forest" : 1,
      ]) );
    set_short("lost in a forest");
}

