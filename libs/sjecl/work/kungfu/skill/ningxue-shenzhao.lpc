// ningxue-shenzhao.c 凝血神爪
// creat by Lklv 2002.1.26 for tdh, quest skills

#include <ansi.h>
inherit SKILL;

string *parry_msg = ({
"$p双掌一翻，将$P的来势尽数化去，$N急劲就似钻入了一片粘稠之物中间一般。\n",
"$p右肩斜闪，左手手指凭空划了几个圈子，以四两微力，拨动$N千斤巨力。\n",
"$p眼见$P攻到，当即使出一招「揽雀尾」，右脚实，左脚虚，运起“挤”字诀，粘连粘随，右掌已搭住$P左腕，横劲发出。$N身不由主的向前一冲，跨出两步，方始站定。\n",
"不料$p双手一圈，如抱太极，一股雄浑无比的力道组成了一个旋涡，只带得$P在原地急转七八下。\n",
"$p连消带打，双手成圆形击出，随即左圈右圈，一个圆圈跟着一个圆圈，大圈、小圈、平圈、立圈、正圈、斜圈，一个个太极圆圈发出，登时便套得$P跌跌撞撞，身不由主的立足不稳。\n",
"$p使出一招「云手」，左手高，右手低，一个圆圈已将$P套开。\n",
"$p觉气息微窒，当下一招「斜飞势」，将$P引偏。\n",
"$p吸一口气，体内真气流转，右掌挥出，一拒一迎，将$P的力道尽行碰了回去。\n",
"$p双掌一翻，使出一招「云手」，双掌柔到了极处，空明若虚，将$P的急劲尽数化去。\n",
"$p当即双掌一扬，迎着$P接去，待得手掌将触未触之际，施出「揽雀尾式」，脚下“金鸡独立式”，左足关地，右足悬空，全身急转，宛似一枚陀螺。\n",
"就在这电光石火的一瞬之间，$p身子一弓，正是「白鹤亮翅」的前半招，$P的劲力登时落空。\n",
});

string query_parry_msg(object weapon, object target)
{
        if ( objectp(target->query_temp("weapon")) )
                return SKILL_D("parry")->query_parry_msg(weapon);
        else
                return parry_msg[random(sizeof(parry_msg))];
}

mapping *action = ({
([
	"action" : HIR"$N势若疯虎，形若邪魔，双爪如钢抓铁钩，左手手腕翻处，右手疾伸，五根手指抓向$n$l"NOR,
	"force" : 200,
	"dodge" : -5,
	"lvl" : 0,
   	"damage_type" : "抓伤"
]),
([
	"action" : HIR"突然人影闪动，$N迫到$n身后，袖中伸出手，五根手指向$n$l插了下去"NOR,
	"force" : 260,
	"weapon" : "五指",
	"dodge" : 10,
	"lvl" : 10,
	"damage_type" : "抓伤"
]),
([
	"action" : HIR"$N手臂关节喀喇一响，手臂斗然长了半尺，一掌按在$n$l，五指即要插进"NOR,
	"force" : 300,
	"weapon" : "手指",
	"dodge" : 5,
   	"lvl" : 20,
	"damage_type" : "刺伤"
]),
([
	"action" : HIR"$N双手微张，十根尖尖的指甲映出灰白光忙，突然翻腕出爪，五指猛地插落"NOR,
	"force" : 360,
	"weapon" : "手爪",
	"dodge" : 5,
	"lvl" : 30,
   	"damage_type" : "刺伤"
]),
([
	"action" : HIR"$N左手突然在$n眼前上围下钩，左旋右转，连变了七八般，蓦地里右手一伸，五根手指直插$n$l"NOR,
	"force" : 380,
	"weapon" : "五根手指",
	"dodge" : 5,
	"lvl" : 40,
	"damage_type" : "戳伤"
]),
([
	"action" : HIR "$N左爪虚晃，右爪蓄力，一招" HIR "「勾魂夺魄」" HIR "直插向$n的$l" NOR,
	"force" : 400,
	"dodge" : 10,
	"lvl"   : 100,
	"skill_name" : "勾魂夺魄" ,
	"damage_type" : "抓伤"
]),
([
	"action" : HIR "$N双手连环成爪，爪爪钩向$n，" HIR "「九子连环」" HIR "已向$n的$l抓出" NOR,
	"force" : 420,
	"dodge" : -10,
	"lvl"   : 120,
	"skill_name" : "九子连环" ,
	"damage_type" : "戳伤"
]),
([
	"action" : HIR "$N身形围$n一转，使出" HIR "「天罗地网」" HIR "，$n的$l已完全笼罩在爪影下" NOR,
	"force" : 450,
	"dodge" : 15,
	"lvl"   : 140,
	"skill_name" : "天罗地网" ,
	"damage_type" : "抓伤"
]),
([
	"action" : HIR "$N使一招" HIR "「风卷残云」" HIR "，双爪幻出满天爪影抓向$n全身" NOR,
	"force" : 470,
	"dodge" : 10,
	"lvl"   : 160,
	"skill_name" : "风卷残云" ,
	"damage_type" : "抓伤"
]),
([
	"action" : HIR "$N吐气扬声，一招" HIR "「唯我独尊」" HIR "双爪奋力向$n天灵戳下" NOR,
	"force" : 500,
	"dodge" : 20,
	"lvl"   : 200,
	"skill_name" : "唯我独尊" ,
	"damage_type" : "抓伤"
]),
});

int valid_enable(string usage)
{
	return usage=="claw" || usage=="parry" ;
}

int valid_learn(object me)
{
	if ( !me->query("chen_jn/pass") )
		return notify_fail("没有陈近南的指点，你无法练习凝血神爪。\n");
	if ((int)me->query_skill("ningxue-shenzhao", 1 ) < 120 )
		return notify_fail("你现在不能学习凝血神爪。\n");
	if ( objectp(me->query_temp("weapon")) || objectp(me->query_temp("secondary_weapon")) )
		return notify_fail("必须空手才能练习凝血神爪。\n");
	if ((int)me->query_skill("claw", 1) < 31)
		return notify_fail("你的基本爪功火候不够，无法学习。\n");
	if ((int)me->query("max_neili") < 1000)
		return notify_fail("你的内力太弱，无法练凝血神爪。\n");
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
	level = (int) me->query_skill("ningxue-shenzhao",1);

	for(i = sizeof(action); i > 0; i--)
	if (level >= action[i-1]["lvl"])
		return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	int lvl = (int)me->query_skill("ningxue-shenzhao", 1 );

	if ( lvl < 150 )
		return notify_fail("你现在不能练习凝血神爪。\n");
	if ((int)me->query("jingli") < 40)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 60)
		return notify_fail("你的内力不够练凝血神爪。\n");
	me->receive_damage("jingli", 30);
	me->add("neili", -(10 + random(lvl/10+1)));
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"ningxue-shenzhao/" + action;
}

void skill_improved(object me)
{
	tell_object(me, "你练着练着突然感觉丹田中气血翻涌！\n");
	if ( me->query("neili") > (me->query_skill("ningxue-shenzhao", 1) / 10) ){
		me->add("neili", -(me->query_skill("ningxue-shenzhao", 1) / 10));
	}
}
