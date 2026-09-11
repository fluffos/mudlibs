// spy.c
// by fire on March 11, 1999
// this is used to spy in a room
void spy_ok(object me);
void confirm_over(mixed p_input)
{
        string my_id;
        my_id=this_body()->query_id()[0];
        if((p_input=="yes")||(p_input=="y"))
		{	this_body()->set_job("spy","status","done");
			write("虽然你没有完成全部的侦察任务，但也有收获，\n"+
				"可以去领赏了。\n");
		}
        else
               write("做事不应半途而废，你准备继续侦察。\n");
        this_user()->modal_pop();
}
void start(string arg)
{
	string p_id,p_area,p_fname;
	object me=this_body(),env;
	string *spied;
	p_id=me->query_id()[0];
	if(!me->query_job("spy","beg_time")){
		write("你现在并没有担任侦察任务。\n");
		return;
	}
	p_area=me->query_job("spy","area");
	spied=me->query_job("spy","spied");
	if(arg=="info") {
		printf("侦察地区：%s。\n",AREA_D->get_area(p_area,"name"));
		printf("需侦察房间数：%d。\n",me->query_job("spy","size"));
		printf("已经侦察过的房间数：%d。\n",sizeof(spied));
		printf("目前状态：%s。\n",
			(me->query_job("spy","status") != "done" ? "继续侦察":"侦察完毕"));
		if((sizeof(spied)>=me->query_job("spy","size"))&&
                     (me->query_job("spy","done_time")>(time()-1800))){
			string ret;
                              ret=AREA_D->stat_me(p_area,"s",0);
			write("侦察结果：\n");
			write(ret);
		}
		return;
	}
	if((arg=="done")&&(me->query_job("spy","status")!="done")){
		if(sizeof(spied)==0){
			write("你一点情报都没有搞到，怎可如此便去交差？\n");
			return;
		}
		write("你的侦察任务尚未全部完成，现在回去只能得到一半奖励，
确认结束侦察行动吗？(y/n)。");
		this_user()->modal_push((: confirm_over :),
                               "",0,0);
		return;

	}
	if((me->query_job("spy","status"))=="done") {
		write("侦察任务完成，快回去报告领赏去吧。\n");
		return;
	}
	env=environment(me);
    if((env->get_area())!=p_area) {
		write("这儿不是需要你侦察的地区，请用cmd spy info 查看详情。\n");
		return;
	}
	p_fname=file_name(env);
	if(member_array(p_fname,spied)!=-1){
		write("这个地方已经侦察过了，请用cmd spy info 查看详情。\n");
		return;
	}
	if(env->is_home()||env->is_base()) {
		write("no use to spy here :) \n");
		return;
	}

	me->set_job("spy","catched",0);	
	write("你左看看，右看看，好象没人注意。\n你掏出一张纸，开始纪录。\n");
	me->other_action(
		"$N贼头贼脑地东张张，西望望，在一张纸上不知道画了些什么。\n");
	me->set_job("spy","spied",spied+({p_fname}));
	me->start_busy(10,"你正忙着侦察呢。\n");
	call_out("spy_ok",random(7)+3,me);
	CHAR_D->set_char(p_id,"catch_time",time()+10);

	CHAR_D->set_char(p_id,"catch_file",PCMD+"spy");
	CHAR_D->set_char(p_id,"catch_function","spy_catch");
	CHAR_D->set_char(p_id,"catch_para",0);
	CHAR_D->set_char(p_id,"catch_area",p_area);
	return;

}


void spy_catch(string o_id,string p_id,mixed none)
{
	object o_o,o_p;
	o_o=find_body(o_id);
	if(!objectp(o_o)) return;
	o_p=find_body(p_id);
	if(!objectp(o_p)) {

		tell_user(o_id,"你好象瞥见了一个贼人，但是一转眼的工夫他就溜掉了。\n");
	o_o->set_job("partol","score",
			o_o->query_job("partol","score")-1);
		return;
	}

	o_o->targetted_action(
		"$N对$T大喝一声：大胆$r，竟敢在此刺探军情，给我拿下！\n",o_p);
	o_p->simple_action(
		"众官兵一拥而上，把$N捆得结结实实。\n");
	o_o->simple_action(
		"$N一挥手，道：带走！\n");
	o_p->simple_action(
		"众官兵把$N押了下去。\n");

	CHANNEL_D->deliver_tell("rumor","system",
		CHAR_D->get_char(p_id,"name")+
		"在"+AREA_D->get_area(CHAR_D->get_char(o_id,"area"),"name")+
		"侦查，被正在巡逻的"+CHAR_D->get_char(o_id,"name")+
		"当场抓获。");
	o_p->set_job("spy","catched",1);	
	o_p->set_job("spy","status","done");	
	(PCMD+"catch")->catch_award(o_id,p_id);

}




void spy_ok(object me)
{
	string p_id;
	string spied;
	int num;
	if(!objectp(me)) return;
	p_id=me->query_id()[0];
	if(me->query_job("spy","catched"))
		return;
	tell_user(p_id,"你纪录完毕，满意地点了点头。\n");
	me->other_action(
		"$N点点头，『嘿嘿』地干笑了两声。\n");
	me->stop_busy();

	CHAR_D->set_char(p_id,"catch_file",0);
	CHAR_D->set_char(p_id,"catch_function",0);
	CHAR_D->set_char(p_id,"catch_para",0);
	CHAR_D->set_char(p_id,"catch_area",0);

	spied=me->query_job("spy","spied");
	num=me->query_job("spy","size");
	if(sizeof(spied)>=num){
		tell_user(p_id,"%^H_GREEN%^任务完成，快去太守处领赏吧。\n%^RESET%^");
		me->set_job("spy","status","done");
		me->set_job("spy","done_time",time());
	}
}
