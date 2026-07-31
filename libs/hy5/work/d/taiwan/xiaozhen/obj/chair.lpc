#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("缺腿椅子", ({ "chair" }));
        set_weight(20000);
	set("long", "这张太师椅已经只剩下两条腿,而且大多被虫蛀空了。\n" );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("material", "wood");
		   set("value", 2000);
                set("mask","庄");
        }
        setup();
}

