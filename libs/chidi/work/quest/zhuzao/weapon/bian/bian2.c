#include <ansi.h>  
#include <weapon.h>
inherit WHIP;
void create()
{
        set_name( HIB"毒龙鞭"NOR, ({"dulong bian", "bian" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", 
                "这是一柄用精钢打造连接的毒龙鞭，尖利的倒钩分外醒目。\n");
                set("value", 12000);   
                set("material", "steal");
                set("wield_neili", 200);
                set("wield_maxneili", 400);
                set("wield_str", 20);
                set("wield_msg", "$N「唰」的一声抖出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n卷回腰间。\n");
        }
        init_whip(100);
        setup();
}

