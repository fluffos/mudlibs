// /d/ygbz/obj/suixin-whip.c
// by yahoo 18:35 99-3-22#include <weapon.h>
#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create()
{
        set_name( HIR "碎心鞭" NOR, ({ "suixin bian", "bian" }) );
        set_weight(10000);
                set("flag",2);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("long", "这是一条由虬筋和冰蚕丝制成的长鞭，鞭的末梢缠有虬龙的利齿。\n");
                set("material", "leather");
                  set("wield_msg", HIR "忽然四处传出一阵清越的龙吟，一条红色的虬龙破空而出落在$N的手中,化作一条长鞭。\n" NOR);
                set("unwield_msg", HIR "一阵龙吟声渐渐消失，$N手中的碎心鞭忽然不见了。\n" NOR);
        }
    set("no_get",1);
    set("no_give",1);
    set("no_drop",1);
               set("value",10000);
    set("rigidity",1000);
    init_whip(1600);
    setup();
}

