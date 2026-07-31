// /u/beyond/mr/obj/liutiao.c 柳条
// this is made by beyond
// update 1997.6.20
#include <weapon.h>
#include <ansi.h>
inherit WHIP;
void create()
{
        set_name(GRN"柳条"NOR,({ "liu tiao", "liutiao" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "枝");
                set("value", 0);
                set("material", "bamboo");
                set("long", "这是一枝柳树条。\n");
                set("wield_msg", "$N抽出一枝$n，握在手中。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
        }
        init_whip(3);
        setup();
}
