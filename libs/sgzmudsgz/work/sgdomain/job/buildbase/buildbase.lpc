// buildbase.c

void commonaward(object usr,int num) {
    int isrobot;
	int n;
	string p_id;
	if(!objectp(usr)) return;
	usr=usr->query_body();
	if(!objectp(usr)) return;
	p_id=usr->query_primary_id();
    isrobot=usr->query_robot();
    if(isrobot)
    {   
		tell_user(p_id,"%^H_RED%^白忙了一场，什么也没捞到。%^RESET%^\n");
		usr->responda("poor "+p_id);
		return;
    }
	n=num+random(num/2);
	CHAR_D->add_honor_point(p_id,n);
	tell_user(p_id,"%^H_GREEN%^干得不错，得到了"+chinese_number(n)+
	   "点奖点。%^RESET%^\n");
	usr->responda("jump");

}

void award(object usr)
{
	commonaward(usr,5);
}

void common_robot(object usr, int num) {
	ROBOT->robot_test(usr,(:commonaward:),num);
}
void ask_buildbase(object me, object target)
{
        string p_area,f_id;
		string p_id,t_id;
		object bs;
		mixed ret;
		p_area=me->query_job("buildbase","area");
		f_id=me->query_job("buildbase","f_id");
		p_id=me->query_primary_id();
		t_id=target->query_primary_id();
		me->clear_asklist("buildbase");
		me->finish_job("buildbase");
		bs=SGBASE(p_area,f_id);
        me->targetted_action(
			"$N对$T笑着说道：本地区建设不足，$s认为应当在"+
			BASE_D->get_base(f_id,"name")+"中再建设一个"+
			BASE_D->get_base(f_id,"roomname")+"，不知$R意下如何？\n",target);
		if(!bs) {
			target->responda("sorry "+p_id);
			DELAY_D->delay_targetted_action(target,me,
				"$N道：本地"+BASE_D->get_base(f_id,"name")+
				"已经不存在了。\n",1);
			return;
		}
		if(bs->get_leader()!=t_id) {
			target->responda("sorry "+p_id);
			DELAY_D->delay_targetted_action(target,me,
				"$N道：$s已经不是"+BASE_D->get_base(f_id,"name")+
				"的总监了。\n",1);
			return;
		}
		ret=bs->can_hame_more_room();
		if(stringp(ret)) {
			target->responda("sorry "+p_id);
			DELAY_D->delay_targetted_action(target,me,
				"$N道："+ret+"\n",1);
			return;
		}
		bs->add_new_room();
		target->responda("great "+p_id);
		target->targetted_action("$N道：好主意，$s立即去办。\n",me);
		ROBOT->robot_test(find_user(p_id),(:award:));
		if(!CHAR_D->get_char(t_id,"task")) {
			CHAR_D->remove_npc_char(t_id);
		}
}