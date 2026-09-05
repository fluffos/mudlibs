// qinse-doupeng.c -- 青色斗篷
//

#include <armor.h>
#include <ansi.h>
inherit SURCOAT;

void create()
{
	set_name(CYN "青色斗篷" NOR, ({ "surcoat","doupeng" }) );
	set("long",  "这是件青色的大斗篷。\n");

  set_weight(1000);
  
  if( clonep() )
  	set_default_object(__FILE__);
  else
	{
  	set("unit", "件");
    set("material", "cloth");
    set("armor_prop/armor", 1);
    set("value", 0);    
   }
   
   setup();
}

