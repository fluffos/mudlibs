// zongjue.c

#include <ansi.h>

inherit F_CLEAN_UP;

int check_fight(object me);
void remove_effect(object me, int skill);

int exert(object me, object target)
{
        int skill;
	if (!me->query("jiuyin/full") && !me->query("jiuyin/shang") && !me->query("jiuyin/gumu"))
		return notify_fail("你无法使用九阴真功。\n");
//	if (!me->query("jiuyin/full") && !me->query("jiuyin/shang") && me->query("jiuyin/gumu") && (int)me->query_skill("jiuyin-zhengong", 1) > 100)
//		return notify_fail("你无法使用九阴真功。\n");
        if( target != me ) return
            notify_fail("你只能对自己用["+HIB+"九阴总诀"+NOR+"]\n"NOR,);
        if( (int)me->query_temp("powerupxtg") ) return
            notify_fail("你已经在先天大法了。\n");
        if( (int)me->query_temp("poweruptxg") ) return
            notify_fail("你已经在运太玄功了。\n");
        if( (int)me->query_temp("powerupkh") ) return
            notify_fail("你已经在运葵花无敌功了。\n");
        if( (int)me->query_temp("liuyun") ) 
            return notify_fail(HIG"你已经在默运流云水袖神功了。\n");
        if( (int)me->query_temp("qzj_tong") ) 
                return notify_fail("你已经在运同归剑了。\n");
        if( (int)me->query_temp("powerup") )
        	return notify_fail("你已经在运别的内功中了。\n");
      if( me->query_temp("fumo")   )
      return notify_fail("你正在使用大金刚拳的特殊攻击「金刚伏魔」！\n");
      if( me->query_temp("jingang")   )
      return notify_fail("你正在使用大金刚拳的特殊攻击「大金刚神通」！\n");
      if( me->query_temp("fanzhen")   )
                return notify_fail("你正在运用「金刚不坏体神功」！\n");
        if((int)me->query_temp("tzzf") ) 
                return notify_fail("你已经在掌刀的运功中。\n");
        if ((int)me->query_temp("shield"))
                return notify_fail("你已经在运护体神功中了。\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("你正在运用「凤凰天舞」心法！\n");

       if(me->query_temp("anran")) 
       return notify_fail("你现在正在使用「黯然」绝技。\n"); 
       if(me->query_temp("anran")) 
       return notify_fail("你现在正在使用「黯然」绝技。\n"); 
       if(me->query_temp("wdpowerup") )
       return notify_fail("你现在正在使用「五毒神功」的绝技。\n"); 
       if(me->query_temp("zhuihun/lpf")) 
       return notify_fail("你正在使用五毒追魂钩之「乱披风」\n"); 

	if ((int)me->query_skill("jiuyin-zhengong", 1) < 200)
		return notify_fail("你的九阴真功太差了。\n");
        if( (int)me->query("neili") < 700 )
        	return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("jiuyin/powerup") )
        	return notify_fail("你已经在运功中了。\n");

	me->set_temp("jiuyin/powerup", 1);
        skill = me->query_skill("force");

        me->add("neili", -600);
        me->receive_damage("qi",0);

        message_combatd(HIB"$N运起了九阴总诀，瞬间将丹田之气运转一周天，功夫威力陡然大增！\n" NOR, me);
        me->add_temp("apply/armor", skill/2);
        me->add_temp("apply/attack", skill/3);
        me->add_temp("apply/dodge", skill/3);
        me->add_temp("apply/damage", skill/3);
        me->add_temp("apply/strength",skill/25);
        me->add_temp("apply/dexerity",skill/25);
        me->add_temp("apply/constitution",skill/25);
        me->add_temp("apply/intelligence",skill/25);
	check_fight(me);
        me->start_call_out((:call_other,__FILE__,"remove_effect",me,skill:),skill);
        if( me->is_fighting() ) me->start_busy(2);
        return 1;
}

int check_fight(object me)
{
	if (!me || !(int)me->query_temp("jiuyin/powerup")) return 0;
        if (!me->is_ghost() && living(me)
            && me->is_fighting() && me->query("neili") > 500
            && me->query_skill_mapped("force") == "jiuyin-zhengong")
        {
                if(me->query("qi") < (int)me->query("max_qi")){
                        message_vision(HIY"$N脸色一沈又回复正常，想是正在调节内息。\n"NOR,me);
                        me->add("neili", -200);
                        me->add("eff_qi",me->query_skill("force")/2);
			if (me->query("eff_qi") > me->query("max_qi")) me->set("eff_qi", me->query("max_qi"));
                        me->add("qi",me->query_skill("force"));
			if (me->query("qi") > me->query("eff_qi")) me->set("qi", me->query("eff_qi"));
                        }
        }
        call_out("check_fight", 2, me);
        return 1;
}       

void remove_effect(object me, int skill)
{
        me->delete_temp("jiuyin/powerup");
        me->add_temp("apply/armor", -skill/2);
        me->add_temp("apply/attack", -skill/3);
        me->add_temp("apply/dodge", -skill/3);
        me->add_temp("apply/damage", -skill/3);
        me->add_temp("apply/strength",-skill/25);
        me->add_temp("apply/dexerity",-skill/25);
        me->add_temp("apply/constitution",-skill/25);
        me->add_temp("apply/intelligence",-skill/25);
        tell_object(me, "你的["+HIB+"九阴总诀"+NOR+"]运行完毕，将内力收回丹田。\n");
}

