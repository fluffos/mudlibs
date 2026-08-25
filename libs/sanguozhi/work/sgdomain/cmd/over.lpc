// over.c 
// by fire on April 4, 1998
// this is used terminate the meeting in localmeeting
void start(string arg)
{
        int my_id,task_id;
        int* my_task;
	string p_id;
	string p_area1;
	p_id=this_body()->query_id()[0];
	p_area1=CHAR_D->get_char(p_id,"area");
        my_id=this_body()->query_id()[0];
        if(!CHAR_D->get_char(my_id,"nation"))
        {  write("等你混了个一官半职以后，再来考虑建议散会吧。\n");
          return;
        }
	if(((file_name(environment(this_body())))!=
((AREA_D->get_area(p_area1,"path"))+(AREA_D->get_area(p_area1,"meeting"))))||(p_area1!=
		environment(this_body())->get_area()))
	{
		write("这个问题必须在会议之所讨论。\n");
		return;
	}
        my_task = TASK_D->get_char_task(my_id);
        if(my_task[1]!=TT_LOCALMEETING)
        {  write("你现在并没有在开会呀。\n");
           return;
        }
        task_id=my_task[0];
        if(TASK_D->get_task(task_id,"suggestion"))
        {   write("现在正在讨论问题，怎么能散会呢？\n");
            return;
        }
        if(((TASK_D->get_task(task_id,"timaim")-
                TASK_D->get_task(task_id,"timer"))<3)&&
                (TASK_D->get_task(task_id,"stage")!=0))
        {
                write("时间不多了，会议马上就结束了，耐心等一等吧。\n");
                return;
        }
	if((time()-TASK_D->get_task(task_id,"start_time"))<30) {
                write("会议才开始，再耐心等一等吧。\n");
                return;
	}
        this_body()->simple_action(
"$N道：$s以为，今天该谈的都谈了，是不是可以早点散会？\n");
        (EV_LOCALMEETING)->get_suggestion(task_id,
            my_id,"over");
}
