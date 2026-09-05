//工部任务 Zine 

#include <ansi.h>
#include "pre&post_task.h"
#define DEPART "honglusi"
int npc_error_finish(object ob,object me)
{
	me->set("song/taskstime",0);
	me->delete_temp("songtasks");
	tell_object(me,ob->name()+"一副欲言又止的样子，似乎有什么情况，你的本次任务被取消了，再回中枢看看吧。\n");
	return 1;
}
mapping *tasks=({
		(["name":"递送国书","comment":"大人递送国书完成，辛苦了。\n","reward":6+random(4),"range":"6-9"]),
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
	object letter;
    string *country=({"蒙古国","大理国","西夏国"});
    string *place=({"蒙古金帐","大殿","皇宫正殿"});
    string *target=({"/d/xiangyang/jinzhang","/d/dalicheng/wangfu4","/d/lingzhou/zhengdian"});
    if (pre_assign(me,DEPART,tasks)==0)
    return 1;
    else
    {
		if (me->query_temp("songtasks/"+DEPART+"/task")==1)
		{
			letter=new("/d/song/obj/letter");
			n=random(sizeof(country));
			if (ob->get_my_pin(me)<5)
			message_vision("$N从桌上拿出一封国书，郑重交给$n，道：我国欲与"+country[n]+"修好关系，大人请赶紧把这封国书递交(dijiao)到"+place[n]+"去。\n",ob,me);
			else
			message_vision("$N从桌上拿出一封国书，郑重交给$n，道：我国欲与"+country[n]+"修好关系，你赶紧把这封国书递交(dijiao)到"+place[n]+"，不得有误。\n",ob,me);
			me->set_temp("songtasks/"+DEPART+"/target",target[n]);
			me->set_temp("songtasks/"+DEPART+"/tocountry",country[n]);
			me->set_temp("songtasks/"+DEPART+"/initime",time());
			letter->set("owner",me->query("id"));
			letter->set_long(country[n]);
			letter->move(me);
		}
		pre_1pin(me,DEPART,tasks);
        return 1;
    }
}
