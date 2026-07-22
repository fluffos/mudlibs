#include <weapon.h>
#include <ansi.h>
inherit HAMMER;
void create()
{
        set_name(HIY"浑元金锤"NOR, ({ "hammer","chui"}) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 200000);
                set("no_put",1);
                set("no_zm",1);
                set("material", "iron");
                set("weapon_prop/strength", 10);
                set("long", "这是一件上古宝物。\n");
                set("wield_msg", "$N拿出一把$n，试了试重量，然后握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_hammer(145);
        setup();
}

