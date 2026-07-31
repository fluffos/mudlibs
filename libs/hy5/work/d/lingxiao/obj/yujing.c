//LUCAS 2000-6-18
// yujing.c

inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIW"冰魄玉精"NOR, ({"bingpo yujing", "yujing"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
         set("long", "这是万年寒玉所凝结而成的冰魄玉精,看上去洁白剔透,散发出绿幽幽的光芒。\n");
set("treasure",1);
                set("unit", "块");
                set("value", 70000);
        }
}

