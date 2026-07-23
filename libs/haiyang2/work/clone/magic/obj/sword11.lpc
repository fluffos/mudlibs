// 暗黑之剑
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(RED"炎之力"NOR, ({"fire jian", "firesword"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", RED"这是一把魔法之剑,做工极其精致。上面有火炎的力量!\n"NOR);
                set("unique", 1);
                set("value", 500000);
                set("treasure",1);       
                set("no_give",1);
                set("no_get",1);
                set("no_put",1);
                
                set("wield_neili", 2000);
                set("wield_maxneili", 3000);
                set("wield_str", 30);        
                set("treasure",1);       
                set("wield_msg",RED"一阵火炎的光芒过后 ，$N的手上多出了一把魔法之剑。\n"NOR);
                set("unwield_msg",RED"$N把手中的光剑插入剑鞘。魔法的光芒也跟着消失了。\n"NOR);
        }
     init_sword(660);
        setup();
}       

mixed hit_ob(object me, object victim, int damage_bonus)
{
int a;
 if (victim->query("magicgift")==2
 && random(3)==0)
{
a = (int)me->query_skill("magic-fire", 1);
a=300+a*2;
if (victim->query("qi") > a)
                victim->receive_damage("qi", a);
a=300+a;
if (victim->query("eff_qi") > a)
                victim->receive_wound("qi", a);
message_vision(RED"$n被炎之力上发出的火炎烧伤了!!\n"NOR, me,victim);
}
}