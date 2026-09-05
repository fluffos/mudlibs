// taixuan-gong.c 侠客岛太玄功
// Jay 4/5/96
// modified by Venus Oct.1997
//2000/6/10日 由lywin调整攻击力！加入自动pfm

#include <ansi.h>
//inherit FORCE;
inherit SKILL;

string *dodge_msg = ({
    "$n左手拍出，劲风到处，把$N震到一边。\n",
    "$n手臂回转，抓住$N手肘一推，将$N远远掷开。\n",
    "$n两腿轻蹬，激跃而出，竟已落在十数丈外。\n",
    "$N只觉眼前一花，只见到$n身形一幌，自己的招数居然莫名其妙就落空了。\n",
});

mapping *action = ({
([  "action":"$N双手一举，一股劲气澎湃汹涌而来，逼得$n踉踉后退",
    "force" : 200,
    "dodge" : 20,
    "damage": 240,
    "damage_type":  "瘀伤"
]),
([  "action":"$N右手伸出，在$n臂膀上迅速无比的一按，$n一跤跌了出去",    
    "force" : 320,
    "dodge" : 20,
    "damage": 350,
    "damage_type":  "瘀伤"
]),
([  "action":"$N大喝一声，张口一股内气向$n脸上喷去",
    "force" : 400,
    "dodge" : 30,
    "damage": 390,
    "damage_type":  "瘀伤"
]),
([  "action":"$N猱身而上，双掌猛地拍向$n",
    "force" : 425,
    "dodge" : 30,
    "damage": 470,
    "damage_type":  "瘀伤"
]),
([  "action":"$N身体微侧，突然飞起一脚，踢向$n下三路。脚到中途，猛地一抬，踢向$n面门",
    "force" : 530,
    "dodge" : 40,
    "damage": 450,
    "damage_type":  "瘀伤"
]),
([  "action":"$N突然间左手一捺，封住$n退路，右手掌力汹涌而出",
    "force" : 630,
    "dodge" : 40,
    "damage": 400,
    "damage_type":  "瘀伤"
]),

});

int valid_enable(string usage)
{
      return usage == "unarmed" || usage == "hand" || usage == "dodge" ||usage == "parry" || usage == "force";
}

mapping query_action(object me, object weapon)
{
	if (random(me->query_skill("taixuan-gong",1)) > 100 && me->query("neili") > 100)
	{
		me->add("neili", -100);
		return ([
	"action": HIR "$N的心中突然一片茫然，只觉得经脉中象有无数的蝌蚪在串来串去，难过非常，
当下不及多想，顺着蝌蚪的走向一阵拳打脚踢！四周顿时劲风乱飑，好不热闹！"NOR,
	"damage": 1000,
	"dodge" : 100,
	"force" : 400,
	"damage_type": "瘀伤"]);
	}
	return action[random(sizeof(action))];
}

string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	return notify_fail("太玄神功无法通过练习来成长。\n");
}

int valid_learn(object me)
{
    if (random(this_player()->query("int")) > 25)
        return 1;
    return notify_fail("你苦思良久！竟是一头雾水，毫无所得！。\n");

}

string exert_function_file(string func)
{
        return __DIR__"taixuan-gong/" + func;
}