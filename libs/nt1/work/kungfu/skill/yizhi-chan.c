// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// yizhi-chan.c 一指禅

#include <ansi.h>
inherit SHAOLIN_SKILL;

string *action_msg = ({
        "$N双指并拢，一式「佛恩济世」，和身而上，左右手一前一后戳向$n的胸腹间",
        "$N左掌护胸，一式「佛光普照」，右手中指前后划了个半弧，猛地一甩，疾点$n的$l",
        "$N身形闪动，一式「佛门广渡」，双手食指端部各射出一道青气，射向$n的全身要穴",
        "$N盘膝跌坐，一式「佛法无边」，左手握拳托肘，右手拇指直立，遥遥对着$n一捺",
});

int valid_enable(string usage) { return usage == "finger" || usage == "parry"; }

int valid_combine(string combo) { return combo == "banruo-zhang"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练一指禅必须空手。\n");

        if ((int)me->query_skill("force") < 60)
                return notify_fail("你的内功火候不够，无法学一指禅。\n");

        if ((int)me->query("max_neili") < 300)
                return notify_fail("你的内力太弱，无法练一指禅。\n");

        if ((int)me->query_skill("finger", 1) < (int)me->query_skill("yizhi-chan", 1))
                return notify_fail("你的基本指法水平有限，无法领会更高深的一指禅。\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "force" : 320 + random(120),
                "attack": 70 + random(10),
                "dodge" : 70 + random(10),
                "parry" : 70 + random(10),
                "damage_type" : "刺伤",
        ]);        
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 80)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 80)
                return notify_fail("你的内力不够练一指禅。\n");

        if( (int)me->query_skill("banruo-zhang", 1) < 180 )
                return notify_fail("你的般若掌修为还不够。\n");

        me->receive_damage("qi", 70);
        me->add("neili", -70);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yizhi-chan/" + action;
}

void skill_improved(object me)
{
        int level = (int)me->query_skill("yizhi-chan", 1);

        if( level == 180 && ! me->query("sl/con"))
        {
                me->add("con", 1);
                me->set("sl/con", 1);
                tell_object(me, "你的一指禅和般若掌学有所成，提高了你的根骨。\n");
        }

        if ((string)me->query("family/family_name") == "少林派")
            {
        if( !(level % 10) && level >= (int)me->query_skill("hunyuan-yiqi", 1) ) {
                me->improve_skill("hunyuan-yiqi", (level - 5), 1);
                tell_object(me, "你在一指禅方面的造诣增进了你的混元一气功修为。\n");
        }
            }
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        mixed result;
        
        if( damage_bonus < 50 ) return 0;

        if( random(damage_bonus/2) > victim->query_str() )
        {
                result = ([ "damage" : damage_bonus ]);
                result += ([ "msg" : HIR "你听到「咻」一声轻响，一股劲气直透$n的前胸！\n" NOR ]);
                return result;
        } 
}

int query_effect_parry(object attacker, object me)
{
        int lvl;

        if (objectp(me->query_temp("weapon")))
                return 0;

        lvl = me->query_skill("yizhi-chan", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 50;
        if (lvl < 280) return 80;
        if (lvl < 350) return 100;
        return 120;
}
