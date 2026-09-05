#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG"阴阳草"NOR, ({"yinyang cao","cao"}));
        set_weight(25);
        if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("unit", "棵");
                set("long","这是一棵阴阳草，也许可以用作药引吧。\n");
                set("value", 100);
                set("medicine", 1);
        }
        setup();
}
