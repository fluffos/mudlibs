//angelsword.c
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name("天使联盟剑", ({ "angel sword","sword" }) );
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一柄闪耀着异样光芒的宝剑。\n");
                set("value", 800000);
                set("material", "steel");
                set("wield_msg", HIW "天使联盟剑缓缓飞起，缕缕白云缭绕，天使联盟剑已在$N手中 ! \n" NOR );
                set("unwield_msg", "白云笼罩之中，天使联盟剑已回到剑鞘。\n");
        }
        init_sword(500);
        setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
int a=10+random(30);
me->add("bellicosity",a);
remove_call_out("remove_add");
call_out("remove_add",30,me,a);
return HIR "忽然间，$N仿佛看到几个天使飞舞，顿时精神大振！\n" NOR;
}

int remove_add(object me,int a)
{
	int b=-a;
	me->add("bellicosity",b);
	return 1;
}
