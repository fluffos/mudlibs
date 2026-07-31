//扭转乾坤
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
inherit F_CLEAN_UP;

int remove_effect(object me,int p)
{
	int tmp,tmp2;
	if( me )
	{
		tmp = me->query_maxkee()-me->query("eff_kee");
		tmp2 = me->query("eff_kee")-me->query("kee");
		me->add_temp("apply/max_kee",-p);
		me->add("eff_kee",-p-tmp);
		if( me->query("eff_kee")>me->query_maxkee() )
			me->set("eff_kee",me->query_maxkee());
		me->add("kee",-p-tmp2);
		if( me->query("kee")>me->query("eff_kee"))
			me->set("kee",me->query("eff_kee"));		
		tmp = me->query_maxsen()-me->query("eff_sen");	
		tmp2 = me->query("eff_sen")-me->query("sen");
		me->add_temp("apply/max_sen",-p);
		me->add("eff_sen",-p-tmp);
		if( me->query("eff_sen")>me->query_maxsen() )
			me->set("eff_sen",me->query_maxsen());	
		me->add("sen",-p-tmp2);
		if( me->query("sen")>me->query("eff_sen"))
			me->set("sen",me->query("eff_sen"));		
		me->delete_temp("powerup");	
		message_vision(YEL"$N"YEL"撤去了黄牙老象的妖身。\n"NOR,me);	
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
        if((int)me->query("kee") < 300 )
                return notify_fail("你体力不足，用不了扭转乾坤！\n");
        if((int)me->query("sen") < 300 )
                return notify_fail("你神智不清，用不了扭转乾坤！\n");
	if((int)me->query_skill("dengxian-dafa", 1) < 200 )
		return notify_fail("你的登仙大法还不够纯熟。\n");
	if((int)me->query("mana") < 300 )
		return notify_fail("你的法力不足以变作神象伤敌！\n");
	if( time()<me->query_temp("xueshan_juanbi")+6 )
		return notify_fail("你不能频繁化象。\n");
	if( me->query_temp("powerup") && me->query_temp("powerup")!="juanbi" )
		return notify_fail("你施展了其他绝技，现在化不了黄牙象。\n");		
		
	if( !target ) target = offensive_target(me);

	if( !target
	||  !target->is_character()
	||  target->is_corpse()
	||  target==me
	|| !me->is_fighting(target) )
		return notify_fail("你要对谁用扭转乾坤？\n");

	if( me->query_temp("powerup") )
	        msg = HIW"$N"HIW"趁$n"HIW"不备，怒吼一声，伸出蛟龙般的鼻子向$p卷去！\n" NOR;
	else	msg = HIW"$N"HIW"趁$n"HIW"不备，怒吼一声，转瞬间化作一只黄牙老象，伸出蛟龙般的鼻子向$p卷去！\n" NOR;
	succ_msg = HIW "$n"HIW"促不击防，被$N"HIW"的长鼻高高卷起，$N"HIW"用力一甩，$n"HIW"如断了线的风筝般飞了出去！\n"NOR;
	p = (me->query_level()+me->is_knowing("xueshan_juanbi"))*10;
	if( !me->query_temp("powerup") )
	{
		me->add("mana",-100);
		me->set_temp("powerup","juanbi");
		tmp = me->query_maxkee()-me->query("eff_kee");
		tmp2 = me->query("eff_kee")-me->query("kee");
		me->add_temp("apply/max_kee",p);
		me->add("eff_kee",p-tmp);
		if( me->query("eff_kee")>me->query_maxkee() )
			me->set("eff_kee",me->query_maxkee());
		me->add("kee",p-tmp);
		if( me->query("kee")>me->query("eff_kee"))
			me->set("kee",me->query("eff_kee"));		
			
		tmp = me->query_maxsen()-me->query("eff_sen");	
		tmp2 = me->query("eff_sen")-me->query("sen");
		me->add_temp("apply/max_sen",p);
		me->add("eff_sen",p-tmp);
		if( me->query("eff_sen")>me->query_maxsen() )
			me->set("eff_sen",me->query_maxsen());
		me->add("sen",p-tmp2);
		if( me->query("sen")>me->query("eff_sen"))
			me->set("sen",me->query("eff_sen"));		
		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, p:), (int)me->query_skill("spells")/5);
	}	

	me->set_temp("xueshan_juanbi",time());
	me->receive_damage("sen",50,me);	
	me->add("mana",-100);
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_CAST,msg,succ_msg);
	me->set_temp("pfm_msg",0);
	
	if( damage>0 )
	{
		t = me->query_skill("dengxian-dafa",1)/50;
		if( t>6 ) t = 6;
		if( target->is_busy() )
		{
			t = t/3;
			if( t>0 )
				target->start_busy((int)target->query_busy()+t);
		}
		else	target->start_busy(t);
	}
	
	else
	{
		message_combatd(HIW "不料$n"HIW"早有准备，扭转身形轻舒猿臂一把抓住了$N"HIW"的鼻子！$N"HIW"疼得一声闷哼，身不由己的被$n"HIW"拖了过去！\n"NOR,me,target);
		me->receive_damage("kee",150,me,TYPE_CAST);
		me->start_busy(3);
        }
        return 1;
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        法术名称：扭转乾坤
        法术所属：登仙大法
        法术效果：一定时间内化作黄牙老象妖身
        	  老象妖身状态下使用则会使对方busy
        	  黄牙老象妖身状态下气血、精神上限增加	
		  冷却时间6秒，失败则自身busy 2 秒
		  不能与魔兽吞天混用
        法术条件：
                  雪山(出师)弟子
        	  人物等级25级
                  法力300点，化象消耗100点，卷鼻消耗100点
                  精神300点，消耗50点
                  气血300点，失败则消耗150点
                  登仙大法 200 级
                  
STR;
        me->start_more(str);
        return 1;
}
