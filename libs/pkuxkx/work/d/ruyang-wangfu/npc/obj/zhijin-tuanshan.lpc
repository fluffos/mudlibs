//zhijin-tuanshan.c -- 汝阳王府王妃服装
//Zone: 汝阳王府
//Create by ddid
//2009-6-3

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIR"大红织锦团衫"NOR, ({ "zhijin tuanshan", "tuanshan", "shan" }) );
  set("long", HIR"一件大红织锦的团衫，胸前有纯金丝线编绣的图案。\n"NOR);
  
  set_weight(3000);
  if( clonep() )
  	set_default_object(__FILE__);
  else
  {
  	set("unit", "件");
    set("material", "cloth");
    set("armor_prop/armor", 2);
    set("value", 50000);
   }
   setup();
}
