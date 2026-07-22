// lifeheal.c

#include <ansi.h>

void do_heal(object me,object who,int t);

int exert(object me, object target)
{
	object *inv;
	int i,t;
        if( me->is_fighting() )
                return notify_fail("战斗中运功疗伤？找死吗？\n");
	if( me->query_level()<8 )
		return notify_fail("你的人物等级不够。\n");
        if( (int)me->query("force") < 500 )
                return notify_fail("你的真气不够。\n");
	if( me->query_skill("lotusforce",1)<80 )
	        return notify_fail("你的莲台心法级别还不够！\n");        
        if( (int)me->query("eff_kee") < (int)me->query_maxkee() /4 )
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");
	if( me->query("kee")<500 )
		return notify_fail("你现在状态不佳。\n");
	if( time()<me->query_temp("putuo_life")+15 )
		return notify_fail("绝招用多就不灵了。\n");
		
	t = me->query_skill("lotusforce",1)/10;
	t+= me->query_spi();
	t+= me->query_spells_damage()/10;
	
	message_vision(HIY"$N"HIY"盘膝跌坐，默念佛经，背后隐现金莲异象，随着阵阵梵呗之音，一股股浓郁的念力笼罩四周。\n"NOR,me);
	me->add("force",-100);
	me->set_temp("putuo_life",time());
	me->start_busy(2);
	
	if( !me->is_fighting() )
		inv = all_inventory(environment(me));
	else	inv = me->query_team();
	
	if( !inv || !arrayp(inv) || sizeof(inv)<1 )
		do_heal(me,me,t);
	else
	{
		for(i=0;i<sizeof(inv);i++)
		{
			if( !inv[i] || !present(inv[i],environment(me))
			 || !living(inv[i])
			 || inv[i]->is_fighting(me)
			 || ( !userp(inv[i]) && inv[i]->is_fighting() ) )
				continue;
			do_heal(me,inv[i],t);				 
		}
	}	
	return 1;
}

void do_heal(object me,object who,int t)
{
	if( !me || !who || !living(me) || !living(who) )
		return;
	if( t<=0 || me->query("force")<30 )
		return;
	me->add("force",-25);
	message_combatd(HIY"一道金光从$N"HIY"背后卷出，将$n"HIY"笼罩住，顿时$p脸色好了很多。\n"NOR,me,who);
	if( t>who->query_maxkee()/10 )
		t = who->query_maxkee()/10;
	if( t>10 )
		who->receive_heal("kee",t/10);
	who->receive_curing("kee",t);
	if( me!=who )
		who->add_friend(me,1);
}

int help(object me)
{
        string str;
        if( !me )  return 0;
        str = @STR

        内功名称：养命诀
        内功所属：莲台心法
        内功效果：利用佛光瞬间治疗和恢复所在区域所有生物的气血
                  战斗中使用仅对队友有效 
                  使用后冷却15秒，自身busy 2 秒
        内功条件：
        	  人物等级 8 级
        	  内力500点，消耗100点，每恢复一个对象，消耗25点
        	  莲台心法 80 级
STR;
        me->start_more(str);
        return 1;
}