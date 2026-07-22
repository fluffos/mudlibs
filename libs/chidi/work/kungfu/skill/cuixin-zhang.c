// /kungfu/skill/cuixin-zhang.c
// pipip 2:19 PM 5/14/02
inherit SKILL;

string type() { return "zhongji"; }
mapping *action = ({
([      "action" : "$N使一招「"BLINK HIC"风起云涌"NOR"」，双手飘移不定击向$n$l",
     "force" : this_player()->query_skill("cuixin-zhang",1)/2,
     "dodge" : this_player()->query_skill("dodge",1)/4,
     "damage" : this_player()->query("jh_dj/dj")*100,
     "parry" : this_player()->query_skill("parry",1)/2,
        "skill_name" : "风起云涌",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N倏忽欺至$n身前，一招「"BLINK HIY"扬波起浪"NOR"」直拍$n的$l",
     "force" : this_player()->query_skill("cuixin-zhang",1)/2,
     "dodge" : this_player()->query_skill("dodge",1)/4,
     "damage" : this_player()->query("jh_dj/dj")*100,
     "parry" : this_player()->query_skill("parry",1)/2,
        "skill_name" : "扬波起浪",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N身形绕$n一转，一招「"BLINK HIG"风雷并起"NOR"」向$n$l接连出掌",
     "force" : this_player()->query_skill("cuixin-zhang",1)/2,
     "dodge" : this_player()->query_skill("dodge",1)/4,
     "damage" : this_player()->query("jh_dj/dj")*100,
     "parry" : this_player()->query_skill("parry",1)/2,
        "skill_name" : "风雷并起",
        "damage_type" : "瘀伤"
]),
});

mapping *action2 = ({
([      "action" : HIB"$N身形拔起，在半空一招「"BLINK HIC"急电惊雷"NOR HIB"」右掌猛击$n的$l"NOR,
     "force" : this_player()->query_skill("cuixin-zhang",1),
     "dodge" : this_player()->query_skill("dodge",1)/2,
     "damage" : this_player()->query("jh_dj/dj")*180,
     "parry" : this_player()->query_skill("parry",1),
     "lvl" : 1200,
        "skill_name" : "急电惊雷",
        "damage_type" : "瘀伤"
]),
([      "action" : YEL"$N使一招「"BLINK HIR"含沙射影"NOR YEL"」，纵起丈余直击$n的$l"NOR,
     "force" : this_player()->query_skill("cuixin-zhang",1),
     "dodge" : this_player()->query_skill("dodge",1)/2,
     "damage" : this_player()->query("jh_dj/dj")*180,
     "parry" : this_player()->query_skill("parry",1),
     "lvl" : 1200,
        "skill_name" : "含沙射影",
        "damage_type" : "瘀伤"
]),
([      "action" : MAG"$N一声大喝使出「"BLINK HIG"夺魄催心"NOR MAG"」，幻出满天掌影，掌掌不离$n的$l"NOR,
     "force" : this_player()->query_skill("cuixin-zhang",1),
     "dodge" : this_player()->query_skill("dodge",1)/2,
     "damage" : this_player()->query("jh_dj/dj")*180,
     "parry" : this_player()->query_skill("parry",1),
     "lvl" : 1200,
        "skill_name" : "夺魄催心",
        "damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query("family/master_id")!="wuming laoren")
        return notify_fail("催心掌乃是无名老人绝学，你只能找他求教。\n");
    if ((int)me->query("max_neili") < 1000)
        return notify_fail("你的内力不够。\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("cuixin-zhang", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    if ((int)me->query_skill("cuixin-zhang",1) > 300)
        return notify_fail("这套武功太过阴毒，我就教到这了，以后就靠你自己提高了。\n");
    return 1;
}


mapping query_action(object me, object weapon)
{
        int i, level;
          mapping a_action;
        level   = (int) me->query_skill("cuixin-zhang",1);
          me = this_player();
       if (me->query_skill("cuixin-zhang",1)<=1000)  
    return action[random(sizeof(action))];
   
        if (me->query_skill("cuixin-zhang",1)>=1001
        && me->query("jh_dj/dj")>=7)
    return action2[random(sizeof(action2))];

    if (me->query_skill("cuixin-zhang",1)>1000
        && me->query("jh_dj/dj")<7)
 return action[random(sizeof(action))];
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
      if( damage_bonus < 110 ) return 0;
     if( me->query("neili") < 50000) return 0;
      if( random(10) < 2   ) return 0;
     
//  第六等级的伤气
        if( me->query_skill("cuixin-zhang",1)>5000
       && me->query("jh_dj/dj")>=25
    && me->query_skill("yijing-force",1)>2000
 ) {
                victim->receive_damage("qi", (damage_bonus - 100) * 2 , me);
return HIB "$N体内的易筋神功的"HIG"刚劲"NOR HIB"与手中攻出的"HIM"催心柔劲"NOR HIB"融合为一，化做一股"BLINK BLK"混元真力"NOR HIB"震碎了$n的心脉！\n" NOR;
  }      
  // 第五等级的伤气
         if( me->query_skill("cuixin-zhang",1)>4000
       && me->query("jh_dj/dj")>=20
    && me->query_skill("yijing-force",1)>2000
)  {
             victim->receive_damage("qi", (damage_bonus ) , me);
return HIB "$N体内的易筋神功的"HIG"刚劲"NOR HIB"与手中攻出的"HIM"催心柔劲"NOR HIB"融合为一，化做一股"BLINK BLK"混元真气"NOR HIB"震破了$n的心脉！\n" NOR;
}
// 第四等级的伤气
        if( me->query_skill("cuixin-zhang",1)>3000
       && me->query("jh_dj/dj")>=15
    && me->query_skill("yijing-force",1)>2000
)  {
             victim->receive_damage("qi", (damage_bonus - 100) / 2 , me);
return HIW "$N猛地运功将易筋神功的柔劲混入第四层催心掌阴柔的掌力内攻向$n！\n" NOR;
}
// 第三等级的伤气
         if( me->query_skill("cuixin-zhang",1)>2000
       && me->query("jh_dj/dj")>=10
    && me->query_skill("yijing-force",1)>1000
)  {
             victim->receive_damage("qi", (damage_bonus - 100) / 3 , me);
return HIW "$N暗暗运功将易筋神功的柔劲混入第三层催心掌阴柔的掌力内攻向$n！\n" NOR;
}

 // 第二等级的伤气
        if ( (me->query_skill("cuixin-zhang",1)>200
         && me->query_skill("yijing-force",1)>200
         && me->query_skill("cuixin-zhang",1)<1001
&& (me->query("neili")*3) > victim->query("max_neili"))
|| (me->query_skill("cuixin-zhang",1)>1000
    && me->query_skill("yijing-force",1)<1000
&& (me->query("neili")*3) > victim->query("max_neili")) ) {
             victim->receive_damage("qi", (damage_bonus - 100) / 4 , me);
return HIW "$N暗暗运功将易筋神功的柔劲混入催心掌阴柔的掌力内攻向$n！\n" NOR;
}
}

int practice_skill(object me)
{
    return notify_fail("催心掌只能通过「"+HIM+"回折式"+NOR+"」来提升。\n");
}


string perform_action_file(string action)
{
        return __DIR__"cuixin-zhang/" + action;
}

