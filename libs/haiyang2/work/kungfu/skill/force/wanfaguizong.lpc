// zongjue.c

#include <ansi.h>

inherit F_CLEAN_UP;

int check_fight(object me);
void remove_effect(object me, int skill);

int exert(object me, object target)
{
        int skill;
        if( target != me ) return
            notify_fail("你只能对自己用["+HIG+"万法归宗"+NOR+"]\n"NOR,);

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

	if ((int)me->query_skill("force", 1) < 400)
		return notify_fail("你的基本内功太差了。\n");
        if( (int)me->query("neili") < 500 )
        	return notify_fail("你的内力不够。\n");

        if( (int)me->query_temp("hslj/powerup") )
        	return notify_fail("你已经在运功中了。\n");
	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");
        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");
        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");
	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("你的内力不够。\n");

	me->set_temp("hslj/powerup", 1);
        skill = me->query_skill("force");

        me->add("neili", -me->query("max_neili")/7);

if (skill > 1000) skill = 1000;
        message_combatd(HIM"$N综合本门内外功，万法精聚于丹田，千招归综于全身！\n" NOR, me);
        me->add_temp("apply/armor", skill/2);
  tell_object(me,HIG"你的防护力提高了!\n"NOR);
        me->add_temp("apply/attack", skill/4);
  tell_object(me,HIG"你的攻击力提高了!\n"NOR);
        me->add_temp("apply/dodge", skill/4);
  tell_object(me,HIG"你的躲闪力提高了!\n"NOR);
        me->add_temp("apply/defense", skill/4);
  tell_object(me,HIG"你的防御力提高了!\n"NOR);
        me->add_temp("apply/damage", skill/3);
  tell_object(me,HIG"你的杀伤力提高了!\n"NOR);
        me->add_temp("apply/strength",skill/20);
  tell_object(me,HIG"你的力量提高了!\n"NOR);
        me->add_temp("apply/dexerity",skill/20);
  tell_object(me,HIG"你的速度提高了!\n"NOR);
        me->add_temp("apply/constitution",skill/20);
  tell_object(me,HIG"你的根骨提高了!\n"NOR);
        me->add_temp("apply/intelligence",skill/20);
  tell_object(me,HIG"你的悟性提高了!\n"NOR);
	check_fight(me);
        me->start_call_out((:call_other,__FILE__,"remove_effect",me,skill:),skill);
        if( me->is_fighting() ) me->start_busy(1);
        return 1;
}

int check_fight(object me)
{
	if (!me || !(int)me->query_temp("hslj/powerup")) return 0;
        if (!me->is_ghost() && living(me)
            && me->is_fighting() && me->query("neili") > 800
            && me->query_skill_mapped("force") != "jiuyin-zhengong")
        {
                if(me->query("qi") < (int)me->query("max_qi")){
                        message_vision(HIW"$N头顶出现了一阵白烟又恢复正常，内劲四溢。\n"NOR,me);
                        me->add("neili", -80);
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
        me->delete_temp("hslj/powerup");
        me->add_temp("apply/armor", -skill/2);
        me->add_temp("apply/attack", -skill/4);
        me->add_temp("apply/dodge", -skill/4);
        me->add_temp("apply/defense", -skill/4);
        me->add_temp("apply/damage", -skill/3);
        me->add_temp("apply/strength",-skill/20);
        me->add_temp("apply/dexerity",-skill/20);
        me->add_temp("apply/constitution",-skill/20);
        me->add_temp("apply/intelligence",-skill/20);
        tell_object(me, "你的["+HIG+"万法归宗"+NOR+"]运行完毕。身法又变回了正常！\n");
}

