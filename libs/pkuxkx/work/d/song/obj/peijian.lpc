//官印
//create by zine 29/3/2011
#include <weapon.h>
inherit SWORD;
#include "/d/song/obj/guanyin/base.h"

void create()
{	
	set_name(WHT"佩剑"NOR, ({ "pei jian","jian"}));
	set_weight(4000);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
	set("long", "这是一柄大宋武将持有的佩剑。\n");
	set("material", "steel");
	set("unit", "柄");
	}
	set("value", 0);
    set("no_give",1);
    set("no_drop",1);
    set("no_put",1);
    set("guanyin",1);
    set("no_store",1);
	set("version",VER);
	set("pro","武");
	init_sword(10);
	setup();
	call_out("check_in",1);
}
