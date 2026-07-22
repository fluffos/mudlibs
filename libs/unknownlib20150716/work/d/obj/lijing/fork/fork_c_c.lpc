#include <weapon.h>
#include <ansi.h>
inherit FORK;
void create()
{
        set_name(HIY"灭魂之叉"NOR, ({"fork","cha" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 200000);
                set("no_put",1);
                set("no_zm",1);
                set("material", "iron");
                set("weapon_prop/courage", 5);
                set("long", "这是一件上古宝物。\n");
                set("wield_msg", "$N抄起一柄$n，还拿衣服擦了擦叉尖。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_fork(150);
        setup();
}

