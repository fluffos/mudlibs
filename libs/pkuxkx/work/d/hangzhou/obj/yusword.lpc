//yuword.c  玉剑  by hubo

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
 set_name(HIW "玉剑" NOR , ({ "yu sword","sword" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一柄用玉打造的宝剑，锋利无比。\n");
                set("value",100000);
                set("material", "steel");
                set("no_steal", 1);
                set("no_beg", 1);
                set("wield_msg", HIY "$N抽出玉剑在手寒气逼人！！\n" NOR );
                set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        }
        init_sword(120+random(80));
        setup();
}


