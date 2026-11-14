#include <rooms.h>
#include <money.h>
#include <properties.h>

inherit "std/npc";

create() {
  if (::create()) {return;}
  SetName("Baby Troll");
  SetShort("a little baby troll");
  SetLong("It looks nasty...\n");
  SetRace("troll");
  SetIds(({"troll"}));
  SetAds(({"a","nasty","fierce","little","baby"})); 
  SetLevel(1);
  SetAttribute("MagicDefence",10);
  SetAlign(-10);
  SetSize(PSIZE_NORMAL);
  SetAC(0);
  SetMaxHP(25);
  SetHP(22);
  SetGender(GENDER_MALE);
  SetHands(({({"left hand",0,6}),({"right hand",0,6})}));
  AddItem("/obj/money",REFRESH_REMOVE,
    (["Money":MONEY_DEMON->CreateMoney((random(2)+1),({"silver"}))]));
}

init() {
  ::init();
  add_action("go_north","north");
}

int go_north() {
  write("A fierce troll blocks your way.\n");
  return 1;
}
