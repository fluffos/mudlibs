#include <ansi.h>
inherit ITEM;
void create()
{
        set_name( WHT"虎骨"NOR, ({ "hu gu", "gu"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long",YEL "这是一块白惨惨的虎骨，是配置良药的配方。\n"NOR);
                set("value", 1000);
                 }
        setup();
}

