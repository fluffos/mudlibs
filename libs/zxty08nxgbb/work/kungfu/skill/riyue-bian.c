#include <ansi.h>
inherit SKILL;
string type() { return "zhongji"; }
int tydamage = this_player()->query("tydamage/bian")?this_player()->query("tydamage/bian"):this_player()->query_skill("riyue-bian");

mapping *action = ({
([  "action":       "$N端坐不动，一招「"+RED+"裂石式"+NOR+"」，手中$w抖得笔直，对准$n的胸腹要害连刺数鞭",
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
   "lvl" : 30,
    "skill_name" : RED "裂石式" NOR,
    "damage_type":  "刺伤"
]),
([  "action":       "$N身形一转，一招「"+RED+"断川式"+NOR+"」，手中$w如矫龙般腾空一卷，猛地向$n劈头打下",
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
    "lvl" : 36,
    "skill_name" : RED "断川式" NOR,
    "damage_type":  "刺伤"
]), 
([  "action":       "$N力贯鞭梢，一招「"+HIW+"破云式"+NOR+"」，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
    "lvl" : 589,
    "skill_name" : HIW "破云式" NOR,
    "damage_type":  "刺伤"
]),
([  "action":       "$N力贯鞭梢，一招「"+HIW+"分海式"+NOR+"」，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
    "lvl" : 512,
    "skill_name" : HIW "分海式" NOR,
    "damage_type":  "刺伤"
]),
([  "action":       "$N力贯鞭梢，一招「"+BLU+"裂空式"+NOR+"」，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
    "lvl" : 535,
    "skill_name" : BLU "裂空式" NOR,
    "damage_type":  "刺伤"
]), 
([  "action":HIW       "$N力贯鞭梢，一招「"+BLU+"佛光普照"+HIW+"」，手中$w"HIW"舞出满天鞭影，排山倒海般扫向$n全身"NOR, 
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
      "lvl" : 1050,
    "skill_name":  BLU "佛光普照" NOR,
    "damage_type":  "挫伤"
]),
([  "action":HIR       "$N力贯鞭梢，一招「"+YEL+"金刚伏魔"+HIR+"」，手中$w"HIR"舞出满天鞭影，排山倒海般扫向$n全身"NOR, 
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
      "lvl" : 1050,
    "skill_name" : YEL "金刚伏魔" NOR,
     "damage_type":  "挫伤"
]),
([  "action":HIC       "$N力贯鞭梢，一招「"+HIR+"佛法无边"+HIC+"」，手中$w"HIC"舞出满天鞭影，排山倒海般扫向$n全身"NOR , 
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
      "lvl" : 1050,
    "skill_name" : HIR "佛法无边" NOR,
    "damage_type":  "挫伤"
]),
});
 int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int practice_skill(object me)
{
    return notify_fail("日月鞭法只能通过「"+RED+"轮字决"+NOR+"」来演练。\n");
} 
int valid_learn(object me)
{ 
 if ( (string)me->query("family/family_name") != "少林派") 
return notify_fail("不是少林弟子也想学这个？\n");
        if (me->query_skill("riyue-bian")< 250 && me->query("family/master_id")!="damo zushi")
        return notify_fail("日月鞭是少林派达摩祖师绝技，其他师傅参悟还来不及，怎能教你？\n");
    if ((int)me->query("max_neili") < 20000)
        return notify_fail("你的内力不够。\n");
    if (me->query_skill("whip", 1) <=me->query_skill("riyue-bian", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    if ((int)me->query_skill("riyue-bian",1) > 150)
        return notify_fail("这套鞭法只可以学到150级，以后要靠使用轮字决来提高了。\n"); 
      if ((int)me->query_skill("hunyuan-yiqi", 1) < 50)
    if ((int)me->query_skill("yijing-force", 1) < 50)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 50)
    if ((int)me->query_skill("buddhism-force", 1) < 50)
    if ((int)me->query_skill("taiji-shengong", 1) < 50)
        return notify_fail("你的禅宗气功火候不够，无法学日月鞭法。\n");
    return 1;
} 
mapping query_action(object me, object weapon)
{
        int i, level;
    level   = (int) me->query_skill("riyue-bian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
      if( damage_bonus < 110 ) return 0;

 // 第二等级的伤气
        if ( me->query_skill("riyue-bian",1)>400
         && me->query_skill("riyue-bian",1)<1001
 && (random(me->query("neili"))*3) > victim->query("max_neili") ) {
             victim->receive_damage("qi", (damage_bonus)*2  , me); 
return HIW "$N的日月鞭法已经达到了"BLINK  HIR"偷天换日"NOR HIW"的境界，自动摧毁了"BLINK HIR"$n"NOR HIW"的真元！！！！\n" NOR;
}
// 第三等级的伤气
        if( me->query_skill("riyue-bian",1)>1000
       && me->query("zjb_dj/dj")>=5
  && (me->query("neili")*3) > victim->query("max_neili") ) {
                victim->receive_damage("qi", (damage_bonus - 100) , me); 
return HIR "$N的日月鞭法已入返璞归真境界，随意一鞭带出一阵内劲扑向$n！！！！！\n" NOR;
  }      
}

string perform_action_file(string action){      return __DIR__"riyue-bian/" + action;}

