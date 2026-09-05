//liegong.c
//by hehe
//2003.3.22
//modified by Zine 2012
#include "/d/menggu/obj/zhai.h"
#include <weapon.h>
inherit STAFF;
#include <ansi.h>

void create()
{
	set_name("猎弓", ({"lie gong","liegong","gong"}));
    set_weight(100);
    if( clonep() )
		set_default_object(__FILE__);
    else 
	{
		set("unit", "把");
		set("value", 1000);
        set("long","这是个做工粗糙的猎弓。\n");
        set("material", "steel");
		set("arrow_assist",1);
		set("is__bow",1);
		set("str_require",10);
		set("xt_str_require",10);
    }
	init_staff(5);
	setup();
}







