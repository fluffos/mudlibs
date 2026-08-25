// ev_war.c 
// this is used to handle the war
// by fire on Sep 19, 1998
inherit __DIR__+"war/att_arrange";
inherit __DIR__+"war/att_input";
inherit __DIR__+"war/abort";
inherit __DIR__+"war/robber";
inherit __DIR__+"war/start_point";
inherit __DIR__+"war/def_meeting";
//inherit __DIR__+"war/input";
inherit __DIR__+"war/def_arrange";
inherit __DIR__+"war/def_input";
inherit __DIR__+"war/attack_enter";
inherit __DIR__+"war/check_result";
inherit __DIR__+"war/train";
inherit __DIR__+"war/train_beg";
inherit __DIR__+"war/train_success";
inherit __DIR__+"war/train_new";
inherit __DIR__+"war/train_check";
inherit __DIR__+"war/train_question";
inherit __DIR__+"war/train_def";
inherit __DIR__+"war/train_over";
void cancel_att_task(string area);
mixed * make_unique(mixed *inp) {
	mixed * tmp=({});
	foreach (mixed x in inp) {
		tmp-=({x});
		tmp+=({x});
	}
	return tmp;
}
void war(string att_area,string def_area)
{
        string att_name,att_id;
        int t_num,i;
        string s_room;
        mixed m_us;
        string p_leader;
        
        string* u_list;
		cancel_att_task(def_area);

        if(!(att_id=AREA_D->get_area(att_area,"nation")))
                att_name=robber_name(att_area);
        else
                att_name=COUNTRY_D->get_country(att_id,"name");
        CHANNEL_D->deliver_tell("rumor","system",
        att_name+"正在计划进攻"+AREA_D->get_area(def_area,"name")+"。");
        t_num=TASK_D->add_task(TT_WAR);
        TASK_D->set_task(t_num,"def_area",def_area);
        TASK_D->set_task(t_num,"area",def_area);
        TASK_D->set_task(t_num,"att_area",att_area);
        TASK_D->set_task(t_num,"att_id",att_id);
        TASK_D->set_task(t_num,"att_name",att_name);
       WARAI_D->create_inf(t_num);
        s_room=AREA_D->get_area(def_area,"path")+
                AREA_D->get_area(def_area,"meeting");
        TASK_D->set_task(t_num,"def_room",s_room);
        //如果是NPC国家，则是全国的NPC将军都有可能参加作战 suicide 2001.4.19
        if (CHAR_D->get_char(AREA_D->get_area(def_area,"nation"),"type")==TYPE_NPC)
            u_list=CHAR_D->check_char_nation("type",TYPE_NPC,AREA_D->get_area(def_area,"nation"));
        else //end
            u_list=CHAR_D->check_char_area("nation",
                AREA_D->get_area(def_area,"nation"),def_area);
        
	u_list=filter_array(u_list,
			(:CHAR_D->get_char($1,"task")==TASK_NONE:));

        TASK_D->set_task(t_num,"def_party",u_list);     
        m_us=([]);
        for(i=0;i<sizeof(u_list);++i)
        {
              m_us[u_list[i]]=1;  // need to disable current task
        }
        p_leader=AREA_D->get_area(def_area,"leader");
        m_us[p_leader]=2;
        TASK_D->set_task(t_num,"chars",m_us);
        TASK_D->set_task(t_num,"timaim",60); // 5 min to prepare
        TASK_D->set_task(t_num,"stage",0);
	if(!att_id) // robber_attack
                call_out("robber_attack_prepare",24,t_num);
       MAP_D->add_city(def_area);
       call_out("def_meeting",5,t_num);
}
int can_auto_war(string a_id)
{
        int* task;
        string p_leader;
        string* u_list;
        p_leader=AREA_D->get_area(a_id,"leader");
        task=TASK_D->get_char_task(p_leader);
        if(task[0]!=-1)  // has some task
        {
                return 0;
        }
		if(AREA_D->get_area(a_id,"status")!=ST_NORMAL)
			return 0;
        u_list=CHAR_D->check_char_area("nation",
                AREA_D->get_area(a_id,"nation"),a_id);
        u_list=filter_array(u_list,(:CHAR_D->get_char($1,"status")==STATUS_ONLINE :));
        if(sizeof(u_list)) // have online char
                return 1;
        return 1;
}
void auto_war() // this just war from band
{
        string* area_list;
        int test=3;
	return ; // disable auto war
        area_list=AREA_D->list_areas();
        while(test--)
        {
                string a_id;
                int p_res;
                a_id=area_list[random(sizeof(area_list))];
 
                p_res=can_auto_war(a_id);
                if(p_res)
                {
                        string p_invender;
                        switch(random(4))
                        {
                                case 0: p_invender="aut bandit"; break;
                                case 1: p_invender="aut brigand"; break;
                                case 2: p_invender="aut yellow"; break;
                                default: p_invender="aut cateran"; break;
                        }
                        war(p_invender,a_id);
						return;
                }
        }
}
void meet_process(int p_id)
{
        int p_stage;
        p_stage=TASK_D->get_task(p_id,"stage");
        switch(p_stage)
        {
                case 0:  // doesn't really attack;
                        abort_war(p_id);
               case 1: // in the attack check the win or lose
                      check_result(p_id);
        }
}
void new_area_war(string att_leader,string att_area,string def_area){
        string att_name;
        int t_num;
        string s_room;
        mixed m_us;
        string p_leader;
	string msg;        
        int i;
        string* u_list;

        att_name=COUNTRY_D->get_country(
			CHAR_D->get_char(att_leader,"nation"),"name");

        t_num=TASK_D->add_task(TT_WAR);

		AREA_D->store_soldiers(att_area);
		AREA_D->store_soldiers(def_area);

        TASK_D->set_task(t_num,"def_area",def_area);
        TASK_D->set_task(t_num,"area",def_area);
        
		TASK_D->set_task(t_num,"att_area",att_area);
        TASK_D->set_task(t_num,"att_id",CHAR_D->get_char(att_leader,"nation"));
        TASK_D->set_task(t_num,"att_name",att_name);
		TASK_D->set_task(t_num,"att_leader",att_leader);

		WARAI_D->create_inf(t_num);


        s_room=AREA_D->get_area(def_area,"path")+
                AREA_D->get_area(def_area,"meeting");
        TASK_D->set_task(t_num,"def_room",s_room);
        u_list=CHAR_D->check_char_area("nation",
                AREA_D->get_area(def_area,"nation"),def_area);
        

		u_list=filter_array(u_list,
			(:CHAR_D->get_char($1,"task")==TASK_NONE:));
                if(sizeof(u_list)>60)
			u_list=filter_array(u_list,(:CHAR_D->get_char($1,"level")>1:));


        TASK_D->set_task(t_num,"def_party",u_list);     
        m_us=([]);
        for(i=0;i<sizeof(u_list);++i)
        {
              m_us[u_list[i]]=1;  // need to disable current task
        }
        p_leader=AREA_D->get_area(def_area,"leader");
		if((!CHAR_D->char_exist(p_leader))&&(sizeof(u_list)>0)) {
			p_leader=u_list[random(sizeof(u_list))];
		}
		TASK_D->set_task(t_num,"pre_def_leader",p_leader);

        m_us[p_leader]=2;

        TASK_D->set_task(t_num,"chars",m_us);
        TASK_D->set_task(t_num,"timaim",60); // 5 min to prepare
        TASK_D->set_task(t_num,"stage",0);
		
		// this field is used to terminate an attack if others
		// attack this area.
		AREA_D->set_area(att_area,"att_task",t_num+1);

		
		call_out("att_collect",10,t_num);
		MAP_D->add_city(def_area);
		call_out("def_meeting",2,t_num);
	msg=DAY_D->query_chinese_day()+"，"+att_name+"的"+CHAR_D->get_char(att_leader,"name")
		+"从"+AREA_D->get_area(att_area,"name")+"发兵攻打"+
		COUNTRY_D->get_country(AREA_D->get_area(def_area,"nation"),"name")+"的"+AREA_D->get_area(def_area,"name")+"。";
	TASK_D->set_task(t_num,"msg_title",msg);

	if(AREA_D->get_area(att_area,"leader")==att_leader) {
		CHAR_D->set_char(att_leader,"ranklocal",R_SG);
		AREA_D->auto_head(att_area);
	}

}
void add_area_war(string att_leader,string att_area,string def_area)
{
	tell_user(att_leader,"你所要攻打的地方正在进行战争，\n"+
		"目前增援功能尚未完成。\n"+
		"因此此次出兵计划取消。\n");
	return;
}
// this is begin a war
void area_war(string att_leader,string att_area,string def_area)
{
	int def_stat,def_task_id;
	def_stat=TASK_D->get_area_task(def_area);
	def_task_id=TASK_D->get_area_task_id(def_area);
//	tell_user("fire",sprintf("the def_stat is %d the def_id is %d\n"));
	cancel_att_task(def_area);
	switch(def_stat) {
	case ST_MEETING:
		(EV_WAR)->urgent_terminate_meeting(def_task_id);
		new_area_war(att_leader,att_area,def_area);
		return;
	case ST_TRAIN:
		(EV_WAR)->urgent_terminate_train(def_task_id);
		new_area_war(att_leader,att_area,def_area);
		return;
	case ST_WAR:
		add_area_war(att_leader,att_area,def_area);
		return;
	case ST_NORMAL:
		new_area_war(att_leader,att_area,def_area);
		return;
	default:
		error(sprintf("something wrong the def_stat is %d\n",def_stat));
	}
}

void urgent_terminate_meeting(int task_id) {
	string p_area,p_leader;
	object o_leader;
	p_area=TASK_D->get_task(task_id,"area");
	p_leader=AREA_D->get_area(p_area,"leader");
	o_leader=CHAR_D->find_char(p_leader);
	if(objectp(o_leader)) {
		o_leader->simple_action(
			"$N表情严肃地道：事态紧急，今日的会就到此结束。\n");
	}
	TASK_D->remove_task(task_id);
}
void urgent_terminate_train(int task_id)
{
	mixed ids;
	ids=TASK_D->get_task(task_id,"chars");
	if(sizeof(ids))
	{
		ids=keys(ids);
		foreach(string id in ids) {
			tell_user(id,"事态紧急，训练中止。\n");
		}
	}
	release_army(task_id);
	TASK_D->remove_task(task_id);
}

void cancel_att_task(string area) {
	int task_id;
	mixed chars;
	string *att_party;
	string att_leader;
	object o;

	task_id=AREA_D->get_area(area,"att_task")-1;
	if(task_id==-1) return;
	if((TASK_D->get_task(task_id,"att_area"))!=area) return;
	if(TASK_D->get_task(task_id,"att_arrange_step")=="over")
		return;
	if(TASK_D->get_task(task_id,"att_arrange_step")=="cancel")
		return;
	// really to cancel the attack task
	TASK_D->set_task(task_id,"att_arrange_step","cancel");
	AREA_D->set_area(area,"att_task",0);
	att_party=TASK_D->get_task(task_id,"att_party");
	chars=TASK_D->get_task(task_id,"chars");
	if(sizeof(att_party)) {
		foreach(string a in att_party) {
			map_delete(chars,a);
		}
		TASK_D->set_task(task_id,"chars",chars);
	}

	att_leader=TASK_D->get_task(task_id,"att_leader");
	o=find_body(att_leader);
	if(objectp(o)) 
		o->simple_action("$N道：情况有变，此次出兵计划取消。");
	o=find_user(att_leader);
	if(objectp(o))
		o->modal_pop();
}
