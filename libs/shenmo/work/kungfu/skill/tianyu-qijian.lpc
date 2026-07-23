// tianyu-qijian.c 天羽奇剑
#include <ansi.h>

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([	"action":"$N使一式"+(order[random(13)])+"「海天一线」"NOR"，手中$w嗡嗡微振，幻成一条疾光刺向$n的$l",
	"force" : 120,
        "dodge" : 110,
	"damage": 240,
	"lvl" : 0,
	"skill_name" : "海天一线",
	"damage_type":	"割伤"
]),
([	"action":"$N错步上前，使出"+(order[random(13)])+"「闪电惊虹」"NOR"，手中$w划出一道剑光劈向$n的$l",
	"force" : 140,
            "dodge" : 110,
	"damage": 240,
	"lvl" : 9,
	"skill_name" : "闪电惊虹",
	"damage_type":	"割伤"
]),
([	"action":"$N手中$w一抖，一招"+(order[random(13)])+"「日在九天」"NOR"，斜斜一剑反腕撩出，攻向$n的$l",
	"force" : 160,
           "dodge" : 115,
	"damage": 250,
	"lvl" : 18,
	"skill_name" : "日在九天",
	"damage_type":	"割伤"
]),
([	"action":"$N手中剑锵啷啷长吟一声，一式"+(order[random(13)])+"「咫尺天涯」"NOR"，一道剑光飞向$n的$l",
	"force" : 180,
            "dodge" : 110,
	"damage": 260,
	"lvl" : 27,
	"skill_name" : "咫尺天涯",
	"damage_type":	"刺伤"
]),
([	"action":"$N一式"+(order[random(13)])+"「怒剑狂花」"NOR"，手中$w舞出无数剑花，使$n难断虚实，无可躲避",
	"force" : 220,
            "dodge" : 151,
	"damage": 280,
	"lvl" : 36,
	"skill_name" : "怒剑狂花",
	"damage_type":	"刺伤"
]),
([	"action":"$N手中$w斜指苍天，剑芒吞吐，一式"+(order[random(13)])+"「九弧震日」"NOR"，对准$n的$l斜斜击出",
	"force" : 260,
            "dodge" : 115,
	"damage": 200,
	"lvl" : 44,
	"skill_name" : "九弧震日",
	"damage_type":	"刺伤"
]),
([	"action":"$N一式"+(order[random(13)])+"「漫天风雪」"NOR"，手腕急抖，挥洒出万点金光，刺向$n的$l",
	"force" : 320,
            "dodge" : 115,
	"damage": 255,
	"lvl" : 52,
	"skill_name" : "漫天风雪",
	"damage_type":	"刺伤"
]),
([	"action":"$N一式"+(order[random(13)])+"「天河倒泻」"NOR"，$w飞斩盘旋，如疾电般射向$n的胸口",
	"force" : 380,
            "dodge" : 115,
	"damage": 300,
	"lvl" : 60,
	"skill_name" : "天河倒泻",
	"damage_type":	"刺伤"
]),
([	"action":"$N一式"+(order[random(13)])+"「天外飞虹」"NOR"，$w突然从天而降，一片金光围掠$n全身",
	"force" : 380,
            "dodge" : 115,
	"damage": 350,
	"lvl" : 60,
	"skill_name" : "天外飞虹",
	"damage_type":	"刺伤"
])
});
string *hit_msg = ({ 
        HIY"\n$N前招将落，后招已至，前后两招形如一式，此起彼伏，连绵不绝！\n"NOR,
        HIC"\n对方正惊愕间，却见$N的剑光已闪至眼前，剑光闪处寒气四射，咄咄逼人！\n"NOR,
        HIR"\n只见$N人影一闪，身形已然欺近对方，手中剑光闪烁，嗡嗡做响！\n"NOR,
        HIM"\n却见$N一剑未定二剑已至，随有前后之分却同时到达，速度之快晃如两剑同时发出！\n"NOR,
        HIG"\n不见$N手臂动作，只听一声龙吟之生，这第二剑已破空而至，刺至身前！\n"NOR,
        HIB"\n紧跟着，$N又是一剑刺至，剑招虽分前后，但剑锋几乎同时到达，速度之快难以言表！\n"NOR,
        HIW"\n一眨眼间$N的身形已欺至身前，若有若无，这第二剑已于电光火石间刺至身前！\n"NOR,
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的内力不够。\n");

        if ((int)me->query_skill("qingyun-shou", 1) < 80)
		return notify_fail("你的青云手火候太浅。\n");
        if ((int)me->query_skill("panyang-zhang", 1) < 80)
		return notify_fail("你的攀阳掌火候太浅。\n");
        if ((int)me->query_skill("liuyue-jian", 1) < 80)
		return notify_fail("你的流月剑舞火候太浅。\n");


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
	level   = (int) me->query_skill("tianyu-qijian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练天羽奇剑。\n");
       if ((int)me->query_skill("qingyun-shou", 1) < 80)
		return notify_fail("你的青云手火候太浅。\n");
        if ((int)me->query_skill("panyang-zhang", 1) < 80)
		return notify_fail("你的攀阳掌火候太浅。\n");
        if ((int)me->query_skill("liuyue-jian", 1) < 80)
		return notify_fail("你的流月剑舞火候太浅。\n");
	me->receive_damage("qi", 45);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"tianyu-qijian/" + action;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int lvl;
        int flvl;
       object weapon;
        string amsgs;

        weapon = me->query_temp("weapon");
        lvl  = me->query_skill("tianyu-qijian", 1);
        flvl = me->query("jiali");

        if ( me->query_temp("09_pfm/zhu")
             && me->query_temp("09_pfm/zhu") > 0
             && weapon
             && weapon->query("skill_type") == "sword"
             && !me->query_temp("09_pfm/zhu_hit_done") )
        {
                amsgs = hit_msg[random(sizeof(hit_msg))];
                me->add("neili", -40);
                me->add_temp("09_pfm/zhu", -1);
                message_vision(amsgs, me);
                me->set_temp("09_pfm/zhu_hit_done", 1);
                if (random(3)==0) victim->start_busy(2);
                COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1);
                COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1); 
                COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), 1); 
                me->delete_temp("09_pfm/zhu_hit_done");
        }

if (me->query_skill_mapped("force") != "bahuang-gong" &&
me->query_skill_mapped("force") != "beiming-shengong")
                return;
        if (lvl < 80 || ! damage_bonus ||
            me->query("neili") < 300)
                return;
flvl=random(lvl)+50;
        if (random(6)==0)
        {
if (victim->query("qi") > flvl)
{
victim->add("qi",-flvl);
victim->add("eff_qi",-flvl);
victim->apply_condition("ss_poison", 10 +
		victim->query_condition("ss_poison"));
}
                return HIW "$n" HIW "身上中了几道生死符!!\n" NOR;
        }

        else if (random(5)==0)
        {
flvl=random(lvl)+50;
        if (random(5)==0)
        {
if (victim->query("qi") > flvl)
{
victim->add("qi",-flvl);
victim->add("eff_qi",-flvl);
}
                return HIR "$n" HIR "被一剑刺中要害，鲜血飞出!!\n" NOR;

}                        }
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