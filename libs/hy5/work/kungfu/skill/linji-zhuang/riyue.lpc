// riyun.c

#include <ansi.h>

int exert(object me)
{	
	int nb, nx, nh, improve;
	nx = (int)me->query("max_qi", 1);
	nb = (int)me->query("eff_jing", 1);
	nh = (int)me->query_skill("linji-zhuang", 1);
	if( me->is_fighting() )
		return notify_fail("战斗中运功？找死吗？\n");

	if ((int)me->query_skill("linji-zhuang", 1) < 150)
		return notify_fail("你的临济十二庄修为还不够。\n");

	if( (int)me->query("neili") < 150 )
		return notify_fail("你的真气不够。\n");
	
      if( me->query_temp("yun_riyue")   )
     		return notify_fail("你正在运用临济十二庄的「日月」字决！\n");

	write(MAG"你席地而坐，五心向天，运行日月二庄，益气升阳，益阴潜阳，
升降反正，天地二气交泰于身，顿觉自己气力上限增加了。\n"NOR);

	message_vision(HIW"只见$N脸上红光时隐时现，不一会
儿便神采弈弈地站了起来。\n"NOR, me);
	if( nx> nb ) {
	improve =  (nx - nb) / 2;
	me->add("max_qi", improve);
	me->add("eff_jing", -improve);
	me->set_temp("yun_riyue", 1);  
        me->add("neili", - 150);    
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, improve :), nh * 3/2 );
	return 1;
	}
	if( nb > nx ) {
	improve =  (nb - nx) / 2;
	me->add("max_qi", improve);
	me->add("eff_jing", -improve);
	me->set_temp("yun_riyue", 1);  
        me->add("neili", - 150);    
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, improve :), nh * 3/2 );
	return 1;
	}
}
void remove_effect(object me, int improve)
{
      me->add("max_qi", - improve/2*3);
      me->add("eff_jing", improve);
      me->delete_temp("yun_riyue");
      tell_object(me, HIR"你所聚天地之精气已散回日月之间，你又恢复了原有精气。\n"NOR);
}
