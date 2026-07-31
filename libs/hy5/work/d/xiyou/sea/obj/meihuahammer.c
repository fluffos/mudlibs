#include <weapon.h>

inherit HAMMER;
int do_read(string arg);

void create()
{
        set_name("八瓣梅花锤", ({ "meihua hammer", "hammer" }) );
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把分八瓣成梅花状的铜锤，上面刻了些符篆。\n");
                set("value", 50);
		set("no_sell", 1);
                set("material", "iron");
                set("wield_msg", "$N拿出一把$n，试了试重量，然後握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_hammer(60);
        setup();
}

