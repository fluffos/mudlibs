// hefu-cloth.c
#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(BLU"日式和服"NOR, ({ "cloth" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", "这是一件日式和服。\n");
                set("material", "cloth");
		set("value", 0);
                set("armor_prop/armor", 50);
        }
        setup();
}

