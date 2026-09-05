//liuye-jia.c -- 汝阳王府卫士长盔甲
//Zone: 汝阳王府
//Create by ddid
//2009-6-3

#include <armor.h>
#include <ansi.h>

inherit ARMOR;

void create()
{
	set_name( HIG"柳叶甲"NOR, ({ "liuye jia", "jia" }) );
  set("long", "一件崭新的铠甲，甲片都是柳叶形状的。\n");
  
  set_weight(3500);
  if( clonep() )
  	set_default_object(__FILE__);
  else
  {
  	set("unit", "身");
    set("material", "iron");
    set("armor_prop/armor", 55);
    set("value", 2000);
   }
   setup();
}
