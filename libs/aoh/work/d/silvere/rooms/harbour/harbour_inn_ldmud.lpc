// This is an inn at the harbour
// created:          Sonic [26-May-1997]
// last changed:     Tune  [29-May-1997]
//                   Sonic [05-Jul-1997] added region/coordinates
//                   Mica  [29-Jul-1997] added a newsboard temp.
//                   Chara [22-Aug-1997] added sailors and song
//                   Chara [04-Sep-1997] added a snide reference to NF
//                   Tune  [08-Oct-1997] added a menu reference in the long


#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <health.h>
#include <macros.h>
#include <rooms.h>
inherit "/std/pub";

varargs void create()
{
   ::create();
   Set(P_INDOORS,1);
   Set(P_INT_SHORT,"The Seaman's Rest");

   Set(P_INT_WIZMSG,
    "This is a small inn. Nothing spectacular, but strong drink. "
    "The exit is to the north.\n");

   Set(P_INT_LONG,
    "Rough trestle tables stand scattered about the snug common room "
    "of the Seaman's Rest, stained and scratched from long years of "
    "use. Sawdust covers the pine plank floor, and small dirty windows "
    "look out on the harbour of Silvere. The landlord serves from "
    "behind a battered counter, and a number of sailors are sitting at "
    "the tables, loudly singing a sea shanty. Barrels of wine and ale "
    "are stacked along the walls. A warped, hand-painted sign hangs "
    "on one wall; presumably, this is the menu.\n");

   AddDetail(({"sailor", "sailors", "seamen", "seaman"}),
    "The sailors seem to be deep in their cups already, and are "
    "singing with much drunken gusto, if not much talent.\n");

   AddDetail("landlord",
    "The landlord is a retired sailor himself, and looks like he knows "
    "how to handle this rowdy bunch. His arms bulge with muscles, his "
    "skin looks as tough as leather, and his sharp eyes seem to "
    "miss nothing.\n");

   AddVItem( 
    ([ P_IDS : ({ "barrel", "barrels" }),
       P_ADS : ({ "wine", "ale" }),
       P_LONG : ({
        "The barrels are made of worn wood, and have a spigot for easy "
        "pouring. There are enough of them that the landlord need not "
	"fear running out any time soon.\n" }),
       P_READ_MSG : 
        "A few barrels have branded on them 'Vinted exclusively "
        "in Silvere' and 'Distilled under royal license of the Lu'meyna "
        "of Silvere'.\n"
  ]) );

   AddVItem(
   ([ P_IDS:({"sawdust"}),
      P_ADS:({"soiled"}),
      P_LONG:
    "They should think about changing it soon; no telling how many "
    "sailors and shipmen have trodden on it.\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"floor","ground"}),
      P_ADS:({"stained","yellow","pine","plank"}),
      P_LONG:
    "Stained yellow pine planks covered with a scattering of soiled "
    "sawdust.\n",
   ]) );

   AddDetail( ({"plank","planks"}),
       "Some of the planks seem to be from the wreckage of a ship. "
       "You can make out a couple of letters that have not been "
       "obliterated by time and ale stains.  There seems to be a "
       "'B', a 't', and a 'y' still visible. This plank is "
       "securely nailed down, and is going nowhere!\n");

   AddWindow( "dirty window",
    "These windows could use some cleaning. However, you can still "
    "make out the harbour through the spiderwebs and smears of dirt.\n",
     SIL_HARBOUR("street1"),
     ([ P_IDS : ({ "windows" }) ]) );

   AddDetail("harbour",
    "You can make out men bustling around the harbour through the "
    "dirty windows.\n");

   AddDetail("battered wooden counter",
    "A battered wooden counter with a few taps for barrels of beer.\n");

   AddVItem(
    ([ P_IDS:({"sign","menu"}),
       P_ADS:({ "hand-painted", "warped" }),
       P_LONG:  #'QueryMenu,
       P_READ_MSG:  #'QueryMenu
    ]) );

   SetIntNoise ("The sailors' singing drowns out most other noise. "
    "Perhaps if you listen to the song, you'll hear the words to "
    "the shanty.\n");

   AddNoise (({"song", "shanty", "the song"}), // better way to do this?
    "The sailors drunkenly belt out...\n\n"
    "  I am a brisk and sprightly lad\n"
    "  But just come home from sea, sir.\n"
    "  Of all the lives I've ever led\n"
    "  A sailor's life for me, sir.\n\n"
    "  Yeo, Yeo, Yeo,\n"
    "  Whilst the boatswain pipes all hands\n"
    "  With a yeo, yeo, yeo!\n\n");
 
   AddNoise (({"sailor", "sailors"}),
    "The sailors' singing drowns out most other noise.  Perhaps if you "
    "'listen song' you can hear the words to the shanty.\n");

   SetMenuHeader(
    "+----------------- The Seaman's Rest --------------------+\n"
    "                                                             \n");


   AddDrink(({"a pint of amber ale","ale","pint of ale" }), 
     10, (BEER_ALCOHOL-1), 12, 0,
    "You drink down a deep amber pint of ale.");

   AddDrink(({"a glass of red wine","wine", "red wine"}),
     11, WINE_ALCOHOL, 10, 0,
    "You quaff a glass of cheap red wine.");

   AddDrink(({"shot of imported rum", "rum", "imported rum"}),
     12, HARD_ALCOHOL, 7, 0,
    "The rum tingles as it slides down your gullet.");

  AddDrink(({"Mica Dark", "dark beer"}),
    15, (BEER_ALCOHOL+2), 11, 0,
    "This beer is darker than the evil soul of Mica!");

  AddDrink(({"Tune's Tequila Sunrise", "tequila", "tune's"}),
    15, (HARD_ALCOHOL+2), 8, 0,
    "It's rumored that this has killed many archwizards!");

  AddDrink(({"Superj's Stout", "stout", "superj's"}),
     8, (BEER_ALCOHOL+3), 11, 0,
     "A hearty beer that is left idling to improve taste.");

  AddDrink(({"Elfgarian Shandy", "shandy", "alsterwasser"}),
     7, 9, 5, 0,
     "The shandy tastes lightly sweet with a bitter undertone. Refreshing!");

  AddDrink(({"Sykoran cider", "cider" }), 
     8, (LOW_ALCOHOL+1), 14, 0,
     "A bitter, smoky cider taste." );

   AddFood(({"a plate of lamb stew","stew","lamb stew" }),
     8, 40, 0,
    "You consume a plate of hearty lamb stew.");

   AddFood(({"a plate of cheese and bread", "cheese and bread"}),
     6, 25, 0,
    "You eat some tangy white cheese and a slice of crusty bread.");

   AddFood(({"buxtehuden rudel pickles", "pickles", "rudel pickles"}),
     2, 9, 0,
    "Eeeeh, these are sour!");
    
   SetMenuFooter(
    "                                                             \n"
    "+--------------------------------------------------------+\n");


   Set(P_HELP_MSG,
    "This is a tavern where you can order food and drink. Just 'read "
    "menu' to see what the tavern offers, then 'buy <food or drink>'. "
    "You can also 'buy <something> for <someone else>'.\n");

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -200,20,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,"You run into a wall.\n");
   AddExit("north",SIL_HARBOUR("entrance"));

   AddItem( "/std/board", REFRESH_HOME,
          ([ P_SHORT : "the central board",
             P_LONG  : "This is the central board.\n",
             "Groups" : ({ "players", "ideas\\.*", "flames", "ponder" })
            ]) );

}
