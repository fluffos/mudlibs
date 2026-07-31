// taiji-dao.c 太极刀
// cleansword 2/15/96

inherit SKILL;

string *action_msg = ({
        "$N手中$w斜指，一招「停车问路」，反身一顿，一刀向$n的$l撩去",
        "$N一招「童子挂画」，左右腿虚点，$w一提一收，平刃挥向$n的颈部",
        "$N展身虚步，提腰跃落，一招「推窗望月」，刀锋一卷，拦腰斩向$n",
        "$N一招「开门见山」，$w大开大阖，自上而下划出一个大弧，笔直劈向$n",
        "$N手中$w一沉，一招「临溪观鱼」，双手持刃拦腰反切，砍向$n的胸口",
        "$N挥舞$w，使出一招「张弓望的」，上劈下撩，左挡右开，齐齐罩向$n",
        "$N一招「风送轻舟」，左脚跃步落地，$w顺势往前，挟风声劈向$n的$l",
        "$N盘身驻地，一招「川流不息」，挥出一片流光般的刀影，向$n的全身涌去",
});


int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("taiji-shengong", 1) < 20)
                return notify_fail("你的太极神功火候太浅。\n");
        if ((int)me->query_skill("taiji-quan", 1) < 20)
                return notify_fail("你的太极拳火候太浅。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return ([
                "action": action_msg[random(sizeof(action_msg))],
                "damage": 120 + random(30),
                "attack": 40 + random(10),
                "dodge" : 40 + random(10),
                "parry" : 40 + random(10),
                "damage_type" : "割伤",
        ]);
}


int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练太极刀法。\n");
        if ((int)me->query("neili") < 50)
                return notify_fail("你的内力不够。\n");
        me->receive_damage("qi", 40);
        me->add("neili", -40);
        return 1;
}


