#include <ansi.h>
inherit ITEM;
void create()
{
        set_name( GRN"万年玄冰"NOR, ({ "xuan bing", "bing"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long",GRN"这是一块晶莹翠绿的玄冰，是配置良药的配方。\n"NOR);
                set("value", 1000);
                 }
        setup();
}

