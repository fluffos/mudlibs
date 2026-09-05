//zhishi-fu.c -- 汝阳王府执事服
//Zone: 汝阳王府
//Create by ddid
//2009-6-2

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(CYN"执事服"NOR, ({ "cloth" }) );
  set("long", "汝阳王府定制的执事服。\n");
  
  set_weight(3000);
  if( clonep() )
  	set_default_object(__FILE__);
  else
  {
  	set("unit", "件");
    set("material", "cloth");
    set("armor_prop/armor", 1);
    set("value", 120);
   }
   setup();
}
