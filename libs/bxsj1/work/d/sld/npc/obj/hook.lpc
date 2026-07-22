// hook.c 双钩

#include <weapon.h>
inherit HOOK;

void create()
{
        set_name("双钩", ({ "shuang gou", "gou" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄精钢制成的钩子。\n");
                set("value", 30);
                set("material", "steel");
        }
        init_hook(30);
        setup();
}
