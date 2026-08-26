// Voice Office

#include <std.h>
#include "../../serakii.h"

inherit VAULT;

void create() {
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);

    set_name("large office");
    set_property("light",2);
    set_short("%^C130%^lar%^C101%^g%^C130%^e of%^C102%^f%^C130%^ice%^CRST%^");
    set_long("This fine office is %^C032%^richly "+
	"appointed%^CRST%^ and carefully designed. "+
	"It's %^C231%^white walls%^CRST%^ are paneled "+
	"in %^C100%^fine wood%^CRST%^ with small "+
	"%^C022%^tasteful paintings%^CRST%^. A "+
	"%^C242%^fine gray carpet%^CRST%^ covers "+
	"the %^C231%^marble floor%^CRST%^. A %^C094%^wood "+
	"desk%^CRST%^ sits on the far wall with a "+
	"%^C124%^high back leather chair%^CRST%^. "+
	"There are no windows in the room but it "+
	"is lit nicely by a %^C036%^c%^C038%^r%^C036%^"+
	"ys%^C038%^t%^C036%^al%^CRST%^ hanging from the ceiling. \n");

    set_items(([
      ({"floor","rug"}) : "The floor is covered in a %^C242%^fine gray carpet%^CRST%^.\n",
      ({"painting"}) : "The painting on the wall is of a %^C243%^massive stone statue%^CRST%^ "+
      "of a man in a %^C022%^dark forest%^CRST%^. The styling of the painting is almost "+
      "impressionist in its depiction of the depths of how large the %^C022%^forest%^CRST%^ "+
      "and how grand the %^C243%^statue%^CRST%^ of the man is.\n",

      ({"desk"}) : "Made from %^C094%^fine mahogany%^CRST%^, this desk is overly large for its "+
      "purpose, made to %^C088%^intimidate %^CRST%^or show off %^C055%^wealth %^CRST%^more than "+
      "just be a %^C058%^desk%^CRST%^ for working at. It is %^C060%^carved %^CRST%^with a relief "+
      "of %^C064%^stags %^CRST%^and %^C136%^hounds %^CRST%^bounding over hills. The surface has "+
      "been polished to a %^C220%^shine%^CRST%^.\n",
      ({"chair"}) : "This fine %^C124%^high back leather chair%^CRST%^ is expensive and comfortable. "+
      "It is meant to not only look %^C055%^authoritative%^CRST%^ but also fit nicely into a %^C056%^rich %^CRST%^room.\n",
    ]));


set_smell("default","%^C130%^You smell polished wood.%^CRST%^");
set_listen("default","%^C141%^You hear nothing from the hallway in this office%^CRST%^");


   set_exits(([
        "west" : CAER"3",

   ]));
               set_door("wooden door",CAER"3","west",0);
}

void reset()
{
        ::reset();
        if(!present("voice"))
        {
new(MOBS"mordecai")->move(TO);

        }
}
