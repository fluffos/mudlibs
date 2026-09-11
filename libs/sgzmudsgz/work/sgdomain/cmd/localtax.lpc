// localtax.c 
// by fire on August 5, 1998
// updated on Aug 27,1998
void start(string arg)
{
        int p_tax,p_oldtax;
        string p_talk;
        int my_id,task_id;
        int* my_task;
	string p_id;
	string p_area1;
	p_id=this_body()->query_id()[0];
	p_area1=CHAR_D->get_char(p_id,"area");
        if((!arg)||(arg==""))
        {
                write("用法：cmd localtax　税率\n");
                write("例子：cmd localtax 30\n");
                write("用 cmd help localtax查看详细帮助。\n");
                return;
        }
	if(((file_name(environment(this_body())))!=
((AREA_D->get_area(p_area1,"path"))+(AREA_D->get_area(p_area1,"meeting"))))||(p_area1!=
		environment(this_body())->get_area()))
	{
		write("这个问题必须在会议之所讨论。\n");
		return;
	}
        p_tax=to_int(arg);
        if((p_tax<10)||(p_tax>70))
        {
                write("税率的有效范围是：10 - 70\n");
                write("用 cmd help localtax 查看详细帮助。\n");
                return;
        }
        my_id=this_body()->query_id()[0];
        if(!CHAR_D->get_char(my_id,"nation"))
        {
                write("等你混了个一官半职以后，再考虑税率问题吧。\n");
                return;
        }

        if(CHAR_D->get_char(my_id,"level")<2)
        {
                write("你的官职太低，不能提这样的建议。\n");
                return;
        }

        my_task = TASK_D->get_char_task(my_id);
        if(my_task[1]!=TT_LOCALMEETING)
        {
                write("这个问题还是在地区会议上谈吧。\n");
                return;
        }
        task_id=my_task[0];
        if(TASK_D->get_task(task_id,"suggestion"))
        {
                write("现在正在讨论其他议题，你的意见等会儿再说吧。\n");
                return;
        }
        if(((TASK_D->get_task(task_id,"timaim")-
                TASK_D->get_task(task_id,"timer"))<3)&&
                (TASK_D->get_task(task_id,"stage")!=0))
        {
                write("时间不多了，回头再提吧。\n");
                return;
        }
        p_oldtax=AREA_D->get_area(CHAR_D->get_char(my_id,
                "area"),"taxlocal");
        if(p_oldtax==p_tax)
        {
                printf("当前税率正是%d。\n",p_oldtax);
                return ;
        }
       if((p_tax-p_oldtax>20)||(p_oldtax-p_tax>20))
        {
                write("税率的幅度一次调整太大会引起百姓对朝政不满的。\n");
                return;
        }
	if(p_tax>p_oldtax)
	{	string p_area;
		int p_safe;
		p_area=CHAR_D->get_char(my_id,"area");
		p_safe=AREA_D->get_area(p_area,"safe");
                if((p_safe<30)||((p_safe-(p_tax-p_oldtax)*2)<=30))
		{
			write("百姓已经极度不满，再提高税率，想引起暴动呀？！\n");
			return;
		}
	}
        if(p_oldtax>p_tax)
                p_talk=sprintf
("$N道：当前税率%d过高，不利于百姓安居乐业。$s以为税率宜
降至%d，则更利于本地区的长治久安。还望诸位大人、将军深思。\n",p_oldtax,p_tax);
        else
p_talk=sprintf
("$N道：当前税率%d过低，导致地区金粮不足，难以抵抗外寇。$s以为税率宜升至%d，
则更利于本地区的长治久安。还望诸位大人、将军深思。\n",p_oldtax,p_tax);
        this_body()->simple_action(p_talk);
        (EV_LOCALMEETING)->get_suggestion(task_id,my_id,"localtax",p_tax);
}
