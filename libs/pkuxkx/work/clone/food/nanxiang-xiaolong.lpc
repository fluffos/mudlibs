inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
        set_name("南翔小笼", ({ "nanxiang xiaolong", "xiaolong" }) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一笼南翔小笼包，嘉定府的贡品，形态小巧，皮薄呈半透明状，以特制的小竹笼蒸熟。\n");
                set("unit", "笼");
		set("value", 800);
                set("food_remaining", 6);
		set("food_supply", 15);
                set("material", "meat");
        }
        setup();
}

