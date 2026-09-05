#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
 set_name(RED "英雄剑" NOR , ({ "hero sword","hero","sword" }) );
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
                set("wield_msg", HIY "英雄剑忽然剧烈颤抖起来，一道眩目的强光之后，$N紧紧的握住了英雄剑 ! \n" NOR );
                set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        }
        init_sword(120);
        setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
//me->add("bellicosity",10+random(30));
return HIR "$N感到＂英雄剑＂的召唤，与英雄剑合为一体,顿时剑气纵横．．．\n" NOR;
}
