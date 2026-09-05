inherit SKILL;

mapping *action = ({
([     "action" : "$N竖起$w来，一招「参拜北斗」，斜斜向$n的$l上刺去",
       "force" : 120,
        "dodge" : 10,
        "parry" : 5,
       "damage": 80,
       "lvl" : 0,
       "skill_name" : "参拜北斗",
       "damage_type" : "割伤"
]),
([     "action" : "$N凝立不动，$n一招攻来，仍是不闪不架，待敌招离身不过半尺,一招「鹞子翻身」，猛地转身，刷的一刀，砍向$n的$l",
       "force" : 180,
        "dodge" : 10,
        "parry" : 10,
       "damage": 80,
       "lvl" : 15,
       "skill_name" : "鹞子翻身",
       "damage_type" : "割伤"
]),
([     "action" : "$N向左滑开三步，刷的一声，$w出手，一招「谏果回甘」，回头向$n的$l砍去",
       "force" : 210,
        "dodge" : 15,
        "parry" : 15,
       "damage": 80,
       "lvl" : 30,
       "skill_name" : "谏果回甘",
       "damage_type" : "割伤",
]),
([     "action" : "$N突然撤手离刀，一招「沙僧拜佛」，双掌击出，砰的一响，打向$n的胸口。待$n一呆，一探手，又已抓住刀柄",
       "force" : 300,
        "dodge" : 10,
        "parry" : 10,
       "damage": 100,
       "lvl" : 45,
       "skill_name" : "沙僧拜佛",
       "damage_type" : "割伤"
]),
([     "action" : "$N$w一起，一招「缠身摘心」，刀光闪闪，已将$n上盘罩住,忽然一刀斩向$n的心窝",
       "force" : 320,
        "dodge" : 10,
        "parry" : 5,
       "damage": 120,
       "lvl" : 60,
       "skill_name" : "缠身摘心",
       "damage_type" : "割伤"
]),
([     "action" : "$N向前一扑，一招「浪子回头」，顺势回过$w，刷的一下，从下而上的斩向$n$l",
       "force" : 350,
        "dodge" : 10,
        "parry" : 5,
       "damage": 140,
       "lvl" : 75,
       "skill_name" : "浪子回头",
       "damage_type" : "割伤"
]),
([     "action" : "$N踏上两步，一招「怀中抱月」，回刀一削，跟着$w一推一横，向$n的$l砍去",
       "force" : 360,
        "dodge" : 15,
        "parry" : 15,
       "damage": 160,
       "lvl" : 100,
       "skill_name" : "怀中抱月",
       "damage_type" : "割伤",
]),
([     "action" : "$N身在半空，使一招「夜叉探海」,内劲运向$w之上，拍拍两刀，快如闪电般砍向$N的$l",
       "force" : 370,
        "dodge" : 15,
        "parry" : 10,
       "damage": 180,
       "lvl" : 120,
       "skill_name" : "夜叉探海",
       "damage_type" : "割伤",
]),
([     "action" : "$N头一低，弯腰避开敌招，一招「拜佛听经」,$w带着疾风呼的一声便向$n横扫过去",
       "force" : 380,
        "dodge" : 15,
        "parry" : 10,
       "damage": 200,
       "lvl" : 140,
       "skill_name" : "拜佛听经",
       "damage_type" : "割伤",
]),
([     "action" : "$N斜身高纵，扑到$n的左侧，一招「进步连环」，连环三刀，往$n的$l削去",
       "force" : 385,
        "dodge" : 25,
        "parry" : 5,
       "damage": 220,
       "lvl" : 160,
       "skill_name" : "进步连环",
       "damage_type" : "割伤",
]),
([     "action" : "$N一招「沙鸥掠波」，$w虚实互用，忽虚忽实,向$n的全身卷去",
       "force" : 390,
        "dodge" : 15,
        "parry" : 15,
       "damage": 240,
       "lvl" : 180,
       "skill_name" : "沙鸥掠波",
       "damage_type" : "割伤",
]),
([     "action" : "$N大喝一声，使招「八方藏刀式」，向前一攻，以左足为轴，转了个圈子，举$w对着$n连砍了八八六十四刀，刀气纵横，迅雷不可挡",
       "force" : 400,
        "dodge" : 10,
        "parry" : 15,
       "damage": 250,
       "lvl" : 200,
       "skill_name" : "八方藏刀式",
       "damage_type" : "割伤",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }


int valid_learn(object me)
{
       if ((int)me->query("max_neili") < 50)
               return notify_fail("你的内力不够练习胡家刀法。\n");
       if ((int)me->query_skill("blade", 1) < 100)
               return notify_fail("你的基本刀法火候太浅。\n");
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
       level   = (int) me->query_skill("hujia-daofa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
       object weapon;
       if ((int)me->query_skill("hujia-daofa",1)<250 && (int)me->query_skill("hujia-daofa",1)>=(int)me->query("yidao/times"))
       	       return notify_fail("你目前的修为就只能练到这个程度了！\n");
       if (!objectp(weapon = me->query_temp("weapon"))
       || (string)weapon->query("skill_type") != "blade")
               return notify_fail("你使用的武器不对。\n");
       if ((int)me->query("qi") < 150)
               return notify_fail("你的体力不够练胡家刀法。\n");
       if ((int)me->query("neili") < 100)
               return notify_fail("你的内力不够练胡家刀法。\n");
       me->receive_damage("qi", 100);
       me->add("neili",-3);
       return 1;
}
string perform_action_file(string action)
{
        return __DIR__"hujia-daofa/" + action;
}
