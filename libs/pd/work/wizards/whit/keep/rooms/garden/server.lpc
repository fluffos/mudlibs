#include <std.h>
inherit VIRTUALSERVER;
void create() {
    ::create();
    set_how_long(1);
    set_day_sentances( ({
	"The gardens seem full of life.  Several birds "
	"flutter around in the numerous bushes.  The "
	"path is made from a grey stone and is keep "
	"clean by the gardeners that watch over the "
	"numerous keep gardens.",
	"The path is made from a grey stone.  "
	"Surrounding the path is numerous types of "
	"trees and shrubs.  Small animals inhabit the "
	"most part of the trees.  The path is clean "
	"of any litter from the trees."
      }) );
    set_night_sentances( ({
	"The gardens seem eerie this late at night.  "
	"A cool breeze runs through the main part of "
	"the garden walkways.  Most of the windows "
	"in the front of the keep are illuminated.  "
	"Despite there being almost noone around, "
	"it seems as if some kind of presence is about.",
	"The gardens seem eerie this late at night.  "
	"A cool breeze runs through the main part of "
	"the garden walkways.  Most of the windows "
	"in the front of the keep are illuminated.  "
	"Despite there being almost noone around, "
	"it seems as if some kind of presence is about."
      }) ); 
    set_item_list(([ "shrubs":"The trees and shrubs surround the path.",
      ]));
    set_properties( ([ "light" : 2,
	"night light" : 1,
	"garden" : 1,
      ]) );
    set_short("the opening gardens of the keep");
}
