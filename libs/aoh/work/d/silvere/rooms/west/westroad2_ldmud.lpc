// A long, wide road from the gates to the west toward the palace
// created:       Sonic    [29-May-1997]
// last changed:  Sonic    [01-Jul-1997]  added region/coordinates
//                Tune     [12-Dec-1998]  trying to add something!
//                Auryn    [24-Apr-1999]  added a few details

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
#include <nightday.h>
#include <msgclass.h>

inherit SILBASEROOM;

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);

   Set(P_INT_SHORT,"Westway");
   Set(P_INT_LONG,
    "The wide, paved Westway of Silvere passes along the narrow, "
    "brightly painted houses of rich merchants and their shop fronts, "
    "@@TimeMsg@@. "
    "Decorated signs hang above many of the shops, declaring a variety "
    "of wonderous wares to be found within.\n"
    "A small lane leads off to the north, and through its meanderings "
    "and twistings can be glimpsed a bright white building.\n");

   Set(P_INT_WIZMSG,
    " NORTH: To the temple of Xalandre.\n"
    " WEST: to the harbour.\n"
    " EAST: deeper into the city.\n");

   Set(P_TIME_MSG,
    ([ DAY_DEFAULT_MSG:"shutters open wide, beckoning all to enter and "
         "squander their hard-earned savings",
      NIGHT_DEFAULT_MSG:"shuttered and shut up for the night",
      ND_SUNSET:"shuttered and shut for the night, though the outlines of "
        "merchants, huddled over a candle counting their day's receipts "
        "can be made out through windows",
      ND_DAWN:
        "shuttered and shut, not yet open for another day's business",
      ND_SUNRISE:
        "shuttered and shut, not yet open for another day's business"
   ]) );

   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -170,10,0 }), C_SILVERE }) );

   AddExit("north",  SIL_WEST("templeroad1"));
   AddExit("west",   SIL_WEST("westroad1"));
   AddExit("east",   SIL_WEST("westroad3"));

   AddVItem(
   ([  P_IDS:  ({ "building", "temple"}),
       P_ADS:  ({ "bright", "white" }),
       P_LONG:
    "Through the twistings of the northerly lane, you can barely make "
    "out what seems to be some sort of temple.\n"
    ]) );

   AddVItem(
   ([  P_IDS: ({ "westway", "road", "street" }),
       P_ADS: ({ "wide", "paved" }),
       P_LONG:
        "This is the main road of Silvere. It leads east and west through "
	"the city. The street is paved with large flagstones and swept "
	"meticulously clean. During daytime, this is one of the busiest"
	"parts of the city.\n"
    ]) );

   AddVItem(
   ([ P_IDS: ({ "stones", "flagstones", "pavement" }),
      P_ADS: ({ "large", "grey" }),
      P_LONG:
       "The road is paved with large grey flagstones, which have been set "
       "so precisely that they fit together almost seamlessly. They are "
       "carefully kept clean of dirt and weeds.\n"
    ]) );

   AddVItem(
   ([  P_IDS:  ({ "lane" }),
       P_ADS:  ({ "small" }),
       P_LONG:
    "A small lane branches off Westway here, winding its way north. "
    "It seems to lead to the large white building you can just glimpse "
    "in the distance.\n"
    ]) );

   AddVItem(
   ([  P_IDS:  ({ "signs", "placards" }),
       P_ADS:  ({ "hanging", "wooden", "decorated", "painted" }),
       P_LONG:
        "Oblong, square, spiral, round -- the merchants of Silvere lack no "
        "amount of imagination in creating the painted wooden placards which "
        "hang above their shops, loudly advertising endless ways to lighten "
        "your pockets and add weight to your load.\n",
       P_READ_MSG:
        "Imported wines, hand-crafted weapons, rare maps, fine foods, brocaded "
        "silks, exotic furnishings -- just "
        "a small selection of the sumptuous goods which can be had -- for "
        "a price, naturally -- along the Westway.\n"
   ]) );

   AddVItem(
   ([ P_IDS: ({ "shops", "shop fronts", "fronts" }),
      P_ADS: ({ "painted" }),
      P_LONG:
       "You see many different shops lining the street, @@TimeMsg@@. It seems "
       "that there is nothing you can't buy in Silvere -- if you have the "
       "money, of course. Merchants offer things for everyday life, like "
       "food and clothes, as well as luxury goods. Just look around and "
       "see what you can find. \n"
    ]) );

   AddVItem(
   ([ P_IDS: ({ "houses", "house" }),
      P_ADS: ({ "painted" }),
      P_LONG:
       "The houses along Westway are painted in bright colours, many of "
       "them with beautiful decorations. They belong mostly to merchants, "
       "who usually have set up their shops on the ground floor.\n"
    ]) );

}

// messages for opening and closing the shops

mixed FilterWeatherData (object client, mixed *data, int newstate)
{
   string msg;
   msg = "";

   if ( newstate == ND_TWILIGHT )
   {
      msg = "As the sun sets on another day in Silvere, the merchants come "
            "out, one by one, and shutter up the shops for the night.\n\n";
   }
   else if ( newstate == ND_EARLY_MORNING )
   {
      msg = "The merchants of Silvere emerge from their shops and unbar "
            "the windows in preparation for another day of haggling.\n\n";
   }

   call_out("open_or_close_shops", 6, client, msg);

   return ::FilterWeatherData( client, data, newstate );
}

void open_or_close_shops(object cl, string s)
{
   msg_object( cl, CMSG_ROOM, s );
}

