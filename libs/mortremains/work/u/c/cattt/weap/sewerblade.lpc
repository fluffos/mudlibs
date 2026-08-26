#include <mudlib.h> 

inherit WEAPON;

void create() {
   seteuid(getuid());
   set("author", "cattt");
   set("name", "SewerBlade");
   set("id", ({ "blade", "SewerBlade", "sewerblade", "sword" }) );
   set("short", "The legendary SewerBlade");
   set("long", "The long mithril blade assures you that this must "+
    "be the legendary SewerBlade.  Ancient engravings of dragons "+ 
    "and warriors grace the blade. It looks as deadly as the battle "+
    "portrayed on it. \n");
   set_bonus(0,1,3);
   set("damage", ({ 500,2000 }) );
   set("type", "slashing");
   set_weapon_type("sword/long");
   set_material_type("metal/mithril");
   set("nosecond", 0);
   set("value", 5000);
   set("light",1);
   set_verbs( ({ "cut", "slash", "strike" }) );
   set_verbs2( ({ "cuts", "slashes", "strikes" }) );

}
