#include <weapon.h>

inherit WHIP;

void create()
{
   set_name("长鞭", ({ "whip" }) );
   set_weight(1000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "条");   
     set("material", "兽皮");
     set("long", "这是一条兽皮做的长鞭。\n");
     set("wield_msg","$N抽出$n握在手里，啪地打个响。\n");
     set("unequip_msg", "$N将$n盘在腰间。\n");
   }
   init_whip(25);
   setup();
}
