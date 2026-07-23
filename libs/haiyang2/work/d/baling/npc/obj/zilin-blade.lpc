

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
   set_name(HIY"紫鳞刀"NOR, ({ "zilin dao","dao","blade" }) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "柄");
     set("value", 1500);
     set("material", "iron");
     set("long", "这把刀看起来金光闪闪，上刻紫鳞二字。\n");
     set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
     set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
   }
   init_blade(380);
   setup();
}
