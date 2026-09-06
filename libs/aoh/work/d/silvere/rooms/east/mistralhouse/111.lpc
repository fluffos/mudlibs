/* Mistral and Joan's House */
/* Kitchen Renovated 11/02/1997 - Mistral and Joan */


#include <properties.h>
#include <config.h>
#include <macros.h>
#include <msgclass.h>
#include <moving.h>
#include <rooms.h>

inherit "/p/houses/common/room/room";

#define DRINK  15

varargs void create() {
  ::create();
  SetIntShort("kitchen");
  SetIntLong("Mistral and Joan's kitchen. One wall is dominated "
  "by a large stone hearth. Inside the hearth a black cauldron "
  "hangs from the spit. Some kindling and logs lie neatly "
  "beneath it. Cooking utensils hang from hooks upon hearth. A "
  "large cupboard graces the far wall, while a small stone well "
  "sits in a far corner. A worn maple table and some chairs "
  "complete the cozy kitchen.\n");

AddDetail( ({"hearth"}),"It is a stone hearth. Well used, but "
             "clean.\n");
AddDetail( ({"utensils"}),"You see a few wooden cooking utensils: "
             "large spoon, fork and spatula.\n");
AddDetail( ({"kindling"}),"Just a few dried sticks sitting beneath "
             "a some split logs.\n");
AddDetail( ({"logs","log"}),"Three large split logs lie atop "
             "a small pile of kindling.\n");
AddDetail( ({"spit"}),"Both ends of a long thick iron rod, "
             "which horizontally spans the length of the hearth, "
             "are inserted into stone walls of the hearth.\n");
AddDetail( ({"dinnerware","dishes"}),"It is just an assortment "
             "of china dishes and cups. There are a few glasses "
             "and some knives, forks, spoons and some crockery.\n ");
AddDetail( ({"stone","stones"}),"They are just plain grey stones. "
             "The mason did a fine job constructing the well and "
             "hearth.\n");
AddDetail( ({"spices","spice"}),"You look through the spices and "
             "you see the usual collection of kitchen spices. Salt "
             "pepper and such...hmm..Thats right! Joan is a witch. "
             "That explains: pickled lizards tongue, eye of newt, "
             "powdered arsenic, marinated toad's hair and such. "
             "You shiver!");

AddVItem(
 ([ P_IDS : ({ "well","stone well"}) ,
    P_ADS : ({ "well" }) ,
    P_LONG : "You look into the corner and see a small stone well. "
    "It is about 1 meter high and 1/2 meter in diameter. There is "
    "an old wooden wooden bucket tied to a hand crank. The bucket "
    "is full of of fresh water. Perhaps you can drink some or fill "
    "up a container. \n",
    P_SMELL : "The water smells fresh and sweet.\n",
    P_NOISE : "You a whisper from the well: A secret...secret..\n",
 ])
);

//AddItem("/players/joan/obj/basket", REFRESH_REMOVE);

AddVItem(
 ([ P_IDS : ({ "table"}) ,
    P_ADS : ({ "maple table", "kitchen table" }) ,
    P_LONG : "It is a well worn and scrubed maple table. "
    "It looks very old. Mistral, Joan and Jr. probably eat their "
    "meals here.\n"
 ]) );


AddVItem(
 ([ P_IDS : ({ "cauldron"}) ,
    P_ADS : ({ "black cauldron", "iron cauldron", "cauldron"}) ,
    P_LONG : "It is a black iron cauldron. It has seen lots "
    "of use.\n"
 ]) );

AddVItem(
 ([ P_IDS : ({ "chair","chairs"}) ,
    P_ADS : ({ "maple chairs", "chair", "chairs"}) ,
    P_LONG : "It is just a plain straight backed old wooden chair. "
    "It matches the table. Maybe you could sit on one.\n"
 ]) );

AddVItem(
 ([ P_IDS : ({ "cupboard"}) ,
    P_ADS : ({ "maple cupboard", "cupboard", "hutch"}) ,
    P_LONG : "It is just a plain old maple hutch. The usual "
    "assortment of dinnerware and spices are stacked on the "
    "shelves.\n"
 ]) );

   SetIntSmell("The aroma of fresh baked bread still lingers "
   "in the air.\n");

  Set(P_REFILL, "water");

  AddRoomCmd("drink", "cmd_drink");
  AddRoomCmd("sit", "cmd_sit");

  AddExit("up","./112");
  AddExit("north","./011");
//  AddExit("rootcellar","/players/joan/xfiles/rooms/house/rcellar");
}

int cmd_drink(string str)
{

  if(!str)
  {
     notify_fail("Drink what from what?\n");
     return 0;
  }

  str = norm_id(str);

  if(str != "water" && str != "water from well" && str != "from well")
  {
    notify_fail("Drink what from what?\n");
    return 0;
  }

  if ( (({int})TP->QueryDrink() + DRINK) > ({int})TP->QueryMaxDrink() )
  {
    notify_fail("You can't drink that much.\n", NOTIFY_NOT_VALID);
    return 0;
  }

  TP->AddDrink( DRINK );

  write("You quench your thirst with the clear, cold water.\n");
  msg_say( CMSG_SAY, NAME(TP) + " drinks from the well.\n", TP );

  return 1;
}

int cmd_sit(string str)
{

  if(!str)
  {
     notify_fail("Sit on what?\n");
     return 0;
  }

  str = norm_id(str);

  if(str != "on chair" && str != "on maple chair" && str != "on old chair")
  {
    notify_fail("Sit on what?\n");
    return 0;
  }

  write("You sit on the comfortable old chair.\n");
  msg_say( CMSG_SAY, NAME(TP) + " sits on the old chair.\n", TP );

  return 1;
}
