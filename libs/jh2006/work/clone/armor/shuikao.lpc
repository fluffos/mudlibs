#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("夜行衣", ({ "ye xingyi" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "一件做工精细的夜行衣。\n");
                set("material", "cloth");
		set("value", 2000);
                set("armor_prop/armor", 60);
        }
        setup();
}

