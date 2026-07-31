// baogou.c 神龙夺命钩

#include <weapon.h>
inherit STAFF;

void create()
{
        set_name("神龙夺命钩", ({ "shenlong gou", "gou" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄锐利无比的宝钩。\n");
                set("value", 30);
                set("material", "steel");
		set("rigidity", 9);
                set("unique", 1);
                set("treasure",1);
                set("wield_maxneili", 1000);
        }
            init_staff(400);
        setup();
}
