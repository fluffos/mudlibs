// importance.c 
// by fire on August 30, 1998
// used to suggest local development importance
string get_reson(int p_inp)
{
        switch(p_inp)
        {
                case AI_BALANCE:
                        return "由于本地区发展不平衡，";
                case AI_AGRICULTURE:
                        return "由于本地区兵粮不足，";
                case AI_INDUSTRY:
                        return "由于本地区物资不足，";
                case AI_BUSINESS:
                        return "由于本地区军资不足，";
                case AI_SAFE:
                        return "由于本地区民心不稳，";
                case AI_MILITARY:
                        return "由于本地区兵士战力不足，";
        }
}
string get_obj(int p_inp)
{
        switch(p_inp)
        {
                case AI_BALANCE:
                        return "均衡";
                case AI_AGRICULTURE:
                        return "加强农业";
                case AI_INDUSTRY:
                        return "加强工业";
                case AI_BUSINESS:
                        return "加强商业";
                case AI_SAFE:
                        return "稳定民心";
                case AI_MILITARY:
                        return "加强军事";
        }
}
string get_talk(int p_oldinp,int p_inp)
{
        string p_ret;
        p_ret=get_reson(p_inp);
        p_ret+="$s以为：目前的"+get_obj(p_oldinp)+"发展策略难以解决这个问题，\n"+
"故建议改为"+get_obj(p_inp)+"发展策略，望诸位大人、将军深思。\n";
        return p_ret;
}
int get_importance(string p_inp)
{
        switch(p_inp)
        {
                case "balance":
                        return AI_BALANCE;
                case "agriculture":
                        return AI_AGRICULTURE;
                case "industry":
                        return AI_INDUSTRY;
                case "business":
                        return AI_BUSINESS;
                case "safe":
                        return AI_SAFE;
                case "military":
                        return AI_MILITARY;
                default:
                        return -1;
        }
}
void start(string arg)
{
        int p_inp,p_oldinp;
        string p_talk;
        int my_id,task_id;
	string p_id;
	string p_area1;
        int* my_task;
	p_id=this_body()->query_id()[0];
	p_area1=CHAR_D->get_char(p_id,"area");
        if(!arg)
                arg="";
        p_inp=get_importance(arg);
        if(p_inp==-1)
        {
                write("用法错误！");
                write("用 cmd help importance 查看详细帮助。\n");
                return;
        }
        my_id=this_body()->query_id()[0];
        if(!CHAR_D->get_char(my_id,"nation"))
        {
                write("等你混了个一官半职之后，再考虑地区重点的问题吧。\n");
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
                write("这个问题还是地区会议上再谈吧。\n");
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
        {
                write("现在正在讨论别的议题，你的意见等会儿再说吧。\n");
                return;
        }
        if(((TASK_D->get_task(task_id,"timaim")-
                TASK_D->get_task(task_id,"timer"))<3)&&
                (TASK_D->get_task(task_id,"stage")!=0))
        {
                write("时间不多了，回头再提吧。\n");
                return;
        }
        {       
		string p_area;
                int p_safe;
                p_area=CHAR_D->get_char(my_id,"area");
                p_safe=AREA_D->get_area(p_area,"safe");
                if(p_safe<5)
                {
                        write("百姓已经极度不满，再变动政策，想引起暴动啊？！\n");
                        return;
                }
        }
        p_oldinp=AREA_D->get_area(CHAR_D->get_char(my_id,
                "area"),"importance");
        if(p_oldinp==p_inp)
        {
                printf("你的建议没有什么新意，还是算了吧。\n");
                return ;
        }
        p_talk=get_talk(p_oldinp,p_inp);
        this_body()->simple_action("$N道："+p_talk);
        (EV_LOCALMEETING)->get_suggestion(task_id,my_id,"importance",p_inp);
}
