#include <ansi.h>
// biguan.c

inherit SKILL;

void skill_improved(object me)
{}

int practice_skill(object me)
{
	return notify_fail("你只有通过4转达到天人合一。才会这门功夫。\n");
}

string *usage_skills = ({ "unarmed", "parry", "dodge","force" });

int valid_enable(string usage)
{
        return (member_array(usage, usage_skills) != -1);
}
string perform_action_file(string action)
{
	return __DIR__"tianrenheyi/" + action;
}

int valid_learn(object me)
{
        int level;
        int i;
//       if( !me->query("zhuanbest",1))
//        return notify_fail("你没有资格使用这项技能！\n");

       if( !me->query("4zhuan") && !me->query("5zhuan"))
        return notify_fail("你没有资格使用这项技能！\n");


        for (i = 0; i < sizeof(usage_skills); i++)
                if (me->query_skill(usage_skills[i], 1) < level)
                        return notify_fail("你对" + to_chinese(usage_skills[i]) + "的理解还"
                                           "不够，无法继续领会更高深的天人合一。\n");

        return 1;
}
string *dodge_msg = ({
        "$n动也不动，把$N震到一边。\n",
        "$n身形微微一抖，将$N迫退。\n",
        "$n手足忽的一晃，$N竟然无法进击，只能自保。\n",
        "$n轻轻一格，将天下所有进攻招数全部封死。\n",
});

mapping *action = ({
([      "action":"$N伸手一探，顿时气流呼啸而至，单手毫无花巧的插向$n$l",
        "force" : 510,
        "attack": 190,
        "dodge" : 100,
        "parry" : 90,
        "damage": 180,
        "weapon": HIW "九阴无极劲" NOR,
        "damage_type":  "刺伤"
]),
([      "action":"$N双手齐抓，幻出千万道耀眼的金光，齐齐照向$n的$l",
        "force" : 510,
        "attack": 185,
        "dodge" : 90,
        "parry" : 120,
        "damage": 175,
        "weapon": HIW "九阴无极劲" NOR,
        "damage_type":  "割伤"
]),
([      "action":"$N身形一转，拳头携着疾速旋转的气流挥出，疾如闪电，势如雷霆，击向$n",
        "force" : 530,
        "attack": 75,
        "dodge" : 90,
        "parry" : 110,
        "damage": 200,
        "weapon": HIW "九阴无极劲" NOR,
        "damage_type":  "刺伤"
]),
([      "action":"$N移步向前，一掌不紧不慢的拍向$n的$l，空气中顿时传来一阵刺耳的暴响",
        "force" : 525,
        "attack": 85,
        "dodge" : 85,
        "parry" : 115,
        "damage": 185,
        "weapon": HIW "九阴无极劲" NOR,
        "damage_type":  "割伤"
]),
([      "action":"$N身体一侧，一掌凌空劈出，一股凛冽的气流顿时澎湃涌至$n的$l处",
        "force" : 530,
        "attack": 65,
        "dodge" : 90,
        "parry" : 115,
        "damage": 200,
        "weapon": HIW "九阴无极劲" NOR,
        "damage_type":  "割伤"
]),
([      "action":"$N双手合拳，蓦的张开，只听“嗤嗤”破空之声，十道劲气一齐射向$n的$l",
        "force" : 540,
        "attack": 80,
        "dodge" : 115,
        "parry" : 120,
        "damage": 280,
        "weapon": HIW "九阴无极劲" NOR,
        "damage_type":  "刺伤"
]),
});


mapping query_action(object me, object weapon)
{
        return weapon ? action[random(sizeof(action))] :
                        action[random(sizeof(action))];
}
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
