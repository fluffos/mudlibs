#include <mudlib.h>   //This calls all the neat stuff Cy programed

inherit WEAPON;

void create() {
  seteuid(getuid());
  set_weapon_type("axe/two-handed");
  set("name" , "axe");
  set("id" , ({ "axe" , "battle axe" }) );
  set("short" , "a large two-handed battle axe");
  set("long" , @EndText
  This looks as if it has been to hell and come back after having slain
  everything. The triple blades are encrusted with blood, and the large
  wooden handle is wrapped with a leather thong. Truly a weapon that
  is geared to cleave and smash opponenets. It will probably fetch a
  formidable price at the shop.

EndText
);
  set_bonus(1,0,3);
  set("nosecond" , 1);
  set_verbs( ({ "smash" , "cleave" , "pummel" }) );
  set_verbs2( ({ "smashes" , "cleaves" , "pummels" }) );
  set("value" , 15000);
  set("damage" , ({ 10,30 }) );
  set("natt_bonus" , 1);
}
