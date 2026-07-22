#include <ansi.h>  
#include <weapon.h>
inherit WHIP;
void create()
{
        set_name(HIW"断云鞭"NOR, ({ "duanyun bian", "bian" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄用精铜打造连接的断云鞭。\n");
                set("value", 8000);   
                set("material", "copper");
                set("wield_neili", 100);
                set("wield_maxneili", 300);
                set("wield_str", 18);
                set("wield_msg", "$N「唰」的一声抖出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n卷回腰间。\n");
        }
        init_whip(50);
        setup();
}

