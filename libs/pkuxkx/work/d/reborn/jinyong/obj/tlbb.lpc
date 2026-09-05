
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("天龙八部", ({"tianlong babu", "babu"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一本金装本的金庸签名的天龙八部。\n");
                set("unit", "本");
                set("value", 10);
                set("material", "paper");
        }
        setup();
}


