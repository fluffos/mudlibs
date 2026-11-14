#include "path.h"
#include <rooms.h>
#include <combat.h>
#include <moving.h>
#include <properties.h>

inherit "/std/npc";

help_player() {
  if (!this_player()) return 0;
  if (!this_player()->QueryQuestSolved("rescue_riding_hood")) {
    this_player()->move(PARK("wolfplace"),M_SILENT);
    write(
"The witch says: Oh dear.. little red riding hood has been eaten?\n"
"  Hurry on to rescue her! I will help you by bringing you to the place\n"
"  where the big bad wolf lives.\n"
"The witch teleports you somewhere.\n");
    tell_room(PARK("wolfplace"),
      this_player()->QueryName()+
	" arrives with some smoke.\n",({this_player()}));
    this_player()->LookAfterMove();
    return "";
    }
  return
"The witch says: You are joking! She is not that stupid to make the same\n"
"  mistake a second time. You've already rescued her from that situation\n"
"  once. She will probably just be playing with her friends somehwere\n"
"  else.\n";
}

create() {
  if (::create()) return 1;
  SetRace("human");
  SetName("good witch");
  SetShort("the good witch of the west");
  SetLong("The good witch of the west is maintaining some flowers.\n");
  SetIds(({"witch","woman","witch of the west"}));
  AddAdjective("good");
  SetLevel(6);
  SetAlign(120);
  SetAC(6);
  SetGender(2);
  SetHands( ({ ({"left hand",0,1}),({"right hand",0,12}) }) );
  SetWimpy(20);
  AddQuestion(({"riding hood","little red riding hood","hood","girl",
    "red riding hood"}),
"The witch smiles.\n"
"She says: Oh.. she is a darling. All animals around love her.\n");
  AddQuestion(({"wolf","help","problem"}),#'help_player);
  AddQuestion("hunter",
"The witch says: Last time I've seen him he told me about the little\n"
"  foxes and that mother fox would not feel good right now.\n");
  AddQuestion("grandma",
"The witch says: Grandma is a wonderful woman. I know her for ages now.\n");
  AddItem("/std/armour",REFRESH_REMOVE,#'wearme,
    ([P_SHORT: "A white witchrobe",
      P_LONG: "A white robe, with some runes on it.\n",
      P_IDS: ({"robe","cloak","witchrobe"}),
      P_ADS: ({"white","witch"}),
      P_DEFENCES: ({1,0,0,0,2,1}),
      P_MAGIC: 1,
      P_RESET_QUALITY: random(80)+20,
      P_ARMOUR_TYPE:AT_CLOAK,
      P_WEIGHT: 2000,
      P_VALUE: 300]));
  AddItem("/std/weapon",REFRESH_REMOVE,#'wieldme,
    ([P_SHORT: "a long broom",
      P_LONG: "This broom looks strange, perhaps this could be a witchbroom?\n",
      P_IDS: ({"broom","withbroom"}),
      P_ADS: ({"long","witch"}),
      P_VALUE: 300,
      P_WC: 11,
      P_NUMBER_HANDS: 1,
      P_WEAPON_TYPE:WT_CLUB,
      P_DAM_TYPE:DT_BLUDGEON,
      P_WEIGHT: 4000,
      P_RESET_QUALITY: random(70)+30,
      P_SIZE:PSIZE_NORMAL]));
  AddItem(OBJ("mastermind"),REFRESH_REMOVE);
}
