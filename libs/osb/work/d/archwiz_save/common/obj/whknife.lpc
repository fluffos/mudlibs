inherit "std/weapon";
#include <properties.h>
#include <combat.h>

create() {
  ::create();
  SetStandard(WT_KNIFE,3,PSIZE_NORMAL);
  AddAdjective("nasty"); AddAdjective("nasty-looking");
  SetShort("a nasty-looking knife");
  SetLong(
"This once belonged to an orc. They call it knife, but it is rather a short "
"sword.\n");
  AddId("knife");
  SetResetQuality(70);
  SetNumberHands(1);
  SetHitObj(this_object());
}

WeaponHit(attacker) {
 int wclass;
 if (attacker && attacker->Query(P_RACE)=="elf") {
    write("smash!\n");
    return 10;
 }
 wclass = random(8)+1;
 if (owner) wclass += random(owner->QueryStr());
 if (wclass>6) wclass=6;
 return wclass;
}
