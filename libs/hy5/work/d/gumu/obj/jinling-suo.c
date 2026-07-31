// jinling-suo.c 金铃索
// By Kayin @ CuteRabbit Studio 1999/3/21 new
#include <ansi.h> 
#include <weapon.h>
inherit WHIP;

void create()
{
        set_name(HIY"金铃"HIW"索"NOR, ({ "jinling suo", "suo" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("long", "这是一条洁白的丝带系成的金铃索，丝带的两端有两个小金铃，不是发出清脆的响声。\n");
                set("value", 10000);
                 set("no_drop", "这样东西不能离开你。\n");
                set("no_give", "这样东西不能给人。\n");
                set("treasure",1);
                set("nopawn",1);
            set("no_get",1);
               set("material", "gold");
                set("wield_msg", HIC"$N从怀中掏出一条$n握在手中。\n"NOR);
                set("unwield_msg", HIC"$N将手中的$n放入怀中。\n"NOR);
	        set("armor_prop/attack", 100);

        }
        init_whip(400);
        setup();
}

