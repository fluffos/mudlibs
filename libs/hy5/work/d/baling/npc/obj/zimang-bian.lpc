

#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
   set_name(MAG"紫莽鞭"NOR, ({ "zimang bian","bian","whip" }) );
   set_weight(3000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "柄");
     set("value", 1500);
     set("material", "iron");
     set("long", "这是一条钢鞭，名为紫莽。\n");
     set("wield_msg", "$N一晃$n，只听“啪”的一声，将$n握在手中。\n");
     set("unequip_msg", "$N将手中的$n盘在了腰上。\n");
   }
   init_whip(380);
   setup();
}
