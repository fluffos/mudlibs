#include <mudlib.h>

inherit ARMOR ;

void create() {
  set("id" , ({ "boots" }) );
  set("short" , "a pair of hard boots");
  set("long" , @EndLong
  A pair of enhanced boots, they seem to shimmy in front of you.

EndLong
);
  set("size" , -1);
  set("bulk" , 1);
  set("mass" , 2);
  set_armor_type("boots");
  set("magic_defense" , 5);
  set("value" , 1500);

  set("armor_object" , 1);
  set("equip_func" , "equip_func");
  set("unequip_func" , "unequip_func");

}
string equip_func() {
  if(this_player()->query("stat/dexterity") > 20) {
    return "the boots seem to be doing nothing for you.";
  }
  this_player()->set("stat/dexterity" , 20);
    return "you feel more dexterious already";
  }
string unequip_func() {
  this_player()->set("stat/dexterity",(this_player()->query("base_stat/dexterity")) );
    return "you feel your dexterity decrease." ;
	}
