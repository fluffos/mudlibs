#include <ansi.h>
#include <combat.h>
inherit SSERVER;
inherit F_CLEAN_UP;

int remove_effect(object me,int p)
{
	if( me )
	{
		me->add_temp("apply/combat_damage",-p);
		me->add_temp("apply/spells_damage",-p);
		me->delete_temp("powerup");	
		message_vision(YEL"$N"YEL"撤去了青面狮子的妖身。\n"NOR,me);	
	}
}

int cast(object me, object target)
{
        string msg,succ_msg;
	int t,damage,p,tmp,tmp2;
	
	if( me->query_level()<25 )
		return notify_fail("你的人物等级不够。\n");
	if( me->query("family/family_name")!="大雪山" 
         && me->query("chushi/chushi_xueshan")!="yes")
		return notify_fail("你不能使用这项技能！\n");
        if((int)me->query("sen") < 300 )
                return notify_fail("你神智不清，用不了魔兽吞天！\n");
	if((int)me->query_skill("dengxian-dafa", 1) < 200 )
		return notify_fail("你的登仙大法还不够纯熟。\n");
	if((int)me->query("mana") < 300 )
		return notify_fail("你的法力不足以变作青狮伤敌！\n");
	if( time()<me->query_temp("xueshan_tuntian")+6 )
		return notify_fail("你不能频繁化狮。\n");
	if( me->query_temp("powerup") && me->query_temp("powerup")!="tuntian" )
		return notify_fail("你施展了其他绝技，现在化不了青狮。\n");		
		
	if( !target ) target = offensive_target(me);

	if( !target
	||  !target->is_character()
	||  target->is_corpse()
	||  target==me
	|| !me->is_fighting(target) )
		return notify_fail("你要对谁用魔兽吞天？\n");

	msg = HIC"$N"HIC"现出妖身，化作一只青面獠牙的狮子，张开血盆大口向$n"HIC"咬去！\n" NOR;
	succ_msg = HIR"结果$n"HIR"给青面狮子吓得辨不清方向，被咬了个正着！\n"NOR;
	p = (me->query_level()+me->is_knowing("xueshan_tuntian"))*15;
	if( !me->query_temp("powerup") )
	{
		me->add("mana",-100);
		me->set_temp("powerup","tuntian");
		me->add_temp("apply/combat_damage",p);
		me->add_temp("apply/spells_damage",p);
		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, p:), (int)me->query_skill("spells")/5);
	}	

	me->set_temp("xueshan_tuntian",time());
	me->receive_damage("sen",100,me);	
	me->add("mana",-100);
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_CAST,msg,succ_msg);
	me->set_temp("pfm_msg",0);
	
	if( damage>0 && !target->is_hunluan() )
	{
		t = me->query_skill("dengxian-dafa",1)/50;
		if( t>6 ) t = 6;
		target->start_hunluan(t,HIR"你被"+me->name()+HIR"所化的青面狮子吓得神智不清！\n"NOR);
	}
	me->start_busy(2);
        return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        法术名称：魔兽吞天
        法术所属：登仙大法
        法术效果：一定时间内化作青面狮子妖身
        	  青狮妖身状态下使用则会使对方陷入混乱
        	  青狮妖身状态下物理、法术攻击增加	
		  使后自身busy 2 秒
		  不能与扭转乾坤混用
        法术条件：
                  雪山(出师)弟子
        	  人物等级25级
                  法力300点，化狮消耗100点，吞天消耗100点
                  精神300点，消耗100点
                  登仙大法 200 级
                  
STR;
        me->start_more(str);
        return 1;
}
