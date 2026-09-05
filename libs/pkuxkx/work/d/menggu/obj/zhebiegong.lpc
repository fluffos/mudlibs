// zhebiegong 弓
// created by zine
#include "/d/menggu/obj/zhai.h"
#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
	set_name(HIB"哲别弓"NOR, ({ "gong","bow","zhebie gong"}));
    set_weight(14000);
	if( clonep() )
		 set_default_object(__FILE__);
    else 
		{
			set("unit", "柄");
			set("long", "这是哲别随身的宝弓。\n");
			set("value", 1);
			set("times", 5);
			set("material", "steel");
			set("is__bow",1);
			init_staff(50+random(55));
		}
	setup();
}

