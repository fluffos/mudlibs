//xunlei.c 迅雷剑

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int perform(object me, object target)
{
  object weapon, ob;
  string msg, string1;
  int count;

  if( !target ) 
  	target = offensive_target(me);

  if( !target || !target->is_character() || !me->is_fighting(target) )
    return notify_fail("「雨打飞花剑」只能对战斗中的对手使用。\n");

	if(me->query_temp("xunlei_yushi"))
		return notify_fail("你剑势未尽，不能再施展「雨打飞花剑」！\n");

	if ( (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword"))
		return notify_fail("你使用的武器不对。\n");

	if( (int)me->query("neili") < 1000 )
		return notify_fail("你的内力不够！\n");

	if( (int)me->query_skill("danxin-jian", 1) < 200 )
		return notify_fail("你的碧血丹心剑不够娴熟，不会使用「雨打飞花剑」。\n");

	if( (int)me->query_skill("cangming-gong", 1) < 150 )
		return notify_fail("你的浩气苍冥功不够高。\n");


  msg = HIR "\n$N微笑弹响手中的"+weapon->query("name")+HIR"，这一弹之间似有歌吟，似是壮志未酬，也似是悲愤难当，天地间顿时充满杀伐气概！\n\n" NOR;
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
	object weapon, *enemy;
	int extra,extra1,da,i,j,count,maxc,rate_fix,damage,eff,tdh_zhengqi;
	mapping attack_val = ([
            "base": ([ "weapon" : "sword" ]),//基本功夫类型
            "skill" : ([ "weapon" : "danxin-jian" ]),//高级技能名称
            ]);
	
	if (!me)
		return;
		
	if (!target)
	{
		me->delete_temp("xunlei");
		call_out("xunlei_end", 5+random(3), me);
		return;
	}
	
	extra  =(int)me->query_skill("danxin-jian",1)/5;
	extra +=(int)me->query_skill("cangming-gong",1)/4;
	
	if ( (!objectp(weapon = me->query_temp("weapon"))
	      ||(string)weapon->query("skill_type") != "sword")
	    && (!objectp(weapon = me->query_temp("secondary_weapon"))
	    || (string)weapon->query("skill_type") != "sword") )
  {
	  tell_object(me, "\n你手中无剑，无法继续使用「雨打飞花剑」。\n" NOR);
		me->delete_temp("xunlei");
		call_out("xunlei_end", 5+random(3), me);
    return;
  }

  if ( me->query_temp("xunlei")  ) 
  {
    if ( weapon->query("weapon_prop") == 0 ) {
      tell_object(me, "\n你的"+weapon->name()+"已毁，无法持续「雨打飞花剑」的攻势！\n\n" NOR);
		  me->delete_temp("xunlei");
		  call_out("xunlei_end", 5+random(3), me);
      return;
    }
    else if ( (int)me->query("neili") < 500  ) {
      tell_object(me, "\n你的内力后继不足，不得不停止「雨打飞花剑」的攻势！\n\n" NOR);
		  me->delete_temp("xunlei");
		  call_out("xunlei_end", 5+random(3), me);
      return;
    }
/*    else if ( me->query_skill_mapped("sword") != "danxin-jian" ) {
      tell_object(me, HIR "\n你转而施展其他剑法，无法再以「雨打飞花剑」攻敌！\n\n" NOR);
		  me->delete_temp("xunlei");
		  call_out("xunlei_end", 5+random(3), me);
      return;
    }  */
    else if ( me->is_busy() ) {
      tell_object(me, HIR "\n你现在动作不够灵活，无法继续维持「雨打飞花剑」攻势！\n\n" NOR);
		  me->delete_temp("xunlei");
		  call_out("xunlei_end", 5+random(3), me);
      return;
    }
    else if (!me->is_fighting() || !objectp(target)) {
      tell_object(me,  "\n你现在没有和人过招，当下收回了「雨打飞花剑」的攻势。\n\n" NOR);
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
        message_vision(HIY"\n$N纵身近前，"+weapon->name()+HIY"陡然弯弯弹出，剑尖直刺$n，出招之快真乃为任何剑法所不及！\n\n" NOR, me,target);
      
      if ( me->query_temp("xunlei") ==3 )
        message_vision(HIW"\n$N伸指在"+weapon->name()+HIW"上一弹，剑声嗡嗡，有若龙吟，"+weapon->name()+HIW"颤处，剑锋来势神妙无方！\n\n" NOR, me,target);
      
      if ( me->query_temp("xunlei") ==2 )
        message_vision(HIG"\n$N陡然间大喝一声，"+weapon->name()+HIG"上寒光闪动，喝道：「"+target->name()+HIG"，可小心了！」\n\n" NOR, me,target);
      
      if ( me->query_temp("xunlei") ==1 )
        message_vision(HIR"\n只见$N随手挥剑，"+weapon->name()+HIR"颤处，前后左右，瞬息之间已攻出了四四一十六招！\n\n" NOR, me,target);
      
      me->add("neili", -100);
	    me->start_busy(1);
      extra = extra * me->query_temp("xunlei")/5;
      me->add_temp("apply/attack",extra);
      me->add_temp("apply/damage",extra*2/3);
// 增加命中敌人后的额外攻击 by lordstar
// 主要与浩气苍冥功而不是丹心剑挂钩，主要是为了鼓励留在天地会，因为只有留在天地会才会有很高的苍冥功
// 初始命中级别 C，有天地会大招为 C+
	  rate_fix= 8;
	  tdh_zhengqi = (me->query("safari_skill/tdh_zhengqi")==1 && me->query("family/family_name")=="天地会"); 
	  if (tdh_zhengqi)
		  rate_fix -= 1;
	  i=(int)me->query_skill("force", "cangming-gong");
      damage = i + random(i/3) + me->query_temp("apply/damage");
      damage = (int)damage*7/10;//计算伤害
	  if (tdh_zhengqi)
		  damage += damage/2;
	  maxc = 1 + ((int)me->query_skill("cangming-gong",1)-100) / 200;
	  if (maxc>5) maxc=5;
	  if (tdh_zhengqi)
		  maxc += 1;
	  i=4;    
      me->set_temp("attack_val", attack_val);
	  while (i)
	  {
        if ( !objectp(weapon = me->query_temp("weapon")) ) break;
        me->set_temp("attack_val", attack_val);
		da = COMBAT_D->do_attack(me, target, weapon, TYPE_SPECIAL, 0);
		if (da>0)
		{
			enemy = me->query_enemy();
			count = sizeof(enemy);
			if (count<=0)
			{
				enemy += ({target});
				count = 1;
			}
			while (count>maxc)
			{
				enemy -= ({enemy[random(count)]});
				count = sizeof(enemy);				
			}
			if (random(2))
			{
				me->add("neili", -20-count*30);
				message_vision(HIC"$N顺着刺中"+target->query("name")+HIC"这一剑，身随剑转，"
							 + weapon->name() + HIC"紧接着划出「雨打式」，闪闪寒星如扑面骤雨！\n" NOR, me,target);
				for (j = 0; j < count; j++)
				{
					if ( F_KUNGFU->hit_rate(me->query_skill("force","cangming-gong"), enemy[j]->query_skill("dodge"), rate_fix, me, enemy[j]) ) 
					{
						message_vision(HIY"$n猝不及防，被攻了个措手不及！\n"NOR, me, enemy[j]);
						eff = enemy[j]->query_busy();
						if (!eff)
						{
						  F_KUNGFU->hit_busy("confuse", 3+random((int)me->query_skill("cangming-gong")/50), enemy[j]);
						}
						else if (eff<30)
						{
							enemy[j]->add_busy(3+random(3));
						}
					}
					else
					{
						message_vision(HIY"$n狼狈不堪地躲了过去！\n"NOR, me, enemy[j]);
					}
				}
			}
			else
			{
				me->add("neili", -40-count*40);
				message_vision(HIW"$N顺着刺中"+target->query("name")+HIW"这一剑，掌中"
							+weapon->name()+HIW"顺势一挽，「飞花式」剑光如雪四散而飞！\n" NOR, me,target);
				for (j = 0; j < count; j++)
				{
					if ( F_KUNGFU->hit_rate(me->query_skill("force","cangming-gong"), enemy[j]->query_skill("dodge"), rate_fix, me, enemy[j]) ) 
					{
						message_vision(HIY"$n一不留神，被剑光掠过，身上飞溅出一丛血花！\n"NOR, me, enemy[j]);
						F_KUNGFU->hit_wound("qi", damage, damage/6+random(damage/6), me, enemy[j]);
						COMBAT_D->report_status(enemy[j]);
					}
					else
					{
						message_vision(HIY"$n狼狈不堪地躲了过去！\n"NOR, me, enemy[j]);
					}
				}
			}
		}
		i--;
	  }
      me->add_temp("apply/attack",-extra);
      me->add_temp("apply/damage",-extra*2/3);
  	  me->set_temp("xunlei_attack",1);
      me->set_temp("xunlei", me->query_temp("xunlei")-1);
      call_out("checking", 1, me, target);
		}
  }
  else 
  {
    message_vision(HIY "\n$N顺势圈转手中"+weapon->name()+HIY"，一十六手「雨打飞花剑」已然尽数使出！\n\n" NOR, me, weapon);
	  me->delete_temp("xunlei");
	  me->start_busy(1+random(2));
    call_out("xunlei_end", 5+random(5), me);
  }
  
	me->delete_temp("attack_val");

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