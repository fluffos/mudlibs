#include <weapon.h>
#include <ansi.h>
inherit THROWING;

void create()
{
        set_name(HIW "冰魄银针" NOR, ({ "bingpo yinzhen", "zhen", "needle", "yinzhen" }));
	set_weight(50);
	if (clonep())
                set_default_object(__FILE__);
        else {
               set("unit", "把");
               set("base_unit", "根");
	        set("long", "一枚纯银的细针，针身镂刻花纹，打造得极是精致。\n");
	        set("value", 5000);
               set("material", "steel");
               set("base_weight", 50);
               set("wield_msg", "$N用拇指和食指从袖底拈出一枚$n。\n");
               set("unwield_msg", "$N将手中的$n放回袖中。\n");
        }
        set_amount(1);
        init_throwing(50);
        setup();
}

