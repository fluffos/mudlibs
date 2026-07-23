/* 
   boluomi-shou.c 波罗蜜手
   和摩诃指(mohe-zhi)互备
   截自佛经中之“六度”。
   2/3/98 by snowman
*/

inherit SKILL;
 
mapping *action = ({
(["action" :"$N双手合十做鞠，第一式「布施式」打出，内劲已逼得衣带翻飞，将$n层层笼罩",
  "force" : 100,
  "dodge" : 35,
  "lvl" : 0,
  "skill_name" : "布施式",
  "damage_type" : "内伤"
]),
(["action" :"$N右手伸出，上翻下压，左挥右劈，在$n眼前连连变幻，这招叫做「持戒式」，最是变化无穷",
  "force" : 150,
  "dodge" : 20,
  "lvl" : 10,
  "skill_name" : "持戒式",
  "damage_type" : "瘀伤"
]),
(["action" :"$N低头垂肩，使「忍辱式」这招，对眼前$n不闻不问，暗地里却聚力双手，伺机拍出",
  "force" : 200,
  "dodge" : 15,
  "lvl" : 20,
  "skill_name" : "忍辱式",
  "damage_type" : "瘀伤"
]),
(["action" :"$N得理不饶人，一招「精进式」，双臂晃动，打出片片掌影，一步步向$n进逼过去",
  "force" : 250,
  "dodge" : 10,
  "lvl" : 40,
  "skill_name" : "精进式",
  "damage_type" : "瘀伤"
]),
(["action" :"$N一式「禅定式」，单臂凌空悬垂，心中平静如水，一点点向着$n顶门压将下来",
  "force" : 300,
  "dodge" : 5,
  "lvl" : 80,
  "skill_name" : "禅定式",
  "damage_type" : "瘀伤"
]),
(["action" :"$N双臂挥动，幻出一莲花般手印，以「般若式」向$n推来，不紧不慢，却又凝重异常",
  "force" : 350,
  "dodge" : 5,
  "lvl" : 100,
  "skill_name" : "般若式",
  "damage_type" : "瘀伤"
]),
});
 
int valid_enable(string usage) { return  usage=="hand" || usage=="parry"; }
 
int valid_combine(string combo){
        if(this_player()->query_skill("boluomi-shou", 1) > 100
	   && this_player()->query_int() > 20)
   	         return combo=="mohe-zhi";
}

 
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                 return notify_fail("练波罗蜜手必须空手。\n");
        if ((int)me->query_skill("yijinjing", 1) < 140)
                 return notify_fail("你的易筋经内功火候不够，无法学波罗蜜手。\n");
        if ((int)me->query("max_neili") < 2000)
		return notify_fail("你的内力太弱，无法练波罗蜜手。\n");
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
        level   = (int) me->query_skill("boluomi-shou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
 
int practice_skill(object me)
{
        if ((int)me->query("jing") < 50)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练波罗蜜手。\n");
        me->receive_damage("jing", 45);
        me->add("neili", -15);
        return 1;
}
 
string perform_action_file(string action)
{
        return __DIR__"boluomi-shou/" + action;
}



