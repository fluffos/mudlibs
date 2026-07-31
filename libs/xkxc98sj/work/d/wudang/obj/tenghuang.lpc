#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(YEL"藤黄"NOR, ({"teng huang", "yao"}));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
            set("unit", "段");
            set("long", YEL"这是一段黄色的树藤，散发着浓浓的药味。\n"NOR);
            set("value", 100);
        }
        setup();
}
#include "medicine.h";
