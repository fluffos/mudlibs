// gethead.c
#define job_id "gethead"
void award(object usr)
{
          AWARD(usr,100); //original is 30, modified by row seem 300 to high, change to 100
}

// target is the npc ppl, me is the player :)
void answer_yes(object target, object me,string ans) {
	object bs;
    string p_area,f_id,p_id;
	int money;
	if(ans!="yes") {
		target->targetted_action(
		"$N不满地对$T说道：定金都不肯给，$r也太小气了。\n",me);
		target->simple_action("$N转身离开了。\n");
		destruct(target);
		return;
	}
	if(MONEY_D->sub_poket_money(me,10000)!=1) {
		me->targetted_action(
			"$N一模口袋，脸一红，对$T不好意思地说，对不起，身上没有那么多钱。\n",target);
		target->responda("ack");
		target->simple_action("$N转身离开了。\n");
		destruct(target);
		me->simple_action("$N象一只木鸡一样呆在路当中。\n");
		return;
	}
	me->targetted_action(
		"$N给$T一两金子。\n",target);
	target->responda("rich");
	target->targetted_action(
		"$N对$T说道：我准备一下，随后就去。\n",me);


	p_area=me->query_job(job_id,"area");
	f_id=me->query_job(job_id,"f_id");

	bs=SGBASE(p_area,f_id);
	if(objectp(bs)) {
		bs->add_head(target);
	}
	target->simple_action("$N转身离开了。\n");
	destruct(target);
	ROBOT->robot_test(find_user(me->query_primary_id()),(:award:));

}

// target is the npc ppl, me is the player :)
void answer_salary(object target, object me,string ans) {
	mapping info;	
	int m_salary=to_int(ans);
	int p_salary;
	string p_id=target->get_p_id();

	target->clear_answer();
	info=target->get_info();
	p_salary=info["salary"];
	if(m_salary<p_salary) {
		target->targetted_action(
		"$N不满地对$T说道：一月才"+CHINESE_D->chinese_value(m_salary*100)+
		"，$r也太小气了。\n",me);
		target->simple_action("$N转身离开了。\n");
		destruct(target);
		return;
	}
	target->set_salary(m_salary);
	target->responda("jump");
	target->targetted_action(
		"$N对$T道：$R真是太好了，不过我还需要一两金子作为定金，可以给我吗？\n",me);
	tell(me,"用 answer yes to "+p_id+" 表示同意。\n");

	target->set_answer(me->query_primary_id(), (:answer_yes:) ); 
}


mixed basic_check(string p_area,string f_id) {
	object bs;
	bs=SGBASE(p_area,f_id);
	if(!objectp(bs)) 
		return "$N对$T疑惑地问：听说"+AREA_D->get_area(p_area,"name")+
			"的"+BASE_D->get_base(f_id,"name")+"已经倒闭了。\n";
	if(!stringp(bs->no_head_room()))
		return "$N对$T疑惑地问：听说"+AREA_D->get_area(p_area,"name")+
			"的"+BASE_D->get_base(f_id,"name")+"已经没有空缺了。\n";
	return 1;
}
void ask_gethead(object me, object target)
{
        string p_area,f_id;
		string p_id,t_id,typ;
		object bs;
		mixed ret;
		p_area=me->query_job(job_id,"area");
		f_id=me->query_job(job_id,"f_id");
		p_id=me->query_primary_id();
		t_id=target->get_p_id();
		me->clear_asklist(job_id);
		me->finish_job(job_id);
		bs=SGBASE(p_area,f_id);
        me->targetted_action(
			"$N对$T笑着说道："+AREA_D->get_area(p_area,"name")+
			"的"+BASE_D->get_base(f_id,"name")+"需要一个新的"+
			BASE_D->get_base(f_id,"headname")+"，\n"+
			"$s久闻$R大名，可否请$R屈就此职？\n",target);

		target->responda("consider");
		ret=basic_check(p_area,f_id);
		if(stringp(ret)) {
			target->targetted_action(ret,me);
			me->finish_job(job_id);
			return ;
		}

		target->targetted_action(
			"$N对$T道：一个月的佣金是多少？\n",me);
		tell(me,"用 answer <数字> to "+t_id+" 来回答 <数字> 代表每月多少两银子(1-100)。\n");
		target->set_answer(p_id, (:answer_salary:) );
}
