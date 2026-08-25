// market suggest to open market
// by fire on January 28, 2000
void start(string arg)
{
	string p_talk;
	int task_id;
	int* my_task;
	string p_id;
	string p_area;
	string f_id;
	string t_string;
	mixed ret;

	p_id=this_body()->query_primary_id();
	p_area=CHAR_D->get_char(p_id,"area");

	if( !CHAR_D->get_char(p_id,"nation") ){
		write("等你混了个一官半职以后，再考虑建造生产基地的问题吧。\n");
		return;
	}
	my_task = TASK_D->get_char_task(p_id);
	if( my_task[1] != TT_LOCALMEETING ){
		write("这个问题还是在地区会议上谈吧。\n");
		return;
	}
	if(((file_name(environment(this_body())))!=
		((AREA_D->get_area(p_area,"path"))+
		(AREA_D->get_area(p_area,"meeting"))))||(p_area!=
		environment(this_body())->get_area()))
	{
		write("这个问题必须在会议之所讨论。\n");
		return;
	}
	task_id = my_task[0];
	if( TASK_D->get_task(task_id,"suggestion") ){
		write("现在正在讨论其他的议题，你的意见等会儿再说吧。\n");
		return;
	}
	if(((TASK_D->get_task(task_id,"timaim")-TASK_D->get_task(task_id,"timer"))<3)
		&&(TASK_D->get_task(task_id,"stage")!=0))
	{
		write("时间不多了，回头再提吧。\n");
                return;
        }
/*	ret=(PJOB+"build/build")->get_build_job(p_area); // the job is for the area
        if(stringp(ret) ){
            	printf("你们地区的的%s工作还没有完成呢。\n",ret);
            	return;
        } */
	write("由于连年战乱，盗贼横行，商业系统暂时关闭了。\n");
        return;
        
	ret=(EV_MERCHANT)->can_have_market(p_area) ;
	if(stringp(ret)) {
		printf("建议无效，原因：%s\n",ret);
		return;
	}
	p_talk="$N道：国以民为本，民不富不强，$s认为本地可以开放集市，各位意下如何。\n";
    this_body()->simple_action(p_talk);
	(EV_LOCALMEETING)->get_suggestion(task_id,p_id,"market",p_area);

}


