/* the chicken is an item for the collector quest, please don't
   change its path or the path of this file without notifying the
   questdepartment AND Cadra */
#include <combat.h>
#include <properties.h>
#include <rooms.h>
#include "path.h"

inherit "/std/npc";

create() {
  if (::create()) return 1;
  SetName("guy");
  SetShort("guy Threepwood");
  SetLong(
"It seems that he is searching for Monkey Island(tm).\n");
  SetLevel(8);
  SetRace("human");
  SetAlign(200);
  SetHP(120);
  SetIds(({"guy","threepwood"}));
  SetHands(({ ({"left hand",0,12}),({"right hand",0,15})}));
  SetAC(6);
  SetGender(GENDER_MALE);
  SetGoChance(1);
  SetWimpy(100);
  AddQuestion(({"cave","caves","pirate caves","pirate cave"}),
    "Guy says: Oh, you're looking for the caves? They are somewhere to the "
    "east.\n");
  AddQuestion(({"ship","ships"}),
    "Guy says: All the ships nowadays are pretty boring.\n"+
    "He looks sad.\n"+
    "Guy says: In earlier days pirateships crossed the ocean, but nowadays only\n"+
    "          those passengerships cross the ocean. No ship to have fun on.\n");
  AddQuestion(({"pirate","pirates"}),
    "Guy says: It's long ago since the pirates plundered this coast.\n"+
    "He sniffs.\n"+
    "Guy says: If I could find those caves, probably I could become the first of a\n"+
    "          new pirate generation.\n");
  AddQuestion(({"island","monkey island","meelee island"}),
    "Guy says: I am searching for it too, but none in this world ever heard\n"+
    "          of it.\n");
  AddQuestion(({"master","swordmaster"}),
    "Guy says: Did you meet him? Tell me where!!!!\n"+
    "Guy looks hopefully.\n");
  InitChats(15,({
    "Guy says: Please help me, I'm searching for Monkey Island(tm).\n",
    "Guy says: Where is this damned swordmaster?\n",
    "Guy says: Have you got any coins? I need to buy a ship.\n",
    "Guy says: I need to leave Meelee Island(tm).\n",
    "Guy says: I want to be a real pirate.\n",
    "Guy says: Is it here also always 10 o'clock?\n",
    "Guy says: I hate being a cannonball.\n"}));
  AddItem("/std/weapon",REFRESH_REMOVE,
    ([P_SHORT:"slashmaster",
      P_LONG:"This is THE sword.\n",
      P_WEIGHT:4500,
      P_WC:11,
      P_VALUE:250,
      P_SIZE:PSIZE_NORMAL,
      P_RESET_QUALITY: 99,
      P_IDS:({"slashmaster","sword","master"}),
      P_WEAPON_TYPE:WT_SWORD,
      P_DAM_TYPE:DT_SLASH]),#'wieldme);
  AddItem(PIROBJ("guychick"),REFRESH_REMOVE);
  AddItem("/std/armour",REFRESH_REMOVE,
    ([P_SHORT:"a 100% cotton T-shirt",
      P_LONG:
"The sentence 'I soon will defeat the swordmaster' can be read on it.\n",
      P_IDS:({"shirt","t-shirt"}),
      P_VALUE:20,
      P_WEIGHT:200,
      P_AC:0,
      P_SIZE:PSIZE_NORMAL,
      P_RESET_QUALITY :100, 
      P_ARMOUR_TYPE:AT_CLOAK]),#'wearme);
}

Die() {
  tell_room(environment(this_object()),
    "Guy says: Oh no! I'm dying. Now I'm never able to solve the game.\n");
  ::Die();
}
