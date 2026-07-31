#include "ansi.h"
string chinese_daoxing(int gain)
{            int year,day,hour;
             string str;

             year=gain/1000;
             day=(gain-year*1000)/4;
             hour=(gain-year*1000-day*4)*3;
             str="";
             if(year) str=str+chinese_number(year)+"年";
             if(day) str=str+chinese_number(day)+"天";
             if(hour) str=str+chinese_number(hour)+"时辰";

             return str;
}

int accept_object(object who,object ob)
{
	object me = this_object();
	int exp,pot,score;
	string str;
	if((string)ob->query("is_task") == (string)me->name()){
	tell_object(who,"恭喜你又完成了一个使命！\n");
	who->add("task",1);
	exp = random(700) + 800;
	pot = exp / 4 + 1;
	score=3+random(4);
	str=chinese_daoxing(exp);
	who->add("combat_exp",exp);
	who->add("potential",pot);
	who->add("wwscore",score);
        tell_object(who,HIY"你被奖励了：\n" +
	str + "道行\n"+
	chinese_number(pot) + "点潜能和"+chinese_number(score)+"点江湖威望!\n"NOR);
	  log_file("task_get","["+ctime(time())+"] "+who->query("id")
   +" got "+pot+" pots by task,and"+score+"wwscore!\n");
	return 1;
	}
	else return 0;
}

