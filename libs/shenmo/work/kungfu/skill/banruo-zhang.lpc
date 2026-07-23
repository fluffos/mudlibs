// banruo-zhang.c 般若掌
// Modified by Venus Oct.1997
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : "$N前腿踢出，后腿脚尖点地，一式「横空出世」，二掌直出，攻向$n
的上中下三路",
    "force" : 250,
    "dodge" : 5,
    "damage": 260,
    "damage_type" : "瘀伤",
    "lvl" : 0,
    "skill_name" : "横空出世"
]),
([  "action" : "$N左掌划一半圆，一式「长虹贯日」，右掌斜穿而出，疾拍$n的胸前
大穴",
    "force" : 260,
    "dodge" : 5,
    "damage": 260,
    "damage_type" : "瘀伤",
    "lvl" : 12,
    "skill_name" : "长虹贯日"
]),
([  "action" : "$N使一式「云断秦岭」，右掌上引，左掌由后而上一个甩劈，斩向$n
的$l",
    "force" : 270,
    "dodge" : 5,
    "damage": 260,
    "damage_type" : "劈伤",
    "lvl" : 18,
    "skill_name" : "云断秦岭"
]),
([  "action" : "$N左掌护胸，右拳凝劲后发，一式「铁索拦江」，缓缓推向$n的$l",
    "force" : 285,
    "dodge" : 5,
    "damage": 260,
    	    "damage_type" : "瘀伤",
    "lvl" : 24,
    "skill_name" : "铁索拦江"
]),
([  "action" : "$N使一式「狂风卷地」，全身飞速旋转，双掌一前一后，猛地拍向$n
的胸口",
    "force" : 200,
    "dodge" : 5,
    "damage": 260,
    "damage_type" : "瘀伤",
    "lvl" : 30,
    "skill_name" : "狂风卷地"
]),
([  "action" : "$N合掌抱球，猛吸一口气，一式「怀中抱月」，双掌疾推向$n的肩头",
    "force" : 220,
    "damage": 2260,
    "dodge" : 5,
    "damage_type" : "瘀伤",
    "lvl" : 36,
    "skill_name" : "怀中抱月"
]),
([  "action" : "$N向上高高跃起，一式「高山流水」，居高临下，掌力笼罩$n的全身",
    "force" : 240,
    "dodge" : 20,
    "damage": 260,
    "damage_type" : "瘀伤",
    "lvl" : 42,
    "skill_name" : "高山流水"
]),
([  "action" : "$N使一式「摘星换斗」，劲气弥漫，双掌如轮，一环环向$n的$l斫去",
    "force" : 370,
    "dodge" : 10,
    "damage": 260,
    "damage_type" : "劈伤",
    "lvl" : 48,
    "skill_name" : "摘星换斗"
]),
([  "action" : "$N两掌上下护胸，一式「翻江搅海」，骤然化为满天掌雨，攻向$n",
    "force" : 310,
    "dodge" : 30,
    "damage": 260,
    "damage_type" : "瘀伤",
    "lvl" : 54,
    "skill_name" : "翻江搅海"
]),
([  "action" : "$N一式「金刚伏魔」，双手合十，对着$n微微一揖，全身内劲如巨浪
般汹涌而出",
    "force" : 360,
    "dodge" : 10,
    "damage": 360,
    "damage_type" : "瘀伤",
    "lvl" : 60,
    "skill_name" : "金刚伏魔"
]),
([	"action" : "$N后腿脚尖点地而出，一式「礼敬诸佛」，二掌合十，罡气直出，攻向$n全身",
	"force" : 300,
        "dodge" : 25,
	"damage": 360,
	"damage_type" : "瘀伤",
	"lvl" : 5,
	"skill_name" : "礼敬诸佛"
]),
([	"action" : "$N左掌划一半圆护胸，一式「称赞如来」，右掌化刀斜穿而出，疾插$n$l",
	"force" : 230,
        "dodge" : 15,
        "damage": 260,
        "damage_type" : "割伤",
        "weapon" : "掌缘",
	"lvl" : 15,
	"skill_name" : "称赞如来"
]),
([	"action" : "$N使一式「广修供养」，右掌上引，左掌由后而上一个甩拍，穿过$n护墙击出",
	"force" : 270,
        "dodge" : 10,
        "damage": 260,
        "damage_type" : "内伤",
	"lvl" : 35,
	"skill_name" : "广修供养"
]),
([	"action" : "$N左掌护胸，右拳凝劲，一式「忏悔业障」，四周罡气弥漫，出掌缓缓拍向$n$l",
	"force" : 360,
        "dodge" : 15,
        "damage_type" : "瘀伤",
	"damage": 260,
	"lvl" : 55,
	"skill_name" : "忏悔业障"
]),
([	"action" : "$N使一式「请转法轮」，全身飞速旋转，罡气飞卷，双掌一前一后，猛地按向$n的胸口",
        "force" : 260,
        "dodge" : 10,
        "damage": 360,
        "damage_type" : "瘀伤",
	"lvl" : 65,
	"skill_name" : "请转法轮"
]),
([	"action" : "$N合掌抱球，猛吸一口气，一式「随喜功德」，全身护满至阳罡气，跟着双掌疾推$n",
        "force" : 300,
        "dodge" : 25,
        "damage": 260,
        "damage_type" : "瘀伤",
	"lvl" : 85,
	"skill_name" : "随喜功德"
]),
([	"action" : "$N向上高高跃起，一式「请佛往世」，罡气居高临下，四散而出，将掌力笼罩了$n的全身",
        "force" : 340,
        "dodge" : 10,
        "damage": 360,
        "damage_type" : "瘀伤",
	"lvl" : 105,
	"skill_name" : "请佛往世"
]),
([	"action" : "$N使一式「恒顺众生」，瞬间劲气弥漫，$P双掌连劈如轮，一环环向$n的$l斩去",
        "force" : 380,
        "dodge" : 110,
        "damage": 360,
        "damage_type" : "割伤",
        "weapon" : "手刀",
	"lvl" : 125,
	"skill_name" : "恒顺众生"
]),
([	"action" : "$N两掌上下护胸，一式「普皆回向」拍出，掌影重重叠叠，带起无边罡气攻向$n",
        "force" : 400,
        "dodge" : 115,
        "damage_type" : "瘀伤",
	"damage": 360,
	"lvl" : 155,
	"skill_name" : "普皆回向"
])
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }   

int valid_combine(string combo) { return combo=="yizhi-chan"; }

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail("练般若掌必须空手。\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
   return notify_fail("你的混元一气功火候不够，无法学般若掌。\n");
    if ((int)me->query("max_neili") < 100)
   return notify_fail("你的内力太弱，无法练般若掌。\n");
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
        int i, level, neili, ljz, sxz, strike;
    level = (int)me->query_skill("banruo-zhang", 1);
        neili = me->query("neili");
        sxz = me->query_skill("banruo-zhang", 1);
        ljz = me->query_skill("banruo-zhang", 1);
 	strike = me->query_skill("strike", 1);
        if (ljz > 79 && sxz > 79 && strike > 79 && neili > 500 
            && random(me->query_int()) > 24 ){
                me->add("neili", -60);
                if(random(10) < 4 )
                return ([
                "action":HIY
    "霎时间,日丽风静，云海平铺，美丽以极。阳光从$N背面斜射下来，形成彩色光环，
$N见到自己的身影清晰地出现在银色世界上。"HIC"『光环随人动，人影在环中』"HIY",使出了
"HIW"般若掌绝学"HIY"『金顶佛光』"NOR,
	        "weapon" : HIY"金顶佛光"NOR,
                "force": 800,
                "dodge": 15,
                "parry": 15,
                "damage": 800,
                "damage_type": "瘀伤"]);
          }
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
   return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
   return notify_fail("你的内力不够练般若掌。\n");
    me->receive_damage("qi", 25);
    me->add("neili", -5);
    return 1;
}

string perform_action_file(string action)
{
        return __DIR__"banruo-zhang/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{                                                                                                                
	int level, jiali, time,level2,damage;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("yijinjing",1);
damage= (int) me->query("neili",1)/10;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "yijinjing")
{
if (victim->query("qi")>= damage )
{
	victim->receive_wound("qi", damage);
}
	return HIR"只见$n$l闷哼一声，吐出一口鲜血，已被易筋经的护体真气给击伤!\n"NOR;
}
}