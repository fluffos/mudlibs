// wuyun-jian.c 五韵七弦剑
// Last Modified by winder on Mar. 10 2000
#include <ansi.h>
inherit SKILL;
#include <combat.h>

#include "/kungfu/skill/eff_msg.h";

string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N左小指轻弹，一招"HIM"「宫韵」"NOR"悄然划向$n的后心",
	"lvl" : 0,
	"skill_name" : "宫韵"
]),
([	"action" : "$N右手无名指若有若无的一划，将琴弦并做一处，"HIR"[商韵]"NOR"已将$n笼罩",
	"lvl" : 10,
	"skill_name" : "商韵"
]),
([	"action" : "$N五指疾挥，一式"HIB"[角韵]"NOR"无形的刺向$n的左肋",
	"lvl" : 20,
	"skill_name" : "角韵"
]),
([	"action" : "$N将手中剑横扫，同时左右手如琵琶似的疾弹，正是一招"HIG"[支韵]"NOR"",
	"lvl" : 30,
	"skill_name" : "支韵"
]),
([	"action" : "$N使出"HIW"「羽韵」"NOR"，将剑提至唇边，如同清音出箫，剑掌齐出，划向$n的$l",
	"lvl" : 40,
	"skill_name" : "羽韵"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("wuzheng-xinfa", 1) < 90)
		return notify_fail("你的无争心法火候不够。\n");


	if ((int)me->query_skill("pomopima-jian", 1) < 90)
		return notify_fail("你的泼墨披麻剑火候不够。\n");

	if ((int)me->query_skill("piaoyibu", 1) < 90)
		return notify_fail("你的飘逸步法火候不够。\n");

	if ((int)me->query_skill("jiangjun-zhang ", 1) < 90)
		return notify_fail("你的裴将军诗杖法火候不够。\n");

	if ((int)me->query_skill("xuantian-zhi", 1) < 90)
		return notify_fail("你的玄天无情指火候不够。\n");

	if ((int)me->query_skill("shigu-bifa", 1) < 90)
		return notify_fail("你的石鼓打穴笔法火候不够。\n");









	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if( (int)me->query("jing") < 35 || (int)me->query("neili") < 15 )
		return notify_fail("你的精或内力不够练五韵七弦剑。\n");
	me->receive_damage("jing", 20);
	me->add("neili", -15);
	return 1;
}

int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("wuyun-jian", 1);

        if( damage < 10 ) return 1;
          
            if ( random(12) == 0 || random(level) > 180){
         ob->start_busy(2);
         msg = RED"$N面对$n的攻势。突然长啸一声 !!\n"NOR;
         msg += RED"「五韵七弦音!!」。$n两眼一花 吐出一口鲜血!!。\n"NOR;
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
	int d_e1 = 20;
	int d_e2 = 40;
	int p_e1 = 10;
	int p_e2 = 10;
	int f_e1 = 100;
	int f_e2 = 250;
	int m_e1 = 370;
	int m_e2 = 370;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("wuyun-jian", 1);
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
		"damage"      : m_e1 + (m_e2 - m_e1) * seq / ttl,
		"damage_type" : random(2) ? "割伤" : "刺伤",
	]);
}
int learn_bonus() { return 25; }
int practice_bonus() { return 25; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"wuyun-jian/" + action;
}

int help(object me)
{
	write(HIC"\n五韵七弦剑："NOR"\n");
	write(@HELP

    日月神教黑木崖武功，梅庄大庄主黄钟公的独门剑法，将琴乐
融入剑法之中，以乐音扰敌心神，从而控制对方内息的变化。

	学习要求：
		无争心法90级，梅庄基本武功90级
		内力100
HELP
	);
	return 1;
}

