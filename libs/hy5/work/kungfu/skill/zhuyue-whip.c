//逐月鞭法 by cigar 2002.01
inherit SKILL;
#include <ansi.h>;
#include "/kungfu/skill/eff_msg.h";
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});


string* skill_head =({
        "$N身形稍退，使出一招 逐月",
        "$N不闪不避，一式 遮月",
        "$N身形一幌，使出 月纹",
        "$N妍然一笑，一式 风花雪月",
        "$N飞身跃起，使出 圆月",
});
string* skill_tail =({
        "，手中$w化为一道无力月光刺向$n的$l。",
        "，手中$w舞出满天鞭影罩向$n。",
        "，手中$w不偏一歪，直封$n的$l。",
        "，手中$w如飞，发出点点月光。",
        "，$w从右肩急甩向后，撒出点点微光击向$n$l。",
});

mapping *action = ({
   ([   "action":
"$n只觉眼前一闪，似乎见到$N身形一幌，但随即又见$N回到原地，却似从未离开，一招"+BLINK""+HIM"「月无痕」"NOR"已悄然划向$n的后心",
     "dodge":     15,
                "parry":                10,
     "damage":     340,
     "damage_type":   "刺伤"
   ]),
   ([   "action":
"飞身跃起，$n抬眼一望，月光失色，但见得$N手中$w舞出满天鞭影，"+BLINK""+HIC"[遮月]"NOR"已将$n笼罩",
     "dodge":     15,
                "parry":                25,
     "damage":     340,
     "damage_type":   "割伤"
   ]),
   ([   "action":
"$N手中$w轻轻一抖，手中$w如幽灵一般,一式"+BLINK""+HIB"[月纹]"NOR"无形的飘向$n的左肋",
     "dodge":     10,
                "parry":                15,
     "damage":     335,
     "damage_type":   "刺伤"
   ]),
   ([   "action":
"$N手中的$w犹似一条柔丝，竟如没半分重量，月光化成片片雪花，在$n身周飘荡不定，正是一招"+BLINK""+HIW"[风花雪月]"NOR"",
     "dodge":     10,
                "parry":                15,
     "damage":     350,
     "damage_type":   "刺伤"
   ]),
   ([   "action":
"突然之间月光失色，$N身形拖出一道道绿光，使出一招"+BLINK""+HIG"「逐月」"NOR"，$w从上空急甩向后，陡地击向$n$l，正如洒洒月光，无处不及",
     "dodge":     20,
                "parry":                10,
     "damage":     455,
     "damage_type":   "刺伤"
   ]),
});

int valid_learn(object me)
{
   object ob;

   if( (int)me->query("max_neili") < 50 )
     return notify_fail("你的内力不够，没有办法练逐月鞭法。\n");

        if ((int)me->query_skill("bitao-shengong", 1) < 220)
                return notify_fail("你的「碧涛心法」火候太浅。\n");

        if ((int)me->query_skill("yubi-jian", 1) < 220)
                return notify_fail("你的「玉壁月华明剑法」火候太浅。\n");


   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "whip" )
     return notify_fail("你必须先找一把鞭子才能练鞭法。\n");

   return 1;
}

int valid_enable(string usage)
{
   return usage=="whip" || usage=="parry";
}


mapping query_action(object me, object weapon)
{
         int i, level, lvl;
         object target;
         mapping pre;
         string *skill, a, b;
         
         level   = (int) me->query_skill("zhuyue-whip",1);
         lvl = (int)me->query_skill("zhuyue-whip", 1);
         for(i = sizeof(action); i > 0; i--)
                 if(level >= action[i-1]["lvl"])
                         return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
   if( (int)me->query("qi") < 30
   ||   (int)me->query("neili") < 3 )
     return notify_fail("你的内力或气不够，没有办法练习逐月鞭法。\n");
   me->receive_damage("qi", 25);
   me->add("neili", -3);
   //write("你按着所学练了一遍逐月鞭法。\n");
   return 1;
}

string perform_action_file(string action)
{
	return __DIR__"zhuyue-whip/" + action;
}




mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level, jiali, time,level2,damage,damage2;
	object weapon;
	weapon = me->query_temp("weapon");
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("bitao-shengong",1);
damage= (int) me->query("neili",1)/10;
damage2=random(me->query_skill("zhuyue-whip",1))+50;
if (damage > 1600) damage=1600;
if (me->is_busy()) return;
if (random(9)==0 && level2>=300 && me->query_skill_mapped("force") == "bitao-shengong" )
{
if (victim->query("qi")>= damage )
{
victim->receive_damage("qi", damage);
	victim->receive_wound("qi", damage);
}
		return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;

}
if (damage_bonus <80) damage_bonus=80;
      if( random(me->query_skill("zhuyue-whip",1)) > 150 ) 
{
	  victim->receive_wound("qi", damage2+120);
        return order[random(13)]+skill_head[random(sizeof(skill_head))]+skill_tail[random(sizeof(skill_tail))]+"\n"NOR;
}
}
