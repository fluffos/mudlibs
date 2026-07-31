#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("破碗", ({ "powan" }));
        set_weight(4000);
	set("long", "摔破了的青瓷碗。\n" );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("material", "stone");
		   set("value", 3000);
                set("mask","庄");
        }
        setup();
}

