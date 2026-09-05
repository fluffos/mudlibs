//banbi.c -- 汝阳王府侍女襦裙半臂
//Zone: 汝阳王府
//Create by ddid
//2009-6-3

#include <armor.h>
#include <ansi.h>

inherit SURCOAT;

void create()
{
	set_name( "半臂", ({ "ban bi", "banbi", "bi" }) );
	set("long", "一件灰白色的短袖衫子。\n");
	
  set_weight(1000);
  if( clonep() )
  	set_default_object(__FILE__);
  else 
  {
  	set("unit", "件");
    set("material", "cloth");
    set("armor_prop/armor", 1);
    set("value", 80);
   }
   setup();
}

