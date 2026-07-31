

#include <weapon.h>
#include <ansi.h>

inherit CLUB;

void create()
{
   set_name(HIR"-满江红-岳家神枪"NOR, ({ "yuejia qiang","qiang","club" }) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "柄");
     set("value", 8500);
     set("material", "iron");
     set("long", "这把枪的名字取自“满江红”之意。\n");
     set("wield_msg", RED"$N一晃$n，“扑棱”一声晃出几点枪花，将$n握在手中。\n"NOR);
     set("unequip_msg", "$N将手中的$n放到了身后。\n");
   }
   init_club(880);
   setup();
}
