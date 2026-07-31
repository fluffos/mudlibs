// xtbs.c 匕首
// by snowman@SJ

#include <weapon.h>
inherit DAGGER;

void create()
{
        set_name("玄铁匕首", ({ "xuantie bishou","bishou"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄精制的玄铁匕首。\n");
                set("value", 30);
		set("rigidity",6);
set("sharpness",3);
		set("unique", 1);
                set("treasure",1);
                set("material", "steel");
        }
        init_dagger(100);
        setup();
}
