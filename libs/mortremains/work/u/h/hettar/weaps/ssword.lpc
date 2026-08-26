#include <mudlib.h>

inherit WEAPON;

void create(){
seteuid(getuid());
  set("author", "hettar");

   set("name", "shortsword");
   set_weapon_type("sword/hand");
   set_weapon_type("sword/short");
   set_material_type("metal/steel");
   set("id", ({ "sword", "shortsword" }) );
   set("short", "a finely crafted shortsword");
   set("long", @Endtext
This fine piece of weaponry should perform excellenly.
Endtext
);
   set_bonus(2,2,2);
   set("damage", ({15,30}));
   set("nosecond", 0);
   set_verbs( ({ "slice", "filet", "slash" }) );
   set_verbs2( ({ "slices", "filets", "slashes" }) );
   set("value", 1000);


 }
