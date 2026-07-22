#include <weapon.h>
#include <ansi.h>
inherit WHIP;

void create()
{
        set_name(HIG"长鞭"NOR, ({"bian", "whip"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {

set("long","一条长约六尺，青红龙筋缠成的长鞭。\n");
                set("unit", "条");
                set("value", 5000);
                set("wield_msg",
"只听「啪」的一声响，$N的手中闪出一条青红色的长鞭．\n");
                set("unwield_msg", "$N把手中$n缠回腰间．\n");
				set("no_sell",1);
        }
        init_whip(70);
        setup();
}

