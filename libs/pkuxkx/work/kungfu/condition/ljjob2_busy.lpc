// ljjob_busy.c
#include <ansi.h>
#include <login.h>

void destroying(object me , object obj);

int update_condition(object me, int duration)
{
	object ob;
	int score = ( random(10) + 1) * ( random(3) + 1 );
//        int rep = random(2000) + 500;
        int rep = (me->query_temp("lingjiuhuwei/killed_number"))* (random(90) + 60);
	me->apply_condition("ljjob2_busy", duration - 1);
	if( duration < 1 && objectp ( ob = present("lj lingpai",me)) && environment(me)->query("short") == me->query_temp("ljhwjob")) 
	{
	tell_object(me,HIW"护卫时间已经到了，你的任务完成了。\n"NOR);
	message_vision(HIW"$N任务完成，把令牌交给了别的弟子。\n"NOR,me,ob); 
//	message_vision(HIG"$N任务完成，把令牌交给了别的弟子。\n"NOR,me,ob); 
	call_out("destroying", 0, me, ob);   
	return 0;
	}
	else if ( duration < 1 && objectp ( ob = present("lj lingpai",me)) && environment(me)->query("short") !=me->query_temp("ljhwjob") )
	{
	tell_object(me,HIW"护卫时间已到，由于你没有在指定地点执行任务，你的任务失败了。\n"NOR);
	message_vision(HIG"$N任务时间已到，把令牌交给了别的弟子。\n"NOR,me,ob); 
if (me->query("family/family_name") == "灵鹫宫")
{
	tell_object(me,"由于你没有完成任务，你的师门忠诚度降低了"+chinese_number(score)+"点。\n");
	me->add("score", - score) ;
}
else
{
        tell_object(me,"由于你没有完成任务，你的武林声望降低了" + chinese_number(rep) + "点。\n");
        me->add("repute", - rep) ;
}
       me->delete_temp("ljjob");
       me->delete_temp("ljhw");
       me->delete_temp("ljhwjob");
       me->delete_temp("lingjiuhuwei");
       destruct(ob);
	return 0;
	} 
	else if (duration < 1 && (me->query_temp("ljhw") || me->query_temp("ljhwjob") )) 
	{
	tell_object(me,HIW"护卫时间已到，你的任务失败了。\n"NOR);
if (me->query("family/family_name") == "灵鹫宫")
{
	tell_object(me,"由于你没有完成任务，你的师门忠诚度降低了"+chinese_number(score)+"点。\n");
	me->add("score", - score) ;
}
else
{
        tell_object(me,"由于你没有完成任务，你的武林声望降低了" + chinese_number(rep) + "点。\n");
        me->add("repute", - rep) ;
}
    me->delete_temp("ljjob");
    me->delete_temp("ljhw");
    me->delete_temp("ljhwjob");
    me->delete_temp("lingjiuhuwei");
	return 0;
	}
	else if (duration < 1) {return 0;}
	return 1;
}

string query_type(object me)
{
	return "job";
}

void destroying(object me , object obj)
{   
int sc,sc1,rep;
if (!me) return;
//奖励并结束任务
       sc1 = ( random(10) + 1) * ( random(3) + 1 );
	     sc = (me->query_temp("ljjob"))* (random(2)+1);
       rep = (me->query_temp("lingjiuhuwei/killed_number"))* (random(90) + 60);
    
	if (sc == 0) 
	{
if (me->query("family/family_name") == "灵鹫宫")
{
        tell_object(me,"由于你没有完成任务，你的师门忠诚度降低了"+chinese_number(sc1)+"点。\n");
       me->add("score",- sc1);
}
else
{
        tell_object(me,"由于你没有完成任务，你的武林声望降低了" + chinese_number(rep) + "点。\n");
        me->add("repute", - rep) ;
}
	}
	else
	{
if (me->query("family/family_name") == "灵鹫宫")
{
	tell_object(me,"你的师门忠诚度提高了"+chinese_number(sc)+"点。\n");
       me->add("score", sc);
}
else
{
       tell_object(me,"你的武林声望上升了" + chinese_number(rep) + "点。\n");
        me->add("repute", rep) ;
}
	}
        me->delete_temp("ljjob");
        me->delete_temp("ljhw");
        me->delete_temp("ljhwjob");
        me->delete_temp("lingjiuhuwei");
        destruct(obj);
}
