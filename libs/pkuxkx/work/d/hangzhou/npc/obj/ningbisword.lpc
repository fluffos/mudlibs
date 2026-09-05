//ningbisword.c  凝碧剑  by hubo

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
 set_name(HIC "凝碧剑" NOR , ({ "ningbi sword","sword" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一柄闪耀着逼人光芒的宝剑\n");
                set("value",100000);
                set("material", "steel");
                set("no_steal", 1);
                set("no_beg", 1);
                set("wield_msg", HIY "$N抽出凝碧剑哈哈大笑说：这宝家伙终于落在我手了！！ \n" NOR );
                set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        }
        init_sword(150);
        setup();
}


