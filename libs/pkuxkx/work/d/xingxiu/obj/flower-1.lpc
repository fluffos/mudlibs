// jmd.c

#include <ansi.h>
#include "/d/xingxiu/obj/xi.h"
inherit ITEM;
void create()
{
	set_name(HIY"垂头菊"NOR, ({ "flower"}));
	set_weight(200);
    set("flower",random(2));
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一朵垂头菊。\n");
			set("unit", "朵");
            set("value",0);
		}
}

