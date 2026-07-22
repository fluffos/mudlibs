// job_chaomai.c
// Create by zeus@刀剑笑 Nov.29.1999

#include <ansi.h>;

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int pass_time;
	object ob;

	pass_time=time()-me->query_temp("merchant/chaomai/starttime");

	if( pass_time>1800 ) {
		tell_object(me, HIG "胡子(edw)告诉你：我要你买的货物我已经搞到了，你还是下次再做吧。我损失的钱直接在你的银行里扣。\n" NOR );
		me->delete_temp("merchant_job");
		me->delete_temp("job");
		if ( ob=present("good check",me) )
			destruct(ob);
		if ( ob=present("check book",me) )
			destruct(ob);
		me->clear_condition("job_chaomai");
		return 0;
	} else if( pass_time > 430 && me->query_temp("job/fulltime") ) {
		tell_object(me, HIG "胡子(edw)告诉你：时间过了四分之一，你还是快点吧。\n" NOR );
		me->set_temp("job/quartime",1);
		me->delete_temp("job/fulltime",1);
	} else if ( pass_time > 860 && me->query_temp("job/quartime") ) {
		tell_object(me, HIG "胡子(edw)告诉你：时间过了二分之一，你还是快点吧。\n" NOR );
		me->set_temp("job/halftime",1);
		me->delete_temp("job/quartime",1);
	} else if ( pass_time > 1290 && me->query_temp("job/halftime") ) {
		tell_object(me, HIG "胡子(edw)告诉你：时间过了四分之三，你还是快点吧。\n" NOR );
		me->set_temp("job/lotstime",1);
		me->delete_temp("job/halftime",1);
	} else if ( pass_time > 1720 && me->query_temp("job/lotstime") ) {
		tell_object(me, HIG "胡子(edw)告诉你：时间就要到了，kick " + me->query("id") + "，你还是快点吧。\n" NOR );
		me->delete_temp("job/lotstime",1);
	}

	me->apply_condition("job_chaomai", duration - 1);

	if( !duration ) return 0;
	return 1;
}