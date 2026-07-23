// lanhua-shou.c -兰花拂穴手
// Modified by Venus Oct.1997
#include <combat.h>
#include <ansi.h>

inherit SKILL;
string* xuedao = ({
        "巨骨穴",
        "地仓穴",
        "肩井穴",
        "颊车穴",
        "承泣穴",
        "风池穴",
        "章门穴",
        "风府穴",
        "精促穴",
        "陶道穴",
        "强间穴",
        "少海穴",
        "犊鼻穴",
        "神门穴",
        "华盖穴",
        "大椎穴",
        "太阳穴",
        "膻中穴",
        "命门穴",
        "鸠尾穴",
        "三阴交",
        "天柱穴"
});

mapping *action = ({
([  "action" : "$N右手五指分开，微微一拨，再并拢向外一拂，一式「花疏云淡」，
拂向$n的膻中要穴",
    "force" : 150,
    "dodge" : 5,
    "damage": 145,
    "damage_type" : "瘀伤",
    "lvl" : 0,
    "skill_name" : "花疏云淡"
]),
([  "action" : "$N侧身掠向$n，一式「轻云蔽月」，左手五指暗暗运气拨向$n的胸前
大穴",
    "force" : 160,
    "dodge" : 5,
    "damage": 245,
    "damage_type" : "瘀伤",
    "lvl" : 10,
    "skill_name" : "轻云蔽月"
]),
([  "action" : "$N使一式「云破月来」，左掌虚攻，右手并指斜前翻出，拍向$n的肩
井穴",
    "force" : 170,
    "dodge" : 15,
    "damage": 245,
    "damage_type" : "内伤",
    "lvl" : 20,
    "skill_name" : "云破月来"
]),
([  "action" : "$N左掌护胸，微微侧身，右掌勾上，一式「幽兰弄影」，缓缓拂向$n
的天突穴",
    "force" : 190,
    "dodge" : -5,
    "damage": 245,
    "damage_type" : "瘀伤",
    "lvl" : 30,
    "skill_name" : "幽兰弄影"
]),
([  "action" : "$N使一式「芳兰竟体」，身影不定地掠至$n身后，猛地拍向$n的大椎
穴",
    "force" : 210,
    "dodge" : 10,
    "damage": 245,
    "damage_type" : "瘀伤",
    "lvl" : 42,
    "skill_name" : "芳兰竟体"
]),
([  "action" : "$N两臂左手下右手上地于胸前成兰花指形翻上，微吸一口气，一式「
兰桂齐芳」，双手向外快速一拨，激出数道劲气逼向$n的华盖、璇玑、紫宫几处大穴",
    "force" : 240,
    "dodge" : 5,
    "damage_type" : "瘀伤",
    "damage": 145,
    "lvl" : 54,
    "skill_name" : "兰桂齐芳"
]),
([  "action" : "$N衣袂飘飘，向上跃起，一式「月影花香」，居高临下，拂出一道劲
力罩向$n的百会大穴",
    "force" : 270,
    "dodge" : 20,
    "damage": 145,
    "damage_type" : "内伤",
    "lvl" : 66,
    "skill_name" : "月影花香"
]),
([  "action" : "$N凝神施展出「花好月圆」，双手疾拂，一环环的劲气逼向$n的上中
下各大要穴",
    "force" : 300,
    "dodge" : 25,
    "damage": 145,
    "damage_type" : "内伤",
    "lvl" : 80,
    "skill_name" : "花好月圆"
]),
([      "action" : "$N左手忽做兰花之形，五指轻拢慢抹，拂向$n的周身大穴",
	"force" : 250,
	"dodge" : 5,
	"parry" : 2,
	"damage": 115,
	"weapon": "左手",
	"lvl" : 55,
	"skill_name" : "兰花手左手式",
	"damage_type" : "擦伤"
]),
([      "action" : "$N右手轻摇，颤抖不定，便如兰花浴风般划向$n的$l",
	"force" : 520,
	"dodge" : 10,
	"parry" : 5,
	"damage": 245,
	"weapon": "右手",
	"lvl" : 85,
	"skill_name" : "兰花手右手式",
	"damage_type" : "擦伤"
]),

});

int valid_enable(string usage) { return usage=="hand" ||  usage=="parry"; }     

int valid_combine(string combo) { return combo=="tanzhi-shentong"; }

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
       return notify_fail(HIC"练兰花拂穴手必须空手。\n"NOR);
    if ((int)me->query_skill("bibo-shengong", 1) < 20)
       return notify_fail("你的碧波神功火候不够，无法学兰花拂穴手。\n");
    if ((int)me->query("max_neili") < 200)
       return notify_fail("你的内力太弱，无法练兰花拂穴手。\n");
    return 1;
}
string query_skill_name(int level)
{
    int i;
    for(i = sizeof(action)-1; i >= 0; i--)
    if(level >= action[i]["lvl"])
    return action[i]["skill_name"];
}


int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
       return notify_fail("你的体力太低了，无法练兰花拂穴手。\n");
    me->receive_damage("qi", 25);
    return 1;
}

string perform_action_file(string action)
{
        return __DIR__"lanhua-shou/" + action;
}

mapping query_action(object me, object weapon)
{
        int i, level, bt, dp;
	object victim;
	string xue;
        string name1,name2;
        
        level  = (int) me->query_skill("lanhua-shou",1);
        bt  = (int) me->query_skill("force",1);
	xue = xuedao[random(sizeof(xuedao))];

	level   = (int) me->query_skill("lanhua-shou",1);
        if (random(level) > 160 && me->query_skill("force") > 250 && me->query("neili") >= 600) {
		me->add("neili", -120);
		me->set_temp("autopfm_lhs", 1);
		return ([
		"action": HIC"忽见$N"+(random(2)?"右":"左")+"手手掌五指分开，形如兰花，姿态曼妙难言，出手优雅，气度闲逸，望之轻描淡写，行若无事地拂向$n的"+xue+""NOR,
		"force" : 560+random(40),
		"dodge" : 20,
		"damage": 560+random(20),
		"damage_type" : "内伤" ]);
	}

        if (random(level) > 130 && me->query_skill("force") > 250 && me->query("neili") >= 600) {
		me->add("neili", -120);
		me->set_temp("autopfm_lhs", 1);
		return ([
		"action": HIC"$N淡然一笑，出手若春兰葳蕤，晓风过林，似慢实快，若重还轻拂向$n的"+xue+"，已深得快、准、奇、清四字要诀"NOR,
		"force" : 550,
		"dodge" : 20,
		"damage": 550,
		"damage_type" : "内伤" ]);
	}

        if (random(level) > 80 && me->query_skill("force") > 250 && me->query("neili") >= 600) {
		me->add("neili", -120);
		me->set_temp("autopfm_lhs", 1);
		return ([
		"action": HIR "$N双手交叠，使出“兰花手双手式”，形状便如兰花新蕾初放，于轻风中微微摇摆。$n看得有些发呆，却蓦然发现$N的十指已拂到面前！" NOR,
		"damage": 456,
		"force": 480,
               	"dodge" : 15,
                "parry" : 15,
		"damage_type": "擦伤"]);
	}
	me->set_temp("autopfm_lhs");
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int hurt, lvl = me->query_skill("lanhua-shou", 1);
        string name1,name2;
        object weapon = victim->query_temp("weapon");
       string msg;
       int j, k;
 int level;
       j = me->query_skill("yuxiao-jian", 1);
       k = me->query_skill("qimen-wuxing",1);
 level = (int) me->query_skill("bibo-shengong",1);
if (random(6)==0 && level>=300 && me->query_skill_mapped("force") == "bibo-shengong")
        {
if (victim->query("qi") > 600)
victim->add("qi",-250+random(200));
victim->add("eff_qi",-(50+random(200)));
                me->add("neili", -20);
if (!victim->is_busy()) victim->start_busy(1);
return HIR "$N施展开奇门五行,$n心神一乱,被打中$l。结果鲜血狂奔!!\n";
        }

	if (me->query_temp("autopfm_lhs")
	&& !me->is_busy()) {
		if (!random(3)) {
			if (!victim->is_busy())
			victim->start_busy(3) + random(3);
			me->add("neili", -40);
			hurt = (victim->query("neili") < lvl / 6 ? victim->query("neili") : lvl / 6);
			victim->add("neili", -hurt);
			victim->add("qi", -lvl / 5);
			victim->add("eff_qi", -lvl / 5);
			me->improve_skill("lanhua-shou", random(me->query("int")/4));
			me->delete_temp("autopfm_lhs");
			return HIR "$n被$N这招双手式同时拂中了数个穴道，只觉得全身巨痛，真气在经脉里四处乱窜,一时竟然无法控制！\n" NOR;
		}
		return 0;
	}
	if (victim->is_busy()) return 0;
	if (!random(7)) {
		victim->start_busy(3) + random(2);
		if (!random(4)
		&& !me->is_busy()) {
			me->add("neili", -20);
			hurt = (victim->query("neili") < lvl / 7 ? victim->query("neili") : lvl / 7);
			victim->add("neili", -hurt);
			victim->add("qi", -lvl / 8);
			victim->add("eff_qi", -lvl / 8);
			me->improve_skill("lanhua-shou", random(me->query("int")/5));
			return HIR "$n被$N拂中了穴道，只觉得一阵钻心的疼痛，真气不由得一滞！\n" NOR;
		}
		return CYN "$n被$N拂中了穴道，真气不由得一滞！\n" NOR;
	}
        if (random(lvl)>200
        && random(10)>5
        && !me->is_busy()) {

            switch (random(3)) {
               case 0: 
                    if (weapon){
                       weapon->unwield();
                       weapon->move(environment(victim));
                       victim->add("neili", -lvl);
                       return CYN "$n被落叶式拂中了「"HIR+name2+CYN"」，手一麻，"+weapon->query("name")+CYN"把持不住，掉在地上。\n" NOR; } else {
                       victim->add("neili", -lvl);
                       return CYN "$n被落叶式拂中了「"HIR+name2+CYN"」，手一麻，丹田也受到了振荡！\n" NOR; }
                    break;
               case 1: 
                    victim->add_temp("apply/dexerity",-lvl/10);
                    victim->add_temp("apply/strength",-lvl/10);
                    victim->add_temp("apply/constitution",-lvl/10);
                    victim->add_temp("apply/intelligence",-lvl/10);
                    call_out("remove_effect", lvl/10, victim, lvl/10);
                    return CYN "$n被舞蝶式连续拂中了任脉诸穴，战力大减！\n" NOR;
                    break;
               case 2: 
                    victim->start_busy(2 + random(2));
                    if (weapon) {
                        victim->map_skill(weapon->query("skill_type"));
                        victim->set_temp("no_enable",1); } else {
                        victim->prepare_skill("leg");
                        victim->prepare_skill("hand");
                        victim->prepare_skill("strike");
                        victim->prepare_skill("cuff");
                        victim->prepare_skill("claw");
                        victim->prepare_skill("unarmed");
                        victim->prepare_skill("sword");
                        victim->prepare_skill("blade");
                        victim->prepare_skill("parry");
                        victim->prepare_skill("finger");
                        victim->set_temp("no_prepare",1); }
                    call_out("remove_special", lvl/10, victim);
                    return CYN "$n被擒拿式拂中了「"HIR+name1+CYN"」，武功的特殊威力无法施展出来。\n" NOR;
                    break;
            }
        }
}
void remove_effect(object victim, int lvl)
{
        if (!victim) return;
        victim->add_temp("apply/dexerity",lvl);
        victim->add_temp("apply/strength",lvl);
        victim->add_temp("apply/constitution",lvl);
        victim->add_temp("apply/intelligence",lvl);
        message_vision(HIW"$N的任脉诸穴血脉行开了。\n"NOR, victim);
}

void remove_special(object victim)
{
        if (!victim) return;
        victim->delete_temp("no_enable");
        victim->delete_temp("no_prepare");
}

