#include <ansi.h>
inherit ITEM;
void create()
{       set_name(HIM"粉红丝绸"NOR, ({ "fenhong sichou","sichou","bu"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long",HIM"这是一块江南出产的名贵丝绸，能在这里买到，真是不容易。\n"NOR);
                set("value", 5000);
                 }
        setup();
}

