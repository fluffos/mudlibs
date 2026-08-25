// train.c 
// this is used to handle the the train process
// by fire on Dec 13, 1998
#include <train.h>
void release_army(int p_id);
void def_pre_arrange(int task_id,string def_area);

//武将排序
void train_arrange(int task_id)
{
   string def_area,def_leader,*def_general;
   def_area=TASK_D->get_task(task_id,"def_area");

   def_general=TASK_D->get_task(task_id,"def_party");
   def_leader=TASK_D->get_task(task_id,"def_leader");
   def_general-=({def_leader});
   //sort by the sum of the char's wuli 
   //added by suicide in 2000.11.08
   //FBUG("%^RED%^Sort def_general_left arrays!%^RESET%^");
   def_general = sort_array(def_general,
                 (: CHAR_D->get_char($1,"skills")["sk_wuli"] > CHAR_D->get_char($2,"skills")["sk_wuli"] ? -1 : 1 :));
   //ended
   
   TASK_D->set_task(task_id,"def_general_left",def_general);

   def_pre_arrange(task_id,def_area);
/*   int p_soldier,p_people,p_horse,p_bow;
   int p_infantry,p_cavalry,p_bowman,p_commando;
   mixed def_general;   
   string def_leader;
   p_soldier=AREA_D->get_area(def_area,"soldier");
   p_horse=AREA_D->get_area(def_area,"horse");
   p_bow=AREA_D->get_area(def_area,"bow");
   p_cavalry= bmin(p_soldier,p_horse);
   p_soldier-=p_cavalry;
   p_bowman=bmin(p_soldier,p_bow);
   p_infantry=p_soldier-p_bowman;
   TASK_D->set_task(task_id,"def_bowman_left",p_bowman);
   TASK_D->set_task(task_id,"def_infantry_left",p_infantry);
   TASK_D->set_task(task_id,"def_cavalry_left",p_cavalry);
   TASK_D->set_task(task_id,"def_commando_left",p_commando);
   TASK_D->set_task(task_id,"def_arrange_troop",0);
   TASK_D->set_task(task_id,"def_arrange_step","newtroop");
   TASK_D->set_task(task_id,"def_curent_arrange_troop",([]));
   def_general=TASK_D->get_task(task_id,"def_party");
   def_leader=TASK_D->get_task(task_id,"def_leader");
   def_general-=({def_leader});
   return; */
}
void train_collect(int task_id)
{
	string def_leader,def_area;
	string p_flyroom,p_short;
	string *def_party;
	string *def_general_left;
	object o_char;
	def_leader=TASK_D->get_task(task_id,"def_leader");
	o_char=CHAR_D->find_char(def_leader);
	def_area=TASK_D->get_task(task_id,"def_area");
	p_flyroom=AREA_D->get_area(def_area,"path")+AREA_D->get_area(def_area,"fly");
	p_short=load_object(p_flyroom)->short();
	if(objectp(o_char))
	{ 	o_char->simple_action("$N道：诸位将军、大人，速到"+
			p_short+"点兵训练。\n");
		CHAR_D->put_char(def_leader,p_flyroom);
		o_char->simple_action("$N来到了"+p_short+"。\n");
		o_char->resign_job("train");
		o_char->add_job("train");
	}
	CHAR_D->put_char(def_leader,p_flyroom);
	def_party=TASK_D->get_task(task_id,"def_general_left");
	if(sizeof(def_party))
	foreach(string p_id in def_party)
	{
		o_char=CHAR_D->find_char(p_id);
		CHAR_D->put_char(p_id,p_flyroom);
		if(objectp(o_char))
		{
			o_char->simple_action("$N来到了"+p_short+"。\n");
		}
   }
}


//初始化训练任务的各参数
void train(string p_area,string leader,string* group)
{
    string att_name,att_id;
    int t_num;
    string s_room;
    mixed m_us;
    string p_leader;
    int i;
    string* u_list;
	AREA_D->store_soldiers(p_area);
    t_num=TASK_D->add_task(TT_TRAIN);
        
    att_id="train aim";
    att_name="目标部队";
    CHANNEL_D->deliver_tell("rumor","system",
      CHAR_D->get_char(leader,"name")+"在"+
      AREA_D->get_area(p_area,"name")+"大规模操练兵士。");
    TASK_D->set_task(t_num,"def_area",p_area);
    TASK_D->set_task(t_num,"area",p_area);
    TASK_D->set_task(t_num,"att_area",p_area);
    TASK_D->set_task(t_num,"att_id",att_id);
    TASK_D->set_task(t_num,"att_name",att_name);
    WARAI_D->create_inf(t_num);	//初始化战斗中显示的信息
    u_list=group;
    TASK_D->set_task(t_num,"def_party",u_list);     
    m_us=([]);
    for(i=0;i<sizeof(u_list);++i)
    {
       m_us[u_list[i]]=1;  // need to disable current task
    }
    m_us[leader]=2;
    TASK_D->set_task(t_num,"chars",m_us);
    MAP_D->add_city(p_area);
    TASK_D->set_task(t_num,"def_leader",leader);
    TASK_D->set_task(t_num,"timaim",2); // 10 second to prepare
    TASK_D->set_task(t_num,"stage",TRAIN_BEG);
    train_arrange(t_num);
}

void train_process(int p_id)
{
	int res,curtime,stage;
	mixed question;
	stage=TASK_D->get_task(p_id,"stage");
  
	switch(stage)
	{
	case TRAIN_BEG:
		train_collect(p_id);
		TASK_D->set_task(p_id,"stage",TRAIN_PROCESS);
		break;
	case TRAIN_PROCESS:
		curtime=TASK_D->get_task(p_id,"curtime");
		TASK_D->set_task(p_id,"curtime",curtime+1);
		res=check_question(p_id);
    switch(res)
    {
        case QUESTION_PROCESS:
            return;
        case QUESTION_OVER_DUE:
            question_overdue(p_id);
            break;
        case QUESTION_FAIL:
            question_fail(p_id);
            TASK_D->set_task(p_id,"stage",TRAIN_END);
            return;
        case QUESTION_SUCCESS:
            question_success(p_id);
            break;
        case NO_QUESTION:
            break; 
        default:
            question_wrong(p_id);
            break;
    }
    question=new_question(p_id);
    if(!question) // no other questions
       TASK_D->set_task(p_id,"stage",TRAIN_END);
    else
       question_new(p_id,question);
    break;
	case TRAIN_END:
		train_over(p_id);
		break;
	case AFTER_TRAIN: 
		release_army(p_id);
    TASK_D->remove_task(p_id);
  }
}
