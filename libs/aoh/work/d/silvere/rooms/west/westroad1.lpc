// A long, wide road from the gates to the west toward the palace
// created:       Sonic    [29-May-1997]
// last changed:  Sonic    [01-Jul-1997]  Added region/coordinates
//                Tune     [08-Oct-1997]  Added the turnable stone,
//                                        room desc, details

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
#include <msgclass.h>
#include <macros.h>
#include <money.h>

inherit SILBASEROOM;

int is_turned;    // is the paving stone up or down?
int is_plat;      // is there money to be found?

varargs void create()
{
   ::create();

   Set(P_INDOORS,0);

   is_turned = 0;
   is_plat = 1;

   Set(P_INT_SHORT,"The Westway");
   Set(P_INT_WIZMSG,
    " WEST:  to the harbour.\n"
    " EAST:  deeper into the city.\n"
    " NORTH: leads to a healer\n"
    " SOUTH: to the city information center.\n");

   Set(P_INT_LONG,
    "This is the regal Westway of Silvere, paved with great grey "
    "flagstones, lit at night, and lined with shops and the "
    "well-kept houses of rich merchants. "
    "The road is kept clean and in good repair, for it is the main "
    "causeway into the city, wending its way eastward to the very "
    "steps of the palace. "
    "Directly to the west are the imposing great gates of the city. "
    "A small alley opens to the north, and a larger road leads off "
    "to the south.\n");

   AddVItem(
    ([  P_IDS: ({ "flagstones", "stones" }),
        P_ADS: ({ "paving", "great", "grey", "flat", "smooth" }),
	P_LONG:
    "Grey, smooth rectangular paving stones cover the Westway, "
    "protecting feet and cart wheels from thick mud during the "
    "rainy season. One of the stones near your feet is cracked "
    "and seems to be a bit loose.\n"
    ]) );

   AddVItem(
    ([  P_IDS: ({ "flagstone", "stone" }),
        P_ADS: ({ "paving", "cracked", "loose" }),
        P_LONG:
     "One of the flagstones is loose, and with a bit of effort, "
     "it might be possible to lift it up.\n"
    ]) );

   AddDetail("shops",
    "Some of the finest and most expensive shops in the realm can be "
    "found along the Westway.\n");

   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -180,10,0 }), C_SILVERE }) );

   AddExit("north",SIL_WEST("whealer1"));
   AddExit("south",SIL_WEST("cityinfo1"));
   AddExit("west", SIL_WEST("harbourgate"));
   AddExit("east", SIL_WEST("westroad2"));

   AddRoomCmd("lift", "cmd_lift");
}

void reset()
{
  ::reset();
  is_plat = 1;
}


int cmd_lift(string str)
{
  string *arr;
  object ob;

  if(!str)
  {
    notify_fail("Lifting air is fun, isn't it?\n", NOTIFY_ILL_ARG);
    return 0;
  }

  // icky-parsing-stuff

  arr = norm_id(str, 1);

  // the logic here is that the object of the command should always
  // be the last word. Not perfect, but what is?

  if(-1 == member(({"stone","flagstone"}), arr[sizeof(arr)-1] ) )
  {
    notify_fail("Well, you can try ... \n", NOTIFY_NOT_VALID);
    return 0;
  }

  if(is_turned)
  {
    write("You heave up the already-turned stone a bit further, "
     "but it slips from your grasp and you succeed only in "
     "dropping it squarely upon your foot. Ouch!!\n");
    return 1;
  }

  msg_room( environment(this_player()), CMSG_ROOM|MMSG_SEE,
     ({ ({string})TP->QueryName() +" gingerly pries up one of the paving "
        "stones from the road and looks beneath it.\n",
        "You hear a sound of softly grating stone.\n"
     }), TP );


  if(is_plat)
  {
    ob = clone_object(MONEY);
    ob->Set(P_MONEY, ([ "platinum" : 1 ]) );
    ob->move(environment(TP), M_SILENT);

    write("You manage to pry up one of the large flagstones and "
        "find a dully gleaming coin beneath it.\n");
  }
  else
  {
    write("You manage to pry up one of the large flagstones but "
      "find nothing of interest.\n");
  }

  SetExtraEntry ("upturned stone", P_INT_LONG,
    "One of the stones near your feet has been "
    "pulled up, leaving a gap in the neat paving.\n");

  call_out("return_stone", 120);

  is_turned = 1;
  is_plat = 0;

  return 1;
}

void return_stone()
{
  msg_room( this_object(), CMSG_ROOM|MMSG_SEE,
     ({ "A man in a rough coat carrying a broom saunters along. "
        "He catches sight of the upturned stone, and quickly tips "
        "it back into place. As he walks away, you see that the "
        "back of his coat is embroidered with a bright sigil of "
        "four griffins.\n",
        "You hear a sound of softly grating stone and a "
        "muffled *plop*.\n"
     }) );

  is_turned = 0;

  RemoveExtraEntry("upturned stone", P_INT_LONG);
}
