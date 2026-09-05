inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIG"炸药包"NOR, ({"bomb", "zha dan",}));
        set_weight(5000000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "    一个包炸药，威力相当的强大。引信已经点燃，马上就要爆炸了～\n");
                set("unit", "个");
                set("value", 0);
        set("no_get", 1);
    }
}
