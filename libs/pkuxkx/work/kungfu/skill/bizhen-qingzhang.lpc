// bizhen-qingzhang.c 碧针清掌
// iszt@pkuxkx, 2006-09-18
//修改一些东西，debuff下,加入busy内力消耗,有筋斗buff没有清掌效果

#include <ansi.h>

inherit SKILL;

string *action_msg = ({
        NOR"$N"NOR"催动内力，袍袖飘飘，双掌向四周凌空拍出，掌风压得$n"NOR"几乎喘不过气来",
        NOR"$N"NOR"猛然间掌力疾吐，双掌齐推，无形中内力以一股排山倒海之势直逼$n",
        NOR"$N"NOR"若无其事的连连出掌，每一掌都带起无数落叶砂石攻向$n"NOR"，威势无比",
        NOR"$N"NOR"原地出掌并不移动，掌风形成一个无形无质的圈子，$n"NOR"陷身其中，难以进退",
        NOR"$N"NOR"身形疾转，四面八方都是掌影，突然间欺近$n"NOR"，令$n"NOR"手足无措",
        NOR"$N"NOR"长笑声中两掌先后向$n"NOR"推出，两股凌厉无匹的掌风相继扑向$n",
        NOR"$N"NOR"神态自若间加催内力，愈发强大的掌力以横扫千军之势在$n"NOR"身边激荡",
        NOR"$N"NOR"作势欲欺身上前，$n"NOR"始料未及，正慌乱间$N"NOR"却又停在原地以掌力攻来",
        NOR"$N"NOR"凝神闭气，聚集全身功力单掌劈出，锐利的掌风仿佛利刃般扫向$n",
        NOR"$N"NOR"一掌接着一掌，内力鼓荡在$N"NOR"周围形成了一个圈子，攻向$n",
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("你的手中拿着武器，无法练习碧针清掌。\n");
        if ((int)me->query("max_neili") < 1000)
                return notify_fail("你的内力太弱，无法练习碧针清掌。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        if(me->query("neili") < 100)
                return ([
                        "action" : "$N一掌拍向$n$l，去势虽狠，却难免露出内力衰竭之象",
                        "force" : 0,
                        "dodge" : 0,
                        "damage_type" : "瘀伤",
                ]);
        if(me->query_temp("qingxiao"))
        {
                me->add("neili", -100);
                return ([
                        "action" : replace_string(action_msg[random(sizeof(action_msg))], NOR, HIG) + NOR,
                        "force" : 800,
                        "dodge" : 100,
                        "weapon" : random(2) ? "掌风" : "掌力",
                        "damage_type" : random(2) ? "割伤" : "瘀伤",
                ]);
        }
        me->add("neili", -40);
        return ([
                "action" : action_msg[random(sizeof(action_msg))],
                "force" : 500,
                "dodge" : 10,
                "weapon" : random(2) ? "掌风" : "掌力",
                "damage_type" : random(2) ? "割伤" : "瘀伤",
        ]);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        if(me->query_temp("qingxiao")&&!me->query_temp("active_buffer/shenghuo-lingfa.jindou")
				&& !me->query_temp("kuihua.guiming")
			    && !victim->is_busy()
                && random(4) > 1)
        {
            F_KUNGFU->hit_busy( "confuse", 3, victim );
            message_vision(HIY"\n\n$N掌力愈来愈强，直逼得$n疲于招架，应接不暇！\n"NOR, me, victim);
	        me->add("neili", -100);
        }
        return 1;
}

int practice_skill(object me)
{
        int level = me->query_skill("bizhen-qingzhang",1);
        if(level > 300)
                level = 0; //降低高级别练习的难度

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("你的手中拿着武器，无法练习碧针清掌。\n");
        if ((int)me->query("max_neili") < 1000)
                return notify_fail("你的内力太弱，无法练习碧针清掌。\n");
        if ((int)me->query("neili") < level + 100)
                return notify_fail("你的真气不够，无法练习碧针清掌。\n");
        if ((int)me->query("jing") < 10)
                return notify_fail("你的精不够，无法练习碧针清掌。\n");

        me->add("jing", -10);
        me->add("neili", -random(100) - level);

        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"bizhen-qingzhang/" + action;
}

int help(object me)
{
        write(HIG"\n碧针清掌："NOR"\n");
        write(DASH_LINE_LF);
        write(@HELP
            「碧针清掌」是摩天居士谢烟客自创的一路掌法，松针尖细沉实，
        不如寻常树叶之能受风，这路掌法能以内力鼓荡松针，将成千成万枚松
        针反击上天，始终不让松针落下地来。
            每出一掌需消耗内力 40 点。
        练习要求：
                最大内力 1000 以上。
        练习消耗：
                碧针清掌等级 300 以前消耗内力最多 碧针清掌等级+100 点；
                碧针清掌等级 300 以后消耗内力最多 100 点；
                消耗精 10 点。
        
HELP
        );
        return 1;
}
