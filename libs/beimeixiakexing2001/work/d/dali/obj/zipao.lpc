//Cracked by Roath
#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("紫袍", ({ "zi pao", "cloth" }));
        set("long", 
"这是一件生丝袍子，胸前精秀的刺了二龙含珠图，金丝裹边富贵非常。\n");
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
                set("value", 1000);
                set("armor_prop/armor", 15);
        }
        setup();
}

