// jingsng.c 金刚拳 大金刚神通

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

void remove_effect(object me, int aamount, int damount);

int perform(object me, object target)
{
	object weapon, ob;	
  	string msg;
	int d_count, count, qi, maxqi, skill;

	if( !me->is_fighting() )
    	return notify_fail("「大金刚神通」只能在战斗中使用。\n");
      if( !target ) target = offensive_target(me);
        if( (int)me->query_temp("liuyun") ) 
                return notify_fail(HIG"你已经在默运流云水袖神功了。\n");

        if( (int)me->query_temp("qzj_tong") ) 
                return notify_fail("你已经在运同归剑了。\n");

        if((int)me->query_temp("tzzf") ) 
                return notify_fail("你已经在掌刀的运功中。\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("你正在运用「凤凰天舞」心法！\n");
       if(me->query_temp("anran")) 
       return notify_fail("你现在正在使用「黯然」绝技。\n"); 
       if(me->query_temp("wdpowerup") )
       return notify_fail("你现在正在使用「五毒神功」的绝技。\n"); 
       if(me->query_temp("zhuihun/lpf")) 
       return notify_fail("你正在使用五毒追魂钩之「乱披风」\n"); 

      if( me->query_temp("fumo")   )
      return notify_fail("你正在使用大金刚拳的特殊攻击「金刚伏魔」！\n");
      if( me->query_temp("jingang")   )
      return notify_fail("你正在使用大金刚拳的特殊攻击「大金刚神通」！\n");
      if( me->query_temp("fanzhen")   )
                return notify_fail("你正在运用「金刚不坏体神功」！\n");
	if( (int)me->query_temp("zuida") ) 
		return notify_fail(HIG"你内息翻滚在八仙醉打中，一时提不起易筋经神功。\n"NOR);

      if( !target || !me->is_fighting(target) )
      return notify_fail("「大金刚神通」只能在战斗中对对手使用。\n");
             
      if( objectp(me->query_temp("weapon")) )
      return notify_fail("你必须空手使用「大金刚神通」！\n");

    if( (int)me->query("neili") < 500 )
		return notify_fail("你的内力还不够高！\n");

	if( (int)me->query_skill("hunyuan-yiqi", 1) < 60)
		return notify_fail("你的混元一气功的修为不够，不能使用大金刚神通! \n");

	if( (int)me->query_skill("cuff") < 150 )
		return notify_fail("你的拳法还不到家，无法使用大金刚神通！\n");

	if( me->query_skill_mapped("cuff") != "jingang-quan") 
		return notify_fail("你没有激发金刚拳，无法使用大金刚神通！\n");
	
//        if( me->query_temp("apply/strength", 1) > 1 )
//                return notify_fail("你还在使用太玄功一类的功夫，不能使用大金刚神通！\n");
       
//        if( me->query_temp("apply/dexerity", 1) > 1 )
//                return notify_fail("你还在使用太玄功一类的功夫，不能使用大金刚神通！\n");

	
    msg = HIY "$N使出大金刚拳的绝技「大金刚神通」，臂力陡然增加！\n" NOR;
	
	qi = me->query("qi");
	maxqi = me->query("max_qi");
	skill = (int) (me->query_skill("jingang-quan",1) / 3);
	count = (int) (me->query_skill("jingang-quan",1) / 3);
	d_count = (int) (me->query_skill("jingang-quan",1) / 5);

	if(qi > (maxqi * 0.1))
	{	
	if( (int)me->query_temp("jingang") ) 
		return notify_fail(HIG"你已经在运功中了。\n");

    	message_vision(msg, me, target);
		
		me->add_temp("apply/strength", count);	
		me->add_temp("apply/dexerity", d_count);
		me->set_temp("jingang", 1);
		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count*2, d_count :), skill);

		me->add("neili", -300);
    	return 1;
	}
	else{
		msg = HIR "$N拼尽毕生功力使出了大金刚拳的终极绝技, 全身骨骼一阵爆响, 欲与敌人同归于尽!\n" NOR;
		message_vision(msg, me, target);
		me->add_temp("apply/strength", count);	
		me->add_temp("apply/dexerity", d_count);
		me->set_temp("jingang", 1);

		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count*9, 0 :), 2);

                ob = me->select_opponent();
		COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
		COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
		COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);		
		msg = HIR "$N用尽了最后一点气力, 喷出一口鲜血, 一头栽倒在地!\n" NOR;
		message_vision(msg, me, target);
		me->add("neili", -300);
		return 1;
	}
}

void remove_effect(object me, int aamount, int damount)
{
	int d_count, count,  skill;	
	count = (int) (me->query_skill("jingang-quan",1) / 3);
	d_count = (int) (me->query_skill("jingang-quan",1) / 5);
	if ( (int)me->query_temp("jingang") ) 
	{
		me->add_temp("apply/strength", -count);	
		me->add_temp("apply/dexerity", -d_count);
		me->delete_temp("jingang");
		tell_object(me, HIY "你的大金刚神通运行完毕，将内力收回丹田。\n" NOR);
	}
}
