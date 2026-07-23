// liaoyuan.c 燎原百击

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
      int lvl;
      object weapon;
      string name;
      weapon = me->query_temp("weapon");
      if (weapon) name = weapon->query("name");

      if( !target ) target = offensive_target(me);
     
      if( !target || !me->is_fighting(target) )
      return notify_fail("燎原百击只能在战斗中对对手使用。\n");

      if (!weapon || weapon->query("skill_type") != "sword"
       || me->query_skill_mapped("sword") != "huifeng-jian")
      return notify_fail("你手里没有剑，无法使用燎原百击！\n");             

      if( (int)me->query_skill("huifeng-jian",1) < 120 )
      return notify_fail("你的回风拂柳剑不够娴熟，不能使用燎原百击！\n");
      
      if( (int)me->query_skill("sword",1) < 120 )
      return notify_fail("你的基本剑法等级不够，不能使用燎原百击！\n");  

      if( (int)me->query_skill("jinding-zhang", 1) < 120 )
      return notify_fail("你的金顶绵掌等级不够，不能使用燎原百击！\n");
      
      if( (int)me->query_skill("linji-zhuang", 1) < 120 )
      return notify_fail("你的临济十二庄等级不够，不能使用燎原百击！\n");
      if (me->query_skill_mapped("force") != "linji-zhuang")
                return notify_fail("你所使用的内功不对。\n");
      if( (int)me->query("max_neili") < 1000 )
      return notify_fail("你的内力太弱，不能使用燎原百击！\n");
      
      if( (int)me->query("neili") < 500 )
      return notify_fail("你的内力太少了，无法使用出燎原百击！\n");   
                                                                                 
      if (me->query_skill_prepared("strike") != "jinding-zhang"
          || me->query_skill_mapped("strike") != "jinding-zhang")
      return notify_fail("你没有使用金顶绵掌，现在无法使用燎原百击进行攻击。\n");

      lvl = ( (int)me->query_skill("huifeng-jian", 1) + (int)me->query_skill("jinding-zhang", 1) ) /20;
      message_vision(HIW"\n$N长啸一声，身子往高空升去，刚好拦住$n，右手中"+name+"刹那间填满空间。\n"NOR, me,target);
// update 截手九式 -> 金顶绵掌 (by xbd)
      message_vision(HIW"左手使出金顶绵掌，带起无数小气旋，威力顿然加强。\n"NOR, me,target);
      me->add("neili", -300); 
      me->add("jingli", -150);      
      me->add_temp("apply/strength", lvl);
      me->add_temp("apply/attack", lvl); 
      me->add_temp("apply/dexerity", lvl/2);

      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
      weapon->unequip(); 
      COMBAT_D->do_attack(me, target, 0, 3);  
      COMBAT_D->do_attack(me, target, 0, 0);
      COMBAT_D->do_attack(me, target, 0, 3);  
      me->add_temp("apply/strength", -lvl);
      me->add_temp("apply/attack", -lvl);
      me->add_temp("apply/dexerity", -(lvl/2));
      weapon->wield();
      me->start_busy(3);
       return 1;
}
