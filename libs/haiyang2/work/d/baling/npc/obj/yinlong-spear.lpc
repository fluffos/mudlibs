

#include <weapon.h>
#include <ansi.h>

inherit CLUB;

void create()
{
   set_name(HIW"银龙枪"NOR, ({ "yinlong spear","qiang","spear" }) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "柄");
     set("value", 1500);
     set("material", "iron");
     set("long", "这把枪看起来好似一条银龙。\n");
     set("wield_msg", "$N一晃$n，“扑棱”一声晃出几点枪花，将$n握在手中。\n");
     set("unequip_msg", "$N将手中的$n放到了身后。\n");
   }
   init_club(680);
   setup();
}
