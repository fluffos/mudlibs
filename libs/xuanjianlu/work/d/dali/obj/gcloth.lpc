//Cracked by Roath
// gcloth.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name( GRN "淡绿稠衫" NOR , ({ "cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}

