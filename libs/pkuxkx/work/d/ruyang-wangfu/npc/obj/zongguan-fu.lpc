//zongguan-fu.c -- 汝阳王府总管服
//Zone: 汝阳王府
//Create by ddid
//2009-6-2

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name( BLU"总管服"NOR, ({ "cloth" }) );
	set("long", "这是一件定制的长袍，只有汝阳王府的总管太监才能穿。\n");
	
  set_weight(3000);
  if( clonep() )
  	set_default_object(__FILE__);
  else 
  {
  	set("unit", "件");
    set("material", "cloth");
    set("armor_prop/armor", 1);
    set("value", 160);
  }
  setup();
}

