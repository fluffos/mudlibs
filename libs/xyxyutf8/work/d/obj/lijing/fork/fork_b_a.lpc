#include <weapon.h>
#include <ansi.h>
inherit FORK;
void create()
{
        set_name(HIR"冷月叉"NOR, ({"fork","cha" }) );
        set_weight(7500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 50000);
                set("no_put",1);
                set("no_zm",1);
                set("material", "iron");
                set("long", "一柄锋利的钢叉。\n");
                set("wield_msg", "$N抄起一柄$n，还拿衣服擦了擦叉尖。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_fork(120);
        setup();
}

