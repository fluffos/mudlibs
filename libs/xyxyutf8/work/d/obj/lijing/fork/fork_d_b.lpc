#include <weapon.h>
#include <ansi.h>
inherit FORK;
void create()
{
        set_name(HIC"回龙摄魂叉"NOR, ({"fork","cha" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 500000);
                set("no_put",1);
                set("no_zm",1);
                set("material", "iron");
                set("weapon_prop/strength", 20);
                set("long", "这是一件传说中的神器。\n");
                set("wield_msg", "$N抄起一柄$n，还拿衣服擦了擦叉尖。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_fork(170+random(20));
        setup();
}

