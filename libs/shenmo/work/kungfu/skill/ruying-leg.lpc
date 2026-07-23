// Last Modified by winder on May. 29 2001
// ruying-leg.c 如影随形腿 不能互备 取自佛经中“六和敬”。

#include <ansi.h>
inherit SKILL;
#include <combat.h>

#include "/kungfu/skill/eff_msg.h";

string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N纵身向前，忽然凌空伸出左腿，一式"HIC"「见和同解」"NOR"，卷起飞砂直踢$n的$l",
	"lvl"   : 0,
	"skill_name" : "见和同解"
]),
([	"action" : "$N身形一闪，双足一点跃如空中，一式"HIM"「戒和同修」"NOR"，在半空连踢七脚，直奔$n$l",
	"lvl"   : 10,
	"skill_name" : "戒和同修"
]),
([	"action" : "$N身体前倾，左脚画圆，凌空而起，右腿顺势使出一式"HIW"「身和同住」"NOR"，横扫$n$l",
	"lvl"   : 30,
	"skill_name" : "身和同住"
]),
([	"action" : "$N一言不发，左足倏地弹出，连环三腿，分踢$n的头，胸，腹，正是一式"HIB"「口和无净」"NOR"",
	"lvl"   : 60,
	"skill_name" : "口和无净"
]),
([	"action" : "$N左足独立，身体旋转，右腿随身形反转横扫，一招"HIR"「意和同悦」"NOR"，拉起劲风扫向$n$l",
	"lvl"   : 100,
	"skill_name" : "意和同悦"
]),												
([	"action" : "$N跃起在半空，双足带起无数劲风，一式"HIW"「利和同均」"NOR"，全身旋转而下，迅捷无伦地轰向$n",
	"lvl"   : 150,
	"skill_name" : "利和同均"
]),
});

int valid_enable(string usage) { return usage=="leg" || usage=="parry"  || usage=="unarmed"; }
int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("学如影随形腿时手里不能拿武器。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 120)
		return notify_fail("你的站桩功火候不够，无法学如影随形腿。\n");
	if ((int)me->query("max_neili") < 1500)
		return notify_fail("你的内力太弱，无法练如影随形腿。\n");

	if ((me->query_skill("shaolin-leg", 1) < 50) ||
		(me->query_skill("shaolin-cuff", 1) < 50))
		return notify_fail("你的少林弹腿和少林南拳火候不够，无法学如影随形腿。\n");
	if ((me->query_skill("yiwei-dujiang", 1) < 50))
		return notify_fail("你的一苇渡江火候不够。\n");
		
	if ((me->query_skill("shaolin-leg", 1) < 50) ||
		(me->query_skill("banruo-zhang", 1) < 50))
		return notify_fail("你的少林弹腿和般若掌火候不够，无法学如影随形腿。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练如影随形腿。\n");
	me->receive_damage("qi", 50);
	me->add("neili", -20);
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
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 30;
	int d_e2 = 20;
	int p_e1 = 10;
	int p_e2 = 320;
	int f_e1 = 500;
	int f_e2 = 800;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("ruying-leg", 1);
	for(i = ttl; i > 0; i--)
		if(lvl > action[i-1]["lvl"])
		{
			seq = i; /* 获得招数序号上限 */
			break;
		}
	seq = random(seq);       /* 选择出手招数序号 */
	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage_type" : random(2) ? "内伤" : "瘀伤",
	]);
}
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	 return __DIR__"ruying-leg/" + action;
}

int help(object me)
{
	write(HIC"\n如影随形腿："NOR"\n");
	write(@HELP

   如影随形腿是南少林高级腿法，不能互备，出自佛经中“六和敬”。

	学习要求：
		站桩功120级
		少林弹腿50级
		般若掌50级
		内力修为1500
HELP
	);
	return 1;
}

mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        int i, level;
        object target;
object weapon;
        level   = (int) me->query_skill("ruying-leg",1);
//        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if( random(12)==1 || random(level) > 150)
	{
        if (userp(victim))
        victim->receive_wound("qi", (damage_bonus+level+100) );	
        victim->start_busy(3);
        return HIC "「无影脚!!」！$N突然踢出南少林无影脚!! $n吐出一口鲜血!!!\n" NOR;
	}
if (damage_bonus < 60) damage_bonus=60;
	if( random(12)==1 || random(level) > 50)
	{

        victim->receive_wound("qi", damage_bonus );	
        return HIM "嘿!!无影脚！！一股鲜血从$n的身子喷出!\n" NOR;
  }
}

int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("ruying-leg", 1);

        if( damage < 10 ) return 1;
         
            if ( random(12) == 0 || random(level) > 150){
          ob->start_busy(3);
         msg = RED"$N面对$n的攻势。突然如影随形的踢出几脚!!。\n"NOR;
         msg += RED"「无影脚!!」。$N如影随形的踢出几脚，$n吐出一口鲜血!!。\n"NOR;
             ob->add("qi",-(level+100));
             ob->add("eff_qi",-(level+100));

        if (userp(ob) && ob->query("qi") > 50
        && ob->query("eff_qi") > 50)
{
if (ob->query("qi")/12 > 20)
             ob->add("qi",-ob->query("qi")/12);
if (ob->query("eff_qi")/12 > 20)
             ob->add("eff_qi",-ob->query("eff_qi")/12);
}

msg += damage_msg(damage, "瘀伤");
message_vision(msg, me, ob);
}

            return damage;
}
