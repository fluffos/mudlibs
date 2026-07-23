// longzhua-gong.c 龙爪功
// modified by Venus Oct.1997
inherit SKILL;
#include <combat.h>
#include <ansi.h>

mapping *action = ({
([      "action" : "$N双手齐出，自上而下同抓，使一招「抢珠式」，迅猛之至，直拿向$n左右太阳穴",
        "force" : 120,
        "dodge" : 5,
    "damage": 225,
        "lvl"   : 0,
        "skill_name" : "抢珠式" ,
        "damage_type" : "内伤"
]),
([      "action" : "$N双手一个圈转，使招「捞月式」，右手倏忽而出，虚拿$n后脑“风府穴”",
        "force" : 130,
        "dodge" : 5,
        "damage": 215,
        "lvl"   : 6,
        "skill_name" : "捞月式" ,   
        "damage_type" : "内伤"
]),
([      "action" : "$N使出一招「拿云式」，左手虚探，右手挟着一股劲风，直拿向$n左肩“缺盆穴”",
        "force" : 150,
        "dodge" : 10,
        "damage": 215,
        "lvl"   : 12,
        "skill_name" : "拿云式" ,       
        "damage_type" : "内伤"
]),
([      "action" : "$N使一招「捕风式」，左手五指朝$n的$l急抓而下，手法劲力稳迅兼备，势道凌厉之极",
        "force" : 180,
        "dodge" : 10,
        "damage": 210,
        "lvl"   : 18,
        "skill_name" : "捕风式" ,     
        "damage_type" : "抓伤"
]),
([      "action" : "$N猛地纵身而起，一招「捉影式」向$n扑将下来，矫健迅捷，威势非凡",
        "force" : 220,
        "dodge" : 15,
        "damage": 210,
        "lvl"   : 24,
        "skill_name" : "捉影式" ,               
        "damage_type" : "抓伤"
]),
([      "action" : "祗听呼地一响，$N右臂疾伸而出，五指微微上下颤动，一招「抚琴式」抓向$n的$l",
        "force" : 260,
        "dodge" : 15,
        "damage": 215,
        "lvl"   : 30,
        "skill_name" : "抚琴式" ,               
        "damage_type" : "抓伤"
]),
([      "action" : "$N左手上拦，右手内挥，陡然化为一招「鼓瑟式」抓向$n$l，劲力威猛无俦",
        "force" : 300,
        "dodge" : 25,
        "damage": 220,
        "lvl"   : 45,
        "skill_name" : "鼓瑟式" ,               
        "damage_type" : "抓伤"
]),
([      "action" : "$N双手「批亢式」疾攻而出，犹如龙影飞空，双爪急舞，瞬息之间，已将$n压制得无处躲闪",
        "force" : 350,
        "dodge" : 25,
        "damage": 225,
        "lvl"   : 50,
        "skill_name" : "批亢式" ,               
        "damage_type" : "抓伤"
]),
([      "action" : "$N踏上几步，化做一招「掏虚式」，右手向$n$l抓将下来，这一抓自腕至指伸得笔直，劲道凌厉已极",
        "force" : 400,
        "dodge" : 30,
        "damage": 225,
        "lvl"   : 55,
        "skill_name" : "掏虚式" ,               
        "damage_type" : "抓伤"
]),
([      "action" : "$N退後一步，架势似守实攻，大巧若拙，「抱残式」稳凝如山般使将出来",
        "force" : 460,
        "dodge" : 40,
        "damage": 230,
        "lvl"   : 60,
        "skill_name" : "抱残式" ,       
        "damage_type" : "抓伤"
]),
([      "action" : "$N一改原先刚猛路子，化做「守缺式」，爪路刚猛中暗藏阴柔，实已到了返璞归真，炉火纯青的境界",
        "force" : 520,
        "dodge" : 40,
        "damage": 250,
        "lvl"   : 70,
        "skill_name" : "守缺式" ,
        "damage_type" : "内伤"
]),
([      "action" : "在呼呼风声中，$N使一招「捕风式」，双手如钩如戢，插向$n的$l",
    "force" : 100,
    "dodge" : 5,
        "damage": 225,
    "lvl"   : 0,
    "skill_name" : "捕风式" ,
    "damage_type" : "内伤"
]),
([      "action" : "$N猛地向前跃出，一招「捉影式」，两腿踢出，双手抓向$n的面门",
    "force" : 110,
    "dodge" : 5,
    "damage": 225,
    "lvl"   : 6,
    "skill_name" : "捉影式" ,
    "damage_type" : "内伤"
]),
([      "action" : "$N双手平伸，十指微微上下抖动，一招「抚琴式」打向$n的$l",    
    "force" : 120,
    "dodge" : 10,
    "damage": 225,
    "lvl"   : 12,
    "skill_name" : "抚琴式" ,
    "damage_type" : "内伤"
]),
([      "action" : "$N左手上拦，右手内挥，一招「击鼓式」击向$n胸口",
    "force" : 140,
    "dodge" : 10,
    "damage": 210,
    "lvl"   : 18,
    "skill_name" : "击鼓式" ,
    "damage_type" : "内伤"
]),
([      "action" : "$N右手虚握，左手掌立如山，一招「批亢式」，猛地击向$n的$l",  
    "force" : 160,
    "dodge" : 15,
    "damage": 210,
    "lvl"   : 24,
    "skill_name" : "批亢式" ,
    "damage_type" : "内伤"
]),
([      "action" : "$N腾步上前，左手护胸，右手探出，一招「掏虚式」击向$n的裆部",
    "force" : 190,
    "dodge" : 15,
    "damage": 215,
    "lvl"   : 30,
    "skill_name" : "掏虚式" ,
    "damage_type" : "内伤"
]),
([      "action" : "$N双手平提胸前，左手护住面门，一招「抱残式」右手推向$n的$l",
    "force" : 220,
    "dodge" : 20,
    "damage": 215,
    "lvl"   : 35,
    "skill_name" : "抱残式" ,
    "damage_type" : "内伤"
]),
([      "action" : "$N两手胸前环抱，腋下含空，五指如钩，一招「守缺式」插向$n的顶
门",
    "force" : 260,
    "dodge" : 20,
    "damage": 20,
    "lvl"   : 40,
    "skill_name" : "守缺式" ,
    "damage_type" : "内伤"
]),
([      "action" : "$N右腿斜插$n二腿之间，一招「抢珠式」，上手取目，下手反勾$n的
裆部",
    "force" : 300,
    "dodge" : 25,
    "damage": 220,
    "lvl"   : 45,
    "skill_name" : "抢珠式" ,
    "damage_type" : "内伤"
]),
([      "action" : "$N一手虚指$n的剑诀，一招「夺剑式」，一手劈空抓向$n手中的长剑
",
    "force" : 350,
    "dodge" : 25,
    "damage": 225,
    "lvl"   : 50,
    "skill_name" : "夺剑式" ,
    "damage_type" : "内伤"
]),
([      "action" : "$N左手指向$n胸前的五道大穴，右手斜指太阳穴，一招「拿云式」使
$n进退两难",
    "force" : 400,
    "dodge" : 30,
    "damage": 225,
    "lvl"   : 55,
    "skill_name" : "拿云式" ,
    "damage_type" : "内伤"
]),
([      "action" : "$N前脚着地，一手顶天成爪，一手指地，一招「追日式」劲气笼罩$n
的全身",
    "force" : 460,
    "dodge" : 40,
    "damage": 330,
    "lvl"   : 60,
    "skill_name" : "追日式" ,
    "damage_type" : "内伤"
])
});

int valid_enable(string usage) { return usage=="claw" ||  usage=="parry"; }     

int valid_combine(string combo) { return combo=="qianye-shou"; }

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail("练龙爪功必须空手。\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
   return notify_fail("你的混元一气功火候不够，无法学龙爪功。\n");
    if ((int)me->query("max_neili") < 100)
   return notify_fail("你的内力太弱，无法练龙爪功。\n");
    return 1;
}

string query_skill_name(int level)
{
    int i;
    for(i = sizeof(action); i > 0; i--)
   if(level >= action[i-1]["lvl"])
      return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
    int i, level;
        string *msg;
        msg = ({
                HIR"\n$N一抓不中，次抓随至，来势更加迅捷刚猛！" NOR,
                HIR"\n$N龙爪手源源而出，一招落空，又即连续急攻！" NOR,
                HIR"\n$n才躲过这招，$N次招又至，抓法快极狠极！"NOR,
        });
    level   = (int) me->query_skill("longzhua-gong",1);
        if (random(level) > 250 && me->query_skill("force") > 200 && me->query("neili") >= 600)
         {
		return ([
		"action": HIR"$N龙爪手源源而出，一招落空，又即连续急攻！"NOR,
		"force" : 460+random(40),
		"dodge" : 20,
		"damage": 460+random(20),
		"damage_type" : "内伤" ]);
	}
else        if (random(level) > 200 && me->query_skill("force") > 200 && me->query("neili") >= 400)
         {
		return ([
		"action": HIC"$N一抓不中，次抓随至，来势更加迅捷刚猛！"NOR,
		"force" : 400+random(40),
		"dodge" : 20,
		"damage": 400+random(20),
		"damage_type" : "内伤" ]);
	}
else        if (random(level) > 150 && me->query_skill("force") > 150 && me->query("neili") >= 200)
         {
		return ([
		"action": HIY"$n才躲过这招，$N次招又至，抓法快极狠极！"NOR,
		"force" : 500+random(40),
		"dodge" : 20,
		"damage": 500+random(20),
		"damage_type" : "内伤" ]);
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
       return notify_fail("你的内力不够练龙爪功。\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}

string perform_action_file(string action)
{
        return __DIR__"longzhua-gong/" + action;
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