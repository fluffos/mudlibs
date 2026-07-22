// xunlei-sword.c 迅雷剑
inherit SKILL;
string type() { return "fuji"; }
int tydamage = this_player()->query("tydamage/sword")?this_player()->query("tydamage/sword"):this_player()->query_skill("xunlei-sword");
mapping *action = ({
([  "action":"$N使一式「潮泛银海」，手中$w疾挽，漫天寒光，隐夹风雷之声，闪电般狂涌向$n的$l",
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
    "lvl" : 0,
    "skill_name" : BLK "潮泛银海" NOR,
    "damage_type":  "割伤"
]),
([  "action":"$N错步上前，使出「银雨飞花」，手中$w登时剑芒暴射，宛如漫天瑞雪飞洒向$n的$l",
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,    "lvl" : 20,
    "skill_name" : RED "银雨飞花" NOR,
    "damage_type":  "割伤"
]),
([  "action":"$N手中$w一抖，一招「"+GRN+"花影滨飞"+NOR+"」，$w犹如狂风扫落叶般急攻向$n的$l",
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,    "lvl" : 34,
    "skill_name" : GRN "花影滨飞" NOR,
    "damage_type":  "割伤"
]),
([  "action":"$N手中$w锵啷啷长吟一声，一式「"+BLU+"神雕找食"+NOR+"」，$w头上脚下洒攻而下，攻势之疾，无以伦比向$n的$l",
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,    "lvl" : 47,
    "skill_name" : BLU "神雕找食" NOR,
    "damage_type":  "刺伤"
]),
([  "action":"$N一式「"+MAG+"西风倒卷"+NOR+"」，手中$w将剑自下拖上，端的无比毒辣使$n难断虚实，无可躲避",
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,    "lvl" : 60,
    "skill_name" : MAG "西风倒卷" NOR,
    "damage_type":  "刺伤"
]),
([  "action":RED"$N手中$w"NOR RED",一式「"HIC"天罗地网"NOR RED"」，仿佛一面无形的黑网向$n的$l斜斜击出",
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
     "lvl" : 1050,
    "skill_name" : BLU "天罗地网" NOR,
    "damage_type":  "刺伤"
]),
([  "action":HIB"$N一式「"HIY"日月失色"HIB"」，$w"HIB"银光万道，如江河倒泻，剑芒绵绵无尽向$n的胸口递去",
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
     "lvl" : 1150,
    "skill_name" : HIR "日月失色" NOR,
    "damage_type":  "刺伤"
]),
([  "action":WHT"$N一式「"HIY"金针渡劫"NOR WHT"」，$w"NOR WHT"形神合一，把全部真气贯注剑身之上，快如天光乍闪向$n刺去",
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
     "lvl" : 1250,
    "skill_name" : HIY "金针渡劫" NOR,
    "damage_type":  "刺伤"
])
});
int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int practice_level(){   return 150;  }
int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你必须先弄把剑才能学迅雷剑法。\n");
    if ((int)me->query_skill("xunlei-sword",1) > 1000)
        return notify_fail("这套剑法我就教到这了，以后就靠你自己提高了。\n");
    if ((int)me->query("max_neili") < 20000)
        return notify_fail("你的内力不够。\n");
    if (me->query_skill("sword", 1) <= me->query_skill("xunlei-sword",1))
       return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
        if (me->query("family/master_id")!="he zudao")
        return notify_fail("迅雷剑法是何足道所创，其他师傅参悟还来不及，怎能教你？\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
        int i, level;
    level   = (int) me->query_skill("xunlei-sword",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
      object weap,weap1;
      weap = victim->query_temp("weapon");
      weap1 = me->query_temp("weapon");
      if( damage_bonus < 100 ) return 0;

           if( (me->query_skill("xunlei-sword") > 450) && (me->query("neili") > 10000)
       && (victim->query_temp("weapon")) 
       && random(10) > 7){
      message_vision(HIY "只见$N手中" + weap1->name() + ""HIY"对准对方的" + weap->name() +""HIR"急刺过去\n" NOR, me ); 
       victim->start_busy(1);
       if ((me->query_skill("force")) > victim->query_skill("force") ){
       message_vision(HIY "\n只听 叮! 的一声巨响，" + weap->name()
  + "被"+weap1->name()+""HIR"从$N"HIR"手中直断成两截，$N"HIR"情急之下只好空手应战。\n" NOR, victim );
       weap->move(environment(me));
       weap->set("name", "断掉的"+ weap->query("name") );
       victim->reset_action();
       weap->set("value", 0);
       weap->set("weapon_prop", 0);
       weap->set("long", "一把断掉的武器，看来是被绝顶高手一剑削断的。\n");
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
      if( me->query_skill("xunlei-sword",1)>5000
  && me->query("jh_dj/dj")>=25  ) {
              victim->receive_damage("qi", (damage_bonus -100 ) * 2 , me);
return WHT  "$N的迅雷剑化气为虚,数道剑气无声无息扑向$n！\n" NOR;
  }      

 //  第五等级的伤气
      if( me->query_skill("xunlei-sword",1)>4000
  && me->query("jh_dj/dj")>=20 ) {
              victim->receive_damage("qi", damage_bonus - 100 , me);
return YEL "$N的迅雷剑已达化境，随意一剑化出无形剑气扑向$n！\n" NOR;
  }      
      if( damage_bonus < 100 ) return 0;

 //  第四等级的伤气
      if( me->query_skill("xunlei-sword",1)>3000
  && me->query("jh_dj/dj")>=15 ) {
           victim->receive_damage("qi", (damage_bonus - 100)  /2 , me);
return MAG "$N的迅雷剑已达化境，随意一剑化出无形剑气扑向$n！\n" NOR;
  }      


 //  第三等级的伤气
      if( me->query_skill("xunlei-sword",1)>2000
  && me->query("jh_dj/dj")>=10 ) {
                victim->receive_damage("qi", (damage_bonus - 100) / 3 , me);
return RED "$N的迅雷剑已达返璞归真境界，随意一剑带出一阵雷鸣声狂轰向$n！\n" NOR;
  }      
 // 第二等级的伤气
        if ( me->query_skill("xunlei-sword",1)>1000 
  && me->query("jh_dj/dj")>=2        ) {
             victim->receive_damage("qi", (damage_bonus - 100) / 4 , me);
          return CYN "$N的迅雷剑已初有小成,发出一道带着雷击的剑气扑向$n！\n" NOR;

}

      return 1;
}

void do_interlink(object me, object victim)
{
    int skill1,skill2,j;
    string second_skill,second_skill2;
    if (me->query_temp("secondary_weapon")) return;
    second_skill = me->query_skill_mapped("parry");
    if (!second_skill || second_skill!="douzhuan-xingyi" )   return;
        second_skill2 = me->query_skill_mapped("staff");
    if (!second_skill2 || second_skill2!="tianshan-zhang" )   return;
    skill1=me->query_skill("dushi-jiren", 1);
    skill2=me->query_skill("stealing", 1);
    if (random(skill1)>1000 && random(skill2)>1000){
    for (j=0;j<10;j++)
       if ((me->is_fighting(victim) || victim->is_fighting(me)) && victim->query("qi")>0 ){
                    me->set_temp("action_msg",HIC"电光再现\n"NOR);
                    if (environment(me) == environment(victim))
                    {
                        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
                    }
                }else break;
        }
    me->delete_temp("secondly_weapon");
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
        return notify_fail("你的体力不够练迅雷剑。\n");
    if ((int)me->query("neili") < 50)
        return notify_fail("你的内力不足以练迅雷剑。\n");
    me->receive_damage("qi", 25);
    me->add("neili",-20);
    return 1;
}

string perform_action_file(string action)
{
    return __DIR__"xunlei-sword/" + action;
}

