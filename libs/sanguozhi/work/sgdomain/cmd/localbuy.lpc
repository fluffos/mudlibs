// localbuy.c by fire on Dec 1999
// this is used to give suggestion for buy sth for localarea
void start(string arg)
{
	string *list;
	mapping name=([]);
	string p_talk,ret="用法：cmd localbuy <id>\n可以建议购买的货物有：\n id       名称\n〓〓〓〓〓〓〓〓\n";
    int my_id,task_id;
    int* my_task;
	string p_id;
	string p_area;
	p_id=this_body()->query_id()[0];
	p_area=CHAR_D->get_char(p_id,"area");

	list=(EV_MERCHANT)->query_goods("list");
	foreach(string l in list)
	{
		name[l]=(EV_MERCHANT)->query_goods(l,"name");
		ret+=sprintf("%-10s% : -20s\n",l,name[l]);
	}
    if((!arg)||(arg==""))
    {
		write(ret);
		return;
    }
	if(((file_name(environment(this_body())))!=
((AREA_D->get_area(p_area,"path"))+(AREA_D->get_area(p_area,"meeting"))))||(p_area!=
		environment(this_body())->get_area()))
	{
		write("这个问题必须在会议之所讨论。\n");
		return;
	}
	if(member_array(arg,list)==-1)
	{
		write("没有这种货物。\n");
		write(ret);
		return;
	}
    my_id=this_body()->query_id()[0];
    if(!CHAR_D->get_char(my_id,"nation"))
    {
         write("等你混了个一官半职以后，再考虑购买物资吧。\n");
         return;
    }
        if(CHAR_D->get_char(my_id,"level")<2)
        {
                write("你的官职太低，不能提这样的建议。\n");
                return;
        }

    my_task = TASK_D->get_char_task(my_id);
    if(my_task[1]!=TT_LOCALMEETING)
    {    write("这个问题还是在地区会议上谈吧。\n");
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
    {     write("时间不多了，回头再提吧。\n");
          return;
    }
    if(stringp((PJOB+"localbuy/localbuy")->get_localbuy(my_id)))
    {	string my_buy=(PJOB+"localbuy/localbuy")->get_localbuy(my_id);
		write("你采购"+name[my_buy]+"的任务还没完成呢。\n");
        return;
    }
    p_talk=sprintf("$N朗声道：本地%s储备不足，难保百姓安居乐业。$s以为急需"+
"购入一批%s，以保本地区的长久治安。还望诸位大人、将军深思。\n",name[arg],name[arg]);
    this_body()->simple_action(p_talk);
    (EV_LOCALMEETING)->get_suggestion(task_id,my_id,"localbuy",arg);
}