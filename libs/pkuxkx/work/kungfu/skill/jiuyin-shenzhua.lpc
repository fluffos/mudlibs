#include <ansi.h>
inherit SKILL;
mapping *action = ({
([ "action" : HIW"$N势若疯虎，形若邪魔，双爪如钢抓铁钩，左手手腕翻处，右手疾伸，五根手指抓向$n$l"NOR,
   "force" : 150,
   "dodge" : 50,
   "lvl" : 0,
   "damage_type" : "抓伤"
]),
([ "action" : HIW"突然人影闪动，$N迫到$n身后，袖中伸出手，五根手指向$n$l插了下去"NOR,
   "force" : 200,
   "weapon" : "五指",
   "dodge" : 50,
   "lvl" : 10,
   "damage_type" : "刺伤"
]),
([ "action" : HIW"$N手臂关节喀喇一响，手臂斗然长了半尺，一掌按在$n$l，五指即要插进"NOR,
   "force" : 230,
   "weapon" : "手指",
   "dodge" : 50,
   "lvl" : 20,
   "damage_type" : "刺伤"
]),
([ "action" : HIW"$N双手微张，十根尖尖的指甲映出灰白光芒，突然翻腕出爪，五指猛地插落"NOR,
   "force" : 260,
   "weapon" : "手爪",
   "dodge" : 50,
   "lvl" : 30,
   "damage_type" : "刺伤"
]),
([ "action" : HIW"$N左手突然在$n眼前上围下钩，左旋右转，连变了七八般，蓦地里右手一伸，五根手指直插$n$l"NOR,
   "force" : 280,
   "weapon" : "五根手指",
   "dodge" : 50,
   "lvl" : 40,
   "damage_type" : "刺伤"
]),
([  "action" : HIW "$N左爪虚晃，右爪蓄力，一招" HIR "「勾魂夺魄」" HIW "直插向$n的$l" NOR,
    "force" : 300,
    "dodge" : 60,
    "lvl"   : 100,
    "skill_name" : "勾魂夺魄" ,
        "damage_type" : "抓伤"
]),
([  "action" : HIW "$N双手连环成爪，爪爪钩向$n，" HIR "「九子连环」" HIW "已向$n的$l抓出" NOR,
    "force" : 320,
    "dodge" : 70,
    "lvl"   : 120,
    "skill_name" : "九子连环" ,
        "damage_type" : "抓伤"
]),
([  "action" : HIW "$N身形围$n一转，使出" HIR "「天罗地网」" HIW "，$n的$l已完全笼罩在爪影下" NOR,
    "force" : 400,
    "dodge" : 50,
    "lvl"   : 140,
    "skill_name" : "天罗地网" ,
    "damage_type" : "抓伤"
]),
([  "action" : HIW "$N使一招" HIR "「风卷残云」" HIW "，双爪幻出满天爪影抓向$n全身" NOR,
    "force" : 450,
    "dodge" : 70,
    "lvl"   : 160,
    "skill_name" : "风卷残云" ,
    "damage_type" : "抓伤"
]),
([  "action" : HIW "$N吐气扬声，一招" HIR "「唯我独尊」" BLU "双爪奋力向$n天灵戳下" NOR,
    "force" : 500,
    "dodge" : 80,
    "lvl"   : 180,
    "skill_name" : "唯我独尊" ,
    "damage_type" : "抓伤"
]),
});

int valid_enable(string usage)
{ 
     return usage=="claw" || usage=="parry" ;
}

int valid_learn(object me)
{
       if( (int)me->query_skill("jiuyin-shenzhua", 1 ) < 140 )
               return notify_fail("你现在不能学习九阴神爪。\n");
       if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
               return notify_fail("练九阴神爪必须空手。\n");
       if ((int)me->query_skill("claw", 1) < 50)
               return notify_fail("你的基本爪功火候不够，无法学习。\n");
       if ((int)me->query_skill("jiuyin-zhengong", 1) < 50)
               return notify_fail("你的九阴真功火候不够，无法学习。\n");
       if ((int)me->query_skill("jiuyin-baiguzhua", 1) > 1)
               return notify_fail("你学了九阴白骨抓，无法学习九阴神爪。\n");
       if ((int)me->query_skill("daode-jing", 1) < 50)
               return notify_fail("你的道学心法火候不够，无法学习。\n");
       if ((int)me->query("max_neili") < 1000)
               return notify_fail("你的内力太弱，无法练九阴神爪。\n");
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
    level   = (int) me->query_skill("jiuyin-shenzhua",1);
    for(i = sizeof(action); i > 0; i--)
        if(level >= action[i-1]["lvl"])
            return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
       if( (int)me->query_skill("jiuyin-shenzhua", 1 ) < 120 )
               return notify_fail("你现在不能练习九阴神爪。\n");
       if ((int)me->query("jingli") < 40)
               return notify_fail("你的体力太低了。\n");
       if ((int)me->query("neili") < 50)
               return notify_fail("你的内力不够练九阴神爪。\n");
       me->receive_damage("jingli", 30);
       me->add("neili", -(10 + random((int)me->query_skill("jiuyin-shenzhua", 1 )/10+1)));
       return 1;
}

string perform_action_file(string action)
{
        return __DIR__"jiuyin-shenzhua/" + action;
}

int hit_ob(object me, object ob, int damage)
{
        message_vision(HIR"$N身上登时出现数条血痕！\n"NOR,ob);
        ob->receive_wound("qi", random(damage / 15), me);
        return 0;
}

