#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIW"绯雨短剑"NOR, ({ "feiyu sword","sword" }) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "绯雨短剑是绯雨阁的镇山之宝．\n");
                set("value", 5000);
                set("material", "black_iron");
		set("wield_msg", "$N抽出一把雪白的$n握在手中,顿时四周杀气弥漫.\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘中。\n");
		set("wield_skill",([
			"sword" : 150,
		]));
		set("wield_ability",([
			"combat_exp" : 500000,
		]));
        }

        init_sword(580);
        setup();
}
