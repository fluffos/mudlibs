// bibo-zhang.c
// Created by Numa 19990924,19991008

inherit SKILL;

// 正面攻击
string* msg_f = ({
	"小腿",
	"右臂",
	"左臂",
	"面门",
	"胸口",
	"小腹",
	"前庭",
});

// 背面攻击
string* msg_b = ({
	"背部",
	"后脑",
	"腰际",
});


mapping *action = ({
    ([  "action":       "$N一个纵身，双掌接连而出，化做「水天一色」飘移不定击向$n的"+ msg_f[random(sizeof(msg_f))],
        "dodge": 10,
        "parry": 5,
        "force": 120,
        "lvl": 0,
        "skill_name" : "水天一色",
        "damage_type": "瘀伤"
        ]),
    ([  "action":       "$N向前大踏一步，突使一招「水花四溅」双掌径直向着$n的"+ msg_b[random(sizeof(msg_b))] +"拍去",
        "dodge": -10,
        "parry": -5,
        "force": 160,
        "lvl": 30,
        "skill_name" : "水花四溅",
        "damage_type": "瘀伤"
    ]),
    ([  "action":       "$N周身一转，左掌划了个弧，右掌以「碧海蓝天」之势向着$n的" + msg_f[random(sizeof(msg_f))] + "穿梭而去",
        "dodge":  20,
        "parry":  10,
        "force": 200,
        "lvl": 50,
        "skill_name" : "碧海蓝天",        
        "damage_type": "瘀伤"
        ]),
    ([  "action":       "$N身行沉稳，双臂鱼贯而出，一招「波涛汹涌」猛击向$n的"+ msg_f[random(sizeof(msg_f))],
        "dodge": 20,
        "parry": 15,
        "force": 240,
        "lvl": 70,
        "skill_name" : "波涛汹涌",        
        "damage_type": "内伤"
        ]),
    ([  "action":       "$N向前大踏一步，两掌并发，左轻右重，劲含刚柔，一招「怒涛拍岸」袭向$n的" + msg_f[random(sizeof(msg_f))],
        "dodge": 20,
        "parry": 15,
        "force": 300,
        "lvl": 90,
        "skill_name" : "怒涛拍岸",
        "damage_type": "内伤"
        ]),

});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练碧波掌法必须空手。\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("bibo-zhang",1);
        for (i = sizeof(action); i > 0; i--)
	        if (level > action[i-1]["lvl"])
        	        return action[NewRandom( i, 20, level/5)];

}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 40)
                return notify_fail("你的体力太低了。\n");
        me->receive_damage("jingli", 20);
        return 1;
}