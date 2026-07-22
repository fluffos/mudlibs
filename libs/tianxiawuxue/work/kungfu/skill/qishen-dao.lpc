// qishenu-dao.c 泣神刀法

inherit SKILL;

mapping *action = ({
([      "action" : "$N手中$w斜指，一招「面目全非」，刀劲裹着刀锋，向$n的$l撩去",
        "force" : 120,
        "dodge" : -10,
        "parry" : 5,
        "damage" : 15,
        "damage_type" : "割伤"
]),
([      "action" : "$N一招「家破人亡」，$w被右手反握，交叉挥动，连人卷成尖锥刀网，向$n直射而来",
        "force" : 130,
        "dodge" : -10,
        "parry" : 10,
        "damage" : 20,
        "damage_type" : "割伤"
]),
([      "action" : "$N展身虚步，提腰跃落，一招「血海深仇」，刀锋一卷，拦腰斩向$n",
        "force" : 140,
        "dodge" : -5,
        "parry" : 5,
        "damage" : 30,
        "damage_type" : "割伤"
]),
([      "action" : "$N一招「骨肉分离」，$w大开大阖，自上而下划出一个闪电，直劈向$n",
        "force" : 160,
        "dodge" : 5,
        "parry" : 5,
        "damage" : 40,
        "damage_type" : "割伤"
]),
([      "action" : "$N手中$w一沉，一招「切肤之痛」，双手持刃拦腰反切，砍向$n的胸口",
        "force" : 180,
        "dodge" : 10,
        "parry" : 5,
        "damage" : 50,
        "damage_type" : "割伤"
]),
([      "action" : "$N一招「天愁地惨」，戾气冲天挥舞，人刀卷缠黑云，齐齐罩向$n",
        "force" : 210,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 60,
        "damage_type" : "割伤"
]),
([      "action" : "$N一招「鬼哭神号」，左脚跃步落地，$w顺势往前，挟风声劈向$n的$l",
        "force" : 240,
        "dodge" : 5,
        "parry" : 15,
        "damage" : 70,
        "damage_type" : "劈伤"
]),
([      "action" : "$N盘身驻地，一招「惊天泣神」，挥出一片流光般的刀影，向$n的全身涌去",
        "force" : 280,
        "dodge" : 20,
        "parry" : 10,
        "damage" : 80,
        "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("blade", 1) < 20)
                return notify_fail("你的基本刀法火候太浅。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
int zhaoshu, level;

zhaoshu = sizeof(action)-1;
level   = (int) me->query_skill("qishen-dao",1);

if (level < 60 )
zhaoshu--;
if (level < 50 )
zhaoshu--;
if (level < 40 )
zhaoshu--;
if (level < 30 )
zhaoshu--;
if (level < 20 )
zhaoshu--;
if (level < 10 )
zhaoshu--;
return action[random(zhaoshu)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("jing") < 100)
                return notify_fail("你的精力不够练此武功。\n");
        if ((int)me->query("qi") < 100)
                return notify_fail("你的体力不够练此武功。\n");
        if ((int)me->query("neili") < 100)
                return notify_fail("你的内力不够练此武功。\n");
        me->receive_damage("qi", 50);
        me->receive_damage("jing", 50);
        me->add("neili", -50);

                return 1;
}
string perform_action_file(string action)
{
        return __DIR__"qishen-dao/" + action;
}

