// sendfood.c  散粮
// by fire on Jan 1999
void start(string arg)
{
	int p_population,p_safe;
    int p_food,p_foodout,p_send;
    int p_month=DAY_D->query_date()[2];
    string p_talk,p_area,p_id;
    int task_id;
    int* my_task;
	string p_area1;
	p_id=this_body()->query_id()[0];
	p_area1=CHAR_D->get_char(p_id,"area");
    if((!arg)||(arg==""))
    {
        write("用法：cmd sendfood 粮食数\n");
        write("例子：cmd sendfood 10000   散一万粮食\n");
        write("用 cmd help sendfood 查看详细帮助。\n");
        return;
    }
    p_send=to_int(arg);
    if(!CHAR_D->get_char(p_id,"nation"))
    {
            write("等你混了个一官半职以后，再考虑散粮赈民吧。\n");
            return;
    }
//        if(CHAR_D->get_char(p_id,"level")<2);
//        {
//                write("你的官职太低，不能提这样的建议。\n");
//                return;
//        }

    my_task = TASK_D->get_char_task(p_id);
    if(my_task[1]!=TT_LOCALMEETING)
    {
            write("这个问题还是在地区会议上谈吧。\n");
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
            write("现在正在讨论其他的议题，你的意见等会儿再说吧。\n");
            return;
    }
    if(((TASK_D->get_task(task_id,"timaim")-
            TASK_D->get_task(task_id,"timer"))<3)&&
            (TASK_D->get_task(task_id,"stage")!=0))
    {
            write("时间不多了，回头再提吧。\n");
            return;
    }
	p_area=CHAR_D->get_char(p_id,"area");
    if(p_month>=9) p_month=17-p_month;
	else p_month=9-p_month;
	p_population=AREA_D->get_area(p_area,"population");
	p_food=AREA_D->get_area(p_area,"food");
	p_foodout=AREA_D->get_area(p_area,"foodout");
    p_safe=AREA_D->get_area(p_area,"safe");
	if((p_send*10)<p_population)
    {   write("一次散粮至少是百姓数目的十分之一。\n");
        return;
    }
	if((p_send)>(10*p_population))
    {   write("一次散粮至多是百姓数目的十倍。\n");
        return;
    }
	if((p_send)>p_food)
    {   write("本地区没有这么许多粮食。\n");
        return;
    }
	if((p_send+p_month*p_foodout)>p_food)
    {
        write("散这么多粮，士兵可能要挨饿。\n");
        return ;
    }
	if(p_safe>=70)
	{
		write("百姓丰衣足食，现在不需要散粮赈灾。\n");
		return;
	}
    p_talk=sprintf("$N说道：国以民为本，当下百姓生活贫苦，\n"+
		"$s以为需散粮%s以赈灾民。\n",
		chinese_number(p_send));
    this_body()->simple_action(p_talk);
    (EV_LOCALMEETING)->get_suggestion(task_id,p_id,"sendfood",p_send);
}
