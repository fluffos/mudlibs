// 暗黑之剑
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(HIB"水晶匕首"NOR, ({"water jian", "watersword"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", HIB"这是一把水晶匕首,做工极其精致。上面有水神的力量!\n"NOR);
                set("unique", 1);
                set("value", 50000);
                set("treasure",1);       
                                set("no_give",1);
                set("no_get",1);
                set("no_put",1);

                set("wield_neili", 2000);
                set("wield_maxneili", 3000);
                set("wield_str", 30);        
                set("treasure",1);       
                set("wield_msg",HIB"一阵蓝色的光芒过后 ，$N的手上多出了一把水晶匕首。\n"NOR);
                set("unwield_msg",HIB"$N收起手中的水晶匕首。蓝色的光芒也跟着消失了。\n"NOR);
        }
     init_sword(670);
        setup();
}       

mixed hit_ob(object me, object victim, int damage_bonus)
{
int a;
 if (victim->query("magicgift")==1
 && random(3)==0)
{
a = (int)me->query_skill("magic-water", 1);
a=320+a*2;
if (victim->query("qi") > a)
                victim->receive_damage("qi", a);
a=320+a;
if (victim->query("eff_qi") > a)
                victim->receive_wound("qi", a);
message_vision(HIB"$n被水晶匕首上发出的冰冻球冻伤了!!\n"NOR, me,victim);
}
}