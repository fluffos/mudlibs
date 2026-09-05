#include <ansi.h>
void init()
{
	add_action("do_diao","diao");
}
int do_diao()
{
	object old_army,army,me=this_player();
	if (me->query_temp("songtasks/"+this_object()->query("songtasks/task_myself")+"/task")!=this_object()->query("songtasks/task_my_number")&&me->query_temp("songtasks/"+this_object()->query("songtasks/task_myself")+"/task")!=this_object()->query("songtasks/task_my_number2"))
	{
		tell_object(me,"没有任命，不能随意调兵。\n");
		return 1;
	}
	if (me->query_temp("songtasks/"+this_object()->query("songtasks/task_myself")+"/diaobing"))
	{
		tell_object(me,"你已经调出了一营精兵。\n");
		return 1;
	}
	if (present(this_object()->query("songtasks/task_myjun_id")+" ying",this_object()))
	{
		tell_object(me,"这里已经有一营"+this_object()->query("songtasks/task_myid")+"精兵整装待发了。\n");
		return 1;
	}
	if (old_army=me->query_temp("lead_army")&&old_army->is_army())
	{
		if (!environment(old_army)) me->delete_temp("lead_army");
		else 
		{
			tell_object(me,"你之前率领的"+old_army->query("name")+"在"+environment(old_army)->query("short")+"等着你呢，如果完成已完成任务，可以就地解散(dismiss)部队。\n");
			return 1;
		}
	}
	army=new("/d/song/obj/army");
	army->set_leader(me,this_object()->query("songtasks/task_myjun_number"),"营",this_object()->query("songtasks/task_weapon"));
	army->move(this_object());
	me->set_temp("ARMY",army);
	me->set_temp("songtasks/"+this_object()->query("songtasks/task_myself")+"/diaobing",1);
	if (me->query_temp("songtasks/"+this_object()->query("songtasks/task_myself")+"/task")==this_object()->query("songtasks/task_my_number"))
	message_vision("$N传令军中，调出了一营"+this_object()->query("songtasks/task_myid")+"士兵，准备换防"+this_object()->query("songtasks/task_target")+"驻地。\n",me);
	if (me->query_temp("songtasks/"+this_object()->query("songtasks/task_myself")+"/task")==this_object()->query("songtasks/task_my_number2"))
	message_vision("$N传令军中，调出了一营"+this_object()->query("songtasks/task_myid")+"士兵，准备开拔剿匪。\n",me);
	tell_object(me,"你可以带领(lead)部队，前进(forward)巡逻。\n");
	if (me->query_temp("songtasks/"+this_object()->query("songtasks/task_myself")+"/task")==this_object()->query("songtasks/task_my_number2"))
	tell_object(me,"遇见敌匪后，你可以接战(jiezhan)，变阵(bianzhen)和督战(duzhan)。\n");
	DASONG_D->multi_record(me,1,"部队出征",2);
	return 1;
}