// shoe.c
#include <armor.h>
inherit BOOTS;
#include <ansi.h>
void create()
{
        set_name(HIG""NOR, ({ "shoes", "xue","xie" }) );
        set("level",1);
        set_weight(1700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "");
                set("value", 10000);
                set("material", "cloth");
                set("armor_prop/armor", 2);
                set("armor_prop/dodge", 8);
				set("no_sell",1);
        }
        setup();
}

