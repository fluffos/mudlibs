// feifeng-whip.c 飞凤鞭法

#include <ansi.h>

inherit SKILL;
string *xue_name = ({ 
"劳宫穴","膻中穴","曲池穴","关元穴","曲骨穴","中极穴","承浆穴","天突穴","百会穴",
"幽门穴","章门穴","大横穴","紫宫穴","冷渊穴","天井穴","极泉穴","清灵穴","至阳穴",}); 


mapping *action = ({
([	"action":  "$N向上跃起，一招「凤凰展翅」，手中$w自下而上，击向$n的脸颊",
	"force":  100,
	"dodge":  30,
	"damage":  220,
	"lvl" : 15,
	"skill_name" : "凤凰展翅",
	"damage_type":	"刮伤"
]),
([	"action":  "$N一招「彩凤栖梧」，手中$w直绕向$n的$l",
	"force":  110,
	"dodge":  30,
	"damage":  230,
	"lvl" : 20,
	"skill_name" : "彩凤栖梧",
	"damage_type":	"内伤"
]),
([  "action":  "$N一招「鸾凤和鸣」，手中$w腾空一卷，一声脆响入磬，猛地向
$n劈头打下",
	"force":  120,
	"dodge":  35,
	"damage":  240,
	"lvl" : 40,
	"skill_name" : "鸾凤和鸣",
	"damage_type":	"劈伤"
]),
([  "action":  "$N踏上一步，冲着$n轻佻一笑，手中$w却毫不停留，一招「游龙
戏凤」，扫向$n的$l",
	"force":  130,
	"dodge":  30,
	"damage":  360,
	"lvl" : 50,
	"skill_name" : "游龙戏凤",
	"damage_type":	"刺伤"
]),
([  "action":  "$N跃在半空，一招「龙飞凤舞」，手中$w如游龙洗空，长凤戏羽，
乱雨倾盆般分点$n左右",
	"force":  150,
	"dodge":  35,
	"damage":  370,
	"lvl" : 60,
	"skill_name" : "龙飞凤舞",
	"damage_type":	"刺伤"
]),
([  "action":  "$N向前急进，手中$w圈转如虹，一招「龙凤呈祥」，罩向$n前胸",
    "force":  270,
	"dodge":  40,
	"damage":  385,
	"lvl" : 75,
	"skill_name" : "龙凤呈祥",
	"damage_type":	"内伤"
])
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if ((int)me->query_skill("kurong-changong", 1) < 20)
		return notify_fail("你的枯荣禅功火候太浅。\n");
//	if ( me->query("gender") != "女性")
//		return notify_fail("大老爷们学这飞凤鞭？天资不足吧。\n");
	if ( !objectp(weapon = me->query_temp("weapon"))
	|| ( string)weapon->query("skill_type") != "whip" )
		return notify_fail("你必须先找一条长鞭才能练鞭法。\n");

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
        level   = (int) me->query_skill("feifeng-whip",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "whip")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练飞凤鞭法。\n");
	me->receive_damage("qi", 10);
	return 1;
}



mixed hit_ob(object me, object victim, int damage_bonus)
{
    string name,weapon;
    name = xue_name[random(sizeof(xue_name))];


if((!random(3)) && (me->query("neili")>200) &&  me->query_skill("kurong-changong",1) > 50)
	   {
  if( !victim->is_busy() )
{ 
	    victim->start_busy(3);
}
        me->add("neili",-30);
		victim->add("neili",-30);
		victim->receive_damage("qi", me->query_skill("feifeng-whip",1)/2+damage_bonus/2);
        victim->receive_wound("qi", me->query_skill("feifeng-whip",1)/2+damage_bonus/2);       
		 victim->apply_condition("yyz_damage",30);
		return HIR "$n被$N发出的纯阳真气抽中"RED+name+HIR"，真气不由得一滞！\n" NOR;
	}   

 
}



int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("kurong-changong",1);
        skill = me->query_skill("kurong-changong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "kurong-changong")
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;

if (me->query("qi") <= me->query("max_qi"))
{
me->add("qi",damage2);
}

if (me->query("eff_qi") <= me->query("max_qi"))
{
me->add("eff_qi",damage2);
}



msg = HIG"$N 深吸一口气！施展开一阳指诀，以纯阳指力遍布全身! 脸色红润多了。\n"NOR;
           if (!ob->is_busy() && random(3)==0)
{
msg += HIY"$n"+HIY+"被$N的纯阳指力反点! 结果点中了 "+ xue_name[random(sizeof(xue_name))] +NOR;
                ob->apply_condition("yyz_damage",30);
                ob->start_busy(3);  
}

//msg += "$n的力道被太极拳借力打力反击回来！\n",  
           message_vision(msg, me, ob);
           return j;
}      
}

