#include <ansi.h>

//高级官员普遍命令
int decide(object me,string id,string what,string decision)
{
	object ob=load_object("/d/song/record/other");
	for (int i=0;i<1000;i++)
	{
		if (ob->query("todo_list/"+me->query("song/depart")+"/"+i)
            &&ob->query("todo_list/"+me->query("song/depart")+"/"+i+"/from")==id
            &&ob->query("todo_list/"+me->query("song/depart")+"/"+i+"/what")==what)
		ob->set("todo_list/"+me->query("song/depart")+"/"+i+"/state",decision);
	}
	ob->save();
	return 1;
}
int do_accept()
{
    object pl,me=this_player();
    string id,what,then_rank;
    if (me->query_temp("song_to_do_list"))
    {
        id=me->query_temp("song_to_do_list/from");
        what=me->query_temp("song_to_do_list/what");
        then_rank=me->query_temp("song_to_do_list/then_rank");
        if (pl=find_player(me->query_temp(id))&&pl->query("song/title")==then_rank)
        {
            tell_object(me,"你同意了"+id+"的请求。\n");
            decide(me,id,what,"同意");
            return 1;
        }
        else
		return notify_fail(id+"现在不在！\n");
    }
    else if (time()-me->query_temp("song_adv_tasks/task_pending_time")>30)
    {
        return 0;
    }
    else
    {
        me->set_temp("song_adv_tasks/task_pending_time","yes");
        if (pl=me->query_temp("song_adv_tasks/task_giver"))
        {
            tell_object(me,"你接受了"+pl->query("name")+"分派的任务。\n");
            tell_object(pl,me->query("name")+"接受了你分派的任务。\n");
            pl->delete_temp("song_adv_tasks/task_give_pending");
        }
        return 1;
    }
}
int do_refuse()
{
    object pl,me=this_player();
    string id,what,then_rank;
    if (me->query_temp("song_to_do_list"))
    {
        id=me->query_temp("song_to_do_list/from");
        what=me->query_temp("song_to_do_list/what");
        then_rank=me->query_temp("song_to_do_list/then_rank");
        if (pl=find_player(me->query_temp(id))&&pl->query("song/title")==then_rank)
        {
            tell_object(me,"你拒绝了"+id+"的请求。\n");
            decide(me,id,what,"拒绝");
            return 1;
        }
        else
		return notify_fail(id+"现在不在！\n");
    }
    else if (time()-me->query_temp("song_adv_tasks/task_pending_time")>30)
    {
        return 0;
    }
    else
    {
        
        if (pl=me->query_temp("song_adv_tasks/task_giver"))
        {
            tell_object(me,"你拒绝了"+pl->query("name")+"分派的任务。\n");
            tell_object(pl,me->query("name")+"拒绝了你分派的任务。\n");
            pl->delete_temp("song_adv_tasks/task_give_pending");
        }
        me->delete_temp("song_adv_tasks");
        return 1;
    }
}

int do_reward(string arg)
{
	object ruyi,me=this_player(),target;
	if (me->query("id")!="zine")
	return 0;
	if (!target=find_player(arg))
	return notify_fail(arg+"并不在线。\n");
	if (!DASONG_D->get_my_pin(target))
	return notify_fail(arg+"并不是大宋官员。\n");
	ruyi=new(__DIR__"ruyi");
	ruyi->set("onwer",target->query("id"));
	ruyi->set("long","这是一张的大宋皇帝亲题的嘉奖令，上面写着"HIW+target->query("name")+NOR+"在其"+chinese_number(target->query("age"))+"岁时，为大宋立下不朽功绩，以资奖励。\n");
	ruyi->move(target);
	tell_object(me,"你发了一张"+ruyi->query("name")+"给"+target->name()+"。\n");
	tell_object(target,"你被大宋授予了一张"+ruyi->query("name")+"，以资奖励。\n");
	tell_object(target,"只要将嘉奖令交给吏部侍郎，可获得大宋功勋度奖励。\n");
	return 1;
}
