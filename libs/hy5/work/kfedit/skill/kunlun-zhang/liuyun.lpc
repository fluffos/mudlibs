// luiyun.c 流云水袖

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

void remove_effect(object me, int aamount, int damount);

int perform(object me, object target)
{
        object weapon;  
        string msg;
        int d_count, count, qi, maxqi, skill;

        if( (int)me->query_temp("liuyun") ) 
                return notify_fail(HIG"你已经在默运流云水袖神功了。\n");

        if( (int)me->query_temp("qzj_tong") ) 
                return notify_fail("你已经在运同归剑了。\n");

        if((int)me->query_temp("tzzf") ) 
                return notify_fail("你已经在掌刀的运功中。\n");
      if( me->query_temp("fumo")   )
      return notify_fail("你正在使用大金刚拳的特殊攻击「金刚伏魔」！\n");
      if( me->query_temp("jingang")   )
      return notify_fail("你正在使用大金刚拳的特殊攻击「大金刚神通」！\n");
      if( me->query_temp("fanzhen")   )
                return notify_fail("你正在运用「金刚不坏体神功」！\n");

        if( !me->is_fighting() )
        return notify_fail("「流云水袖」只能在战斗中使用。\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("你正在运用「凤凰天舞」心法！\n");
        if ((int)me->query_temp("shield"))
                return notify_fail("你已经在运护体神功中了。\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("你正在运用「凤凰天舞」心法！\n");

       if(me->query_temp("anran")) 
       return notify_fail("你现在正在使用「黯然」绝技。\n"); 
       if(me->query_temp("wdpowerup") )
       return notify_fail("你现在正在使用「五毒神功」的绝技。\n"); 
       if(me->query_temp("zhuihun/lpf")) 
       return notify_fail("你正在使用五毒追魂钩之「乱披风」\n"); 


    if( (int)me->query("neili") < 400 )
                return notify_fail("你的内力还不够高！\n");

        if( (int)me->query_skill("xuantian-wuji", 1) < 60)
                return notify_fail("你的玄天无极功的修为不够，不能使用流云水袖! \n");

        if( (int)me->query_skill("strike", 1) < 80 )
                return notify_fail("你的基本掌法还不到家，无法使用流云水袖！\n");

        if( me->query_skill_mapped("strike") != "kunlun-zhang") 
                return notify_fail("你没有激发昆仑掌，无法使用流云水袖！\n");
   if(me->query_skill_mapped("force") != "xuantian-wuji" )
	return notify_fail("你没有用玄天无极。\n");

//        if( me->query_temp("apply/strength", 1) > 1 )
//                return notify_fail("你还在使用太玄功一类的功夫，不能使用流云水袖！\n");
       
//        if( me->query_temp("apply/dexerity", 1) > 1 )
//                return notify_fail("你还在使用太玄功一类的功夫，不能使用流云水袖！\n");
        
msg = HIR "$N轻喝一声使出昆仑掌中的绝学「流云水袖」，臂力陡然增加，衣袖横扫敌人的面门！\n" NOR;
        
        qi = me->query("qi");
        maxqi = me->query("max_qi");
        skill = (int) (me->query_skill("kunlun-zhang",1) / 3);
        count = (int) (me->query_skill("kunlun-zhang",1) / 3);
        d_count = (int) (me->query_skill("kunlun-zhang",1) / 5);

        if(qi > (maxqi * 0.1))
        {       
        message_vision(msg, me, target);

                me->add_temp("apply/strength", count); 
                me->add_temp("apply/dexerity", d_count);
                me->add_temp("apply/armor", count+100);
                me->add_temp("apply/damage", count+100);
                me->set_temp("liuyun", 1);
                //me->start_busy(3);     
                me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count*2, d_count :), skill);

                me->add("neili", -300);
        return 1;
        }
        else{
                msg = HIR "$N拼尽毕生功力使出了昆仑掌中的终极绝技「流云水袖」， 全身骨骼一阵爆响, 欲与敌人同归于尽!\n" NOR;
                message_vision(msg, me, target);
                me->add_temp("apply/strength", count);
                me->add_temp("apply/dexerity", d_count);
                me->add_temp("apply/armor", count+100);
                me->add_temp("apply/damage", count+100);
                me->set_temp("liuyun", 1);
                //me->start_busy(3);     
                me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count*9, 0 :), 2);
                me->add("neili", -300);

                return 1;


        }
}

void remove_effect(object me, int aamount, int damount)
{
        int d_count, count;
        count = (int) (me->query_skill("kunlun-zhang",1) / 3);
        d_count = (int) (me->query_skill("kunlun-zhang",1) / 5);
        
        if ( (int)me->query_temp("liuyun") ) 
        {
                me->add_temp("apply/strength", -count); 
                me->add_temp("apply/dexerity", -d_count);
                me->add_temp("apply/armor", -(count+100));
                me->add_temp("apply/damage", -(count+100));
                me->delete_temp("liuyun");
                tell_object(me, HIY "你的「流云水袖」神功运行完毕，将内力收回丹田。\n" NOR);
                me->start_busy(2);
        }
}

