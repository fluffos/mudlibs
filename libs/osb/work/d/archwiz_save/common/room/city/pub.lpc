#include <config.h>
#include "path.h"
#include <rooms.h>
#include <moving.h>
inherit "room/pub";

#define ADV_ATTR "AdventArchwizPub"
// Attribute storing the time() of the last free order.

string old_change;

go_east() {
  if (!this_player()) return 0;
  if (!query_once_interactive(this_player())) return;
  return this_player()->move("/room/restroom",M_GO,"east");
}

void create() {
  string sign;
	::create();
	SetIntShort("The local pub of Nightfall City");
	SetIntLong(
"You are in the local pub of Nightfall City. It is probably the biggest pub "
"in the world but surely the oldest. This pub has a long tradition. Many "
"mighty wizards and Archwizards have once drunken their beers and "
"firebreathers here in these rooms! Now you are to step into their footsteps.\n"
"You can order drinks here or 'buy [drink] for [somebody]. To see what you "
"can drink here, just 'read menu'! Cheers!\n"
"The exit lies to the west, a funny doorway leads east. "
"In one corner a stairway leads up. There is a sign attached to one wall.\n");
  sign = "  /---------------\\\n"
         "  | Spelunkers    |\n"
         "  |      Welcome! |\n"
         "  \\---------------/\n"
       ;
  AddDetail("sign", "The sign has been attached recently. It reads:\n"+sign);
  AddReadMsg("sign", sign);
        AddExit("west", "./yard");
        AddExit("up", "./pubattic");
        AddExit("east",#'go_east);
        AddDrink("special",10,8,10,0);
        AddDrink("coffee",0,0,2,20);
        AddDrink("firebreather",25,20,12,140);
        AddDrink("beer",0,2,2,3);
        if (-1 != member( ({ "Oct", "Nov", "Dec", "Jan", "Feb"})
                        , ctime()[4..6])
           )
          AddDrink( "mulled wine", 25,20, 12, 100
                  , "As you drink, warm fires run through your veins.");
  AddItem( "/obj/toplist", REFRESH_REMOVE );
	AddItem(OBJ("Go/rules"), REFRESH_REMOVE);
        AddItem(OBJ("Go/go_player"),REFRESH_HOME);
  old_change = QueryDiscountFunc();
  SetDiscountFunc("SpelunkerDiscount");
}

/*---------------------------------------------------------------------------*/
int SpelunkerDiscount(int value)

/* The first order per NF-Day is free for Spelunkers.
 */
  
{
  if (ADVENT("i/advlib")->SolvedAdvent(this_player()))
  {
    if (time() - this_player()->QueryAttr(ADV_ATTR) >= DAY_LENGTH)
    {
      write("Aah, you're a true Spelunker. Then this one is on the house!\n");
      this_player()->SetAttr(ADV_ATTR, time());
      return 0;
    }
  }
  
  if (stringp(old_change))
    return call_other(this_object(), old_change, value);
  return value;
}
