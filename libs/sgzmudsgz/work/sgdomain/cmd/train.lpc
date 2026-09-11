// train.c 
// by fire on Dec 12, 1998
// this is used to give train suggestion on the localmeeting.
void start(string arg)
{
        int my_id,task_id;
        int* my_task;
        int p_soldier;
	string p_id;
	string p_area1;
	p_id=this_body()->query_id()[0];
	p_area1=CHAR_D->get_char(p_id,"area");
//        write("正在修改程序，请先不要训练。\n"); return;
        my_id=this_body()->query_id()[0];

/*if( !wizardp(this_body()) ){
        write("练兵暂时禁止。\n");
        return;
};*/
        if(!CHAR_D->get_char(my_id,"nation"))
        {  write("等你混了个一官半职以后，再来考虑练兵的问题吧。\n");
          return;
        }
        my_task = TASK_D->get_char_task(my_id);
        if(my_task[1]!=TT_LOCALMEETING)
        {  write("这个问题还是在地区会议上谈吧。\n");
           return;
        }
	if(((file_name(environment(this_body())))!=
((AREA_D->get_area(p_area1,"path"))+(AREA_D->get_area(p_area1,"meeting"))))||(p_area1!=
		environment(this_body())->get_area()))
	{
		write("这个问题必须在会议之所讨论。\n");
		return;
	}
        task_id=my_task[0];
        if(TASK_D->get_task(task_id,"suggestion"))
        {   write("现在正在讨论其他的议题，你的意见等会儿再说吧。\n");
            return;
        }
        if(((TASK_D->get_task(task_id,"timaim")-
                TASK_D->get_task(task_id,"timer"))<3)&&
                (TASK_D->get_task(task_id,"stage")!=0))
        {
                write("时间不多了，回头再提吧。\n");
                return;
        }
        p_soldier=AREA_D->get_area(CHAR_D->get_char(my_id,
             "area"),"soldier");
        if(p_soldier<50)
        {   write("一共才那几个兵，有什么好练的？！\n");
            return;
        } 
        this_body()->simple_action(
"$N道：常言道，兵贵精而不贵多，$s愿领兵习演阵法，以壮军威。\n");
        (EV_LOCALMEETING)->get_suggestion(task_id,
            my_id,"train");
}
