#include <ansi.h>
inherit ITEM;
void setup()
{}

void create()
{
        set_name(HIB"积木"NOR, ({"gift"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "盒");
                set("long", GRN"这是圣诞老人送的礼物，好好玩的积木！肯定可以卖大价钱。\n"NOR);
                set("value", 100000);
        }
        setup();
}
