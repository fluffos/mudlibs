#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name("英雄剑", ({ "hero sword","sword" }) );
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一柄闪耀着逼人光芒的宝剑\n");
                set("value", 800);
                set("material", "steel");
                set("wield_msg", HIY "英雄剑忽然剧烈颤抖起来，一道眩目的强光之后，$N紧紧的握住了英雄剑 ! \n" NOR );
                set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        }
        init_sword(100);
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	message_vision(HIR "$N的眼里映着＂英雄剑＂闪出的诡异红光．．．\n" NOR,me);
	return 10+random(30);
}

