// 美女神拳 meinv-shenquan
// by iber 于千喜年
inherit SKILL;
#include <ansi.h>
mapping *action = ({
    ([  "action":
        "忽然$N大喝一声："HIG"＊"HIC"天"HIG"＊"HIW"马"HIG"＊"HIY"流"HIG"＊"HIM"星"HIG"＊"HIB"拳"HIG"＊"NOR"，顿时拳头如雨点般击向$n的$l",
        "dodge": -10,
        "parry": -10,
        "force": 50,
        "damage": 200,
        "damage_type": "瘀伤"
        ]),
    ([  "action":
        "$N倏忽欺至$n身前，大呼道："WHT"＊"HIM"庐"WHT"＊"HIB"山"WHT"＊"HIR"升"WHT"＊"HIY"龙"WHT"＊"HIG"霸"WHT"＊"NOR"，以一记威猛的勾拳向$n奋力击去",
        "dodge": -10,
        "parry": -10,
        "force": 100,
          "damage": 400,
        "damage_type": "瘀伤"
    ]),
    ([  "action":
"$N身形悄然一退，双拳一报，高呼："HIC"＊"HIR"曙"HIC"＊"HIW"光"HIC"＊"HIG"女"HIC"＊"HIY"神"HIC"＊"HIM"的"HIC"＊"HIB"宽"HIC"＊"YEL"恕"HIC"＊"NOR"，夹杂一股寒气攻向$n",
        "dodge": -10,
        "parry": -10,
        "force": 200,
           "damage": 600,
        "damage_type": "冻伤"
        ]),
    ([  "action":
        "$N身形拔地而起，在半空长啸："HIR"＊"HIG"凤"HIR"＊"HIC"翼"HIR"＊"HIB"天"HIR"＊"HIY"翔"HIR"＊"NOR"，双手卷起一片熊熊的火焰直喷向$n",
        "dodge": -10,
        "parry": -10,
        "force": 300,
         "damage": 700,
        "damage_type": "灼伤"
        ]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练美女神拳必须空手。\n");
          if ((int)me->query("max_neili") < 70000)
        return notify_fail("你的内力太弱，无法练美女神拳。\n");
          if ( (int)me->query("t") > 1 || (int)me->query("r") > 1  )
          return notify_fail("由于你的天性不够，你永远无法学到美女神拳。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 10000)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 10)
        return notify_fail("你的内力不够了！休息一下再练吧。\n");
        me->receive_damage("qi", 5);
        me->add("neili", -5);
        return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 100 ) return 0;

        if((damage_bonus/2) > victim->query_str()&& 
               !victim->query_temp("boduo")){
                victim->receive_wound("qi", (damage_bonus - 100) / 2 );
                victim->add_temp("boduo",1);                return HIW "只听到一个冷酷的声音："BLINK"第一感剥夺！\n" NOR;
        }
        if( (damage_bonus/2) > victim->query_str()&& 
                victim->query_temp("boduo")== 1){                victim->receive_wound("qi", (damage_bonus - 90) / 2 );
                victim->add_temp("boduo",1);
                return HIG"只听到一个冷酷的声音："BLINK"第二感剥夺！\n" NOR;
        }
        if( (damage_bonus/2) > victim->query_str()&& 
                victim->query_temp("boduo")== 2){                victim->receive_wound("qi", (damage_bonus - 80) / 2 );
                victim->add_temp("boduo",1);
                return HIB "只听到一个冷酷的声音："BLINK"第三感剥夺！\n" NOR;
        }
        if( (damage_bonus/2) > victim->query_str()&& 
                victim->query_temp("boduo")== 3){       
                victim->receive_wound("qi",(damage_bonus - 70) / 2 );
                victim->add_temp("boduo",1);
                return HIY"只听到一个冷酷的声音："BLINK"第四感剥夺！\n" NOR;
        }
        if( (damage_bonus/2) > victim->query_str() && 
                victim->query_temp("boduo")== 4){
                victim->receive_wound("qi", (damage_bonus - 60) / 2 );
                victim->add_temp("boduo",1);
                return HIC"只听到一个冷酷的声音："BLINK"第五感剥夺！\n" NOR;
        }
        if( (damage_bonus/2) > victim->query_str()&& 
                victim->query_temp("boduo")== 5){
                victim->receive_wound("qi", (damage_bonus - 50) / 2 );
                victim->add_temp("boduo",1);
                return HIR "只听到一个冷酷的声音："BLINK"第六感剥夺！\n" NOR;
        }
        if( (damage_bonus/2) > victim->query_str()&& 
                victim->query_temp("boduo")== 6){
                victim->delete_temp("boduo");
                return WHT"只听到一个冷酷的声音："BLINK"再次剥夺开始！\n" NOR;
        }
        
}

string perform_action_file(string action)
{
        return __DIR__"meinv-shenquan/" + action;
}
