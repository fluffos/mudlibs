// SKILL zhemei-shou.c

#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string *action_msg = ({
		 ""+(order[random(13)])+"$N单手立起，一指突出，融合剑法与指法精义，结构严谨，气势宏伟，指指点点戳向$n"NOR"",
		 ""+(order[random(13)])+"$N单臂伸出，手掌做刀，掌缘布满真力，砍斫纵横，上劈下切，各路刀法与斧法合成一路急攻$n"NOR"",
		 ""+(order[random(13)])+"$N双手显得渐渐沉重，使动时越来越滞涩，犹如舞动一根钢杖，而且越来越重，似无止境"NOR"",
		 ""+(order[random(13)])+"$N十指探出，随手挥洒，于轻灵飘逸中化去了$n的招数，却蕴含有猛烈的反击招式"NOR"",
		 ""+(order[random(13)])+"$N双臂弯出，甩将开来，柔若无骨，灵动之极，东一绕，西一缠，逼得$n竟连一口气也喘不过来"NOR"",
});

mapping *action = ({
([	"action" : "$N一招"+(order[random(13)])+"「吹梅笛怨」"NOR"，双手横挥，抓向$n",
	"force" : 130,
	"dodge" : 20,
	"damage" : 210,
	"lvl" : 0,
	"skill_name" : "吹梅笛怨",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一招"+(order[random(13)])+"「黄昏独自愁」"NOR"，身子跃然而起，抓向$n的头部",
	"force" : 150,
	"dodge" : 20,
	"damage" : 220,
	"lvl" : 10,
	"skill_name" : "黄昏独自愁",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一招"+(order[random(13)])+"「寒山一带伤心碧」"NOR"，双手纷飞，$n只觉眼花缭乱",
	"force" : 150,
	"dodge" : 30,
	"damage" : 230,
	"lvl" : 30,
	"skill_name" : "寒山一带伤心碧",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一招"+(order[random(13)])+"「梅花雪落覆白苹」"NOR"，双手合击，$n只觉无处可避",
	"force" : 150,
	"dodge" : 30,
	"damage" : 245,
	"lvl" : 40,
	"skill_name" : "梅花雪落覆白苹",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一招"+(order[random(13)])+"「砌下落梅如雪乱」"NOR"，双手飘然抓向$n",
	"force" : 250,
	"dodge" : 30,
	"damage" : 250,
	"lvl" : 50,
	"skill_name" : "砌下落梅如雪乱",
	"damage_type" : "瘀伤"
]),

([	"action" : "$N双手平举，一招"+(order[random(13)])+"「云破月来花弄影」"NOR"击向$n",
	"force" : 300,
	"dodge" : 35,
	"damage" : 280,
	"lvl" : 60,
	"skill_name" : "云破月来花弄影",
            "damage_type" : "瘀伤"
]),
([	"action" : "$N一招"+(order[random(13)])+"「花开堪折直须折」"NOR"，拿向$n，似乎$n的全身都被笼罩",
	"force" : 350,
	"dodge" : 30,
	"damage" : 200,
	"lvl" : 70,
	"skill_name" : "花开堪折直须折",
	"damage_type" : "内伤"
]),

([	"action" : "$N左手虚晃，右手一记"+(order[random(13)])+"「红颜未老恩先绝」"NOR"击向$n的头部",
	"force" : 350,
	"dodge" : 30,
	"damage" : 250,
	"lvl" : 80,
	"skill_name" : "红颜未老恩先绝",
           "damage_type" : "瘀伤"
]),
([	"action" : "$N施出"+(order[random(13)])+"「虚妄笑红」"NOR"，右手横扫$n的$l，左手攻向$n的胸口",
	"force" : 400,
	"dodge" : -10,
	"damage" : 250,
	"lvl" : 90,
	"skill_name" : "虚妄笑红",
            "damage_type" : "瘀伤"
]),
([	"action" : "$N施出"+(order[random(13)])+"「玉石俱焚」"NOR"，不顾一切扑向$n",
	"force" : 450,
	"dodge" : -20,
	"damage" : 350,
	"lvl" : 100,
	"skill_name" : "玉石俱焚",
            "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"|| usage=="hand"; }

int valid_combine(string combo) { return combo=="liuyang-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练天山折梅手必须空手。\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力太弱，无法练天山折梅手。\n");

        if ((int)me->query_skill("qingyun-shou", 1) < 80)
		return notify_fail("你的青云手火候太浅。\n");
        if ((int)me->query_skill("panyang-zhang", 1) < 80)
		return notify_fail("你的攀阳掌火候太浅。\n");
		
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level,lvl_temp;
	level = (int) me->query_skill("zhemei-shou",1);
	lvl_temp = random((int)me->query_skill("zhemei-shou", 1));

	if ( lvl_temp > 80 && random(3) >1 )
	{
		if ( lvl_temp <= 100 )
			return ([
				"action": HIC"$N右手一弯，掌上凝聚阴柔之力，无声无息劈向$n的「至阳穴」，跟着左拳猛击而出，击向$n胸口的「膻中穴」"NOR,
				"damage_type": "内伤",
				"dodge": 100,
		"damage": 600,
				"force": 360,
			]);

		if ( lvl_temp <= 120 )
			return ([
				"action": HIG"$N左手袍袖一拂，激出一股内劲，袖力中夹着掌力，一前一后击向$n"NOR,
				"damage_type": "内伤",
		"damage": 600,
				"dodge": 100,
				"force": 400,
			]);

		if ( lvl_temp <= 140 )
			return ([
				"action": HIB"$N手腕转了个小圈，既快且准，三只手指搭上$n手腕，大拇指和小指跟着便即收拢，扣住$n脉门，$n顿时动弹不得"NOR,
				"damage": 100,
				"damage_type": "瘀伤",
		"damage": 600,
				"dodge": 100,
				"force": 450,
			]);

		if ( lvl_temp <= 160 )
		{
				return ([
					"action": HIW"$N双手连抓，使出「天山折梅手」的高深武功，抓中带扣，扣中夹掌，连攻$n的命门大穴"NOR,
					"damage_type": "瘀伤",
		"damage": 600,
					"dodge": 120,
					"force": 500,
				]);


		}

		return
		([
		"action": HIR"这时$N内力生发，将「逍遥」二字发挥得淋漓尽致，姿势优雅美观，潇洒如意\n"
			 "然而逍遥派武学的诸般狠辣招数自然而然的也使了出来，所使招数渐趋阴险刻毒\n"
			 "$N招招凶险，皆攻向$n要害，直欲致$n死得惨酷无比"NOR,
		"damage_type": "瘀伤",
		"damage": 500,
		"dodge": 600,
		"force": 550,
		]);

	}
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练天山折梅手。\n");
        if ((int)me->query_skill("qingyun-shou", 1) < 80)
		return notify_fail("你的青云手火候太浅。\n");
        if ((int)me->query_skill("panyang-zhang", 1) < 80)
		return notify_fail("你的攀阳掌火候太浅。\n");
	me->receive_damage("qi", 45);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"zhemei-shou/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;

        lvl  = me->query_skill("beiming-shengong", 1);
if (lvl==0)
        lvl  = me->query_skill("bahuang-gong", 1);
        flvl = me->query("jiali");
if (me->query_skill_mapped("force") != "bahuang-gong" &&
me->query_skill_mapped("force") != "beiming-shengong")
                return;
        if (lvl < 80 || ! damage_bonus ||
            me->query("neili") < 300)
                return;
flvl=random(lvl)+50;
        if (random(5)==0)
        {
if (victim->query("qi") > flvl)
{
victim->add("qi",-flvl);
victim->add("eff_qi",-flvl);
}
                return HIR "$n" HIR "的一只手臂，被$N用力弯折！疼痛难忍!!\n" NOR;
        }
        else if (random(4)==0)
        {
if (victim->query("neili") > 1500)
victim->add("neili",-300);
if (me->query("neili") < me->query("max_neili"))
victim->add("neili",(random(lvl)+50));

return HIC "$n" HIC "全身功力如流水般源源不绝地流入$N的身体！\n" NOR;
        }
}


int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("bahuang-gong",1);
        level2= (int) me->query_skill("bahuang-gong",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/10;
if (damage2>= 3800) damage2 = 3800;
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "bahuang-gong")
{
if (ob->query("neili") >= damage2)
{
ob->add("neili",-damage2);
me->add("neili",damage2);
if (!ob->is_busy())	ob->start_busy(1);
}
msg = HIR"$N突然发招,$n全身内力如流水般源源不绝地流入$N的身体\n"NOR;

           message_vision(msg, me, ob);
           return j;
}       
}