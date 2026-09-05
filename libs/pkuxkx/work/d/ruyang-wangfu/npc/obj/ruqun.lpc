//ruqun.c -- 汝阳王府侍女襦裙半臂
//Zone: 汝阳王府
//Create by ddid
//2009-6-3

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name( "襦裙", ({ "ru qun", "ruqun", "qun"}) );
	set("long", "一条并不十分华丽的襦裙。\n");
  set_weight(2000);
  if( clonep() )
  	set_default_object(__FILE__);
  else 
  {
  	set("unit", "条");
    set("material", "cloth");
    set("armor_prop/armor", 1);
    set("value", 80);
   }
   setup();
}

