// pili-biao.c 霹雳镖

#include <ansi.h>
inherit SKILL;
string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"qx_snake_poison",
"anqi_poison",
"yf_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"tmzhuihun_poison",
"tmpili_poison",
"zm_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


mapping *action = ({
([      "action" : "$N手中$w脱手而出,使出一招"+(order[random(13)])+"「火龙飞腾」"NOR"，打向$n的$l  ",
        "skill_name" : "火龙飞腾",
        "force" : 100,
        "dodge" : 25,
        "parry" : 5,
        "lvl" : 0,
        "damage" : 120,
        "damage_type" : "刺伤",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :)

]),
([      "action" : "$N身体一侧，使一招"+(order[random(13)])+"「火树银花」"NOR"，手中$w弹向$n的大腿  ",
        "skill_name" : "火树银花",
        "force" : 140,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 8,
        "damage" : 140,
        "damage_type" : "刺伤",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :)
]),
([      "action" : "$N腾空而起，使出"+(order[random(13)])+"「霹雳天降」"NOR"，手中$w飞快地射向$n的$l  ",
        "skill_name" : "霹雳天降",
        "force" : 180,
        "dodge" : 10,
        "parry" : 5,
        "lvl" : 16,
        "damage" : 160,
        "damage_type" : "刺伤",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :)
]),
([      "action" : "$N使出一招"+(order[random(13)])+"「火如雨下」"NOR"，$w如暴雨般扑向$n  ",
        "skill_name" : "火如雨下",
        "force" : 220,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 24,
        "damage" : 180,
        "damage_type" : "刺伤",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :)
]),
});

int valid_enable(string usage) { return (usage == "throwing") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 400)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("biyun-xinfa", 1) < 80)
		return notify_fail("你的碧云心法火候太浅。\n");
	if ((int)me->query_skill("biye-wu", 1) < 30)
		return notify_fail("你的碧叶随风舞火候太浅。\n");
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
	level   = (int) me->query_skill("pili-biao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("你使用的武器不对。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够，练不了霹雳镖。\n");
	me->receive_damage("qi", 30);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	        int lvl;
        int flvl;
	int level, jiali, time,level2,damage,damage2;
	object weapon;
object target;

        level = (int) me->query_skill("biyun-xinfa",1);
        level2= (int) me->query_skill("biyun-xinfa",1);

damage2= (int) victim->query("neili",1)/8;
if (damage2>= 3800) damage2 = 3800;
	
if (random(8)==0 && level>=300 && me->query_skill_mapped("force") == "biyun-xinfa")
{
            victim->receive_damage("qi",20);
            victim->receive_wound("qi",15 + random(10));
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
            victim->apply_condition(du[random(sizeof(du))], 25);
if (!victim->is_busy()) victim->start_busy(2);	
 return HIR "$N突然收掌，然后迅速发掌! 掌中尽然有毒砂，这掌风尽然是五颜六色的！$n硬起头皮，以掌硬接！！结果身中巨毒！!\n";
}	
	
	weapon=me->query_temp("weapon");
              
        if(weapon &&
        (string)weapon->query("skill_type") == "throwing"){
          victim->apply_condition("tmpili_poison", random(me->query_skill("pili-biao")) + 50 +
	  victim->query_condition("tmpili_poison"));
	}
}


string perform_action_file(string action)
{
		return __DIR__"pili-biao/" + action;
}

int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("pili-biao", 1);

        if( me->is_busy()) return 1;
        if( damage < 50 ) return 1;
        if (  level > 100
        && random(5)==1)
        {

            msg = HIC"$n出招时，突然所用的内力随着伤口流出!\n"NOR;
            ob->add("neili",-level/2);
            me->add("neili",level/2);
            if ( random(2) == 1){
             if (!ob->is_busy())
             ob->start_busy(2+random(2));
}
}
}