//xuantie-jianfa.c 玄铁剑法  
inherit SKILL;
#include <ansi.h>
string type() { return "zhongji"; }
int tydamage = this_player()->query("tydamage/sword")?this_player()->query("tydamage/sword"):this_player()->query_skill("xuantie-jianfa");

mapping *action = ({
([      "action" : "$N一招杞人忧天抬头向天，浑若不见，呼的一剑向自己头顶空空提起，剑光斜下，化成弧形，凌厉落下落向$n的$l。",
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
        "lvl" : 0,
        "skill_name" : "杞人忧天",
        "damage_type" : "砍伤"
]),
([      "action" : "$N一招无中生有剑体下垂，无半点防御姿式，突然间手足齐动，上步近身，一道剑光划向$n.",
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
        "lvl" : 10,
        "skill_name" : "无中生有",
        "damage_type" : "划伤"
]),
([      "action" : "$N一招拖泥带水剑光云袖飘动，宛若流水，飞沙走石剑光直刺$n的咽喉。",
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
        "lvl" : 20,
        "skill_name" : "拖泥带水",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招"HIY" 力不从心 "NOR"含胸收腹，头缓缓低下，脚步沉重的迈向$n,剑光由下至上斜劈$n的软肋。",
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
        "lvl" : 120,
        "skill_name" : "力不从心",
    "damage_type" : "劈伤"
]),
([      "action" : "$N一招"HIR" 行尸走肉 "NOR"发出一剑。这一剑发出时恍恍惚惚，隐隐约约，若有若无的刺向$n的前心",
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
        "lvl" : 150,
        "skill_name" : "行尸走肉",
        "damage_type" : "刺伤"
]),
([      "action" : "$N持剑平托，一招"HIM" 庸人自扰 "NOR"没精打采的扫向$n的$l.",
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
        "lvl" : 230,
        "skill_name" : "庸人自扰",
            "damage_type" : "砍伤"
]),
([      "action" : "$N一招"RED" 倒行逆施 "NOR"突然纵起丈余，头下脚上，倒过身子，一剑刺向$n的$l"NOR,
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
     "lvl" : 1001,
        "skill_name" : "倒行逆施",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招"YEL" 玄冰落月 "NOR"凝目远眺，突然剑光如一弯新月班落向$n的头顶。"NOR,
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
     "lvl" : 1100,
        "skill_name" : "玄冰落月",
           "damage_type" : "砍伤"
]),
([      "action" : "$N一招"BLU" 暗云藏星 "NOR"脚下虚浮，有如几天不吃不睡后的脚步朗舱的袭到$n的身旁，剑光一道刺向$n的前心。"NOR,
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
     "lvl" : 1150,
        "skill_name" : "暗云藏星",
           "damage_type" : "刺伤"
]),
([      "action" : "$N一招"HIC" 徘徊空谷 "NOR"左掌右剑，虚虚实实的剑光刺向$n的$l。"NOR,
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
     "lvl" : 1200,
        "skill_name" : "徘徊空谷",
           "damage_type" : "刺伤"
]),
});
int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 20000)
        return notify_fail("你的内力不够。\n");
     if ((int)me->query_skill("force", 1) < 300)
        return notify_fail("你的内功火候太浅。\n");
        if (me->query_skill("xuantie-jianfa")< 250 && me->query("family/master_id")!="yang guo")
        return notify_fail("玄铁剑法是杨过绝技，其他师傅参悟还来不及，怎能教你？\n");
  if (me->query_skill("sword", 1) <=me->query_skill("xuantie-jianfa", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
        int i, level;
    level   = (int) me->query_skill("xuantie-jianfa",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
      if( damage_bonus < 110 ) return 0;
     if( me->query("neili") < 50000   ) return 0;
      if( random(10) < 2   ) return 0;
 //  第六等级的伤气
      if( me->query_skill("xuantie-jianfa",1)>4000
  && me->query("zjb_dj/dj")>=25  ) {
              victim->receive_damage("qi", (damage_bonus ) * 2 , me);
return HIW  "$N手中重剑发出一阵阵"HIW"奇重剑气"NOR"夹着阵阵"HIC"海啸之声"NOR"压的$n传不过气来！！\n" NOR;

  }      

 //  第五等级的伤气
      if( me->query_skill("xuantie-jianfa",1)>3000
  && me->query("zjb_dj/dj")>=15 ) {
              victim->receive_damage("qi", damage_bonus  , me);
return WHT  "$N以手中一柄重剑发出一阵"HIB"海啸"NOR"般的"HIW"剑气"NOR"震碎了$n的心脉！！！\n" NOR;
  }      
      if( damage_bonus < 110 ) return 0;

 //  第四等级的伤气
      if( me->query_skill("xuantie-jianfa",1)>2000
  && me->query("zjb_dj/dj")>=10 ) {
           victim->receive_damage("qi", (damage_bonus - 100)  , me);
return MAG "$N的玄铁剑法已入化镜，随意一招竟似万马奔腾般直袭$n！！！！！\n" NOR;
  }    
 
 //  第三等级的伤气
        if( me->query_skill("xuantie-jianfa",1)>1000
       && me->query("zjb_dj/dj")>=4 ){
                victim->receive_damage("qi", (damage_bonus - 100) / 3 , me);
return CYN "$N的玄铁剑法已入化镜，随意一招竟似万马奔腾般直袭$n！！！！！\n" NOR;
  }  

 // 第二等级的伤气
        if ( me->query_skill("xuantie-jianfa",1)>400
       && me->query("zjb_dj/dj")>=2 ){
             victim->receive_damage("qi", (damage_bonus - 100) / 8 , me);
return RED "$N的玄铁剑法已入化镜，随意一招竟似万马奔腾般直袭$n！！！！！\n" NOR;
}    
}

int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够练玄铁剑法。\n");
    me->receive_damage("qi", 30);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"xuantie-jianfa/" + action;
}


