// piqiu.c


#include <armor.h>

inherit SURCOAT;

void create()
{
        set_name("皮裘", ({ "pi qiu", "qiu"}) );
	set("long",
		"一件厚厚的皮裘，能够抵御寒冷，是上雪山的必备物品。\n");
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 50000);
                set("material", "cloth");
                set("armor_prop/armor", 5);
                set("armor_prop/dodge", -20);
        }
        setup();
}

