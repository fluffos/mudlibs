// Haven - LoKi 2022

#include <std.h>
#include "../graez.h"

inherit ROOM;

void create() {
    set_terrain(BARREN);
    set_travel(PAVED_ROAD);
    set_property("indoors",0);

    set_name("desolate empty village");
    set_short("%^C245%^desolate %^C189%^empty%^C245%^ village%^CRST%^");

    set_long("This %^C102%^village%^CRST%^ around you has obviously "+
      "been %^C100%^constructed%^CRST%^ quite recently. The %^C094%^buildings%^CRST%^ "+
      "are %^C094%^freshly hewn wood%^CRST%^ with %^C143%^thatched roofs%^CRST%^ "+
      "and %^C221%^newly glazed%^CRST%^ and %^C100%^fired pots%^CRST%^. "+
      "%^C058%^Tall walls%^CRST%^ surround you on all sides and the %^C058%^parapets%^CRST%^ "+
      "are intact and by your estimation with how well constructed they are a small "+
      "force could keep an %^C243%^army%^CRST%^ out of this settlement for quite "+
      "some time. What is odd is how %^C241%^dead quiet%^CRST%^ the entire area is. "+
      "There is no bustle, no %^C239%^echos%^CRST%^ from a %^C064%^busy marketplace%^CRST%^, "+
      "not even the %^C221%^yapping of dogs%^CRST%^ that you expect to hear in a settlement "+
      "like this. Strangely even birdsong is absent. In the distance to the south you can "+
      "see the %^C241%^mountain ranges%^CRST%^ and to the north %^C022%^more forest%^CRST%^.\n");

    set_items(([
      ({"walls","parapets"}) : "Reaching an impressive thirty feet in the air and over "+
      "two feet thick, the %^C058%^walls%^CRST%^ around the settlement are wel more than most "+
      "settlements this size could even dream of needing. The %^C094%^wood%^CRST%^ has been "+
      "prepared with some %^C081%^concoction%^CRST%^ that makes it glisten as if %^C081%^wet%^CRST%^ "+
      "and you realize that the walls themselves are completely %^C088%^fireproof%^CRST%^. A small "+
      "group of %^C081%^dedicated defenders%^CRST%^ would have been able to defend these walls "+
      "against a %^C103%^horde%^CRST%^ for an extended amount of time.\n",
      ({"ground"}) : "The ground is %^C060%^hard packed%^CRST%^ as if a thousand people had walked "+
      "it, but none of the %^C242%^prints%^CRST%^ are fresh.\n",
      ({"roof","roofs"}) : "the %^C143%^roofs%^CRST%^ of the buildings are %^C143%^thatch%^CRST%^, perfect "+
      "for a relatively %^C110%^mild climate%^CRST%^ and will protect buildings from the %^C087%^elements%^CRST%^ "+
      "without trapping too much %^C088%^heat%^CRST%^ inside in the summer.\n",
      ({"walls","buildings"}) : "The %^C058%^buildings%^CRST%^ around you are obviously new, as if in the "+
      "last year or so. The %^C094%^lumber%^CRST%^ is fresh hewn and the walls do not have the age marks "+
      "from %^C088%^cooking fires%^CRST%^ or %^C244%^fatigue%^CRST%^. This settlement is very young.\n",
      ({"mountains"}) : "The %^C239%^mountains%^CRST%^ dominate the southern horizon. Beyond them is the "+
      "endless battlefield between the %^C062%^undead%^CRST%^ and the %^C151%^port capital of Graez%^CRST%^.\n",


    ]));


set_smell("default","%^C130%^You smell fresh lumber.%^CRST%^");
set_listen("default","%^C141%^You hear nothing but from your own actions.%^CRST%^");

}



