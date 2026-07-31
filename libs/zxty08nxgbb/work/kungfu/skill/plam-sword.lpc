// /kungfu/skill/palm-sword.c
// pipip 12/19/03
inherit SKILL;

string type() { return "zhongji"; }
mapping *action = ({
([      "action" : HIW"$N左掌轻巧一翻，猛的自下而上直插$n的心口，掌未到，掌风已可伤人"NOR,
     "force" : this_player()->query_skill("palm-sword",1)/2,
     "dodge" : this_player()->query_skill("dodge",1)/4,
     "damage" : this_player()->query("zjb_dj/dj")*100,
     "parry" : this_player()->query_skill("parry",1)/2,
     "damage_type" : "刺伤"
]),
([      "action" : HIW"$N猛的转身回手，反手一掌甩出，只见一道剑芒竟凌空刺向$n的$l"NOR,
     "force" : this_player()->query_skill("palm-sword",1)/2,
     "dodge" : this_player()->query_skill("dodge",1)/4,
     "damage" : this_player()->query("zjb_dj/dj")*100,
     "parry" : this_player()->query_skill("parry",1)/2,
     "damage_type" : "刺伤"
]),
([      "action" : HIW"$N双掌连环击出，掌力到处竟有剑光隐隐闪动，$n被攻了个措手不及"NOR,
     "force" : this_player()->query_skill("palm-sword",1)/2,
     "dodge" : this_player()->query_skill("dodge",1)/4,
     "damage" : this_player()->query("zjb_dj/dj")*100,
     "parry" : this_player()->query_skill("parry",1)/2,
     "damage_type" : "刺伤"
]),
});

mapping *action2 = ({
([      "action" : HIB"$n忽觉眼前一花，呼吸困难，$N一记"BLINK+HIW"掌剑"NOR+HIB"已急速插向$n的咽喉要处"NOR,
     "force" : this_player()->query_skill("palm-sword",1),
     "dodge" : this_player()->query_skill("dodge",1)/2,
     "damage" : this_player()->query("zjb_dj/dj")*180,
     "parry" : this_player()->query_skill("parry",1),
     "lvl" : 1200,
     "damage_type" : "刺伤"
]),
([      "action" : HIG"$N腰身一扭，双掌上下翻飞，幻出漫天"BLINK+HIW"掌网"NOR+HIG"将$n所有活路尽皆封杀"NOR,
     "force" : this_player()->query_skill("palm-sword",1),
     "dodge" : this_player()->query_skill("dodge",1)/2,
     "damage" : this_player()->query("zjb_dj/dj")*180,
     "parry" : this_player()->query_skill("parry",1),
     "lvl" : 1200,
     "damage_type" : "刺伤"
]),
([      "action" : HIR"$N眼中寒芒四射，身形猛的一缩，右掌隐隐带动一股摄人"BLINK+HIW"死气"NOR+HIR"，分成三段攻击连续刺向$n，"NOR,
     "force" : this_player()->query_skill("palm-sword",1),
     "dodge" : this_player()->query_skill("dodge",1)/2,
     "damage" : this_player()->query("zjb_dj/dj")*180,
     "parry" : this_player()->query_skill("parry",1),
     "lvl" : 1200,
     "damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return usage=="unarmed"; }

int valid_learn(object me)
{
        return notify_fail("掌剑绝技只能靠自己领悟，别人想教也无从教起。\n");
}


mapping query_action(object me, object weapon)
{
        int i, level;
        mapping a_action;
        level = (int) me->query_skill("plam-sword",1);
        me = this_player(); 

        if (me->query_skill("plam-sword",1)<=1300
        && me->query("zjb_dj/dj")<30)
        return action[random(sizeof(action))];
   
        if (me->query_skill("plam-sword",1)>=1301
        && me->query("zjb_dj/dj")>=30)
        return action2[random(sizeof(action2))];
 
        if (me->query_skill("plam-sword",1)>=1301
        && me->query("zjb_dj/dj")<30)
        return action[random(sizeof(action))];

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
      if( damage_bonus < 110 ) return 0;

 // 第1等级的伤气
         if ( (me->query_skill("plam-sword",1)>500
         && me->query("zjb_dj/dj")>=10
         && me->query("zjb_dj/dj")<30
         && (me->query("neili")*5) > victim->query("max_neili"))
         && (me->query_skill("plam-sword",1)<=1301) ) 
{
         victim->receive_damage("qi", (damage_bonus - 100) / 8 , me);
return RED "$N掌风内夹着一股无形剑气，$n惊讶中已被$N掌剑所伤！！\n" NOR;
}

 //  第2等级的伤气
         if( me->query_skill("plam-sword",1)>1300
         && me->query("zjb_dj/dj")>=30
         && (me->query_skill("hand-blade",1)>1300)
         && (me->query("neili")*5) > victim->query("max_neili"))
{ 
         victim->receive_damage("qi", (damage_bonus - 100) / 3 , me);
return HIR "$N掌风到处，"BLINK+HIY"刀芒"HIC"剑气"NOR+HIR"一齐激出，$n毫无招架之力，直被震的五脏俱焚，口鼻血流不止！！！\n" NOR;
  }      

}


string perform_action_file(string action)
{
        return __DIR__"plam-sword/" + action;
}

