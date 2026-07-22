#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL"雄黄"NOR, ({"xiong huang", "yao"}));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
            set("unit", "株");
            set("long", YEL"这是一株小草，可是味道非常的刺鼻，你站在几米远都可闻到。\n"NOR);
            set("value", 100);
        }
        setup();
}
#include "medicine.h";