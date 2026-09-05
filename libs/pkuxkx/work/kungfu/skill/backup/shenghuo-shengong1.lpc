// shenghuolin.c
// Writed by yuer
inherit SKILL;
mapping *action = ({
([      "action":"$N身形一晃，“啪”的一声，抓住$n的后领，远远掷了出去.",
        "force" : 120,
        "dodge" : -10,
        "damage": 35,
        "lvl" : 0,
               "weapon" : "左手手掌",
        "damage_type":  "淤伤"
]),
([      "action":"$N$w向$n咽喉点去，$w忽然尾端一弹，急点$n手腕",
        "force" : 140,
        "dodge" : -10,
        "damage": 50,
        "lvl" : 10,
                "weapon" : "右手",
        "damage_type":  "刺伤"
]),
([      "action":"$N突然连翻三个筋斗，白影一闪,有如一条白链，$w向$n重重击去。",
        "force" : 160,
        "dodge" : 5,
        "damage": 75,
        "lvl" : 25,
                "weapon" : "右手手掌",
        "damage_type":  "刺伤"
]),
([      "action":"突然间$N向后摔出，$w从一个不可思议的角度电般急射向$n。",
        "force" : 200,
       "dodge" : 5,
        "damage": 100,
        "lvl" : 40,
        "weapon" : "手指",
        "damage_type":  "刺伤"
]),
([      "action":"$N身体急转，旋风般飞起两脚，$w乘虚刺向$n的小腹，端的是神妙无伦
，不可思议",
        "force" : 260,
       "dodge" : 5,
        "damage": 115,
        "lvl" : 55,
                "weapon" : "手指",
        "damage_type":  "刺伤"
]),
([      "action":"$n攻向$N的$l，$N不退反进，忽然低头向$n撞来，攻了$n一个措手不及
",
        "force" : 270,
       "dodge" : 5,
        "damage": 150,
        "lvl" : 70,
                "weapon" : "左手",
        "damage_type":  "刺伤"
]),
([      "action":"$N跃身半空，忽然向$n头顶坐了下来，甚是怪异，竟以臀部攻人。",
        "force" : 370,
       "dodge" : 5,
        "damage": 170,
        "lvl" : 80,
                "weapon" : "臀部",
        "damage_type":  "淤伤"
]),
([      "action":"$N左肩一沉，滴溜溜地一个转身，绕到$n的背后，斜身反挑$w刺向$n。",
        "force" : 370,
       "dodge" : 5,
        "damage": 35,
        "lvl" : 20,
                "weapon" : "手指",
        "damage_type":  "刺伤"
]),
([      "action":"$N挥剑反撩，剑锋上冷光闪动，$w划出一个优美的圆弧，劈向$n。",
       "dodge" : 5,
        "damage": 70,
        "lvl" : 70,
        "damage_type":  "刺伤"
]),
([      "action":"$N一声轻叱，$w圈转，剑点如飞花般散了开来罩向$n。",
       "dodge" : 5,
       "parry" : 10,
        "damage": 70,
        "lvl" : 50,
        "damage_type":  "刺伤"
]),
([      "action":"$N手中$w略划半弧，倏地刺出，银星点点，剑尖连刺$n的七处要害。",
       "dodge" : -5,
       "parry" : 10,
        "damage": 80,
        "lvl" : 80,
        "damage_type":  "刺伤"
]),
([      "action":"寒光陡闪，$N猛地反刺$n,$w犹如灵蛇，颤动不绝。",
       "dodge" : 5,
       "parry" : 10,
        "damage": 30,
        "lvl" : 5,
        "damage_type":  "刺伤"
]),
([      "action":"$N一声清啸，剑气纵横散开，剑锋闪烁不定，围着$n环刺，银光飞舞，
犹如散开了一幕剑网。",
       "dodge" : －15,
       "parry" : 10,
        "damage": 115,
        "lvl" : 100,
        "damage_type":  "刺伤"
]),
([      "action":"$N回剑护身，猛地一剑挺出疾刺$n，捷入闪电，势若奔雷。",
       "dodge" : 5,
       "parry" : 10,
        "damage": 80,
        "lvl" : 60,
        "damage_type":  "刺伤"
]),
([      "action":"$N右腕陡沉，连刺三剑，快如闪电，嗤嗤有声。",
       "dodge" : 5,
       "parry" : 10,
        "damage": 30,
        "lvl" : 10,
        "damage_type":  "刺伤"
]),
([      "action":"$N斜晃反挑，剑势飞舞，轻盈灵动，矫若飞龙。",
       "dodge" : 5,
       "parry" : 10,
        "damage": 60,
        "lvl" : 30,
        "damage_type":  "刺伤"
]),
});
int valid_enable(string usage)
{
    return usage == "sword" || usage == "strike" || usage == "parry";
}
int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
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
        level   = (int) me->query_skill("shenghuo-shengong1",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int valid_practice(object me)
{
        return notify_fail("圣火神功不能练的方式。\n");
}
string perform_action_file(string action)
{
        return __DIR__"shenghuo-shengong/" + action;
}
string *parry_msg = ({
        "只见$n将手中$v舞成一片，顿时格开了$N的$w。\n",
        "$n身子一侧，用手中$v轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
});
string *unarmed_parry_msg = ({
        "但是$n身子一侧，用左手轻轻一推$N的$w，$N的$w一下就偏了出去。\n",
        "$n左手轻轻推出，拍向$N的$w，然后脚下一滑，身体向右一侧，避过了攻击。\n"
,
});
string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
