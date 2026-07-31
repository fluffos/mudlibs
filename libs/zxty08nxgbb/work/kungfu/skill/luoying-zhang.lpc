// luoying-zhang.c 落英神剑掌
// by victori
inherit SKILL;
mapping *action = ({
([      "action" : "$N双手平伸，向外掠出，一式「"+RED+"春云乍展"+NOR+"」，指尖轻盈漂动，轻轻反点$n的$l",
        "force" : 100,
        "dodge" : 15,
        "damage_type" : "瘀伤",
        "lvl" : 10,
        "skill_name" : "春云乍展"
]),
([      "action" : "$N右手五指缓缓一收，一式「"+MAG+"回风拂柳"+NOR+"」，五指忽然遥遥拂向$n，
$n只觉得五股疾风袭向自己五处大穴",
        "force" : 110,
        "dodge" : 10,
        "damage_type" : "内伤",
        "lvl" : 0,
        "skill_name" : "回风拂柳"
]),
([      "action" : "$N突然纵身跃入半空，一个轻巧转身，单掌劈落，
一式「"+BLK+"江城飞花"+NOR+"」，拍向$n的头顶",
        "force" : 120,
        "dodge" : 15,
        "damage_type" : "瘀伤",
        "lvl" : 10,
        "skill_name" : "江城飞花"
]),
([      "action" : "$N突然跃起，双手连环，运掌如剑，势如疾风电闪，
一式「"+HIC+"雨急风狂"+NOR+"」，攻向$n的全身",
        "force" : 130,
        "dodge" : 15,
        "damage_type" : "瘀伤",
        "lvl" : 10,
        "skill_name" : "雨急风狂"
]),
([      "action" : "$N左手挥起，掌心朝天，伸出右手并拢食指中指，捻个剑决，
一式「"+HIM+"星河在天"+NOR+"」，直指$n的中盘",
        "force" : 140,
        "dodge" : 20,
        "damage_type" : "瘀伤",
        "lvl" : 20,
        "skill_name" : "星河在天"
]),
([      "action" : "$N突然抽身而退，接着一式「"+HIM+"流华纷飞"+NOR+"」，平身飞起，双掌向$n的后脑连拍数掌",
        "force" : 140,
        "dodge" : 35,
        "damage_type" : "瘀伤",
        "lvl" : 30,
        "skill_name" : "流华纷飞"
]),
([      "action" : "$N突然抽身跃起，左掌挟着劲风汹涌拍出，接着右掌自左掌后突地伸出，
一式「"+HIR+"彩云追月"+NOR+"」抢在左掌前向$n的$l拍去",
        "force" : 150,
        "dodge" : 35,
        "damage_type" : "瘀伤",
        "lvl" : 30,
        "skill_name" : "彩云追月"
]),
([      "action" : "$N使一式「"+HIG+"天如穹庐"+NOR+"」，全身突然飞速旋转，双掌忽前忽后，猛地拍向$n的胸口",
        "force" : 160,
        "dodge" : 30,
        "damage_type" : "瘀伤",
        "lvl" : 40,
        "skill_name" : "天如穹庐"
]),
([      "action" : "$N前后一揉，一式「"HIC+"朝云横度"+NOR+"」，化掌如剑，一股凌厉剑气袭向$n的下盘",
        "force" : 170,
        "dodge" : 35,
        "damage_type" : "内伤",
        "lvl" : 50,
        "skill_name" : "朝云横度"
]),
([      "action" : "$N使一式「"HIW+"白虹经天"+NOR+"」，双掌舞出无数圈劲气，一环环向$n的$l斫去",
        "force" : 180,
        "parry" : 15,
        "dodge" : 35,
        "damage_type" : "内伤",
        "lvl" : 70,
        "skill_name" : "白虹经天"
]),
([      "action" : "$N双手食指和中指一和，一式「"MAG+"紫气东来"+NOR+"」，一股强烈的气流涌向$n的全身",
        "force" : 190,
        "parry" : -5,
        "dodge" : 20,
        "damage_type" : "内伤",
        "lvl" : 60,
        "skill_name" : "紫气东来"
]),
([      "action" : "$N一式「"BLU+"落英漫天"+NOR+"」，双掌在身前疾转，掌花飞舞，
铺天盖地直指向$n。$n只见漫天掌花，眼花缭乱。",
        "force" : 200,
        "parry" : -20,
        "dodge" : -15,
        "damage_type" : "瘀伤",
        "lvl" : 99,
        "skill_name" : "落英漫天"
])
});
int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; } 
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练落英神剑掌必须空手。\n");
    if ((int)me->query_skill("bibo-shengong", 1) < 100)
        return notify_fail("你的碧波神功火候不够，无法学落英神剑掌。\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力太弱，无法练落英神剑掌。\n");
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
    level = (int)me->query_skill("luoying-zhang", 1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
       return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
       return notify_fail("你的内力不够练落英神剑掌。\n");
    me->receive_damage("qi", 20);
    me->add("neili", -1);
    return 1;
}    
string perform_action_file(string action)
{
        return __DIR__"luoying-zhang/" + action;
}
