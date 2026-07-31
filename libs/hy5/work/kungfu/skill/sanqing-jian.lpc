
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

// sanqing-jian.c【三清剑法】
//for 道士 NPCs, if going to be used by players, need refine. 

/*
三清剑法    dodge  -5    parry  15    damage  20
道家功夫，轻灵飘逸，不沾凡尘之气。但唯其太过讲究
而不太实用。
*/

inherit SKILL;
#include <ansi.h>;
#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

string* skill_head =({
        "$N身形稍退，",
        "$N仰天长笑，看也不看，",
        "$N轻轻一跃，",
        "$N神态悠闲，",
        "$N身形转个不停，突然 ",
        "$N脚下踏了个七星步，",
        "$N脚下踏了个八卦步，",        
        "$N脚下踏了个两仪步，",                
        "$N脚下踏了个四向步，",                        
});

string* skill_tail =({
        " 手中$w势若飞瀑向$n拦腰一斩。",
        " 手中$w对准$n的$l凌空一斩。",
        " 反手将$w对准$n$l一剑刺去。",
        " 手中$w轻妙地划向$n的$l。",
        " 反手对准$n$l一剑刺去。",
        " 趁$n转身之际，挥出一剑。",
        " 手中$w化为一道无力月光刺向$n的$l。",
        " 手中$w舞出满天剑影罩向$n。",
        " 手中$w不偏一歪，直封$n的$l。",
        " 手中$w如飞，发出点点月光。",
        " $w从右肩急甩向后，撒出点点微光击向$n$l。",
});



mapping *action = ({
   ([   "action":     "$N使出一招"+BLINK""+HIR"「星河影动」"NOR+"，剑光闪烁不定，若有若无地刺向$n$l",
     "dodge":     0,
     "parry":     15,
     "damage":     335,
     "damage_type":   "刺伤"
   ]),
   ([   "action":     "$N身形转个不停，突然一招"+BLINK""+HIY"「一点灵犀」"NOR+"使出，手中$w划出一道银弧，径刺$n$l",
     "dodge":     10,
     "parry":     15,
     "damage":     345,
     "damage_type":   "刺伤"
   ]),
   ([   "action":     "$N脚下踏了个七星步，一招"+BLINK""+HIM"「古道西风」"NOR+"手中$w势若飞瀑向$n拦腰一斩",
     "dodge":     15,
     "parry":     15,
     "damage":     340,
     "damage_type":   "劈伤"
   ]),
   ([   "action":     "但见$N连退几步，忽然间纵身跃起，手中$w一式"+BLINK""+HIW"「沧海月明」"NOR+"对准$n的$l凌空一斩",
     "dodge":     15,
     "parry":     5,
     "damage":     350,
     "damage_type":   "劈伤"
   ]),
   ([   "action":     "$N轻轻一跃，使了个"+BLINK""+HIB"「乘风归去」"NOR+"，却在转身之际对准$n$l斜斜挥出一剑",
     "dodge":    35,
     "parry":     25,
     "damage":     335,
     "damage_type":   "刺伤"
   ]),
   ([   "action":     "$N神态悠闲，手中$w凭空一指，一招"+BLINK""+HIC"「白云千载」"NOR+"轻妙地划向$n的$l",
     "dodge":     10,
     "parry":     10,
     "damage":     440,
     "damage_type":   "刺伤"
   ]),
   ([   "action":     "$N手中$w向外一分，使一招"+BLINK""+HIG"「曲径通幽」"NOR+"反手对准$n$l一剑刺去",
     "dodge":     30,
     "parry":     20,
     "damage":     435,
     "damage_type":   "刺伤"
   ]),
});

int valid_learn(object me)
{
   object ob;

   if( (int)me->query("max_neili") < 50 )
     return notify_fail("你的内力不够，没有办法练三清剑法。\n");

     if( (string)me->query_skill_mapped("force")!= "kongdong-xinfa")
     return notify_fail("必须崆峒心法才能学。\n");

if ((int)me->query_skill("kongling-jian", 1) < 200)
		 return notify_fail("你的空灵剑火候不够，无法学。\n");

if ((int)me->query_skill("qishang-cuff", 1) < 200)
		 return notify_fail("你的七伤魔拳火候不够，无法学手。\n");


if( (int)me->query_skill("shizi-zhan",1) < 200 )
		return notify_fail("你的十字战不够。\n");

	if( (int)me->query_skill("luofeng",1) < 200 )
		return notify_fail("你的落风六式不够。\n");

	if( (int)me->query_skill("kongling-jian",1) < 200 )
		return notify_fail("你的空灵剑法不够。\n");


   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "sword" )
     return notify_fail("你必须先找一把剑才能练剑法。\n");

   return 1;
}

int valid_enable(string usage)
{
   return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
         int i, level, lvl;
         object target;
         mapping pre;
         string *skill, a, b;
         
         level   = (int) me->query_skill("sanqing-jian",1);
         lvl = (int)me->query_skill("sanqing-jian", 1);
         for(i = sizeof(action); i > 0; i--)
                 if(level >= action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level, jiali, time,level2,damage,damage2;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("sword",1);
        level2= (int) me->query_skill("kongdong-xinfa",1);
damage= (int) me->query("neili",1)/10;
damage2=random(me->query_skill("sanqing-jian",1))+50;
if (damage > 1600) damage=1600;
if (me->is_busy()) return;
if (random(9)==0 && level2>=300 && me->query_skill_mapped("force") == "kongdong-xinfa")
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
	victim->receive_wound("qi", damage);
}
	return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("sanqing-jian",1)) > 150 ) 
{
	  victim->receive_wound("qi", damage2+120);
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
}

int practice_skill(object me)
{
   if( (int)me->query("qi") < 100
   ||   (int)me->query("neili") < 30 )
     return notify_fail("你的内力或气不够，没有办法练习三清剑法。\n");

    if( (string)me->query_skill_mapped("force")!= "kongdong-xinfa")
     return notify_fail("必须崆峒心法才能学。\n");

if ((int)me->query_skill("kongling-jian", 1) < 200)
		 return notify_fail("你的空灵剑火候不够，无法学。\n");

if ((int)me->query_skill("qishang-cuff", 1) < 200)
		 return notify_fail("你的七伤魔拳火候不够，无法学手。\n");


if( (int)me->query_skill("shizi-zhan",1) < 200 )
		return notify_fail("你的十字战不够。\n");

	if( (int)me->query_skill("luofeng",1) < 200 )
		return notify_fail("你的落风六式不够。\n");

	if( (int)me->query_skill("kongling-jian",1) < 200 )
		return notify_fail("你的空灵剑法不够。\n");
		
   me->receive_damage("qi", 32);
   me->add("neili", -6);
//   write("你按着所学练了一遍三清剑法。\n");
   return 1;
}
string perform_action_file(string action)
{
	return __DIR__"sanqing-jian/" + action;
}



 
