// zhebiegong 弓
// created by zine

#include <weapon.h>
#include <ansi.h>
inherit STAFF;
#include "/d/menggu/obj/zhai.h"
void create()
{
	set_name(HIB"硬弓"NOR, ({ "gong","bow","ying gong"}));
    set_weight(4000);
	if( clonep() )
		 set_default_object(__FILE__);
    else 
		{
			set("unit", "柄");
			set("long", "这是一柄三石的硬弓。\n");
			set("value", 1);
			set("times", 5);
			set("material", "steel");
			set("arrow_assist",50);
			set("is__bow",1);
			set("str_require",55);
			set("xt_str_require",10);
		}
	init_staff(1+random(15));
	setup();
}

