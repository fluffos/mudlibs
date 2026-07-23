// yizhi-chan.c 一指禅
// modified by Venus Oct.1997

inherit SKILL;

mapping *action = ({
([      "action" : "$N双指并拢，一式「佛恩济世」，和身而上，左右手一前一后戳向$n
的胸腹间",
    "force" : 160,
    "dodge" : -5,
    "parry" : -5,
    "damage": 310,
    "lvl" : 0,
    "skill_name" : "佛恩济世",
    "damage_type" : "刺伤"
]),
([      "action" : "$N左掌护胸，一式「佛光普照」，右手中指前后划了个半弧，猛地一
甩，疾点$n的$l",
    "force" : 120,
    "dodge" : 10,
    "parry" : 15,
    "damage": 230,
    "lvl" : 20,
    "skill_name" : "佛光普照",
    "damage_type" : "刺伤"
]),
([      "action" : "$N身形闪动，一式「佛门广渡」，双手食指端部各射出一道青气，射
向$n的全身要穴",
    "force" : 240,
    "dodge" : 20,
    "parry" : 20,
    "damage": 260,
    "lvl" : 40,
    "skill_name" : "佛门广渡",
    "damage_type" : "刺伤"
]),
([      "action" : "$N盘膝跌坐，一式「佛法无边」，左手握拳托肘，右手拇指直立，遥
遥对着$n一捺",
    "force" : 480,
    "dodge" : 40,
    "parry" : 30,
    "damage": 290,
    "lvl" : 60,
    "skill_name" : "佛法无边",
    "damage_type" : "刺伤"
]),
([	"action" : "$N双指并拢，一式「道行般若」，和身缓缓而上，左右手一前一后弹向$n$l",
	"force" : 300,
        "dodge" : 30,
	"damage": 290,
	"weapon": "无形指力",
	"lvl" : 5,
	"skill_name" : "道行般若",
	"damage_type" : "刺伤"
]),
([	"action" : "$N左掌护胸，含笑一式「小品般若」，右手中指前后划了个半弧，轻轻一甩，点向$n$l",
        "force" : 350,
        "dodge" : 10,
        "damage": 290,
        "weapon": "无形指力",
	"lvl" : 25,
	"skill_name" : "小品般若",
        "damage_type" : "刺伤"
]),
([	"action" : "$N身形闪动，一式「光赞般若」，双手食指端部各射出一道青光，射向$n的全身要穴",
        "force" : 400,
        "dodge" : 10,
        "damage": 290,
        "weapon": "无形指力",
	"lvl" : 45,
	"skill_name" : "光赞般若",
        "damage_type" : "刺伤"
]),
([	"action" : "$N盘膝跌坐，一式「放光般若」，全身罡气密布，左手握拳托肘，右手拇指直立，遥遥对着$n一捺",
        "force" : 450,
        "dodge" : -5,
        "weapon": "无形指力",
	"damage": 290,
	"lvl" : 65,
	"skill_name" : "放光般若",
        "damage_type" : "刺伤"
]),
([	"action" : "$N面露宝相，结兰花手，轻轻一下点出「摩诃般若」，凭空凝气成线，缓缓刺向$n",
        "force" : 400,
        "dodge" : 15,
        "weapon": "无形指力",
	"damage": 290,
	"lvl" : 105,
	"skill_name" : "摩诃般若",
        "damage_type" : "刺伤"
]),
([	"action" : "$N口念佛经，内息激发，衣衫渐渐胀鼓，身若金刚，便立指一式「金刚般若」，对着$n点去",
        "force" : 500,
        "dodge" : 20,
        "weapon": "无形指力",
	"damage": 290,
	"lvl" : 155,
	"skill_name" : "金刚般若",
        "damage_type" : "刺伤"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }    

int valid_combine(string combo) { return combo=="banruo-zhang"; }

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail("练一指禅必须空手。\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
   return notify_fail("你的混元一气功火候不够，无法学一指禅。\n");
    if ((int)me->query("max_neili") < 100)
   return notify_fail("你的内力太弱，无法练一指禅。\n");
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
    level   = (int) me->query_skill("yizhi-chan",1);
    for(i = sizeof(action); i > 0; i--)
   if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
   return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
   return notify_fail("你的内力不够练一指禅。\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}
string perform_action_file(string action)
{
        return __DIR__"yizhi-chan/" + action;
}

mixed hit_ob(object me, object target)
{
    string msg;
    int j;
    j = me->query_skill("yizhi-chan", 1);
   
    if( random(20) >= 15 && !target->is_busy() && j > 100 &&
       me->query("neili") > target->query("neili") &&
       me->query("neili") > 1000 && me->query("max_neili") > 1500 &&
        j > random(target->query_skill("dodge",1))){
          switch(random(2)){
            case 0 :
               msg = "$N身形闪动，一式「佛门广渡」，双手食指端部各射出一道青气，射向$n的全身要穴！\n";
               msg += "$n只觉全身一麻，已被这一招「佛门广渡」点中！\n"; 
               target->start_busy(3);
               break;
            case 1 :
               msg = "$N双指并拢，一式「佛恩济世」，和身而上，左右手一前一后戳向$n的胸腹间！\n";
               msg += "结果$n气血一滞，已被定在当堂。\n";
               target->start_busy(3);
               break;
            
            }         
        message_vision(msg, me, target);
        }
}