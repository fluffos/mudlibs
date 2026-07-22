// baojia.c 天蚕宝甲

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIW "天蚕宝甲" NOR, ({ "bao jia", "jia" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("unique", 1);
                set("value", 50000);
                set("material", "gold");
                set("armor_prop/armor", 50);
        }
        setup();
}

