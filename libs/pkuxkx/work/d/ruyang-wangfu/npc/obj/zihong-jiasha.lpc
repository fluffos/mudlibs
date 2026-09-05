//zihong-jiasha.c -- 汝阳王府经堂法师服装
//Zone: 汝阳王府
//Create by ddid
//2009-6-3

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name( RED"紫红袈裟"NOR, ({ "zihong jiasha", "zihong", "jiasha"}) );
  set("long", "这是一件喇嘛常穿的紫红袈裟。\n");
  set_weight(2500);
  if( clonep() )
  	set_default_object(__FILE__);
  else 
  {
  	set("unit", "件");
    set("material", "cloth");
    set("armor_prop/armor", 2);
    set("value", 0);
  }
  setup();
}

