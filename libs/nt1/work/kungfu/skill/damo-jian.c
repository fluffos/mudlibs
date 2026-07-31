// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// damo-jian.c 达摩剑

#include <ansi.h>

inherit SHAOLIN_SKILL;

string *action_msg = ({
        "$N使一式「万事随缘往」，手中$w嗡嗡微振，幻成一条疾光刺向$n的$l",
        "$N错步上前，使出「来去若梦行」，剑意若有若无，$w淡淡地向$n的$l挥去",
        "$N一式「浮世沧桑远」，纵身飘开数尺，运发剑气，手中$w遥摇指向$n的$l",
        "$N纵身轻轻跃起，一式「轮回法舟轻」，剑光如轮疾转，霍霍斩向$n的$l",
        "$N手中$w中宫直进，一式「水月通禅寂」，无声无息地对准$n的$l刺出一剑",
        "$N手中$w斜指苍天，剑芒吞吐，一式「鱼龙听梵音」，对准$n的$l斜斜击出",
        "$N左指凌空虚点，右手$w逼出丈许雪亮剑芒，一式「千里一苇去」刺向$n的$l",
        "$N合掌跌坐，一式「禅心顿自明」，$w自怀中跃出，如疾电般射向$n的胸口",
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_combine(string combo) { return combo == "xiuluo-dao"; }

int valid_learn(object me)
{
        if ((int)me->query("int") < 30)
                return notify_fail("你的天资不足，无法理解达摩剑法的剑意。\n");  
               
        if ((int)me->query("max_neili") < 300)
                return notify_fail("你的内力不够。\n");

        if ((int)me->query_skill("force") < 60)
                return notify_fail("你的内功火候太浅。\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("damo-jian", 1))
                return notify_fail("你的基本剑法水平有限，无法领会更高深的达摩剑法。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        int j, wt, level;
        object target;
        string *msg;

        level   = (int) me->query_skill("damo-jian",1);
        wt = me->query_temp("sl_weituo");
        target = me->select_opponent();
        weapon = me->query_temp("weapon");

        msg = ({ 
                HIR"\n$N剑招越攻越急，出剑突快，顷刻之间，$n" +HIR"上全是进手招数。\n"NOR,
                HIY"\n$N身随剑转，回剑横掠，一剑跟著一剑，绵绵不尽，剑招连环进击，紧密无比。\n"NOR,
                HIC"\n原本达摩剑走的均是刚猛路子，此刻却带了三分灵动之气，剑势更加厉害！\n"NOR,
                HIW"\n这时$N心剑合一，势成自然，将「韦陀伏魔剑」发挥到了淋漓尽致。\n"NOR,
        });

        if( wt > 1 && wt < 6 && !me->query_temp("weituo_attack")) {

                message_vision( msg[wt-2] , me, weapon);
                me->set_temp("weituo_attack", 1);
                for( j=0; j < wt-1; j++ )
                {
                        if (! me->is_fighting(target)) break;
                        me->add("neili", -50);
                        COMBAT_D->do_attack(me, target, weapon);
                }
                me->delete_temp("weituo_attack", 1);
                me->add_temp("sl_weituo", 1);

        }

        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "damage": 140 + random(60),
                "attack": 80 + random(10),
                "dodge" : 80 + random(10),
                "parry" : 80 + random(10),
                "damage_type" : random(2)?"刺伤":"割伤",
        ]);
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 90)
                return notify_fail("你的体力不够练达摩剑。\n");
        if ((int)me->query("neili") < 90)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("qianye-shou", 1) < 100)
                return notify_fail("你的如来千叶手修为还不够。\n");

        me->receive_damage("qi", 80);
        me->add("neili", -80);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"damo-jian/" + action;
}

int query_effect_parry(object attacker, object me)
{
        int lvl;

        if (! me->query_temp("weapon"))
                return 0;

        lvl = me->query_skill("damo-jian", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 50;
        if (lvl < 280) return 80;
        if (lvl < 350) return 100;
        return 120;
}

mixed hit_ob(object me, object victim, int damage_bonus) 
{ 
        object weapon;
        int i;
        
        if (me->query("neili") < 300 
        ||  me->query_skill_mapped("sword") != "damo-jian" 
        ||  ! objectp(weapon = me->query_temp("weapon")) 
        ||  weapon->query("skill_type") != "sword") 
                return 0; 
                
        if (me->query_temp("damo-jian/lian") ||
            me->is_busy())
                return 0;

        message_combatd(HIY "\n$N" HIY "身随剑转，回剑横掠，一剑跟著一剑，绵绵不尽，"
                        "剑招连环进击，紧密无比。\n" NOR, 
                        me, victim); 
                                             
        me->add("neili", -270); 
                       
        me->set_temp("damo-jian/lian", 1); 
        
        for (i = 0; i < 3; i++) 
        { 
                if (! me->is_fighting(victim)) 
                        break; 
                  
                if (! victim->is_busy() && random(2) == 1) 
                        victim->start_busy(1); 
        
                COMBAT_D->do_attack(me, victim, weapon, 0); 
        } 
        me->delete_temp("damo-jian/lian"); 
        
}
                        
