// lonely-sword.c ¾Ž
// Last Modified by sir 10.22.2001

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *parry_msg = ({
	"ȴ$n̤ǰһʽбָұۣҪʹ$Pˡ\n",
	"$nԹΪأԽΪˣ$P͹ػӳλ̩ɽ\n",
	"$nͻ䣬����ڽزʹɽġͼʹ$PС\n",
	"$nͻȻһ$P$lһȴţ$P޴룬Ʋͣ\n"
	"$nܣٽʹ����両ࡹ$P$l뵲С\n",
	"$nͻȻʹɷ罣ġڤڤǷλȴƫ$Pһʣ\nͼͻ$PĹƣ\n"
	"$nͦһǡƳᶡش$P$lͼ$PĹƻ⡣\n",
	"ֻ$n˷Ʈ磬һʽ�����޶׽صס$P\n�����\n",
	"$n˷ʹɽС롹ɭɭܣܿ$P\n",
});

mapping *action = ({
([	"action" : "$Nͦϣ$wһһз·̩ɽġȪֱ$n
$l",
	"lvl" : 0,
	"skill_name" : "Ȫ"
]),
([	"action" : "$N$nӳȪܽءϸǡʯ�����
�����ףڡɽ񽣣",
	"lvl" : 7,
	"skill_name" : "ɽ"
]),
([
	"action" : "$Nת̳ʮŽȻǻɽŮʮŽ
ʮŽһУַ֮죬ֱǷ˼",
	"lvl" : 14,
	"skill_name" : "ŮʮŽ"
]),
([	"action" : "$Nƺ����裬�����ɽΪһ$n
ȥ",
	"lvl" : 21,
	"skill_name" : "ɽ"
]),
([	"action" : "$Nͻɭϣǧ۶ǹꪣɳǧ
ɽƻ$n$l",
	"lvl" : 28,
	"skill_name" : "ǹ"
]),
([	"action" : "ȴ$N潣ߣһգұһ䣬ҲԽתԽӺ
̩ɽʮ̡Ϊһ$n",
	"lvl" : 35,
	"skill_name" : "̩ɽʮ"
]),
([	"action" : "$Nͻ䣬ʹɽġһ㡹$n$l֪
;ͻȻת򣬴$n֮⣡",
	"lvl" : 42,
	"skill_name" : "һ"
]),
([	"action" : "$Nһǡɽ$wն䣬ֱ$n
$l",
	"lvl" : 49,
	"skill_name" : "ɽ"
]),
([	"action" : "$N$wԽתԽ죬ʹľȻǺɽġٱǧʮʽ
ʽƾӿԹ߲ɵĿΪ֮ѣ",
	"lvl" : 56,
	"skill_name" : "ٱǧʮʽ"
]),
([	"action" : "$NЦׯϣ$wӣڡĦΪһʽش
$n",
	"lvl" : 63,
	"skill_name" : "Ħ"
]),
([	"action" : "$N$wʹ̫⣬ССԲȦ޾
ԴԴز$n",
	"lvl" : 70,
	"skill_name" : "̫"
]),
([	"action" : "$Nأ$wҺɨЮ֮Ʊ$nĦ
Ľ¶ţ",
	"lvl" : 77,
	"skill_name" : "Ħ"
]),
([	"action" : "ȴ$NͻȻ鲽ʹ䵱ѵˮһУ",
	"lvl" : 84,
	"skill_name" : "ѵˮ"
]),
([	"action" : "$N˽磬з$n$lԱ$nأǡ
ħġʽ",
	"lvl" : 91,
	"skill_name" : "ʽ"
]),
([	"action" : "$NͻȻ˽һֹġ罣Ȼ$nҴ
",
	"lvl" : 98,
	"skill_name" : "罣"
]),
([	"action" : "$Nߣһһ$nĪֲ$N
ʵ",
	"lvl" : 105,
	"skill_name" : "Ī"
]),
([	"action" : "$Nת$nµ$n̳һ֪ʹʲ
ô",
	"lvl" : 112,
	"skill_name" : ""
]),
([	"action" : "$NͻȻһ$n$lһȴţ$n޴룬֪
Ǻã",
	"lvl" : 119,
	"skill_name" : ""
]),
([	"action" : "$NЮƣ󿪴صҿһͨнԻ$nƵ
$nòأ",
	"lvl" : 126,
	"skill_name" : "󿪴"
]),
([	"action" : "$Nֺὣ$n$lеһȻ$n
Կ彣ƣ",
	"lvl" : 133,
	"skill_name" : ""
]),
([	"action" : "$NٽӣѸޱȵص$n$lȴ˿ʲô
ʽ",
	"lvl" : 140,
	"skill_name" : "ٽ"
]),
([	"action" : "$Nһָ$n$nڣ˵ף
˼飡",
	"lvl" : 147,
	"skill_name" : ""
]),
([	"action" : "$NͻЦݣƺѿ$n书ʽгһ$n
$l",
	"lvl" : 154,
	"skill_name" : "ͻЦ"
]),
([	"action" : "$N$wһڣ$nԼ$wײ֮ʵѲ⣡",
	"lvl" : 180,
	"skill_name" : "֮"
])
});

int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }
string query_parry_msg(string limb)
{
	return parry_msg[random(sizeof(parry_msg))];
}
int valid_learn(object me)
{
	object ob;

	mapping myfam;
	myfam = (mapping)me->query("family");
	if(!myfam || myfam["family_name"] != "ɽ"|| myfam["master_id"] != "feng qingyang")
		return notify_fail("¾Žֻǰѧϰ\n");
	if( (int)me->query("max_neili") < 600 )
		return notify_fail("ûа취¾Ž\n");
	if( (int)me->query_skill("zixia-shengong",1)<100)
		return notify_fail("¾Žϼ񹦲ϰ\n");
	if( !(ob = me->query_temp("weapon"))
	|| (string)ob->query("skill_type") != "sword" )
		return notify_fail("һѽ\n");
	if ((int)me->query_skill("lonely-sword",1) > 120)
		return notify_fail("׽Ҿͽ̵ԺҪԼˡ\n");

	return 1;
}
int practice_skill(object me)
{
	return notify_fail("¾Žֻܾͨʽ\n");
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
	int d_e1 = -25;
	int d_e2 = -5;
	int p_e1 = -55;
	int p_e2 = -35;
	int f_e1 = 150;
	int f_e2 = 230;
	int m_e1 = 220;
	int m_e2 = 320;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("lonely-sword", 1);
	for(i = ttl; i > 0; i--)
		if(lvl > action[i-1]["lvl"])
		{
			seq = i; /*  */
			break;
		}
	seq = random(seq);       /* ѡ */
	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage"      : m_e1 + (m_e2 - m_e1) * seq / ttl,
		"damage_type" : random(2) ? "" : "",
	]);
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point() { return 1.0; }

int valid_effect(object me, object weapon, string name, int skill)
{
}
string perform_action_file(string action)
{
	return __DIR__"lonely-sword/" + action;
}

int help(object me)
{
	write(HIC"\n¾Ž"NOR"\n");
	write(@HELP

    ¾Žнˣ
    ׽Ķǰֽܡ
һܶɵã⽣ʩչ޵У̽
޵£һƵһжɵãίʵ
ɾ塣
    ʤУǿҸǿ¾ŽʽмУ
С¾ŽҪּڡ򡹣ɾ಻ϵ
ȣʤͨ˾Ž⣬ʩɡ
    ¾ŽԡܾʽƽʽƵʽ
ǹʽƱʽʽʽƼʽ
ھŽʽŽĵһСܾʽֱ仯
ܾ����ϰڶСƽʽƽ¸Ÿ
ɵĽСƵʽƽⵥ˫Ҷ
ͷ󿳵նֵСǹʽƽⳤ
ǹꪡìü����ˡȡֳ
֮СƱʽƽֱޡﵡѨӡ
ӡü̡ذס師ơ˽鳡׵ȵȶ̱У
Сʽƽǳޡڹǹ
ɴǵȵССʽƵȭָ
Ĺ򣬽ȭ̴õѨħצצɳƣȭ
ڡڰСƼʽ����֣
һʱѧ֮����Ҫһ�����
����˷ְ����Եİ
˵СھŽʽΪԸϳڹĵ˶ã
֮һġ

	ѧϰҪ
		ֻѧϰ
		ϼ100
		600
HELP
	);
	return 1;
}

