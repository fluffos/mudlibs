// gogogo
#include <ansi.h>
#include <armor.h>
inherit BOOTS;

void create()
{
        set_name(WHT"疾风靴"NOR, ({"windy shoes", "shoes" }) );
        set("level",7);
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("value", 0);
                set("no_sell", 1);
                set("fz_get",1);
                set("no_drop", 1);
                set("no_put",1);
                set("no_zm",1);
                set("material", "cloth");
                set("armor_prop/armor", 40);
                set("armor_prop/dodge", 10);
                set("armor_prop/parry", 10);
        }
        setup();
}

