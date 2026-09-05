#include <ansi.h>
inherit ITEM;
void create()
{
        set_name( MAG"麝香"NOR, ({ "she xiang", "xiang"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long",MAG"这是一块新鲜的麝香，是配置良药的配方。\n"NOR);
                set("value", 1000);
                 }
        setup();
}

