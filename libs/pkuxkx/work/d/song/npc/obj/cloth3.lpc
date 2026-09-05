// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
        set_name(HBGRN+HIR+"官服"+NOR, ({ "guan fu","cloth" }) );
        set_weight(3000);
		set("long","这是一件低级官员的绿底官服。\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}

