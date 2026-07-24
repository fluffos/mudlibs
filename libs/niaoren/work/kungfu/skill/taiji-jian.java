// taiji-jian.c 太極劍
// modified by Venus Oct.1997
// cleansword 2/15/96
// Marz 5/21/96

inherit SKILL;

mapping *action = ({
([      "action" : "$N虛步提腰，一招「蜻蜓點水」，手中$w輕輕顫動，一劍劍點向$n的
$l",
    "force" : 120,
    "dodge" : 20,
    "damage" : 25,
    "lvl" : 0,
    "damage_type" : "刺傷"
]),
([      "action" : "$N向前跨上一步，左手劍訣，右手$w使出一式「指南針」直刺$n的$l
",
    "force" : 140,
    "dodge" : 15,
    "damage" : 30,
    "lvl" : 0,
    "damage_type" : "刺傷"
]),
([      "action" : "$N一招「燕子掠波」，$w自上而下划出一個大弧，平平地向$n的$l揮
去",
    "force" : 170,
    "dodge" : 15,
    "damage" : 40,
    "lvl" : 9,
    "damage_type" : "刺傷"
]),
([      "action" : "$N一招「右攔掃」，一招「左攔掃」，劍鋒平指，一氣呵成橫掃$n的
$l",
    "force" : 190,
    "dodge" : 10,
    "damage" : 50,
    "lvl" : 19,
    "damage_type" : "刺傷"
]),
([      "action" : "$N使出「三環套月」，$w划出三個圓圈，劍鋒直出，綿綿不斷划向$n
的$l",
    "force" : 240,
    "dodge" : 10,
    "damage" : 60,
    "lvl" : 29,
    "damage_type" : "刺傷"
]),
([      "action" : "$N左腳踏實，右腳虛點，一招「仙人指路」，右手$w帶著一團劍花，
逼向$n的$l",
    "force" : 280,
    "dodge" : 5,
    "damage" : 70,
    "lvl" : 39,
    "damage_type" : "刺傷"
]),
([      "action" : "$N一招「卻步抽劍」，左腳躍步落地，$w回抽，反手勾向$n的$l",  
    "force" : 300,
    "dodge" : 5,
    "damage" : 80,
    "lvl" : 59,
    "damage_type" : "刺傷"
]),
([      "action" : "$N右腿半屈般蹲，一招「如封似閉」，劍尖虛指，轉身撩向$n的$l",
    "force" : 330,
    "dodge" : -5,
    "damage" : 90,
    "lvl" : 79,
    "damage_type" : "刺傷"
]),
([  "action" : "$N回身擰腰，右手虛抱，一招「撥云瞻日」，$w中宮直進，刺向$n的$l",
    "force" : 380,
    "dodge" : -5,
    "damage" : 115,
    "lvl" : 99,
    "damage_type" : "刺傷"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry")
; }

int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
   return notify_fail("你的內力不夠。\n");
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
   return notify_fail("你的太極神功\火候太淺。\n");
    if ((int)me->query_skill("taiji-quan", 1) < 20)
   return notify_fail("你的太極拳火候太淺。\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int) me->query_skill("taiji-jian",1);
    for(i = sizeof(action); i > 0; i--)
   if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
   return notify_fail("你使用的武器不對。\n");
    if ((int)me->query("qi") < 50)
   return notify_fail("你的體力不夠練太極劍法。\n");
    me->receive_damage("qi", 30);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"taiji-jian/" + action;
}
