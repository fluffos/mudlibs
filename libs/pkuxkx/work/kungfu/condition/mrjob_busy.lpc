// mrjob_busy.c
#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	object ob;
   int kar, exp, pot, rep, sc;
   kar = me->query("kar") * (5 + random(20));
   exp = 2 * kar;
   pot = exp / 10;
   rep = 100;
   sc = 1 + random(10);
   if (me->query("combat_exp") < 1000000)
   {
   	exp = exp / 3;
   	pot = exp /10;
   }
	me->apply_condition("mrjob_busy", duration - 1);
	if( duration < 1 && me->query("murong/yuxi"))
	{
	tell_object(me,HIW"任务时间已经到了。\n"NOR);
   if((string)me->query("family/family_name")!="姑苏慕容")
   {
	tell_object(me,HIC "由于你没有找回大燕传国玉玺，被扣除：\n"
                + chinese_number(exp) + "点实战经验，\n"
                + chinese_number(pot) + "点潜能，\n"
                + chinese_number(rep) + "点江湖声望作为惩罚。\n" NOR);
                me->add("combat_exp", - exp);
                me->add("potential", - pot);
                me->add("repute", - rep);
   }
   else
   {
   	if (me->query("combat_exp") > 1000000)   sc = 2 * sc;
	tell_object(me,HIC "由于你没有找回大燕传国玉玺，被扣除：\n"
                + chinese_number(exp) + "点实战经验，\n"
                + chinese_number(pot) + "点潜能，\n"
                + chinese_number(sc) + "点师门忠诚度作为惩罚。\n" NOR);
                me->add("combat_exp", - exp);
                me->add("potential", - pot);
                me->add("score", - sc);
   }

        	me->delete("murong/yuxi");
        	return 0;
	}

	else if (duration < 1) {return 0;}
	return 1;
}

string query_type(object me)
{
	return "job";
}

