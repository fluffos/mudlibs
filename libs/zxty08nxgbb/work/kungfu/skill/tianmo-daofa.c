#include <ansi.h>
inherit SKILL;

string type() { return "zhongji"; }

int tydamage = this_player()->query("tydamage/blade")?this_player()->query("tydamage/blade"):this_player()->query_skill("tianmo-daofa");

mapping *action = ({
([
        "action" : HIB"$N一举手中的$w，向前直攻，正是一招"+HIW"「尸横遍野」"NOR"直指$n的$l"NOR,
        "skill_name" : "尸横遍野",
        "force" : 660,
        "dodge" : 480,
        "parry" : 340,
        "damage" : tydamage,
        "damage_type" : "砍伤"
]),
([
        "action" : HIM"$N使出"+HIW"「借尸还魂」"NOR"，$w左右摇摆不定，摇摇晃晃得砍向$n的$l"NOR,
        "skill_name" : "借尸还魂",
        "force" : 660,
        "dodge" : 480,
        "parry" : 340,
        "damage" : tydamage,
        "damage_type" : "割伤"
]),
([
        "action" : HIW"$N一招「阴风袭体」，$n一呆，$l已经被$N劈中"NOR,
        "skill_name" : "阴风袭体",
        "force" : 660,
        "dodge" : 480,
        "parry" : 340,
        "damage" : tydamage,
        "damage_type" : "砍伤"
]),
([
        "action" : HIC"$N跃起丈余，手中$w画了个弧线，斜斜划下，「阴徊九天」，击向$n的$l"NOR,
        "skill_name" : "阴徊九天",
        "force" : 660,
        "dodge" : 480,
        "parry" : 340,
        "damage" : tydamage,
        "damage_type" : "割伤"
]),
([
        "action" : HIG"$N刀交左手，突然挥$w反撩而上，一式「天魔天下」，迅捷无比的攻向$n的$l"NOR,
        "skill_name" : "天魔天下",
        "force" : 660,
        "dodge" : 480,
        "parry" : 340,
        "damage" : tydamage,
        "damage_type" : "砍伤"
]),
});

int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }

int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "blade")
        return notify_fail("你还是先找把刀来吧。\n");
    if ((int)me->query("max_neili") < 20000)
        return notify_fail("你的内力不够。\n");
    if (me->query_skill("blade", 1)<=me->query_skill("tianmo-daofa",1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
       if ((int)me->query_skill("tianmo-shengong", 1) < 100)
        return notify_fail("你的天魔神功火候太浅。\n");

        if (me->query("family/master_id")!="tian mo")
        return notify_fail("天魔刀法乃是天魔的得意武功，你只能找他学习。\n");
    if ((int)me->query_skill("tianmo-daofa",1) > 300)
        return notify_fail("这套刀法我就教此处，你今后在这套刀法上的成就就要看你自己了。\n");
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
    level   = (int) me->query_skill("tianxin-blade",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 60 || me->query("neili") < 30)
                return notify_fail("你的体力不够练天魔刀法。\n");
        me->receive_damage("jingli", 50);
        me->add("neili", -20);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"tianmo-daofa/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
      object weap,weap1;
      weap = victim->query_temp("weapon");
      weap1 = me->query_temp("weapon");
      if( damage_bonus < 100 ) return 0;

           if( (me->query_skill("tianmo-daofa") > 450) && (me->query("neili") > 10000)
       && (victim->query_temp("weapon")) 
       && random(10) > 7){
       message_vision(HIR "只见$N手中" + weap1->name() + ""HIY"幻化出千万刀影，千刀齐出将对方的" + weap->name() +""HIR"劈的火星直冒！\n" NOR, me ); 
       victim->start_busy(1);
       if ((me->query_skill("force")) > victim->query_skill("force") ){
       message_vision(HIW "\n运起天魔神功全力一刀劈下，只听 乒! 的一声巨响，" + weap->name()
  + "被"+weap1->name()+""HIW"从$N"HIR"手中直劈成两段，$N"HIR"情急之下只好空手应战。\n" NOR, victim );
       weap->move(environment(me));
       weap->set("name", "断掉的"+ weap->query("name") );
       victim->reset_action();
       weap->set("value", 0);
       weap->set("weapon_prop", 0);
       weap->set("long", "一把断掉的武器，从中断开，破口整齐，看来是被绝顶高手一刀劈开的。\n");
       } else {
      message_vision(HIY "\n$N暗运卸字决，" + weap->name()
   + ""HIY"顺着方向快速旋转数下，将"+weap1->name()+""HIY"上的真劲全数卸去。\n" NOR, victim );
      victim->add("neili", -1000);
      }
      me->add("neili", - (20+random(30)));
      }
      if( me->query("neili") < 50000   ) return 0;
      if( random(10) < 2   ) return 0;

 //  第六等级的伤气
      if( me->query_skill("tianmo-daofa",1)>4000
    && me->query_skill("tianmo-shengong",1)>1500
  && me->query("zjb_dj/dj")>=25  ) {
              victim->receive_damage("qi", (damage_bonus ) * 2 , me);
return WHT "$N体内的天魔神功与刀招中发出的天魔刀法意融合为一，化做一股天魔真力震碎了$n的心脉！！！\n" NOR;
  }      

 //  第五等级的伤气
      if( me->query_skill("tianmo-daofa",1)>3000
    && me->query_skill("tianmo-shengong",1)>1200
  && me->query("zjb_dj/dj")>=15 ) {
              victim->receive_damage("qi", damage_bonus  , me);
return YEL "$N的天魔刀法已到第五等级，一刀随意挥出,一股魔气扑向$n！！！！！\n" NOR;
  }      
      if( damage_bonus < 100 ) return 0;

 //  第四等级的伤气
      if( me->query_skill("tianmo-daofa",1)>2000
    && me->query_skill("tianmo-shengong",1)>1000
  && me->query("zjb_dj/dj")>=10 ) {
           victim->receive_damage("qi", (damage_bonus - 100)  , me);
return MAG "$N的天魔刀法已到第四等级，魔刀发出阵阵刀影罩住$n！！！！！\n" NOR;
  }  

 //  第3等级的伤气
        if( me->query_skill("tianmo-daofa",1)>1000
       && me->query("zjb_dj/dj")>=4
    && me->query_skill("tianmo-shengong",1)>1000
&& (me->query("neili")*3) > victim->query("max_neili") ) {
                victim->receive_damage("qi", (damage_bonus - 100) / 3 , me);
return CYN "$N的天魔刀法已入返璞归真境界，随意一招带出无数劲气扑向$n！！！！！\n" NOR;
  }  
 // 第二等级的伤气
        if ( me->query_skill("tianmo-daofa",1)>200
         && me->query_skill("tianmo-shengong",1)>200
  && me->query("zjb_dj/dj")>=2        ) {
             victim->receive_damage("qi", (damage_bonus - 100) / 8 , me);
return RED "$N大喝一声，提起全身天魔真气，一股暗劲侵入$n的经脉！！！\n" NOR;
}    
}

