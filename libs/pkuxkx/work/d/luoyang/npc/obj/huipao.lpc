// huipao.c -- 白布长袍
//

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("灰布长袍", ({ "cloth","pao" }) );
  set("long", "这是件普普通通的灰布长袍。\n");
  
  set_weight(2000);
  
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
