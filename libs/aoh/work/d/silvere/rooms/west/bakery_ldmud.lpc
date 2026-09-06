// created:          Tune    [??-Jan-1996]
// updated:          Tune    [24-Apr-1999]

#include <properties.h>
#include <rooms.h>
#include <silvere.h>
#include <nightday.h>
#include <msgclass.h>

inherit "/std/shop";

// -- prototypes -----

string todays_sign();
void add_my_articles();
void set_special();
void init_baked_goods();

// -- global variables ----

string todayspecial_sign;
string todayspecial_file;
string *food_array;

varargs void create()
{
  ::create();
  SetIntShort("Eldranna's Bake Shoppe");
  SetIntLong(
  "The pleasant aroma of freshly baked bread and wood smoke mingle, "
  "assaulting your sense of hunger as you step into the bake shoppe. "
  "Pine shelves filled with breads and pasteries tantalize you from behind "
  "the counter. A chalkboard hangs on one wall.\n");

  AddDetail( ({"shelf", "shelves" }),
    "Several pine shelves are fixed to the back wall of the small bake shop.\n"
    "Breads and pastries are arranged in neat rows accross the shelves.\n");

  AddDetail( ({"bread","breads", "pastry", "pastries", "row","rows" }),
    "Look at the chalkboard to see what Eldranna has baked today.\n");

  SetBright(20);
  SetIndoors(1);

  SetAppraise(0);
  SetIdentify(0);
  SetSell(0);

  RemoveDustbin();

  SetShopkeeper("/d/silvere/npc/eldranna");

  AddExit("east", SIL_WEST("councilroad1"));

  init_baked_goods();   // fills the array
  set_special();   // selects one of the foods and makes it the daily special

  add_my_articles();

  SetIntSmell("The sweet, doughy smell of baking bread and acrid wood smoke "
    "assails your nose.\n");


  AddVItem(
  ([  P_IDS : ({ "chalkboard", "blackboard", "board" }),
      P_ADS : ({ "special", "black" }),
      P_LONG : #'todays_sign /*'*/,
      P_READ_MSG : #'todays_sign /*'*/
   ]) );

  AddWindow( "large window",
              "Small, wavy panes of glass set into a wooden frame.\n",
              SIL_WEST("councilroad1"),
              ([ P_IDS : ({ "windows" }) ]) );
}

void add_my_articles()
{
    string tmp;
    int x;

    for(x = 0; x < 3; x++)
    {
       tmp = random_select(food_array);
       AddArticle(tmp, REFRESH_NONE, 5);
       food_array -= ({ tmp });
    }
}

// needs to be reinitialized every "mud-day"

void init_baked_goods()
{
   food_array =
     ({ "/d/silvere/obj/bakery/croissant",
        "/d/silvere/obj/bakery/raspberrytart",
        "/d/silvere/obj/bakery/doughnut",
        "/d/silvere/obj/bakery/blueberrypie",
        "/d/silvere/obj/bakery/appletart",
        "/d/silvere/obj/bakery/sweetroll",
        "/d/silvere/obj/bakery/scone"
      });
}


/*  Ideas:
      "sticky buns",
 "meat pasties", "mincemeat pie", "apple pie",
"blueberry tarte", "bread rolls", "raisin buns",
"cheese tarte", "a loaf of bread"
}
*/


string todays_sign()
{
   return
  " +--------------------------------------------------+ \n"
  " |              Eldranna's Bake Shoppe              | \n"
  " |                    ~ ~ ~ ~ ~                     | \n"
  " |                Our daily special                 | \n"
  " |                                                  | \n"
  " |"  + sprintf("%|49s", todayspecial_sign ) + " | \n"
  " |           (30% off the normal price!)            | \n"
  " +--------------------------------------------------+ \n";

}

// ----------------------------------------------------------------------
//  set_special()
// ----------------------------------------------------------------------
//  Chooses one item from the stock of items, clones it and adds it,
//  to the shop, then removes it from the array of items ands
//  sets the sign string to display the special of the day.
// ----------------------------------------------------------------------

void set_special()
{
   object ob;

   todayspecial_file = random_select(food_array);

   AddArticle( todayspecial_file, REFRESH_REMOVE, 4 );

   food_array -= ({ todayspecial_file });

   ob = find_object( todayspecial_file );
   if( ob )
   {
      todayspecial_sign = ({string})ob->Query("special_of_the_day");

      if(!todayspecial_sign)
         todayspecial_sign = ({string})ob->QueryShort();  // just in case...
      if(!todayspecial_sign)
         todayspecial_sign = "None Today";
   }
}

// ----------------------------------------------------------------------
//  ModifyPrice()                    [/std/shop/trading.c]
// ----------------------------------------------------------------------
//  Checks if the object bought is the special of the day.
//  If yes, returns a 30% discount on the price.
// ----------------------------------------------------------------------


int ModifyPrice(object ob, int price, string verb)
{

   if( ( (explode(object_name(ob),"#")[0]) == todayspecial_file) &&
        verb == "buy" )
   {
       price = (price * 7) / 10;  // 30% discount
       return price;
   }

   return ::ModifyPrice(ob,price,verb);
}


mixed FilterWeatherData(object client, mixed *data, int newstate)
{
   if ( newstate == ND_EARLY_MORNING )
   {
      msg_object(client, CMSG_ROOM,
         "Eldranna sets up the shop in anticipation of another "
         "busy day. She sweeps up a bit, fills the shelves with "
         "freshly baked goods, and chalks in a new special of "
         "the day.\n");
      init_baked_goods();
      set_special();
      RemoveStore();
      add_my_articles();
   }

   return ::FilterWeatherData( client, data, newstate );
}

