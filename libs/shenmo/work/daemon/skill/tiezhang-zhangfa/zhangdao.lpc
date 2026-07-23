// 掌刀
#include <ansi.h>

inherit F_SSERVER;

void remove_effect(object me, int amount);

int perform(object me, object target)
{
        int skill;

        if(!target ) target = offensive_target(me);
        if(!target || !me->is_fighting(target) )
                return notify_fail("只能在战斗中使用。\n"); 
        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能使用「掌刀」！\n");       
        if((int)me->query("neili") < 500  ) 
                return notify_fail("你的内力不够。\n");
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

        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("你正在运用「凤凰天舞」心法！\n");
        if ((int)me->query_temp("shield"))
                return notify_fail("你已经在运护体神功中了。\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("你正在运用「凤凰天舞」心法！\n");
       if(me->query_temp("wdpowerup") )
       return notify_fail("你现在正在使用「五毒神功」的绝技。\n"); 
       if(me->query_temp("zhuihun/lpf")) 
       return notify_fail("你正在使用五毒追魂钩之「乱披风」\n"); 

       if(me->query_temp("anran")) 
       return notify_fail("你现在正在使用「黯然」绝技。\n"); 

        if((int)me->query_temp("tzzf") ) 
                return notify_fail("你已经在掌刀的运功中。\n");
        if((int)me->query_skill("tiezhang-zhangfa", 1) < 120 )
                return notify_fail("你的铁掌掌法还不够娴熟，使不出「掌刀」来。\n");
        if((int)me->query_skill("force") < 140 )
                return notify_fail("你的内功等级不够，使不出「掌刀」来。\n");
        if((int)me->query_str() < 25 )
                return notify_fail("你的膂力还不够强劲，使不出「掌刀」来。\n");
        if( (int)me->query_skill("guiyuan-tunafa", 1) < 120 )
                return notify_fail("你的归元土吐纳法等级还不够，使不出「掌刀」绝技。\n");

   if (me->query_skill_mapped("unarmed") != "tiezhang-zhangfa"
     ||me->query_skill_prepared("strike") != "tiezhang-zhangfa")
                return notify_fail("你没有把铁掌做为基本招架和备为掌法。\n");


        skill = me->query_skill("tiezhang-zhangfa") ;
        skill = skill + me->query_skill("tiezhang-zhangfa")*2;
        skill = skill / 3+1;
        me->add("neili", -((int)me->query_skill("tiezhang-zhangfa",1)+100));

        message_vision(YEL "$N突然面色苍白，双手颤抖，随即两眼神光一闪，一双手掌颜色变的雪白，发出一种奇怪的光芒！\n" NOR, me, target);
        me->set_temp("tzzf", 1);
        me->add_temp("apply/attack", skill);
        me->add_temp("apply/defense", skill*2);
        me->add_temp("apply/damage", skill*2);
        me->add_temp("apply/armor", skill*2);
                me->start_busy(2);     
        me->add("neili",-200);
        me->start_call_out( (: call_other, this_object(), "remove_effect", me, skill :), skill/2);
        return 1;

}

void remove_effect(object me, int amount)
{        
        int skill;
if (me)
{
        skill = me->query_skill("tiezhang-zhangfa") ;
        skill = skill + me->query_skill("tiezhang-zhangfa")*2;
        skill = skill / 3+1;
		me->delete_temp("tzzf");
                 me->start_busy(1);     
        me->add_temp("apply/attack", -skill);
        me->add_temp("apply/defense", -skill*2);
        me->add_temp("apply/damage", -skill*2);
        me->add_temp("apply/armor", -skill*2);
}
        message_vision(YEL "\n$N掌刀运功完毕，双手逐渐恢复了原状。\n" NOR, me);        
}
