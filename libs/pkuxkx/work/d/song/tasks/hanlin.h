//工部任务 Zine 

#include <ansi.h>
#include "pre&post_task.h"
#define DEPART "hanlinyuan"
int npc_error_finish(object ob,object me)
{
	me->set("song/taskstime",0);
	me->delete_temp("songtasks");
	tell_object(me,ob->name()+"一副欲言又止的样子，似乎有什么情况，你的本次任务被取消了，再回中枢看看吧。\n");
	return 1;
}
mapping *tasks=({
		(["name":"购买史籍","comment":"大人百忙之余，还为翰林院找来了史籍，感激不尽啊。\n","reward":6+random(4),"range":"6-9"]),
	});
int ask_finish()
{
    object me=this_player();
	return is_finish(me,DEPART,tasks);
}
int ask_task()
{
	int n;
    object me=this_player();
    object ob=this_object(),gy;
	string *book=({"史记","汉书","后汉书","三国志","晋书","宋书","南齐书","梁书","陈书","魏书","北齐书","周书","隋书","南史","北史",});
    if (pre_assign(me,DEPART,tasks)==0)
    return 1;
    else
    {
		if (me->query_temp("songtasks/"+DEPART+"/task")==1)
		{
			n=random(sizeof(book));
			command("say 我翰林院正在修撰唐史，需要大量史籍作为参考，大人如能找到一本"+book[n]+"，不胜感激。");
			tell_object(me,"扬州天月书肆、北京荣宝斋、成都青羊宫、洛阳望星楼、晋阳南市、岳阳洞庭湖附近经常有人卖书。\n");
			me->set_temp("songtasks/hanlinyuan/book",book[n]);
			me->set_temp("songtasks/hanlinyuan/target",n+1);
			me->set_temp("songtasks/hanlinyuan/initime",time());
		}
		pre_1pin(me,DEPART,tasks);
        return 1;
    }
}
