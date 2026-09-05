// junfu.c

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("官服", ({ "guanfu", "cloth" }));
        set("long", "这是一件朝廷官员才可以穿的官服。\n");
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
                set("value", 0);
                set("armor_prop/armor", 15);
        }
        setup();
}
