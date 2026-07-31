// caoxie.c 草鞋
// kxkxkx 2004年3月

#include <armor.h>

inherit BOOTS;

void create()
{
   set_name("草鞋", ({"cao xie", "xie"}));
   set_weight(1000);
   if(clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "双");
      set("long", "一双稻草编成的鞋子。\n");
      set("value", 0);
      set("material", "boots");
      set("armor_prop/dodge", 1);		
   }
   setup();
}
