// hongying-qiang.c 红缨枪

#include <ansi.h>
#include <weapon.h>
inherit SPEAR;

void create()
{
        set_name(RED"红缨枪"NOR , ({ "hongying qiang", "qiang", "spear","hongying" }));
        set_weight(12000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄在枪头有红缨的长枪，有时有扰乱敌人的功能。\n");
                set("value", 1000);
                set("material", "steel");
        }
        init_spear(30);
        setup();
}
