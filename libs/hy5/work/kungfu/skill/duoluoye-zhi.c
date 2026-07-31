/* 
   duoluoye-zhi.c 多罗叶指
   和风云手(fengyun-shou)互备
   截自佛经中之“欲界诸天”。
   2/3/98 by snowman
*/

inherit SKILL;
 
mapping *action = ({
(["action" :"$N一式「四天王天」，连出四指，带起空中无限气劲，一道道地插向$n$l",
  "force" : 100,
  "dodge" : 25,
  "lvl" : 0,
  "weapon" : "气劲",
  "skill_name" : "四天王天",
  "damage_type" : "刺伤"
]),
(["action" :"$N面带笑容使出「仞利天」，，身形微侧，手指从袖底穿出，挟一股极利的劲力刺向$n",
  "force" : 150,
  "dodge" : 15,
  "lvl" : 20,
  "weapon" : "指力",
  "skill_name" : "仞利天",
  "damage_type" : "刺伤"
]),
(["action" :"$N一式「夜摩天」，左掌立刃大开大阖，右手飘忽灵动，忽然一指点出，刺向$n$l！",
  "force" : 200,
  "dodge" : 15,
  "lvl" : 40,
  "weapon" : "指风",
  "skill_name" : "夜摩天",
  "damage_type" : "刺伤"
]),
(["action" :"$N使出一招「兜率天」，左掌连劈，劲力罩住$n的身子，右手一挥，一指点向$n$l",
  "force" : 250,
  "dodge" : 10,
  "lvl" : 60,
  "weapon" : "指力",
  "skill_name" : "兜率天",
  "damage_type" : "刺伤"
]),
(["action" :"$N双手抱圆，内力运行，「化乐天」击出，一缕指风飞袭$n，看似无力，实是无坚不摧",
  "force" : 300,
  "dodge" : 5,
  "lvl" : 80,
  "weapon" : "指风",
  "skill_name" : "化乐天",
  "damage_type" : "刺伤"
]),
(["action" :"$N向$n连点数指，劲风更激起无数尖啸之声，这招「他化自在天」虚虚实实，防不胜防",
  "force" : 350,
  "dodge" : -5,
  "lvl" : 100,
  "weapon" : "指力",
  "skill_name" : "他化自在天",
  "damage_type" : "刺伤"
]),
});
 
int valid_enable(string usage) { return  usage=="finger" || usage=="parry"; }
 
int valid_combine(string combo){
        if(this_player()->query_skill("duoluoye-zhi", 1) > 100
	   && this_player()->query_int() > 20)
   	         return combo=="fengyun-shou";
}

 
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                 return notify_fail("练多罗叶指必须空手。\n");
        if ((int)me->query_skill("yijinjing", 1) < 140)
                 return notify_fail("你的易筋经内功火候不够，无法学多罗叶指。\n");
        if ((int)me->query("max_neili") < 2000)
		return notify_fail("你的内力太弱，无法练多罗叶指。\n");
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
        level   = (int) me->query_skill("duoluoye-zhi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
 
int practice_skill(object me)
{
        if ((int)me->query("jing") < 50)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练多罗叶指。\n");
        me->receive_damage("jing", 45);
        me->add("neili", -15);
        return 1;
}
 
string perform_action_file(string action)
{
        return __DIR__"duoluoye-zhi/" + action;
}



