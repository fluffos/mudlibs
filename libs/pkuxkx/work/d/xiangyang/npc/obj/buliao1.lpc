#include <ansi.h>
inherit ITEM;
void create()
{       set_name( RED"大红土布"NOR, ({ "dahong tubu","tubu","bu"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long",RED"这是一块大红色的家织布，手工比较糙。\n"NOR);
                set("value", 1000);
                 }
        setup();
}

