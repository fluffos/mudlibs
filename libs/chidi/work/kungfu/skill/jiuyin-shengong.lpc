// jiuyin-shengong.c 九阴神功

inherit FORCE;

string *dodge_msg = ({
        "$n动也不动，把$N震到一边。\n",
        "$n身形微微一抖，将$N迫退。\n",
        "$n手足忽的一晃，$N竟然无法进击，只能自保。\n",
        "$n轻轻一格，将天下所有进攻招数全部封死。\n",
});

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("jiuyin-shengong", 1);
        return lvl * lvl * 22 * 15 / 100 / 200;
}

mapping *action = ({
([      "action":"$N伸手一探，毫无花巧的袭向$n",
        "force" : 510,
        "attack": 190,
        "dodge" : 100,
        "parry" : 90,
        "damage": 180,
        "damage_type":  "震伤"
]),
([      "action":"$N双手齐抓，照向$n的$l",
        "force" : 510,
        "attack": 185,
        "dodge" : 90,
        "parry" : 120,
        "damage": 175,
        "damage_type":  "抓伤"
]),
([      "action":"$N身形一转，拳头挥出，击向$n的$l",
        "force" : 530,
        "attack": 175,
        "dodge" : 90,
        "parry" : 110,
        "damage": 200,
        "damage_type":  "瘀伤"
]),
([      "action":"$N移步向前，一掌不紧不慢的拍向$n的$l",
        "force" : 525,
        "attack": 185,
        "dodge" : 85,
        "parry" : 115,
        "damage": 185,
        "damage_type":  "内伤"
]),
([      "action":"$N身体一侧，飞起一脚，踢向$n的$l",
        "force" : 530,
        "attack": 165,
        "dodge" : 90,
        "parry" : 115,
        "damage": 200,
        "damage_type":  "瘀伤"
]),
([      "action":"$N双手合拳，蓦的张开，抓向$n的$l",
        "force" : 540,
        "attack": 200,
        "dodge" : 115,
        "parry" : 120,
        "damage": 180,
        "damage_type":  "抓伤"
]),
});

string *usage_skills = ({ "unarmed", "finger", "strike",
                          "claw", "hand", "cuff", "dodge",
                          "parry", "force" });

int valid_enable(string usage)
{
        return (member_array(usage, usage_skills) != -1);
}

int valid_force(string force) { return 1; }

int double_attack() { return 1; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
        int level;
        int i;

        if ((int)me->query("combat_exp") < 3000000)
                return notify_fail("你觉得九阴神功深奥之极，"
                                   "凭自己的战斗经验一时间难以领会。\n");

        if ((int)me->query_skill("martial-cognize", 1) < 300)
                return notify_fail("你觉得九阴神功过于深奥，以"
                                   "自己的武学修养全然无法明白。\n");

        if (me->query("character") != "光明磊落")
                return notify_fail("九阴神功正大恢弘，气度俨然，你"
                                   "怎么也学不得神似。\n");

        if (me->query("str") < 22 && me->query_str() < 63)
                return notify_fail("你发现自己的膂力不足，无法"
                                   "将九阴神功运用自如。\n");

	if (me->query("gender") == "无性" &&
	    (int)me->query_skill("jiuyin-shengong", 1) > 199)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的九阴神功。\n");
 if (!me->query("zhuanshi/times"))
              return notify_fail("你还没有投胎转世，不适合学习高深的九阴神功。\n");


        level = me->query_skill("jiuyin-shengong", 1);

        if ((int)me->query_skill("martial-cognize", 1) < level)
                return notify_fail("你觉得自己的武学修养有限，难以领会更高深的九阴神功。\n");

        for (i = 0; i < sizeof(usage_skills); i++)
                if (me->query_skill(usage_skills[i], 1) < level)
                        return notify_fail("你对" + to_chinese(usage_skills[i]) +
                                           "的理解还不够，无法继续领会更高深的九阴神功。\n");
 if ( me->query_skill("kuihua-mogong",1) )
        return notify_fail("你都学了葵花魔功，还学九阴神功做什麽？！\n");
        
  
if ( me->query_skill("bluesea-force",1) )
        return notify_fail("你都学了南海玄功，还学九阴神功做什麽？！\n");
      
 if ( me->query_skill("never-defeated",1) )
        return notify_fail("你都学了不败神功，还学九阴神功做什麽？！\n");
   
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("九阴神功博大精深，无法简单的通过练习进步。\n");
}

int difficult_level()
{
        return 500;
}

string perform_action_file(string action)
{
        return __DIR__"jiuyin-shengong/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"jiuyin-shengong/exert/" + action;
}


