// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit SKILL;
object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}
string* buwei = ({
        "右手肘部",
        "手腕",
        "左手关节",
        "颈部",
        "肩部关节",
        "背心要穴",
        "膝关节",
        "命门"
});
mapping *action = ({
        ([      "action":               
"$N左腿在前，右腿在后，双掌用力向$n的$l挥来",
                "dodge":                30,
                "parry":                10,
                "force":                90,
                "damage":                190,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N左脚点地，身体向后旋转，右腿向疾风扫落叶般扫向$n的$l",
                "dodge":                10,
                "parry":                30,
                "force":                90,
                "damage":                90,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N右手虚晃，左肘从我意想不到的角度撞向我$n的$l",
                "dodge":                30,
                "parry":                10,
                "force":                90,
                "damage":                120,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N右脚凌空，晃出一片腿影，霎那间向$n的$l一连踢出三脚",
                "dodge":                10,
                "parry":                30,
                "force":                90,
                "damage":                130,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N凌空跃起，身体向后急转，双脚从下往上一前一后地撩向$n的$l",
                "dodge":                20,
                "parry":                30,
                "force":                90,
                "damage":                140,
                "damage_type":  "瘀伤"
        ]),
});

int valid_learn(object me)
{
    if ((int)me->query_skill("shayi-xinfa", 1) < 30)
   return notify_fail("你的杀意心法火候不够。\n");
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练合气道必须空手。\n");
        return 1;
}

int valid_enable(string usage) { return  usage=="unarmed" || usage=="parry"; }

mapping query_action(object me, object weapon)
{
        int i, level;
        object victim;
        string bw;
        
        if( !victim && me->is_fighting() ) victim = offensive_target(me);
        level   = (int) me->query_skill("aikido",1);
        
        bw = buwei[random(sizeof(buwei))];
if (me && victim)
{
        if ((int) me->query_skill("aikido",1) > random(50)  && me->query("neili") > 300
        && random(me->query("combat_exp")) > victim->query("combat_exp")/2 && random(4)==0
         && me->query_skill_mapped("unarmed") == "aikido"
         && me->query_skill_mapped("parry") == "aikido"
         && !me->is_busy()
         && victim->query("qi") > 100
         && !victim->is_busy()
         && !me->query_temp("weapon")) {
                me->add("neili", -50);
                message_vision(HIY"$N用合气道擒拿法斗然间抓住了$n的"+bw+"!\n"NOR,me,victim);
                message_vision(CYN"$N退避不及被$n抓住了"+bw+",然后被抛出！\n"NOR,victim,me);
if (userp(victim))
                victim->add("qi",-victim->query("qi")/20);
else            victim->add("qi",-level);
                victim->start_busy(2 + random(level/50));
        }
}
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
    if ((int)me->query_skill("shayi-xinfa", 1) < 10)
   return notify_fail("你的杀意心法火候不够。\n");

        if( (int)me->query("qi") < 80 )
                return notify_fail("你的体力不够了，休息一下再练吧。\n");
        if( (int)me->query("neili") < 50 )
                return notify_fail("你的内力不够了，休息一下再练吧。\n");
        me->receive_damage("qi", 40);
        me->add("neili", -30);
        return 1;
}
int effective_level() { return 10;}
 
string *parry_msg = ({
        "$n就势一滚，双手一撑地，全身弹出$N的$w的攻击范围。\n",
});

string *unarmed_parry_msg = ({
        "$n就势一滚，双手一撑地，全身弹出$N的攻击范围。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
	return 10;
}
int practice_bonus()
{
	return 5;
}
int black_white_ness()
{
	return -10;
}

string perform_action_file(string action)
{
    return __DIR__"aikido/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;
string msg;
        lvl  = me->query_skill("shayi-xinfa", 1);
        flvl = me->query("jiali");

if (me->query_skill_mapped("force") == "shayi-xinfa" && lvl > 300 && random(8)==0)
{
flvl=random(lvl)*2+150;
                  msg = HIR"「二重劲!」$N以极快速的连击,在第一击后,$n没产生抵抗力时给予第二击! \n"NOR;
if (random(3)==0) msg = HIR"「隔空击物!」。$N将二重劲的威力传至远方攻击的$n,用以弥补远距离攻击的不足 。\n"NOR;
if (random(3)==1) msg = HIR"「喷射火焰!」。$N胃装油袋,用火石制的假牙点火喷出火焰,$n被极大的火焰打中!! \n"NOR;
if (random(3)==2) msg = HIR"「仙鹤飞腿!」。$N使出丑鬼直接传授的拳法之一踢向$n! 这踢法已独创一格!!\n"NOR;

if (victim->query("qi") > flvl)
{
victim->start_busy(2);
victim->add("qi",-flvl);
victim->add("eff_qi",-flvl);

}
                return msg;
        }


}