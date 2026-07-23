// luanpifeng.c 乱披风 
// by snowman@SJ 30/09/1999

#include <ansi.h>

inherit F_SSERVER;
int remove_effect(object me);

int perform(object me, object target)
{
    object weapon = me->query_temp("weapon");  
    int skill;
    
    if( !target ) target = offensive_target(me);
     
    if( !target || !me->is_fighting(target))
                return notify_fail("「乱披风」只能在战斗中对对手使用。\n");
    
    
 	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("「乱披风」开始时必须拿着一把剑！\n");
     
	if( (int)me->query("neili") < 100 )
		return notify_fail("你的真气不够！\n");

        if( (int)me->query_skill("wudu-shengong",1) < 50 )
                return notify_fail("你的五毒神功修为还不够！\n");

	if( (int)me->query_skill("sword",1) < 50 ||
	    me->query_skill_mapped("sword") != "wudu-goufa")
		return notify_fail("你的五毒钩法还不到家，无法使用乱披风！\n");

	if( (int)me->query_skill("wudu-goufa",1) < 50 )
		return notify_fail("你的五毒钩法还不到家，无法使用乱披风！\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("你正在运用「凤凰天舞」心法！\n");

        if( (int)me->query_temp("liuyun") ) 
                return notify_fail(HIG"你已经在默运流云水袖神功了。\n");

        if( (int)me->query_temp("qzj_tong") ) 
                return notify_fail("你已经在运同归剑了。\n");
      if( me->query_temp("fumo")   )
      return notify_fail("你正在使用大金刚拳的特殊攻击「金刚伏魔」！\n");
      if( me->query_temp("jingang")   )
      return notify_fail("你正在使用大金刚拳的特殊攻击「大金刚神通」！\n");
      if( me->query_temp("fanzhen")   )
                return notify_fail("你正在运用「金刚不坏体神功」！\n");

        if((int)me->query_temp("tzzf") ) 
                return notify_fail("你已经在掌刀的运功中。\n");

    if ( (int)me->query_temp("zhuihun/lpf") ) 
        return notify_fail("你正在使用五毒追魂钩之「乱披风」。\n");

    message_vision(HIY "\n$N将发结解开，披头散发，脸色突然变白，手中的"+weapon->name()+"也跟着剧烈抖动着！
突然$P一声狂嚎，如神哭鬼号似的厉啸响自天地，发疯似的将五毒追魂钩狂乱使出！\n"NOR, me);                 
    
    skill = me->query_skill("wudu-goufa", 1);
    
    	me->add_temp("apply/attack",  skill/3);
//    	me->add_temp("apply/dodge",  skill/4);

    	
    	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
    	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
    	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
    	me->set_temp("ryb_fumo", 1);
	me->set_temp("zhuihun/lpf",1);
me->start_busy(3);
//	me->start_perform(1, "乱披风");
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me:), skill/3 );
        return 1;
}

int remove_effect(object me)
{
	if(!me) return 0;
        me->add_temp("apply/attack", - (me->query_skill("wudu-goufa", 1)/3));
//        me->add_temp("apply/dodge", - (me->query_skill("wudu-goufa", 1)/4));
        me->delete_temp("zhuihun/lpf");
        if(living(me))
        	message_vision(HIG "\n$N大口大口地喘气，招数也渐渐恢复正常，看来是消耗了不少的气力！\n\n" NOR, me);

        return 0;
}

