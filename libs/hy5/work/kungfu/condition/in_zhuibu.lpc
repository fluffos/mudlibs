// in_zhuibu.c

// by QingP



#include <ansi.h>

#include <condition.h>



inherit F_CLEAN_UP;



int update_condition(object me, int duration)

{

	if ( duration < 1 ) {

		if (!me->query_condition("after_zhuibu"))

		{

			if (me->query_temp("抓/thief"))

				me->delete_temp("抓/thief");

			else if (me->query_temp("抓/caihua zei"))

				me->delete_temp("抓/caihua zei");

			else if (me->query_temp("抓/jiangyang dadao"))

				me->delete_temp("抓/jiangyang dadao");

			else if (me->query_temp("抓/chaoting qinfan"))

				me->delete_temp("抓/chaoting qinfan");

			else if (me->query_temp("抓/shanzhai dawang"))

				me->delete_temp("抓/shanzhai dawang");



			me->set("title",me->query("oldtitle"));

			me->delete("oldtitle");

			me->apply_condition("after_zhuibu", 7);

			tell_object(me, HIW"你没在指定的时间内抓回逃犯，人家已经翻案了！\n"NOR);

		}



		return 0;

       	}



	me->apply_condition("in_zhuibu", duration - 1);

	

	return 1;

}