// recruit.c
// by fire on August 5, 1998
void start(string arg)
{
        int p_soldier;
	int p_population,p_tmp;
        string p_talk, type;
        int my_id,task_id;
        int* my_task;
	mapping troop;
	string p_id;
	string p_area1;
	p_id=this_body()->query_id()[0];
	p_area1=CHAR_D->get_char(p_id,"area");

        if( (!arg)||(arg=="") ){
                write("用法：cmd recruit　士兵数\n");
                write("例子：cmd recruit 100   征一百士兵\n");
                write("例子：cmd recruit -200 footman 裁二百新兵\n");
                write("用 cmd help recruit 查看详细帮助。\n");
        	write("详细兵种名称请help trooptype.\n");        
	return;
        }
	if( sscanf(arg, "%d %s", p_soldier, type) != 2 )p_soldier=to_int(arg);
        if( p_soldier<50 && p_soldier>-50){
                write("征兵或裁兵数不能小于50。\n");
                write("用 cmd help recruit 查看详细帮助。\n");
                return;
        }
        if( (stringp(type)&&p_soldier>0)||(!stringp(type)&&p_soldier<0) ){
                write("用法：cmd recruit　士兵数\n");
                write("例子：cmd recruit 100   征一百士兵\n");
		write("例子：cmd recruit -200 footman 裁二百新兵\n");
		return;
	}
        my_id = this_body()->query_id()[0];
        if( !CHAR_D->get_char(my_id,"nation") ){
                write("等你混了个一官半职以后，再考虑征兵裁兵的问题吧。\n");
                return;
        }

        if((CHAR_D->get_char(my_id,"level")<3)&&(p_soldier<0))
        {
                write("你的官职太低，不能建议裁兵。\n");
                return;
        }

        if((CHAR_D->get_char(my_id,"level")<2)&&(p_soldier>0))
        {
                write("你的官职太低，不能建议征兵。\n");
                return;
        }

        my_task = TASK_D->get_char_task(my_id);
        if( my_task[1] != TT_LOCALMEETING ){
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
        task_id = my_task[0];
        if( TASK_D->get_task(task_id,"suggestion") ){
                write("现在正在讨论其他的议题，你的意见等会儿再说吧。\n");
                return;
        }
        if( ((TASK_D->get_task(task_id,"timaim")-
                TASK_D->get_task(task_id,"timer"))<3)&&
                (TASK_D->get_task(task_id,"stage")!=0)){
                write("时间不多了，回头再提吧。\n");
                return;
        }
        if( (PJOB+"recruit/recruit")->get_recruit_left(my_id)>0 ){
            	int p_left = (PJOB+"recruit/recruit")->get_recruit_left(my_id);
            	printf("你的征兵任务还差%s名士兵没有完成。\n", chinese_number(p_left));
            	return;
        }

	if( p_soldier < 0 ){
		write("统一全国兵力尚且不足，怎么能就此轻易裁兵呢？\n");//2001.4.13
		return;

		troop = AREA_D->get_area(CHAR_D->get_char(my_id,"area"),"troop");
		if( !mapp(troop) ) troop = ([ ]);
		if( member_array(type, keys(troop)) == -1 ){
			write("没有"+type+"这种军队。\n");
			return;
		}
		if( troop[type] + p_soldier < 0 ){
			write(""+type+"部队没有这没多人。\n");
			return;
		};
	}
	p_population=AREA_D->get_area(CHAR_D->get_char(my_id,"area"),"population");
	p_tmp=bmin(p_population*4/100,500);
        if(p_soldier>p_tmp){
                printf("当前最大征兵数是%d。\n",p_tmp);
                return ;
        }
	if(p_soldier>0){
		if(AREA_D->get_area(CHAR_D->get_char(my_id,"area"),"safe")<10){
			write("百姓已经极度不满，再征兵，想引起暴动啊？！\n");
			return;
		}
	}
        if(p_soldier>0){
                p_talk=sprintf("$N道：本地兵士匮乏，难保百姓安居乐业。$s以为急需
			征兵%d，以保证本地区的长治久安。还望诸位大人、将军深思。\n",p_soldier);
		(EV_LOCALMEETING)->get_suggestion(task_id,my_id,"recruit",p_soldier);
	}
        else {
		p_talk=sprintf("$N道：本地%s兵士已足，$s以为宜裁兵%d，令其归田生产，
			更利于本地区的繁荣昌盛。还望诸位大人、将军深思。\n",WARAI_D->query_type(type, "name"),(-1*p_soldier));
		(EV_LOCALMEETING)->get_suggestion(task_id,my_id,"recruit",
			(["no":p_soldier, "type":type]));
	}
        this_body()->simple_action(p_talk);
}
