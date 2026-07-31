#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG"五派令旗"NOR, ({ "ling qi"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "面");
                set("long",
                        "一面五派令旗。\n");
                set("value", 0);
                set("material", "paper");
		 
         }
}

