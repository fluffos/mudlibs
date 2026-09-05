// jmd.c

#include <ansi.h>
#include "/d/xingxiu/obj/xi.h"
inherit ITEM;
void create()
{
	set_name(HIM"报春花"NOR, ({ "flower"}));
	set_weight(200);
    set("flower",random(2));
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一朵粉色的报春花。\n");
			set("unit", "朵");
            set("value",0);
		}
}

