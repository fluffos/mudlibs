// taizu-quan 太祖长拳
#include <ansi.h>
inherit SKILL;  
#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";


mapping *action = ({
([     "action" : "$N一式「千里横行」，双臂直上直下，猛攻而前，打向$n的$l",
       "force" : 100,
        "dodge" : 20,
        "parry" : 50,
       "damage": 200,
       "lvl" : 0,       
       "damage_type" : "内伤"
]),
([     "action" : "$N上身前倾，右拳直出呼的一声打向$n，正是一招「冲阵斩将」",
       "force" : 135,
        "dodge" : 20,
       "damage": 200,
       "lvl" : 0,
        "damage_type" : "瘀伤"
]),
([     "action" : "$N使招「河朔立威」，右手向上一扬，左手握拳打向$n",
       "force" : 240,
        "dodge" : 10,
        "parry" : 25,
       "damage": 200,
       "lvl" : 10,
        "damage_type" : "内伤"
]),
([     "action" : "$N双拳呼呼打出，连接三遍，正和「击鼓三通」之意",
       "force" : 350,
        "dodge" : 35,
        "parry" : 330,
       "damage": 200,
       "lvl" : 10,
        "damage_type" : "瘀伤"
]),
([     "action" : "$N跳起往左旋身一转，左脚落地后双拳齐出，捣向$n的$l，「扬马立威」",
       "force" : 400,
        "dodge" : 110,
        "parry" : 335,
        	"damage": 200,
       "lvl" : 30,
        "damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }



string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
    int i, level;
    object ob;
    ob = me->select_opponent();
       level   = (int) me->query_skill("taizu-quan",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
    level   = (int) me->query_skill("taizu-quan",1)/10;
    if (!userp(me) || (int)me->query_skill("taizu-quan", 1) > 10)
{
if (  !me->is_busy()
&&living(ob)
&& !me->query_temp("dsauto")
&& !me->query_temp("sc_hama")
&& random(me->query_skill("taizu-quan",1))> 180
)
{
	 message_vision(HIW"\n「二重劲!」$N以极快速的连击,在第一击后,$n没产生抵抗力时给予第二击! \n"NOR, me,ob);
me->set_temp("dsauto",1);
	me->add_temp("apply/attack", (level*2));
	me->add_temp("apply/damage", (level*4));
		COMBAT_D->do_attack(me, ob, me->query_temp("weapon"));
	me->add_temp("apply/attack", -(level*2));
	me->add_temp("apply/damage", -(level*4));
me->delete_temp("dsauto");
}
}

}

int practice_skill(object me)
{
       if ((int)me->query("jingli") < 30)
               return notify_fail("你的体力太低了。\n");
       if ((int)me->query("neili") < 20)
               return notify_fail("你的内力不够练太祖长拳。\n");
       me->receive_damage("jingli", 30);
       me->add("neili", -10);
       return 1;
}



int valid_learn(object me)
{
        return notify_fail("NPC武功，不对玩家开放。\n");
}





mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("taizu-quan",1);
	jiali = me->query("jiali");
if (userp(me)) return;
if (!me) return;
if (!victim) return;
if (!level2) return;
if (!jiali) jiali=10;
	if( damage_bonus > 50 && random(level2)>80 ) {
	victim->receive_wound("qi", (random(jiali)+100));
	return RED"只见$n$l上鲜血狂奔，已被无形气劲切了开来!\n"NOR;
        }
}
       
       
       
int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("taizu-quan", 1);

//        if( me->is_busy()) return 1;

        if( userp(me)) return 1;
        if( damage < 10 ) return 1;
    if (userp(me)) return 1;

        if (  random(level) > 150
         

           ){
         msg = HIG"$N面对$n的攻势。身形一闪，突出狠招!!!。\n"NOR;
            message_vision(msg, me, ob);
            if ( random(3) == 0 && ob->query("qi") > 50
        && ob->query("jing") > 50
        && ob->query("eff_qi") > 50
        && ob->query("eff_jing") > 50){
         msg = HIR"「 隔空击物! 」。$N将二重劲的威力传至远方攻击的$n,用以弥补远距离攻击的不足 。\n"NOR;
             if (!ob->is_busy())
             ob->start_busy(3);
if ((int)ob->query("qi") < 60000)
{
if (ob->query("qi")/15 > 20)
             ob->add("qi",-ob->query("qi")/15);
if (ob->query("eff_qi")/15 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/15);
}
else
{
ob->add("qi",-5000);
ob->add("qi",-5000);
}
msg += damage_msg(damage, "瘀伤");



            }
else  if (random(3)==1 && ob->query("qi") > 50
        && ob->query("jing") > 50
        && ob->query("eff_qi") > 50
        && ob->query("eff_jing") > 50){
         msg = HIR"「仙鹤飞腿!」。$N使出丑鬼直接传授的拳法之一踢向$n! 这踢法已独创一格!!\n"NOR;
             if (!ob->is_busy())
             ob->start_busy(3);
if ((int)ob->query("qi") < 60000)
{
if (ob->query("qi")/20 > 20)
             ob->add("qi",-ob->query("qi")/20);
if (ob->query("qi")/20 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/20);
}
else
{
ob->add("qi",-4000);
ob->add("qi",-4000);
}

msg += damage_msg(damage, "瘀伤");
            }
else  if (random(3)==2 && ob->query("qi") > 50
        && ob->query("jing") > 50
        && ob->query("eff_qi") > 50
        && ob->query("eff_jing") > 50){
         msg = HIR"「喷射火焰!」。$N胃装油袋,用火石制的假牙点火喷出火焰,$n被极大的火焰打中!! \n"NOR;
             if (!ob->is_busy())
             ob->start_busy(3);
if ((int)ob->query("qi") < 60000)
{
if (ob->query("qi")/30 > 20)
             ob->add("qi",-ob->query("qi")/30);
if (ob->query("eff_qi")/30 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/30);
}
else
{
ob->add("qi",-3500);
ob->add("qi",-3500);
}
msg += damage_msg(damage, "瘀伤");
            }
else
           msg = HIG"$n认得这招历害,逃了开来，还好无事!。\n"NOR;
            message_vision(msg, me, ob);
            return damage;
        }
}
