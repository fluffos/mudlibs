//Cracked by Kafei
// huaxuan.c 回旋

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
void checking(object me);
int perform(object me, object target)
{
      int lvl;
      
      
      lvl = ((int)me->query_skill("hamagong", 1)+(int)me->query_skill("shexing-diaoshou", 1))/2;
	  if( !target ) target = offensive_target(me);
	   if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「蛇形回旋步」之技只能在战斗中对敌人使用。\n");

        if( (int)me->query_temp("gb_huixuan") )
                return notify_fail("你已经使出了蛇形回旋步！\n");

        if( (int)me->query_skill("shexing-diaoshou", 1) < 150 )
                return notify_fail("你的功夫不够娴熟。\n");
       
	if ((int)me->query_skill("hamagong", 1) < 80)
		return notify_fail("你的蛤蟆功火候不够。\n");

      if( (int)me->query("max_neili") < 1000 )
      return notify_fail("你的内力太弱，不能使出蛇形回旋步！\n");
      if( (int)me->query("neili") < 200 )
      return notify_fail("你的内力太少了，不能使出蛇形回旋步！\n");   
	        if( (int)me->query("neili") < 300 )
      return notify_fail("你的精力太少了，不能使出蛇形回旋步！\n");   
      message_vision(HIC"\n突然$N跃起，大袖飞舞，东纵西跃，双手绞成蛇行,身法轻灵之极,回旋往复，真似一只玉燕、一只大鹰翩翩飞舞一般。\n"NOR, me);
      me->add("neili", -100); 
      me->add("jing", -100);      
	  me->set_temp("gb_huixuan",lvl/15);
	  me->add_temp("apply/attack",lvl/3);
	  
		me->start_busy(1);
		remove_call_out("checking");
		call_out("checking", 1, me,lvl/3);

      return 1;
}
void checking(object me)
{
	int i;
      int lvl;
      
      
      lvl = ((int)me->query_skill("hamagong", 1)+(int)me->query_skill("shexing-diaoshou", 1))/2;

       if( !living(me) || me->is_ghost())
        {
                me->delete_temp("gb_huixuan");
				me->add_temp("apply/attack",-lvl/3);
                return ;
        }
		if( !me->is_fighting())
        {
				me->delete_temp("gb_huixuan");
		        message_vision(HIW"\n$N深深吸了口气，将蛇形刁手上的内劲收了回来。\n"NOR, me);
				me->add_temp("apply/attack",-lvl/3);
				
                return ;
        }
		if( me->query_temp("gb_huixuan") <= 0 )
        {
				me->delete_temp("gb_huixuan");
		        message_vision(HIW"\n$N深深吸了口气，身法中渐失蛇形之意。\n"NOR, me);
				me->add_temp("apply/attack",-lvl/3);
				
                return ;
        }

		me->add_temp("gb_huixuan",-1);
		call_out("checking", 1, me,lvl);
		return;
}
