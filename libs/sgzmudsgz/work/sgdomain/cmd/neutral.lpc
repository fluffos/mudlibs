// neutral.c 
// by fire on August 10, 1998
string s_ret;
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
        {
                write("等你混了个一官半职以后，再考虑中立不中立吧。\n");
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
	task_id=my_task[0];
                switch(my_task[1])
                {
                case TT_LOCALMEETING:
                        if(!TASK_D->get_task(task_id,"suggestion"))
                        {
                    write("现在没有什么议题可以表示中立的。\n");
                        return;
                        }
                        s_ret=(EV_LOCALMEETING)->neutral_sb(task_id,my_id,arg);
                     if(stringp(s_ret))
                      write(s_ret);
                        break;
                default:
                    write("现在没有什么议题可以表示中立的。\n");
            return;
                }
}
