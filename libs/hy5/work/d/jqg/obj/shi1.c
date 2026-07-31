// shi1.c
// By River 98.10
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIG"鹅"MAG"卵"HIB"石"NOR, ({"e luanshi", "e", "luanshi", "stone"}));
        set_weight(50000);
        if (clonep())
               set_default_object(__FILE__);
        else {
               set("long", "这是一块色彩斑斓的鹅卵石。\n");
               set("unit", "块");
        }
        setup();
}
