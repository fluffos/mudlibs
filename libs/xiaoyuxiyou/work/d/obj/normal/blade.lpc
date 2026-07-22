#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
        set_name(HIG"战刀"NOR, ({"dao", "blade"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把金光闪闪的圆头长刀，刀把上镶嵌有白玉。\n");
                set("value", 2500);
                set("material", "gold");
                set("wield_msg", "$N「唰」地一声抽出一把$n握在手中，金光闪闪！\n");
                set("unwield_msg", "$N将手中的$n插入金色刀鞘。\n");
        set("weapon_prop/courage", 15);
			set("no_sell",1);

        }
        init_blade(70);
        setup();
}

