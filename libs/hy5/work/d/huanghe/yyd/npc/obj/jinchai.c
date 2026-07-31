// 金钗 jinchai.c
// zly 99.6.21

#include <ansi.h>

inherit ITEM;

void create()
{
          set_name(HIY"金钗"NOR, ({"jin chai","jin","chai"}));
        set("long",
                "\n这是一支精致漂亮的金钗，钗上一颗明珠又大又圆，宝光莹然。\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "支");
        set("weight", 10);
        set("value", 50);
}
        setup();
}
