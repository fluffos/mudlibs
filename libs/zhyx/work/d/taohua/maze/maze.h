// Code of JHSH
// Room: 
// Date: 

#include <ansi.h>
#include "localtime.h"

int check_count(object me, int count)
{
	int age,tmp1,tmp2,tmp, lvl, qmwx, bonus;
	mixed *local;

	age = (int)me->query("age");
  	local = localtime(((int)me->query("birthday")-14*365*24*60)*60);
  	tmp1 = (local[LT_YEAR]%10+local[LT_YEAR]%12+local[LT_MON]+local[LT_MDAY])%8;
  	tmp2 = (((local[LT_HOUR]+1)%24)/2)%8;
  	tmp = tmp1*8 + tmp2;
	me->set_temp("test-sz",tmp);
  	qmwx = me->query_skill("qimen-wuxing", 1);
	lvl = 1+random(qmwx)/20;	

       if (tmp == count) {
		if (me->query_temp("taohua/count")==2080) {
			tell_object(me,HIW"\n\n
四周景物突然变得模糊起来，你觉得头脑一阵晕眩......
你定了定神，发现自己成功了！
\n\n"NOR);
			if (!me->query("taohua_maze")){
				if ( qmwx < 100) bonus = 100000;
				else bonus = qmwx*1000;
				me->add("combat_exp",bonus);
				me->add("potential",bonus*2);
				me->add("int",1);
				me->set("taohua_maze",age);
				me->delete_temp("taohua/count");
				me->add("success_taohua_maze",1);
				tell_object(me,sprintf(HIY"你获得了%d点经验、%d点潜能，1点先天悟性！\n"NOR,
						bonus,
						bonus*2));
				me->move("/d/taohua/mudi");
		        	log_file("Taohua",sprintf("%s(%s) passed Taohua Maze on %s. \n",
       		                 me->name(), getuid(me), ctime(time())));
			} 
		}
		else {
			tell_object(me,HIW"\n\n
你脚下一虚，不由自主的向下飞坠......
你的意识渐渐模糊起来......
\n\n"NOR);
	    		me->unconcious();
			me->delete_temp("taohua/count");
			me->move("/d/taohua/enter_m");
		}
	} 
	else if (me->query_temp("/taohua/count/") > 2100) {
		tell_object(me, HIW"\n\n
忽见得一阵狂风挂来，天空中乌云密布，
一阵阴冷的浓雾瞬间把你裹住......
\n\n"NOR);
		me->unconcious();
		me->delete_temp("taohua/count");
		me->move("/d/taohua/enter_m");
	}
	return 1;
}

void remove_effect(object me, int level)
{
        me->add_temp("apply/int", -level);
        tell_object(me, HIB"你心中一动，脑海中空空荡荡，似乎有什麽东西正离你而去。\n"NOR); 
}