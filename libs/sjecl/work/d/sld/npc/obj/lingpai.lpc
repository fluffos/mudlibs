
#include <ansi.h>

inherit ITEM;

 void create()
{
        set_name(YEL "通行令牌" NOR, ({"ling pai"}));
        set_weight(20);
        
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "神龙教的通行令牌。\n");
		set("sld",1);
        }

        setup();
}

