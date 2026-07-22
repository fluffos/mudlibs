#include <ansi.h>  
#include <weapon.h>
inherit WHIP;

void create()
{
        set_name( HIY"紫金鞭"NOR, ({"zijin bian", "bian" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", 
                "这是一柄用野金打造连接的紫金鞭，夺目灿烂的光芒尽显华丽。\n");
                set("value", 50000);   
                set("material", "gold");
                set("wield_neili", 500);
                set("wield_maxneili", 800);
                set("wield_str", 22);
                set("wield_msg", "$N「唰」的一声抖出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n卷回腰间。\n");
        }
        init_whip(200);
        setup();
}

