#include <ansi.h>
inherit __DIR__"song_officer";
#include "/d/song/tasks/hubu.h"
void create()
{
	call_out("npc_to_player",1,"户部尚书",60,-1);
	::create();
}

void init()
{
    add_action("do_a1","answer");
	add_action("do_request","request");
}
int do_a1(string arg)
{
    object me=this_player();
    object ob=this_object();
    int answer,n=3+random(3);
    if (!me->query_temp("songtasks/hubu/answer"))
    {
        tell_object(me,ob->name()+"不解地望着你。\n");
        return 1;
    }
	if (me->query_temp("songtasks/sansishi/task")==3&&me->query_temp("songtasks/sansishi/task3_answerd"))
	{
		tell_object(me,"既然已经了解了两地的民众人数，回三司使继续造册吧。\n");
        return 1;
	}
    if (me->query_temp("songtasks/hubu/2/finish"))
    {
		tell_object(me,"既然已经答对了题目，那就复命吧。\n");
        return 1;
    }
    if(!arg || (sscanf(arg, "%s %d", arg, answer)< 2 ))
    {
        tell_object(me,"你必须回答一个答案！\n");
        return 1;
    }
    if (arg=="甲地"&& answer==me->query_temp("songtasks/hubu/question_x"))
    {
        message_vision("$N答道：莫不是"+chinese_number(answer)+"？\n",me);
        tell_object(me,"恭喜你，答对了甲地的平民数。\n");
        me->set_temp("songtasks/hubu/answersuc_x",1);
        if (me->query_temp("songtasks/hubu/answersuc_x")&&me->query_temp("songtasks/hubu/answersuc_y"))
        {
			command("say 大人果然不同凡人，这么快就算出来了，老夫佩服佩服。");
			if (me->query_temp("songtasks/sansishi/task")==3)
			{
				me->set_temp("songtasks/sansishi/task3_answerd",1);
				return 1;
			}
			me->set_temp("songtasks/hubu/2/finish",1);
        }
        return 1;
    }
    if (arg=="乙地" && answer==me->query_temp("songtasks/hubu/question_y"))
    {
        message_vision("$N答道：莫不是"+chinese_number(answer)+"？\n",me);
        tell_object(me,"恭喜你，答对了乙地的平民数。\n");
        me->set_temp("songtasks/hubu/answersuc_y",1);
        if (me->query_temp("songtasks/hubu/answersuc_x")&&me->query_temp("songtasks/hubu/answersuc_y"))
        {
            command("say 大人果然不同凡人，这么快就算出来了，老夫佩服佩服。");
			if (me->query_temp("songtasks/sansishi/task")==3)
			{
				me->set_temp("songtasks/sansishi/task3_answerd",1);
				return 1;
			}
			me->set_temp("songtasks/hubu/2/finish",1);
        }
        return 1;
    }
    else
    {
		command("say 回答错误！\n");
		me->delete_temp("songtasks");
        return 1;
    }
    
}
int question(object me)
{
    object ob=this_object();
    int a1,a2,b1,b2,c1,c2,x,y,*pool=({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20});
	if (me->query_temp("songtasks/hubu/task")!=2&&me->query_temp("songtasks/sansishi/task")!=3)
    {
        tell_object(me,ob->name()+"傲慢地望着天花板，并不理你。\n");
        return 1;
    }
	if (me->query_temp("songtasks/hubu/answer"))
    {
        tell_object(me,ob->name()+"催促你快去把这个算出来。\n");
        return 1;
    }
    else
    {
        a1=pool[random(sizeof(pool))];
		pool-=({a1});
        a2=pool[random(sizeof(pool))];
		pool-=({a2});
        b1=pool[random(sizeof(pool))];
		pool-=({b1});
        b2=pool[random(sizeof(pool))];
        x=1+random(50000);
        y=1+random(50000);
        c1=a1*x+b1*y;
        c2=a2*x+b2*y;
        me->set_temp("songtasks/hubu/question_x",x);
        me->set_temp("songtasks/hubu/question_y",y);
		command("say "+me->query("name")+"大人教我。");
        tell_object(me,HIW"大宋甲地去年税率是"+chinese_number(a1)+"两，乙地税率是"+chinese_number(b1)+"两，他们上缴的税款总额是"+chinese_number(c1)+"两。\n"NOR);
        tell_object(me,HIW"到了今年甲地税率变为"+chinese_number(a2)+"两，乙地税率变成了"+chinese_number(b2)+"两，他们缴纳的税款总额是"+chinese_number(c2)+"两。\n"NOR);
        tell_object(me,HIW"两地各有多少平民呢？回答模式如：answer 甲地 18，answer 乙地 20。\n"NOR);
        me->set_temp("songtasks/hubu/answer",1);
        return 1;
    }
}

int do_request()
{
	return question(this_player());
}
