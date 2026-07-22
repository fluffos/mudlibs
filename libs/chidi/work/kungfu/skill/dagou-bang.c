inherit SKILL;
string type() { return "zhongji"; }
int tydamage = this_player()->query("tydamage/club")?this_player()->query("tydamage/club"):this_player()->query_skill("dagou-bang");

mapping *action = ({
([  "action": "$N使出一招「棒打双犬」，手中$w化作两道青光砸向$n的$l",
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,    "lvl" : 1,
    "damage_type": "挫伤"
]),
([  "action":"$N举起$w，居高临下使一招「狗急跳墙」敲向$n的$l",
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,    "lvl" : 0,
    "damage_type":  "挫伤"
]),
([  "action": "$N手中$w左右晃动，一招「"+RED+"拨草寻蛇"+NOR+"」向$n的$l攻去",
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
        "lvl" : 140,
    "damage_type": "挫伤"
]),
([  "action": "$N举起$w，居高临下使一招「"+GRN+"打草惊蛇"+NOR+"」敲向$n的$l",
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
        "lvl" : 140,
    "damage_type": "挫伤"

]),
([  "action": HIW"$N施出「"+YEL+"拨狗朝天"+HIW+"」，$w由下往上向$n撩去"NOR,
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
      "lvl" : 1050,
    "damage_type": "挫伤"
]),
([  "action": HIW"$N施出「"+HIG+"醉打疯狗"+HIW+"」，$w由下往上向$n$l撩去"NOR,
        "force" : 560,
        "dodge" : 280,
        "parry" : 240,
        "damage" : tydamage,
      "lvl" : 1050,
    "damage_type": "挫伤"
]),
}); 

int valid_enable(string usage) { return usage == "club"; }
int practice_level(){   return 200;  }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 20000)
        return notify_fail("你的内力不够。\n");
      if (me->query_skill("club",1) <= me->query_skill("dagou-bang",1))
      return notify_fail("你的基础不够，无法领会更高深的技巧！\n");
        if (me->query_skill("dagou-bang")< 250 && me->query("family/master_id")!="hong qigong")
        return notify_fail("打狗棒法是丐帮帮主洪七公绝技，向不外传，怎能教你？\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
        int i, level;
    level   = (int) me->query_skill("dagou-bang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

 int practice_skill(object me)
 {
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "club")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "club")
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够练打狗棒法。\n");
    me->receive_damage("qi", 40);
    return 1;
 }




mixed hit_ob(object me, object victim, int damage_bonus)
{
      if( damage_bonus < 110 ) return 0;
      if( me->query("neili") < 50000   ) return 0;
      if( random(10) < 2   ) return 0;
  //  第六等级的伤气
        if( me->query_skill("dagou-bang",1)>5000
       && me->query("jh_dj/dj")>=25
) {
                victim->receive_damage("qi", (damage_bonus ) * 2 , me); 
return HIR "$N的打狗棒法已入天人合一境界，随意一棍呼啸着带出一股强劲扑向$n！\n" NOR;
  } 
   //  第五等级的伤气
        if( me->query_skill("dagou-bang",1)>4000
       && me->query("jh_dj/dj")>=15
) {
                victim->receive_damage("qi", (damage_bonus ) , me); 
return HIR "$N的打狗棒法已入返璞归真境界，随意一棍带出一阵内劲扑向$n！\n" NOR;
  } 
   //  第四等级的伤气
        if( me->query_skill("dagou-bang",1)>3000
       && me->query("jh_dj/dj")>=10
) {
                victim->receive_damage("qi", (damage_bonus - 100) / 2 , me); 
return HIW"$N发挥出打狗棒法的"BLINK HIR"第四层精髓"NOR HIW"，震毁了$n的"HIB BLINK"真元"NOR HIW"！\n"NOR;
  } 
  //  第三等级的伤气
        if( me->query_skill("dagou-bang",1)>2000
       && me->query("jh_dj/dj")>=5
 ) {
                victim->receive_damage("qi", (damage_bonus) / 3 , me); 
return HIW"$N发挥出打狗棒法的"BLINK HIR"第三层精髓"NOR HIW"，震毁了$n的"HIB BLINK"真元"NOR HIW"！\n"NOR;
  }      
  
 // 第二等级的伤气
        if ( me->query_skill("dagou-bang",1)>400
         && me->query_skill("dagou-bang",1)<1001
&& (me->query("neili")*3) > victim->query("max_neili") ) {
             victim->receive_damage("qi", (damage_bonus - 100) / 4 , me); 
return HIW"$N发挥出打狗棒法的"BLINK HIR"第二层精髓"NOR HIW"，震毁了$n的"HIB BLINK"真元"NOR HIW"！\n"NOR;
} 
}

void do_interlink(object me, object victim)
{
    int skill,i,j;
    object *enemy,weapon=me->query_temp("weapon");
    string all_enemy;
    if (!weapon) return;
    if( me->query("neili") < 3000 ) return;
    if (skill > 1800) skill=1800;
    if(( me->query("family/family_name") != "丐帮") && userp(me) )
    return;    
     // if(( me->query_skill_mapped("force") != "huntian-qigong") && userp(me) )
    //return;
    skill=me->query_skill("dagou-bang", 1);
    if (skill >1000) skill=1000;
    if (random(skill)>500){
        enemy=me->query_enemy();
        if (!sizeof(enemy)) return;
        if (sizeof(enemy)==1 && enemy[i]->query("eff_qi")<0 ) return;
        all_enemy=enemy[0]->name();
        for (i=1;i<sizeof(enemy);i++)
            all_enemy+=("、"+enemy[i]->name());
        message_vision(HIG+"$N手中"+(me->query_temp("weapon"))->query("name")+HIG"幻出一股光芒，光芒如实质般劈天盖地般攻向对方！\n\n" NOR,me);
        me->add("neili", -1000);
        me->set_temp("dagou-bang",1);
          for (i=0;i<sizeof(enemy);i++){
          for (j=0;j<(skill/(100*sizeof(enemy)));j++)
                if ((me->is_fighting(enemy[i]) || enemy[i]->is_fighting(me)) && enemy[i]->query("eff_qi")>0 ){
                    if (environment(me) == environment(enemy[i]))
                     {
                        COMBAT_D->do_attack(me, enemy[i], me->query_temp("weapon"));
                     }
                }else break;
        }
    me->delete_temp("dagou-bang");
    me->start_busy(2);

    }
}
string perform_action_file(string action){      return __DIR__"dagou-bang/" + action;}

