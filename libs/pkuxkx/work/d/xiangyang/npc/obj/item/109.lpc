#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIY"金沙"NOR, ({"jin sha","sha", "jinsha", "gold nugget"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一粒亮闪闪的金沙。\n");
                 set("unit", "粒");
//                set("base_unit", "粒");
                set("value", 3000+random(2001));
                set_weight(20);
        }
        setup();
}
