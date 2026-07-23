// da-shitou.c

#include <weapon.h>
#include <ansi.h>

inherit HAMMER;

void create()
{
        set_name("大铁锤"NOR,({ "da tiechui", "tiechui" }) );
         set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                 set("value", 1000);
                set("material", "steel");
                set("long", "这是一个很重的大铁锤。\n");
                set("wield_msg", "$N拿出一个$n，试了试重量后握在手中。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
        }
        init_hammer(10);
        setup();
}
