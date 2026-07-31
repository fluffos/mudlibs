#include <weapon.h>
#include <ansi.h>
inherit WHIP;
void create()
{
        set_name(HIR"勾魂索"NOR, ({"whip","bian"}));
        set_weight(7500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("no_put",1);
                set("value", 50000);
                set("no_zm",1);
                set("material", "iron");                
                set("long","一条长长的皮鞭，上面沾满了鲜血。\n");
		set("wield_msg", "只听「啪」的一声响，$N的手中闪出一条$n。\n");
		set("unwield_msg", "$N把手中$n缠回腰间．\n");
        }
        init_whip(120);
        setup();
}

