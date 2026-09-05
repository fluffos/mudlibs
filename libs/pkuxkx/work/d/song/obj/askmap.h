// xinzha Zine 户部任务

#include <ansi.h>
void init()
{
    add_action("do_dating","dating");
	//楚大业镖局npc的命令 
	//seagate镖局命令直接加在楚大业的文件里，否则使用这个头文件的所有npc都出错，Zine
    //add_action("do_getesc","getesc");
	//add_action("do_listesc", "listesc");
}

int removezhao(object where)
{
    if (where)
    {
        where->delete("zhao");
        return 1;
    }
}

int do_dating()
{
    object me=this_player();
    object ob=this_object();
    string loc;
	string *taskwhere=({"镇江","苏州","扬州","江州","岳阳","南昌","泉州","闽南"});
	string *taskloc=({"/d/zhenjiang/","/d/suzhou/","/d/city/","/d/jiangzhou/","/d/yueyang/","/d/nanchang/","/d/quanzhou2/","/d/fuzhou/"});
    object where;
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query_temp("songtasks/hubu/task_where")!=ob->query("loc"))
    {
        tell_object(me,"无可奉告！\n");
        return 1;
    }
    if (me->query_temp("songtasks/hubu/task1ask"))
    {
        tell_object(me,"你不是打听过了吗？\n");
        return 1;
    }
    else
    {
		loc=taskloc[member_array(me->query_temp("songtasks/hubu/task_where"),taskwhere)];
        where=TASK_D->random_room(loc);
        message_vision("$N紧紧抓住$n的手：朝廷没有忘记我们呀！\n",ob,me);
        message_vision("$N道：要画这里的地图，最好是去"+where->query("short")+"找一下，好像有前人遗落的残图。\n",ob);
        tell_object(me,RED"你心中暗想，要抓紧时间也许去晚了就找不到了！\n"NOR);
        me->set_temp("songtasks/hubu/task1ask",1);
        where->set("zhao",1);
        call_out("removezhao",120,where);
        return 1;
    }
}