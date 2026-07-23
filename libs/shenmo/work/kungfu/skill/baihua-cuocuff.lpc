// Last Modified by winder on Sep. 12 2001
// baihuacuo-cuff.c 百花拳

#include <ansi.h>
inherit SKILL;
#include <combat.h>

#include "/kungfu/skill/eff_msg.h";
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N振臂一掠，使一招"HIC"「斗转星移」"NOR"，双手自两侧击向$n",
	"skill_name" : "斗转星移",
	"lvl" : 0
]),
([	"action" : "$N使一招"HIW"「横云断峰」"NOR"，左手成掌，护住前胸，右手成拳，打向$n的$l",
	"skill_name" : "横云断峰",
	"lvl" : 5
]),
([	"action" : "$N左手伸出，右手紧握，使一招"GRN"「分花拂柳」"NOR"，直进中宫，向$n的$l打去",
	"skill_name" : "分花拂柳",
	"lvl" : 10
]),
([	"action" : "$N双手一并，右手用刚，左手用柔，使一招"RED"「颠倒阴阳」"NOR"，分击$n的前胸和$l",
	"skill_name" : "颠倒阴阳",
	"lvl" : 15
]),
([	"action" : "$N双手双外推出，身体滴溜溜一转，划了一个大圈，使一招"BLU"「夜战八方」"NOR"，击向$n的$l",
	"skill_name" : "夜战八方",
	"lvl" : 20
]),
([	"action" : "$N一跃上前，使一招"MAG"「风虎云龙」"NOR"，右拳奋力向$n的$l打去",
	"skill_name" : "风虎云龙",
	"lvl" : 25
]),
([	"action" : "$N拳掌一分，斜身上步，一招"HIG"「穿花绕树」"NOR"，锤向$n的$l",
	"skill_name" : "穿花绕树",
	"lvl" : 30
]),
([	"action" : "$N左脚前踏半步，右手使一招"HIY"「倒打金钟」"NOR"，指由下向$n的$l戳去",
	"skill_name" : "倒打金钟",
	"lvl" : 35
]),
([	"action" : "$N一招"YEL"「指天划地」"NOR"，小臂划了半个圆弧，双掌缓缓向外推出，向$n的$l挥去",
	"skill_name" : "指天划地",
	"lvl" : 40
]),
([	"action" : "$N左手横挡，右掌一挥，右手使一招"GRN"「燕子斜飞」"NOR"，挥向$n的$l",
	"skill_name" : "燕子斜飞",
	"lvl" : 45
]),
([	"action" : "$N左手虚攻，右手紧并,使一招"HIR"「移花接木」"NOR"，向$n的$l插去",
	"skill_name" : "移花接木",
	"lvl" : 50
]),
([	"action" : "$N趁势前扑，一招"HIM"「魁星踢斗」"NOR"拳中夹腿打向$n的$l",
	"skill_name" : "魁星踢斗",
	"lvl" : 55
]),
([	"action" : "$N左手在$n面门一晃，右手一记"HIW"「云横秦岭」"NOR"击向$n的$l",
	"skill_name" : "云横秦岭",
	"lvl" : 60
]),
([	"action" : "$N施出"MAG"「月移花影」"NOR"，身形不住闪动，双手同时攻向$n的$l",
	"skill_name" : "月移花影",
	"lvl" : 65
]),
([	"action" : "$N稳扎马步，吐气开声，"HIY"「中流砥柱」"NOR"，双拳锤向$n的$l",
	"skill_name" : "中流砥柱",
	"lvl" : 70
]),
});
int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int valid_combine(string combo) { return combo=="benlei-shou"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练百花拳必须空手。\n");
	if ((int)me->query_skill("honghua-shengong", 1) < 100)
		return notify_fail("你的红花神功火候不够，无法学百花拳。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练百花错拳。\n");
	return 1;
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("你的内力不够练百花拳。\n");
	me->receive_damage("qi", 35);
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
	int d_e1 = 35;
	int d_e2 = 80;
	int p_e1 = 60;
	int p_e2 = 95;
	int f_e1 = 230;
	int f_e2 = 480;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("baihua-cuocuff", 1);
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
		"damage_type" : "瘀伤",
	]);
}
int learn_bonus() { return 20; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point() { return 1.0; }
string perform_action_file(string action)
{
	return __DIR__"baihua-cuocuff/" + action;
}
mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        int i, level;
        object target;
object weapon;
        level   = (int) me->query_skill("baihua-cuocuff",1);
//        target = me->select_opponent();
        weapon = me->query_temp("weapon");

	if( random(12)==1 || random(level) > 150)
	{
        if (userp(victim))
        victim->receive_wound("qi", (damage_bonus+level+100) );	
        return HIY "「百花错拳!!」！$N稳扎马步，吐气开声 双拳锤向$n几处大穴!! $n吐出一口鲜血!!!\n" NOR;
	}
if (damage_bonus < 60) damage_bonus=60;
	if( random(12)==1 || random(level) > 50 ||  (int)me->query_temp("kongming")  )
	{

        victim->receive_wound("qi", damage_bonus );	
        return HIR "百花错拳！一股鲜血从$n的身子喷出!\n" NOR;
  }
}

int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("baihua-cuocuff", 1);

        if( damage < 10 ) return 1;
          ob->start_busy(2);
            if ( random(12) == 0 || random(level) > 150){
         msg = YEL"$N面对$n的攻势 施出「月移花影」，身形一闪，双手同时攻向$n。\n"NOR;
         msg += YEL"$n感到双眼一花，尽然不能动了!!。\n"NOR;
ob->start_busy(4);

msg += damage_msg(damage, "瘀伤");
message_vision(msg, me, ob);
}

            return damage;
}

int help(object me)
{
	write(HIM"\n百花拳："NOR"\n");
	write(@HELP

    百花拳是天池怪侠袁士霄所创。袁士霄痛悔当年错过大好因缘，
以世上万物多错，创出此拳。此拳取众家之长，往往似是而非，诱敌
入彀，故称错拳。
    红花会总舵主陈家洛为袁士霄入室弟子，得传此拳。

	学习要求：
		红花神功100级
		内力修为100
HELP
	);
	return 1;
}
