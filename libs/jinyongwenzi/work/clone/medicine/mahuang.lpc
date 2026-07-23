#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL"麻黄"NOR, ({"ma huang", "yao"}));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
            set("unit", "株");
            set("long", YEL"这是一株非常普通的有着黄色叶子的小植物。\n"NOR);
            set("value", 100);
        }
        setup();
}
#include "medicine.h";
