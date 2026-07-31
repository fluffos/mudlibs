inherit SKILL;
#include <ansi.h>;

mapping *action = ({
   ([   "action":
"$N手中$w向$n的$l直劈过来。",
     "dodge":     1000,
     "parry":                300,
     "damage":     200,
     "damage_type":   "刺伤"
   ]),
   ([   "action":
"$N手中$w向$n的$l斜劈过来。",
     "dodge":     1000,
     "parry":                300,
     "damage":     200,
     "damage_type":   "割伤"
   ]),
   ([   "action":
"$N手中的$w划了一个三角，向$n的$l刺了过去。",
     "dodge":     1000,
     "parry":                300,
     "damage":     200,
     "damage_type":   "刺伤"
   ]),
   ([   "action":
"$N手中的$w划了个大圆，向$n的$l刺了过去。",
     "dodge":     1000,
     "parry":                300,
     "damage":     200,
     "damage_type":   "刺伤"
   ]),
   ([   "action":
"$N手中的$w对着$n的$l旋了过去。",
     "dodge":     1000,
     "parry":                300,
     "damage":     200,
     "damage_type":   "刺伤"
   ]),
});

int valid_learn(object me)
{
   object ob;

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
        int i, level;
        if (!me) me = this_object();
        level   = (int) me->query_skill("westsword",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
        {
   if( (int)me->query("kee") < 30
   ||   (int)me->query("force") < 3 )
     return notify_fail("你的内力或气不够，没有办法练习西洋剑法。\n");
   me->receive_damage("kee", 30);
   me->add("force", -3);
   //write("你按著所学练了一遍西洋剑法。\n");
   return 1;
}


mixed hit_ob(object me, object victim,int damage_bonus)
        
{	
        if( damage_bonus > 100 ) 
{
        victim->receive_wound("qi", damage_bonus );
        return HIR "光速拳!!一阵拳影！！！一股鲜血从$n的身子喷出\n" NOR;	
}
        if( damage_bonus < 75 ) 
{
        victim->receive_wound("qi", damage_bonus );	
        return YEL "光速拳!!一阵拳影！！！$n闷哼一声,身子晃了两晃！\n" NOR;
}
else
{       
        victim->receive_wound("qi", damage_bonus );	
        return HIM "光速拳!!一阵拳影！！！你听到「嗤啦」一声轻响，脸上竟溅到一些血滴！\n" NOR;
}

}
