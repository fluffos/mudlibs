//工部侍郎

#include <ansi.h>
#include <title.h>
#include "/d/yingtianfu/neicheng/npc/daming_npc_officer.h"
#include "huilu.h"
int ask_ys()
{
	string *place=({});
	object me=this_player(),where;
	if (me->query_temp("mingtasks/gongbu/task")!=4)
	{
		command("say 这是我部事宜，不劳大人挂心。");
		return 1;
	}
	if (me->query_temp("mingtasks/gongbu/yingshan"))
	{
		command("say 事不宜迟，大人快些上路吧。");
		return 1;
	}
	place=DAMING_D->ytf_task_place();
	if (!sizeof(place))
	{
		command("say 任务暂时不能完成。");
		return 1;
	}
	where=load_object(place[random(sizeof(place))]);
	if (me->query("mingpin")==1)
	message_vision("$N道：听说"+where->query("short")+"有些年久失修了，本官去修缮(xiushan)一番。\n",me);
	else if (me->query("mingpin")<4)
	command("say "+where->query("short")+"有些年久失修了，大人请去修缮(xiushan)一番。");
	else
	command("say "+where->query("short")+"有些年久失修了，你快去修缮(xiushan)一番。");
	me->set_temp("mingtasks/gongbu/yingshan",where->query("short"));
	return 1;
}
int ask_yh()
{
	object me=this_player(),from,destination;
	int i,j,*pool=({0,1,2,3,4,5,6,7,8,9,10});
	string* local_c=({"扬州","镇江","杭州","苏州","福州","泉州","南昌","岳阳","江州","成都","牙山"});
	string* local_path=({"/d/city/","/d/zhenjiang/","/d/hangzhou/","/d/suzhou/","/d/fuzhou/","/d/quanzhou2/","/d/nanchang/","/d/yueyang/","/d/jiangzhou/","/d/chengdu/","/d/yashan/"});
	if (me->query_temp("mingtasks/gongbu/task")!=3)
	{
		command("say 这是我部事宜，不劳大人挂心。");
		return 1;
	}
	if (me->query_temp("mingtasks/gongbu/yuhen"))
	{
		command("say 事不宜迟，大人快些上路吧。");
		return 1;
	}
	i=random(11);
	pool-=({i});
	j=pool[random(sizeof(pool))];
	while (!objectp(from) || 
          !from->isroom()||
          TASK_D->place_belong(from)=="不明区域"||
          base_name(from) == "/adm/daemons/taskd")
	{from=TASK_D->random_room(local_path[i]);}
	while (!objectp(destination) || 
          !destination->isroom()||
          TASK_D->place_belong(destination)=="不明区域"||
          base_name(destination) == "/adm/daemons/taskd")
	{destination=TASK_D->random_room(local_path[j]);}
	if (!from||!destination)
	{
		command("say 我还有事要忙，你迟些再来。");
		return 1;
	}
	message_vision("$N拉过$n，小声说着什么。\n",this_object(),me);
	command("whisper "+me->query("id")+" 朝廷有一批物资要从"+local_c[i]+"的"+from->query("short")+"运送到"+local_c[j]+"的"+destination->query("short")+"，就偏劳大人去押运(yayun)一下了。");
	me->set_temp("mingtasks/gongbu/yuhen",1);
	me->set_temp("mingtasks/gongbu/yuhen_from",from);
	me->set_temp("mingtasks/gongbu/yuhen_to",destination);
	me->set_temp("mingtasks/gongbu/yuhen_to_area",TASK_D->place_belong(destination));
	me->set_temp("mingtasks/gongbu/yuhen_to_short",destination->query("short"));
	return 1;
}
int ask_cj()
{
    object me=this_player();
    if (!me->query("mingpin"))
    {
        tell_object(me,"工部侍郎傲慢地望着天花板，并不理你。\n");
        return 1;
    }
    else
    {
        command("say 近年长江南岸，洪水频繁。");
        command("say 你首先要找到决口的地方，然后治理(zhili)就好了，做完别忘了回来复命。");
        return 1;
    }
}
