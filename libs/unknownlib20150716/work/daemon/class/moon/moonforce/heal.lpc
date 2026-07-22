//moonforce--heal.c
#include <ansi.h>
inherit F_CLEAN_UP;

void do_heal(object who,int t);

int valid_exert(object me)
{
        if( me->is_fighting() )
                return notify_fail("战斗中运功疗伤？找死吗？\n");
	if( me->query_level()<15 )
		return notify_fail("你的人物等级不够。\n");
        if( (int)me->query("force") < 500 )
                return notify_fail("你的真气不够。\n");
	if( me->query("eff_kee")>=me->query_maxkee() )
		return notify_fail("现在不需要。\n");                
        if( (int)me->query("eff_kee") <= (int)me->query_maxkee()/5 )
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");
	if( me->query_skill("moonforce",1)/10<=0 )
		return notify_fail("你的圆月心法级别还不够！\n");
	if( time()<me->query_temp("moon_heal")+15 )
		return notify_fail("绝招用多就不灵了。\n");
	if( me->query_temp("heal") )
		return notify_fail("你目前已经在疗伤状态了。\n");
	return 1;	
}

int exert(object me, object target)
{
	int t;
	
	if( !valid_exert(me) )
		return 0;	
			
	t = me->query_skill("moonforce",1)/10;
	if( t>30 )
		t = 30;	
	message_vision(HIW"$N"HIW"运转「圆月心法」，背后隐现圆月异象，随着圆月缓缓转动，一股股浓郁的太阴之力笼罩$N"HIW"全身。\n"NOR,me);
	me->add("force",-100);
	me->set_temp("heal",1);
	me->set("force_factor", 0);
	call_out("do_heal",0,me,t);
        return 1;
}

void remove_eff(object who)
{
	if( !who )
		return;
	message_vision(HIW"$N"HIW"背后的圆月异象渐渐淡出。。。。\n"NOR,who);
	who->set_temp("moon_heal",time());
	who->delete_temp("heal");
	if( !who->is_busy() )
		who->start_busy(1);
}			

void do_heal(object who,int t)
{
	int p;
	if( !who )
		return;
	if( t<=0 || who->query("force")<10 || !living(who) )
	{
		remove_eff(who);
		return;
	}
	if( who->query("eff_kee")<who->query_maxkee() )
	{
		who->add("force",-10);
		message_combatd(HIW"$N"HIW"背后圆月缓缓转动，一缕缕太阴之气招展垂下，潜移默化中修复其身心。。。。\n"NOR,who);
		p = who->query_spi()+who->query_str();
		if( p>100 )
			p = 100;
		p = p/2+random(p);
		p+= p*(int)who->query_temp("apply/receive_curing_kee")/100;
		who->receive_curing("kee", p+1);
		if( p/10>0 )
			who->receive_heal("kee",p/10);
		t--;
	}	
	call_out("do_heal",0,who,t);
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        内功名称：疗伤诀
        内功所属：圆月心法
        内功效果：运转圆月心法，利用太阴之气一定时间内持续治疗和恢复自身气血
                  使用后冷却15秒
        内功条件：
        	  人物等级 15 级
                  内力500点，消耗100点，恢复期间每恢复一次，消耗10点
STR;
        me->start_more(str);
        return 1;
}