// build
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

	if( (!arg)||(arg=="") ){
		write("用法：cmd build <生产基地ID>\n");
		write("例子：cmd build farm  建造(升级)农场\n");
		write("详细生产基地名称请 info b.\n");        
		return;
	}
	f_id=arg;
	if( !CHAR_D->get_char(p_id,"nation") ){
		write("等你混了个一官半职以后，再考虑建造生产基地的问题吧。\n");
		return;
	}
	if((CHAR_D->get_char(p_id,"level")<2))
	{
		write("你的官职太低，不能建议建造生产基地。\n");
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

	ret=BASE_D->can_build(p_area,f_id);
	if(stringp(ret)) {
		printf("建议无效，原因：%s\n",ret);
		return;
	}
	if(ret==1) {
		t_string="建造"+BASE_D->get_base(f_id,"name");
               (EV_LOCALMEETING)->get_suggestion(task_id,p_id,"build",f_id);
	}
	else {
		t_string="升级"+BASE_D->get_base(f_id,"name");
		(EV_LOCALMEETING)->get_suggestion(task_id,p_id,"update",f_id);
	}
	p_talk=sprintf(
	"$N道：本地区地大人多，但生产尚且不足。$s以为我们当%s，以加强本地的经济实力。\n",
	t_string);
    this_body()->simple_action(p_talk);
}


