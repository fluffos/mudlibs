#include <weapon.h>

inherit CLUB;

void create()
{
   set_name("长枪", ({ "spear" }) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "杆");   
     set("material", "iron");
     set("long", "这是一杆长枪，比较沉重。\n");
     set("wield_msg","$N抽出$n握在手中，扑棱一声，抖了个枪花。\n");
     set("unequip_msg", "$N放下了手中的$n。\n");
   }
   init_club(25);
   setup();
}
