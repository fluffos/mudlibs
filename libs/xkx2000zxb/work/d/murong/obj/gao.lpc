//Cracked by Kafei
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIW"松子糕"NOR, ({"songzi gao", "gao"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一块松子仁做成的糕点,香喷喷的。\n");
                set("unit", "碗");
                set("value", 80);
                set("food_remaining", 3);
                set("food_supply", 60);
        }
}
