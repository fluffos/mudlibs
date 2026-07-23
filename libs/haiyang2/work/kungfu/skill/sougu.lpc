//sougu.c 搜骨鹰爪功
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "\n$N双臂一拢，左爪直攻$n下盘，右爪却挟风雷之势推向$n腰间，一虚一实，正是一招「推爪式」",
	"force" : 170,
	"dodge" : 5,
	"damage_type" : "抓伤",
	"lvl" : 0,
	"damage" : 215,
	"skill_name" : "推爪式"
]),
([	"action" : "\n$N身形陡起，如雄鹰击日般“倏”地从$n头顶越过，使一招「盖爪式」双爪疾向$n脑后击下",
	"force" : 190,
	"dodge" : 20,
	"damage_type" : "抓伤",
	"damage" : 225,
	"lvl" : 5,
	"skill_name" : "盖爪式"
]),
([	"action" : "\n$N就地一滚，突然到了$n身前，使一招「掏爪式」，右爪直奔$n小腹",
	"force" : 215,
	"dodge" : 20,
	"damage_type" : "抓伤",
	"damage" : 235,
	"lvl" : 10,
	"skill_name" : "掏爪式"
]),
([	"action" : "\n$N左爪护胸，右爪凝劲后发，一招「托爪式」，缓缓托向$n的$l",
	"force" : 245,
	"dodge" : 5,
	"damage_type" : "抓伤",
	"damage" : 225 ,
	"lvl" : 20,
	"skill_name" : "托爪式"
]),
([	"action" : "\n$N身形诡异，疾速前扑，使一招「撩爪式」，直撩$n裆部",
	"force" : 280,
	"dodge" : 25,
	"damage_type" : "抓伤",
	"damage" : 255,
	"lvl" : 35,
	"skill_name" : "撩爪式"
]),
([	"action" : "\n$N身形飘忽，陡然转到$n身后，一招「锁爪式」，双爪直向$n咽喉插下",
	"force" : 320,
	"dodge" : 35,
	"damage_type" : "抓伤",
	"damage" : 265,
	"lvl" : 60,
	"skill_name" : "锁爪式"
]),
([	"action" : "\n$N一声厉啸，身形拔起，使出「千爪式」，由半空盘旋下击，$n顿觉漫天爪影，罩向全身死穴",
	"force" : 365,
	"dodge" : 40,
	"damage_type" : "抓伤",
	"damage" : 295,
	"lvl" : 85,
	"skill_name" : "千爪式"
])
});

int valid_enable(string usage) { return usage=="claw" ||  usage=="parry"; }
int valid_combine(string combo) { return combo=="hanbing-mianzhang"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练搜骨鹰爪功必须空手。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法学搜骨鹰爪功。\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
		if(level >= action[i]["lvl"])
			return action[i]["skill_name"];
}

mapping query_action(object ob, object weapon)
{
	int i, level;
	level = (int)ob->query_skill("sougu", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练鹰爪功。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -5);
	return 1;
}
int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("jiuyang-shengong",1);
        skill = me->query_skill("jiuyang-shengong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
if ( level2<= 0) level2= (int) me->query_skill("shenghuo-shengong",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "jiuyang-shengong" || me->query_skill_mapped("force") == "shenghuo-shengong"))
{
j = -damage/2; 
j = 0;
if (damage2> 5000)	damage2=5000;
msg = HIC+"$N运起九阳神功 全身内力爆发，浮现出一层刚猛的劲气! !" +NOR;
           message_vision(msg, me, ob);
if ( me->is_busy())
{
me->start_busy(1);
ob->start_busy(2);
}
if (me->query("neili") > me->query("max_neili")*2)
{
		
		me->add("neili", damage2);
}

}


           return j;
}      
string perform_action_file(string action)
{
	return __DIR__"sougu/" + action;
}
