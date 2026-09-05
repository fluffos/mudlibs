// jiuyin-baiguzhao.c 九阴白骨爪
//Made By:pingpang
#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([  "action" : "$N使一招[旋风爪]，右爪往$n的胳膊爪去，$n胳膊连皮带肉被$N抓了下来",
         "force" : 150,
         "dodge" : 10,
         "damage": 5,
         "skill_name" : "旋风爪",
         "damage_type" : "瘀伤"
         ]),
        ([  "action" : "$N左爪突然升起，弯成铁爪状，使出一招[天鹰爪]打向$n的$1",
         "force" : 180,
         "dodge" : 15,
         "damage": 20,
         "skill_name" : "天鹰爪",
         "damage_type" : "瘀伤"
         ]),
        ([  "action" : "$N双爪紧扣，使出一招[双龙爪],打向$n的$l",
         "force" : 240,
         "dodge" : 10,
         "damage": 40,
         "skill_name" : "双龙爪",
         "damage_type" : "瘀伤"
         ]),
        ([  "action" : "$N左爪成钳状,使出一招[飞虎抓],向$n的$1处打去",
         "force" : 300,
         "dodge" : 5,
         "damage": 80,
         "skill_name" : "飞虎抓",
         "damage_type" : "瘀伤"
         ]),
        ([  "action" : "$N施出「飞天爪」，双爪向$n的后心爪去,$n的后心顿时露出五个血孔",
         "force" : 360,
         "dodge" : 10,
         "damage": 120,
         "skill_name" : "飞天爪",
         "damage_type" : "瘀伤"
         ])
});
mapping query_action(object me)
{   int skill=me->query_skill("jiuyin-baiguzhao",1);
    if (random(me->query_skill("claw")) > 120 
            && me->query_skill("force") > 80 
            && me->query("neili") > 600 && random(skill) > 100) 
    {
        me->add("neili", -100);
        return ([
                "action": HIR"$N右手向前一升，从一个不可思议的角度向$n的天灵盖抓去。"NOR,
                "force": 540,
                "damage": 200,
                "damage_type": "瘀伤"]);
    }
    return action[random(sizeof(action))];
}

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }
int valid_combine(string combo) { return combo=="cuixin-zhang";}

int valid_learn(object me)
{
    if ((int)me->query("shen") > 0)
        return notify_fail("道德小于零才能练这种阴毒功夫。\n");
    if ((int)me->query_skill("jiuyin-shengong",1)<30)
        return notify_fail(to_chinese("jiuyin-shengong")+"大于 30 级才能学九阴白骨爪。\n");
    return 1;
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("你的内力不够练九阴白骨爪。\n");
    me->receive_damage("qi", 25);
    me->add("neili", -10);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"jiuyin-baiguzhao/" + action;
}

string *parry_msg = ({
        "只听见「锵」一声，被$p格开了。\n",
        "结果「当」地一声被$p挡开了。\n",
        "但是被$n用手中$v架开。\n",
        "但是$n身子一侧，用手中$v格开。\n",
        });

string *unarmed_parry_msg = ({
        "但是$n身子一侧，用左手轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
        "$n左手轻轻推出，拍向$N的$w，然后身体向右一侧，顺势后拉，$N就象打空了似的，对$n毫无伤害。\n",
        });

string query_parry_msg(object weapon)
{
    if( weapon )
        return parry_msg[random(sizeof(parry_msg))];
    else
        return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string query_yinyang()
{
	return "太阴";
}