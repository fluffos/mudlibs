// 暗黑之剑
#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(BLK"暗黑之剑"NOR, ({"dark jian", "darksword"}));
        set_weight(15000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", BLK"这是一把暗黑之剑,做工极其精致。是众神的遗产之一!\n"NOR);
                set("unique", 1);
                set("value", 0);
		set("no_put", 1);
		set("no_put", 1);
		set("no_get", 1);
		set("no_drop", 1);
		set("no_pawn", 1);
                set("treasure",1);       
                        set("armor_prop/intelligence",15);
         set("armor_prop/strength",15);
                set("wield_neili", 2000);
                set("wield_maxneili", 3000);
                set("wield_str", 30);        
                set("skill", ([
                        "name": "magic-dark",
                        "exp_required": 20000000,
                        "difficulty": 300,
                        "min_skill":  500,
                             "max_skill": 1000,              
                ]) );
                set("armor_prop/attack", 50);	
                set("treasure",1);       
                set("wield_msg",BLK"一阵黑暗的光芒过后 ，$N的手上多出了一把暗黑之剑。\n"NOR);
                set("unwield_msg",BLK"$N把手中的光剑插入剑鞘。黑暗的光芒也跟着消失了。\n"NOR);
        }
     init_sword(1888);
        setup();
}       
void owner_is_killed()
{
       destruct(this_object());
}
int query_autoload()
{
       return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
int a;
if (1)
if (random(4)==0)
{
message_vision(BLK"$N手上的暗黑之剑，使天空变的漆黑，一个小型的黑洞出现在$n的上空！\n"NOR, me,victim);
message_vision(BLK"暗黑核融术!!  $n附近发生了核爆！！\n"NOR, me,victim); 
 if (random(2)==0)
{
a = (int)me->query_skill("magic-dark", 1);
a=600+a*3;
                victim->receive_damage("qi", a);
a=600+a;
                victim->receive_wound("qi", a);
message_vision(BLK"$n根本没法躲避，$n附近成了黑暗的核地狱!!\n"NOR, me,victim);
}
else message_vision(HIR"$n轻轻一笑，用魔力造了一个防护屏，结果毫发无伤。!\n"NOR, me,victim);
}
if (random(4)==1)
{
message_vision(BLK"$N手上的暗黑之剑，使天空变的漆黑,$n所处的地方温度突然下降,挂起了暴风雪！\n"NOR, me,victim);
message_vision(BLK"暗黑暴风雪!!  $n附近挂起了暴风雪！！\n"NOR, me,victim); 
 if (random(2)==1)
{
if (!victim->is_busy())
victim->start_busy(3);
message_vision(BLK"$n的附近成为了黑暗的冰海!!$n觉的全身剧痛，挣不开眼了!!\n"NOR, me,victim);
}
else message_vision(BLK"$n飞身跃起，逃过了一难。!\n"NOR, me,victim);
}

}