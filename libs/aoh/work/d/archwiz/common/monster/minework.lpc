inherit "/std/npc";

#include <combat.h>
#include <properties.h>
#include <rooms.h>

create() {
  if (::create()) return 1;
  SetName("mineworker");
  SetShort("a dwarven mineworker");
  SetLong(
"He looks as if he works down here.\n");
  SetIds(({"miner","worker","dwarf","mineworker"}));
  SetAds(({"dwarven","a"}));
  SetRace("dwarf");
  SetLevel(12);
  SetAlign(0);
  SetGender(GENDER_MALE);
  SetAC(4);
  InitChats(20,({
    "Worker says: No admittance to this mine!\n",
    "Worker says: Private property! Keep out!\n",
    "Miner laughs: Go home, tourist!\n",
    "Miner asks: Where is your worker's helmet?\n"}) );
  InitAChats(10,({
    "Worker shouts: Alarm! Alarm!\n"}) );
  AddItem("/std/weapon",REFRESH_REMOVE,#'wieldme,
    ([P_SHORT: "a strong pick",
      P_LONG: "A strong pickaxe. Probably the former owner has been a miner?\n",
      P_IDS: ({"axe","pickaxe","pick","pick-axe"}),
      P_ADS: ({"strong","pick"}),
      P_WC: 7,
      P_SIZE:PSIZE_SMALL,
      P_RESET_QUALITY: 79,
      P_WEIGHT: 2000,
      P_VALUE:  50,
      P_WEAPON_TYPE: WT_AXE,
      P_DAM_TYPE: DT_SLASH]) );
  AddItem("/std/armour",REFRESH_REMOVE,#'wearme,
    ([P_SHORT: "a yellow worker helmet",
      P_LONG:  "It looks pretty yellow.\n",
      P_IDS: ({"helmet","helm"}),
      P_ADS: ({"yellow","worker","a"}),
      P_ARMOUR_TYPE:AT_HELMET,
      P_AC: 1,
      P_SIZE:PSIZE_SMALL,
      P_RESET_QUALITY: 81,
      P_WEIGHT: 500,
      P_VALUE: 80]) );
  AddItem("/std/armour",REFRESH_REMOVE,#'wearme,
    ([P_SHORT: "a pair of sturdy workers gloves",
      P_LONG:  "These gloves look used.\n",
      P_IDS: ({"gloves"}),
      P_ADS: ({"a","pair of","sturdy","workers"}),
      P_WEIGHT: 150,
      P_VALUE: 60,
      P_SIZE:PSIZE_SMALL,
      P_RESET_QUALITY: 55,
      P_AC: 1,
      P_ARMOUR_TYPE:AT_GLOVES]) );
}

init() {
  ::init();
  add_action("go_west","west");
}

int go_west() {
  write("The mineworker bars the way and shouts: ``NO ENTRY''\n");
  return 1;
}
