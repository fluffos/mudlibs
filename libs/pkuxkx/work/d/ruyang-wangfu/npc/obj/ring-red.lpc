//ring-red.c -- 汝阳王府王妃服装
//Zone: 汝阳王府
//Create by ddid
//2009-6-4

#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
	set_name(HIR"红宝石戒指"NOR, ({ "red ring", "red", "ring" }) );
  set("long", HIR"一只戒指，上面镶嵌着一颗硕大的红宝石。\n"NOR);
  
  set_weight(600);
  if( clonep() )
  	set_default_object(__FILE__);
  else
  {
  	set("unit", "只");
    set("material", "GOLD");
    set("armor_prop/armor", 1);
    set("value", 60000);
   }
   setup();
}
