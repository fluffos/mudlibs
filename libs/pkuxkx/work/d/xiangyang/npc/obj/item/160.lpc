#include <ansi.h>
inherit ITEM;
void setup()
{}

void create()
{
        set_name(HIW"玩具火车"NOR, ({"gift"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "辆");
                set("long", GRN"这是圣诞老人送的礼物，可以跑的火车！肯定可以卖大价钱。\n"NOR);
                set("value", 800000);
        }
        setup();
}
