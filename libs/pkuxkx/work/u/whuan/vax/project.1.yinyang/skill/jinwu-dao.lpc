// jinwu-dao.c 金乌刀法
inherit SKILL;
mapping *action = ({
([      "action" : "$N使出「积雪几疑世」向左虚劈一刀，拖刀来，又向右空刺，待得
$n急于招架之时，$w急进中宫劈向$n。",
        "force" : 220,
        "dodge" : -5,
        "parry" : -5,
        "damage": 50,
        "lvl" : 0,
        "skill_name" : "积雪几疑世",
        "damage_type" : "割伤"
]),
([      "action" : "$N一招「得雨势更急」忽地门户大开，手中$w上劈下撩，左砍右削，
恰似一片刀光挟着$N飘向$n.",
        "force" : 240,
        "dodge" : -5,
        "parry" : -5,
        "damage": 60,
        "lvl" : 9,
        "skill_name" : "得雨势更急",
        "damage_type" : "割伤",
]),
([      "action" : "$N单刀环舞，使出「浪头飞碎白」在日光照耀下，$w发出一片耀眼白
光，如一匹白练卷向$n,令$n手足无措。",
        "force" : 260,
        "dodge" : -5,
        "parry" : 5,
        "damage": 70,
        "lvl" : 29,
        "skill_name" : "浪头飞碎白",
        "damage_type" : "割伤"
]),
([      "action" : "$N一式「藏焉未为固」反转$w，刀尖指地，蓦地上挑，身体顺势前仆，
刀锋发出嗤嗤声响撩向$n的下腹。",
        "force" : 280,
        "dodge" : -5,
        "parry" : 10,
        "damage": 80,
        "lvl" : 39,
        "skill_name" : "藏焉未为固",
        "damage_type" : "割伤"
]),
([      "action" : "$N双足点地，一式「蜿蜒若没骨」向空中跃起，待到$n的头顶上方时
身体直线下坠，刀尖下指，刺向$n。",
        "force" : 300,
        "dodge" : 5,
        "parry" : 15,
        "damage": 85,
        "lvl" : 59,
        "skill_name" : "蜿蜒若没骨",
        "damage_type" : "刺伤"
]),
([      "action" : "$N双手立刀胸前，一招「屹立作山势」，足一点地向前连翻两个筋斗，
待跃到$n前时，霍霍刀光罩向$n，落地后渊停狱峙立于$n面前。",
        "force" : 320,
        "dodge" : 10,
        "parry" : 10,
        "damage": 95,
        "lvl" : 69,
        "skill_name" : "屹立作山势",
        "damage_type" : "割伤"
]),
([      "action" : "$N高跃丈许，一招「天风吹海水」空中双手举$w过顶，力贯刀柄向下
猛劈向$n的头部，刀锋激得气流呜呜作响。",
        "force" : 340,
        "dodge" : -5,
        "parry" : -5,
        "damage": 105,
        "lvl" : 89,
        "skill_name" : "天风吹海水",
        "damage_type" : "割伤"
]),
([      "action" : "只见$N$w贴身，使出「不舍昼夜流」身形陡地下沉，向$n滚去，眨眼间
到了$n面前，$w挥出砍向$n的腿部。",
        "force" : 360,
        "dodge" : 5,
        "parry" : 25,
        "damage": 115,
        "lvl" : 109,
        "skill_name" : "不舍昼夜流",
        "damage_type" : "割伤"
]),
});
int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int valid_combine(string combo) { return combo=="shenghuo-shengong"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 50)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("jiuyang-shengong", 1) < 30)
                return notify_fail("你的九阳神功火候太浅。\n");
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
        level   = (int) me->query_skill("jinwu-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
        object weapon;
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练金乌刀。\n");
        me->receive_damage("qi", 35);
        return 1;
}
string *parry_msg = ({
        "只听见「锵」一声，被$p格开了。\n",
        "结果「当」地一声被$p挡开了。\n",
        "但是被$n用手中$v架开。\n",
        "但是$n身子一侧，用手中$v格开。\n",
});
string *unarmed_parry_msg = ({
        "但是被$p格开了。\n",
        "结果被$p挡开了。\n",
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
	return "太阳";
}