//【龙形搏击】dragonfight.c
// cglaem...12/19/96.
//meipai skill(only dragon related NPCs can use it)

inherit SKILL;
#include <ansi.h>;
#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});



string* skill_head =({
        "$N身形稍退，使出一招 赑屃驮碑",
        "$N不闪不避，一式 螭吻望月",
        "$N身形一幌，使出 饕餮吞天",
        "$N冲天一笑，一式 睚眦怒杀",
        "$N飞身跃起，使出 狴犴憎恶",
});
string* skill_tail =({
        "，双掌化为一道疾光刺向$n的$l。",
        "，双掌舞出满天拳影罩向$n。",
        "，双掌不偏一歪，直击向$n的$l。",
        "，双掌如飞，发出点点寒光。",
        "，双掌右肩急甩向后，陡地击向$n$l。",
});

mapping *action = ({
	([	"action":
"$N纵身跃起，一招「金猊吐火」，双掌以排山倒海之势击向$n的$l",
		"dodge":		10,
		"parry":		10,
		"force":		150,
		"damage":		350,			
		"damage_type":		"瘀伤",
		"weapon" :		"双掌",
		"parry_msg":	"只听见「锵」一声，被$N劈手格开",
	]),
	([	"action":
"$N似退反进，突然欺身向前，五指如钩，对准$n的$l一把抓了过去",
		"dodge":		10,
		"parry":		20,
		"force":		100,
		"damage":		350,	
		"damage_type":		"抓伤",
		"weapon":		"右手五指",
                "parry_msg":    "只听见「锵」一声，被$N劈手格开",
	]),
	([	"action":
"只见$N一旋身，双腿如铁棍一般扫向$n。这一招「趴蝮戏水」当真是防不胜防",
		"dodge":		10,
		"parry":		20,
		"force":		120,
		"damage":		350,				
		"damage_type":		"砸伤",
		"weapon":		"双腿",
                "parry_msg":    "只听见「锵」一声，被$N劈手格开",
	]),
	([	"action":
"$N忽发龙吟，使出一招「椒图守穴」，啸声中和身而上，向$n直撞而来",
		"dodge":		10,
		"parry":		10,
		"force":		100,
		"damage":		350,				
		"damage_type":		"撞伤",
		"weapon":		"全身",
                "parry_msg":    "只听见「锵」一声，被$N劈手格开",
	]),
            ([	"action":
"只见$N一个筋斗翻在半空，一招「龙腾四海」将发未发，但是全身劲气疾卷$n",
		"dodge":		0,
		"parry":		20,
		"force":		150,
		"damage":		350,				
		"damage_type":		"内伤",
		"weapon":		"劲气",
                "parry_msg":    "只听见「锵」一声，被$N劈手格开",
	]),
            ([	"action":
"$N身形一长，朝$n劈面就是一拳。这招「苍龙出海」势若奔雷，锐利无比",
		"dodge":		10,
		"parry":		30,
		"force":		180,
		"damage":		550,				
		"damage_type":		"瘀伤",
		"weapon":		"拳头",
                "parry_msg":    "只听见「锵」一声，被$N劈手格开",
	]),
});

int valid_learn(object me)
{
   if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");

    if( (string)me->query_skill_mapped("force")!= "jinghai-force")
     return notify_fail("必须靖海神功才能学。\n");



	if(me->query_skill("longjiao-blade", 1) < 150)
		return notify_fail("你的缚龙斩鲛刀为不够，无法修炼。\n");

	if(me->query_skill("bibo-sword", 1) < 150)
		return notify_fail("你的碧波神剑修为不够，无法修炼。\n");

	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练龙形博击必须空手。\n");
	return 1;
}

int valid_enable(string usage)
{
        return (usage=="unarmed") || (usage=="parry");
}
mapping query_action(object me, object weapon)
{
         int i, level, lvl;
         object target;
         mapping pre;
         string *skill, a, b;
         
         level   = (int) me->query_skill("dragonfight",1);
         lvl = (int)me->query_skill("dragonfight", 1);
         for(i = sizeof(action); i > 0; i--)
                 if(level >= action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level, jiali, time,level2,damage,damage2;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("jinghai-force",1);
damage= (int) me->query("neili",1)/10;
damage2=random(me->query_skill("dragonfight",1))+50;
if (damage > 1600) damage=1600;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "jinghai-force")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
	victim->receive_wound("qi", damage);
}
	return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("dragonfight",1)) > 150 ) 
{
	  victim->receive_wound("qi", damage2+120);
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}


}


int practice_skill(object me)
{
   if( (int)me->query("qi") < 100
   ||   (int)me->query("neili") < 30 )
     return notify_fail("你的内力或气不够。\n");

    if( (string)me->query_skill_mapped("force")!= "jinghai-force")
     return notify_fail("必须靖海神功才能学。\n");



	if(me->query_skill("longjiao-blade", 1) < 150)
		return notify_fail("你的缚龙斩鲛刀为不够，无法修炼。\n");

	if(me->query_skill("bibo-sword", 1) < 150)
		return notify_fail("你的碧波神剑修为不够，无法修炼。\n");
		
   me->receive_damage("qi", 32);
   me->add("neili", -16);

   return 1;
}

string perform_action_file(string action)
{
	return __DIR__"dragonfight/" + action;
}