// kylinpi.c
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIY"火麒麟皮"NOR, ({ "kylin pi", "pi" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                  set("no_sell",1);
                set("unit", "块");
                set("material", "fur");
                set("value", 300000);
                set("armor_prop/armor",500 );
        }
        setup();
}

