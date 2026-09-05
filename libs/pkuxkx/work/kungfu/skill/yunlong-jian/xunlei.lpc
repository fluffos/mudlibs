//xunlei.c 迅雷剑

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
  object weapon, ob;
  string msg, string1;
  int count;

  if( !target ) 
  	target = offensive_target(me);

  if( !target || !target->is_character() || !me->is_fighting(target) )
    return notify_fail("「迅雷剑」只能对战斗中的对手使用。\n");

	if(me->query_temp("xunlei_yushi"))
		return notify_fail("你剑势未尽，不能再施展「迅雷剑」！\n");

	if ( (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword"))
		return notify_fail("你使用的武器不对。\n");

  if( (int)me->query("neili") < 800 )
    return notify_fail("你的内力不够！\n");

	if( (int)me->query_skill("yunlong-jian", 1) < 200 )
		return notify_fail("你的云龙剑法不够娴熟，不会使用「迅雷剑」。\n");

	if( (int)me->query_skill("yunlong-shengong", 1) < 150 )
		return notify_fail("你的云龙神功不够高。\n");


  msg = HIR "\n$N手中"+weapon->query("name")+HIR"剑尖指向自己胸口，剑柄斜斜向外，怪异之极，竟似回剑自戕一般！\n\n" NOR;
  message_vision(msg, me,target);
	me->start_busy(1);
  ob = me->select_opponent();
	me->set_temp("xunlei",4);
  me->add("neili", -50);
	me->set_temp("xunlei_yushi",1);
	call_out("checking", 1, me, target);
  return 1;
}


void checking(object me, object target)
{
	object weapon;
	int extra,extra1;
	
	if (!me)
		return;
		
	if (!target)
	{
		me->delete_temp("xunlei");
		call_out("xunlei_end", 5+random(3), me);
		return;
	}
	
	extra  =(int)me->query_skill("yunlong-jian",1)/5;
	extra +=(int)me->query_skill("yunlong-shengong",1)/4;
	
	if ( (!objectp(weapon = me->query_temp("weapon"))
	      ||(string)weapon->query("skill_type") != "sword")
	    && (!objectp(weapon = me->query_temp("secondary_weapon"))
	    || (string)weapon->query("skill_type") != "sword") )
  {
	  tell_object(me, "\n你手中无剑，无法继续使用迅雷剑。\n" NOR);
		me->delete_temp("xunlei");
		call_out("xunlei_end", 5+random(3), me);
    return;
  }

  if ( me->query_temp("xunlei")  ) 
  {
    if ( weapon->query("weapon_prop") == 0 ) {
      tell_object(me, "\n你的"+weapon->name()+"已毁，无法持续迅雷剑的攻势！\n\n" NOR);
		  me->delete_temp("xunlei");
		  call_out("xunlei_end", 5+random(3), me);
      return;
    }
    else if ( (int)me->query("neili") < 200  ) {
      tell_object(me, "\n你的内力后继不足，不得不停止迅雷剑的攻势！\n\n" NOR);
		  me->delete_temp("xunlei");
		  call_out("xunlei_end", 5+random(3), me);
      return;
    }
    else if ( me->query_skill_mapped("sword") != "yunlong-jian" ) {
      tell_object(me, HIR "\n你转而施展其他剑法，无法再以迅雷剑攻敌！\n\n" NOR);
		  me->delete_temp("xunlei");
		  call_out("xunlei_end", 5+random(3), me);
      return;
    }
    else if ( me->is_busy() ) {
      tell_object(me, HIR "\n你现在动作不够灵活，无法继续维持迅雷剑攻势！\n\n" NOR);
		  me->delete_temp("xunlei");
		  call_out("xunlei_end", 5+random(3), me);
      return;
    }
    else if (!me->is_fighting() || !objectp(target)) {
      tell_object(me,  "\n你现在没有和人过招，当下收回了迅雷剑的攻势。\n\n" NOR);
		  me->delete_temp("xunlei");
		  call_out("xunlei_end", 5+random(3), me);
      return;
    }
	  else
	  {
      //显示perform具体情况
      me->set_temp("combat_env",me->query("env/skip_combat"));
      me->set("env/skip_combat",0);
      target->set_temp("combat_env",target->query("env/skip_combat"));
      target->set("env/skip_combat",0);        
      if ( me->query_temp("xunlei") ==4 )
        message_vision(HIY"\n$N纵身近前，"+weapon->name()+HIY"陡然弯弯弹出，剑尖直刺$n，出招之快真乃为任何剑法所不及！\n" NOR, me,target);
      
      if ( me->query_temp("xunlei") ==3 )
        message_vision(HIW"\n$N伸指在"+weapon->name()+HIW"上一弹，剑声嗡嗡，有若龙吟，"+weapon->name()+HIW"颤处，剑锋来势神妙无方！\n" NOR, me,target);
      
      if ( me->query_temp("xunlei") ==2 )
        message_vision(HIG"\n$N陡然间大喝一声，"+weapon->name()+HIG"上寒光闪动，喝道：「"+target->name()+HIG"，可小心了！」\n" NOR, me,target);
      
      if ( me->query_temp("xunlei") ==1 )
        message_vision(HIR"\n见$N随手挥剑，"+weapon->name()+HIR"颤处，前后左右，瞬息之间已攻出了四四一十六招！\n" NOR, me,target);
      
      me->add("neili", -100);
	    me->start_busy(1);
      extra = extra * me->query_temp("xunlei")/5;
      me->add_temp("apply/attack",extra);
      me->add_temp("apply/damage",extra*2/3);
      message_vision(HIW"左一剑！\n" NOR,me,target);
      COMBAT_D->do_attack(me, target, weapon);
      message_vision(HIC"右一剑！\n" NOR,me,target);
      COMBAT_D->do_attack(me, target, weapon);
      message_vision(HIR"上一剑！\n" NOR,me,target);
      COMBAT_D->do_attack(me, target, weapon);
      message_vision(HIG"下一剑！\n" NOR,me,target);
      COMBAT_D->do_attack(me, target, weapon);
      me->add_temp("apply/attack",-extra);
      me->add_temp("apply/damage",-extra*2/3);
  	  me->set_temp("xunlei_attack",1);
      me->set_temp("xunlei", me->query_temp("xunlei")-1);
      call_out("checking", 1, me, target);
		}
  }
  else 
  {
    message_vision(HIY "\n$N顺势圈转手中"+weapon->name()+HIY"，一十六手「迅雷剑」已然尽数使出！\n" NOR, me, weapon);
	  me->delete_temp("xunlei");
	  me->start_busy(1+random(2));
    call_out("xunlei_end", 5+random(3), me);
  }
  
  //恢复combat设置    	                                          
  me->set("env/skip_combat",me->query_temp("combat_env"));        
  target->set("env/skip_combat",target->query_temp("combat_env"));        
}

void xunlei_end(object me, object target)
{
	object weapon;
	
	if (!me) 
		return;
	
	weapon = me->query_temp("weapon");

	me->delete_temp("xunlei");
	me->delete_temp("xunlei_yushi");
  tell_object(me, HIR "\n你暗自调息，渐渐平复腾涌的真气。\n\n" NOR);
}