// zimu-zhen.c 子母针法

#include <ansi.h>
inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *action = ({
([	"action":		"$N双手连环挥舞，一招"+(order[random(13)])+"「穿心针」"NOR"，$w直奔$n的胸腹要害",
	"dodge":		10,
        "force":		200,
	"damage":		200,
	"poison": 30,
	"lvl" : 0,
	"skill_name" : "穿心针",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"刺伤"
]),
([	"action":		"$N身形晃动，一招"+(order[random(13)])+"「破气针」"NOR"，手中$w如一串银线，往$n咽喉打去",
	"dodge":		20,
	"force":		200,
	"damage":		300,
	"poison": 40,
	"lvl" : 60,
	"skill_name" : "破气针",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"刺伤"
]),
([	"action":		"$N五指微张，一招"+(order[random(13)])+"「吸血针」"NOR"，手中$w飞蚊般往$n全身叮去",
	"dodge":		40,
	"force":		200,
	"damage":		400,
	"poison": 50,
 	"lvl" : 90,
	"skill_name" : "吸血针",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"刺伤"
]),
([	"action":		"$N大喝一声，一招"+(order[random(13)])+"「摄魂针」"NOR"，$w幻化出夺目光亮，打向$n",
	"dodge":		50,
	"force":		200,
	"damage":		500,
	"poison": 60,
	"lvl" : 100,
	"skill_name" : "摄魂针",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"刺伤"
]),
([	"action":		"$N错步一跃，一招"+(order[random(13)])+"「夺魄针」"NOR"，$w带着阵阵阴风，打向$n全身",
	"dodge":		60,
	"force":		200,
	"damage":		600,
	"poison": 70,
 	"lvl" : 110,
	"skill_name" : "夺魄针",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"刺伤"
]),
([	"action":		"$N双目精芒闪动，一招"+(order[random(13)])+"「离别针」"NOR"，手中$w全数脱手飞出，排山倒海般打向$n全身",
	"dodge":		50,
	"force":		200,
	"damage":		700,
	"poison": 80,
	"lvl" : 120,
	"skill_name":  "离别针",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"刺伤"
]),
([	"action":		"$N纵声长啸，一招"+(order[random(13)])+"「天魔针」"NOR"，$w竟然带着一股强烈劲风，扫向$n",
	"dodge":		70,
	"force":		200,
	"damage":		800,
	"poison": 90,
	"lvl" : 130,
	"skill_name" : "天魔针",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"刺伤"
]),
([	"action":		"$N眼中杀气突然大盛，一招"+(order[random(13)])+"「地煞针」"NOR"，$w飞蝗般打向$n全身",
	"dodge":		100,
        "force":		200,
	"damage":		900,
	"poison": 100,
	"lvl" : 200,
	"skill_name" : "地煞针",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"刺伤"
]),
});

int valid_enable(string usage) { return (usage == "throwing") || (usage == "parry"); }

int valid_learn(object me)
{
	object weapon;

	if( (int)me->query("max_neili") < 500 )
		return notify_fail("你的内力够练子母连环针, 再多练练吧。\n");

	if ((int)me->query_skill("biyun-xinfa", 1) < 100)
		return notify_fail("你的碧云心法火候太浅。\n");
	if ((int)me->query_skill("pili-biao", 1) < 200)
		return notify_fail("你的碧云心法火候太浅。\n");
	if ((int)me->query_skill("liuxing-dao", 1) < 200)
		return notify_fail("你的流星赶月刀火候太浅。\n");
	if ((int)me->query_skill("zhuihun-biao", 1) < 200)
		return notify_fail("你的追魂夺命镖火候太浅。\n");


	if ( !objectp(weapon = me->query_temp("weapon"))
	|| ( string)weapon->query("skill_type") != "throwing" )
		return notify_fail("你手上并没有暗器，怎么练？\n");

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
	level   = (int) me->query_skill("zimu-zhen",1);
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
	if ((int)me->query_skill("pili-biao", 1) < 200)
		return notify_fail("你的霹雳镖火候太浅。\n");
	if ((int)me->query_skill("liuxing-biao", 1) < 200)
		return notify_fail("你的流星赶月镖火候太浅。\n");
	if ((int)me->query_skill("zhuihun-biao", 1) < 200)
		return notify_fail("你的追魂夺命镖火候太浅。\n");

	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练子母针法。\n");
	me->receive_damage("qi", 5);
	return 1;
}

string perform_action_file(string action)
{
	if ( this_player()->query_skill("zimu-zhen", 1) >= 50 )
		return __DIR__"zimu-zhen/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{
	int level, jiali, time,level2;
	object weapon;
	weapon = me->query_temp("weapon");
             
        if(weapon->query("name")=="子母飞针" && weapon->query("id")=="zimuzhen" && me->query_temp("marks/子母针")         ){
          victim->apply_condition("zm_poison", random(me->query_skill("zimu-zhen")) + 10 +
	  victim->query_condition("zm_poison"));
	}
        level = (int) me->query_skill("biyun-xinfa",1);
        level2= (int) me->query_skill("zimu-zhen",1);
	jiali = me->query("jiali");
if (!me) return;
if (!victim) return;
if (!weapon) return;
//if (!level) return;
if (!level2) return;
if (!jiali) jiali=10;
	if( damage_bonus > 100 && random(level2)>150 && random(3)==0) {
	victim->receive_wound("qi", (random(jiali)+100));
	return HIB"$n只觉$l上一阵麻痒，伤口尽流出了碧绿色的血!\n"NOR;
        }
}

int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
        limbs = ob->query("limbs");
        level = me->query_skill("zimu-zhen", 1);

        if( me->is_busy()) return 1;
        if( damage < 100 ) return 1;
        if (  random(level) > 180
         && me->query_skill_mapped("throwing") =="zimu-zhen"
         && me->query_skill_mapped("parry") =="zimu-zhen"
         && weapon
         && weapon->query("skill_type") == "throwing"
         && me->query_skill("throwing") > 300
         && random(me->query_skill("throwing",1)) > 150
         && !me->is_busy()
         && me->query("neili") > 200 
         && me->query("max_neili") > 900
         && random(me->query_int()) >= 20 ){
            me->add("neili", -100);
            msg = HIB"$n刚出玩招后，觉得身上的伤口一阵麻痒！难受的在地上打起了滚。\n"NOR;
            ob->add("neili",-ob->query("neili")/15);
            if ( random(2) == 1){
             if (!ob->is_busy())
             ob->start_busy(2+random(2));
}
else             msg = HIG"$n刚出玩招后，觉得身上的伤口一阵麻痒！但$n咬了咬牙关挺了过去。\n"NOR;
            message_vision(msg, me, ob);
            return damage;
        }
}
