#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"夜明珠"NOR, ({ "lighting-pearl"}) );
        set_weight(3);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一个在黑夜闪闪发光的夜明珠。\n");
                set("value", 10000);
        }
}

