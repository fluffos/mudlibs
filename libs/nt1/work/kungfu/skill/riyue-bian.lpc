// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// riyue-bian.c 日月鞭法

#include <ansi.h>

inherit SKILL;

string *action_msg = ({
        "$N端坐不动，一式「阿那律刺」，手腕力抬，$w滚动飞舞，宛如灵蛇乱颤，前缠后绕，其力沾粘不散",
        "$N一式「目捷连刺」，将手$w中抖得笔直，“呲呲”声中向$n疾刺而至，所挟劲风已令$n一阵气窒",
        "$N内劲到处，将$w抖动转成两个圆圈，一式「舍利佛刺」，跃起从半空中往$n$l缠下",
        "$N劲走螺旋，一式「富楼那刺」，$w在$n眼前上圈下钩，左旋右转，连变了数种招式，忽然从$n$l处倒卷上来",
        "$N一声高喝，吸气催力，一式「迦旋延刺」，$w急速转动，鞭影纵横，直中有圆，圆中有直，似真似幻，绞向$n",
        "$N含胸拔背、沉肩坠肘，一式「弘忍能刺」，力道灵动威猛，虚实分明，劲力从四面八方向$n挤压出去",
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
        mapping fam;
        object weapon;

        fam = me->query("family"); 
        if( !mapp(fam) || fam["family_name"] != "少林派" )
                return notify_fail("你不属于少林派，不能学习博大精深的日月鞭法！\n");

        if ( fam["family_name"] == "少林派" && fam["generation"] > 36 )
                return notify_fail("你资格不够，不能学习日月鞭法，等到升了辈份再说吧。\n");

        if ((int)me->query("str") < 26)  
                return notify_fail("就你这身子骨还练日月鞭法？小心弄折了胳膊。\n");  
                
        if( (int)me->query("max_neili") < 500 )
                return notify_fail("你的内力不足，没有办法练日月鞭法，多练些内力再来吧。\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("你的内功火候太浅，没有办法练日月鞭法。\n");

        if ((int)me->query_skill("whip", 1) < 100)
                return notify_fail("你的基本鞭法火候太浅，没有办法练日月鞭法。\n");
                
        if ((int)me->query_skill("hunyuan-yiqi", 1) < 50)
                return notify_fail("你的混元一气功火候太浅。\n");

        if ( !objectp(weapon = me->query_temp("weapon"))
        || ( string)weapon->query("skill_type") != "whip" )
                return notify_fail("你必须先找一条鞭子才能练鞭法。\n");
                
        if ((int)me->query_skill("whip", 1) < (int)me->query_skill("riyue-bian", 1))
                return notify_fail("你的基本鞭法水平还不够，无法领会更高深的日月鞭法。\n");
        return 1;
}

mapping query_action(object me)
{
        if (random(me->query_str()) >= 32 
        &&  me->query_skill("riyue-bian", 1) > 120)
        {
                if (random(me->query_str()) >= 38 
                &&  me->query_skill("riyue-bian", 1)> 170) 
                {           
                        return ([
                             "action": HIR "$N把手中$w抖动成圈，绕着$n越转越急，越转越快，$p登时身不由主，被套得连转了几身，眼看就要摔倒！"NOR,
                             "dodge" : 120,
                             "parry" : 120,
                             "attack": 200,
                             "damage": 180,
                             "damage_type": "摔伤"
                        ]);
                }     
                return ([
                        "action": HIR "$N手腕一抖，但见飞舞的$w从天而下和$n缠在一起，一股排山倒海的内劲无声息的向$n胸口撞去！"NOR,
                        "dodge" : 100,
                        "parry" : 100,
                        "attack": 180,
                        "damage": 160,
                        "damage_type": "内伤"
                ]);
        }
        
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "damage": 120 + random(40),
                "attack": 70 + random(10),
                "dodge" : 70 + random(10),
                "parry" : 70 + random(10),
                "damage_type" : random(2)?"劈伤":"刺伤", 
        ]);
}

int practice_skill(object me)
{
       if ((int)me->query("qi") < 80)
                return notify_fail("你的体力不够练日月鞭法。\n");
                
       if ((int)me->query("neili") < 80 )
                return notify_fail("你的内力不够练日月鞭法。\n");
                
       me->receive_damage("qi", 70);
       me->add("neili", -70);
            
       return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        mixed result;
        int level;
        object weapon;
        string *msg;
        weapon = me->query_temp("weapon");
        msg = ({
                HIR"只听得“啊”的一声惨叫，$n背脊为"+weapon->name()+HIR"所击中，摔出了战圈，眼见是不活了。\n"NOR,
                HIR"这一鞭威力极巨，登时打得$p脑浆迸裂，四肢齐折，不成人形。\n"NOR,
                HIR""+weapon->name()+HIR"一抖之下，一股排山倒海的内劲向$n胸口撞到，$n当场肋骨断折，五脏齐碎。\n"NOR,
        });
        result = ([ "damage" : damage_bonus ]);
        result += ([ "msg" : msg[random(sizeof(msg))] ]);
        return result;
}

string perform_action_file(string action)
{
        return __DIR__"riyue-bian/" + action;
}

int query_effect_parry(object attacker, object me)
{
        int lvl;

        if (! me->query_temp("weapon"))
                return 0;

        lvl = me->query_skill("riyue-bian", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 50;
        if (lvl < 280) return 80;
        if (lvl < 350) return 100;
        return 120;
}
