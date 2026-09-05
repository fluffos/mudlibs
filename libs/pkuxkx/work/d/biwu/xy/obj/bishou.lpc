// bishou.c 匕首

#include <weapon.h>
inherit DAGGER;

void create()
{
	string * pre=({"分水","峨嵋","苍生",});
	set_name(pre[random(sizeof(pre))]+"刺", ({ "bishou"}));
    set_weight(300);
	if( clonep() )
                set_default_object(__FILE__);
    else 
		{
			set("unit", "柄");
			set("long", "这是一柄精制的匕首。\n");
			set("value", 1);
			set("material", "steel");
			init_dagger(70+random(15));
		}
    setup();
}
