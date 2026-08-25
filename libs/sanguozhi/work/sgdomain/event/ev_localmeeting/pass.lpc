// pass.c
// by fire on Aug 14, 1998
// to handle pass a suggestion in the meeting
#define MAX_POLICE_SAFE 80
void award(object usr);
string get_problem(int task_id);
void dis_over(int task_id);

void pass_market(string p_area)
{
	mixed ret;
	ret=(EV_MERCHANT)->market(p_area);
	if(stringp(ret)) 
		CHANNEL_D->deliver_tell("rumor","system","因为"+ret+"，"+
		AREA_D->get_area(p_area,"name")+"开办集市失败。");
}


void pass_war(string p_area,string p_para,string p_id,int task_id){
	TASK_D->set_task(task_id,"war_leader",p_id);
	TASK_D->set_task(task_id,"att_area",p_area);
	TASK_D->set_task(task_id,"def_area",p_para);
	return ;

}
void pass_build(string p_area,string f_id)
{
    int p_gold=AREA_D->get_area(p_area,"gold");
	int p_goldneed=BASE_D->get_base(f_id,"gold");
    mixed * bases=AREA_D->get_area(p_area,"base");
	string p_dis=AREA_D->get_area(p_area,"name")+
		"开始建造"+BASE_D->get_base(f_id,"name")+"。";
	if(p_gold<p_goldneed) {
		p_dis+="但是资金不足，建造失败。";
	}
	else {
		object bs;
		if(!arrayp(bases))
			bases=({});
		bases+=({f_id});
		AREA_D->set_area(p_area,"base",bases);
		AREA_D->set_area(p_area,"gold",p_gold-p_goldneed);
		// need init base_server here
		p_dis+=AREA_D->get_area(p_area,"name")+
		"建成了"+BASE_D->get_base(f_id,"name")+"。";
		bs=SGBASE(p_area,f_id);
		if(objectp(bs)) {
			bs->init_rooms();
			bs->check_me();
		}

	}
    CHANNEL_D->deliver_tell("rumor","system",p_dis);
}

void pass_update(string p_area,string f_id)
{
    int p_gold=AREA_D->get_area(p_area,"gold");
	int p_goldneed=BASE_D->get_base(f_id,"gold");
	string p_dis=AREA_D->get_area(p_area,"name")+
		"开始升级"+BASE_D->get_base(f_id,"name")+"。";
	if(p_gold<p_goldneed) {
		p_dis+="但是资金不足，升级失败。";
	}
	else {
		object bs;
		int lev;
		bs=SGBASE(p_area,f_id);
		AREA_D->set_area(p_area,"gold",p_gold-p_goldneed);
		// need init base_server here
		p_dis+=AREA_D->get_area(p_area,"name")+
		"升级了"+BASE_D->get_base(f_id,"name")+"。";
		if(objectp(bs)) {
			lev=bs->get_level();
			lev++;
			bs->set_level(lev);
			bs->check_me();
		}

	}
    CHANNEL_D->deliver_tell("rumor","system",p_dis);
}


void pass_sendfood(string p_area,int p_para)
{
    int p_population=AREA_D->get_area(p_area,"population");
    int p_inc;
	int p_safe;
	string p_dis;
	AREA_D->set_area(p_area,"food",
		AREA_D->get_area(p_area,"food")-p_para);
	p_inc=p_para*10/p_population;
	p_inc=bmin(p_inc,20);
	p_safe=AREA_D->get_area(p_area,"safe");
	if(p_safe<MAX_POLICE_SAFE) {
		p_safe+=p_inc;
		p_safe=bmin(MAX_POLICE_SAFE,p_safe);
	}
	AREA_D->set_area(p_area,"safe",p_safe);
    p_dis=AREA_D->get_area(p_area,"name")+"开仓放粮，百姓欢欣鼓舞。";
    CHANNEL_D->deliver_tell("rumor","system",p_dis);
}
void pass_localbuy(string p_area,string p_what, string p_id)
{
   string p_dis;
   object o_id;
   o_id=find_body(p_id);
   if(objectp(o_id))
   {
      o_id->add_job("localbuy");
      o_id->set_job("localbuy","what",p_what);
      o_id->set_job("localbuy","memo","购买"+(EV_MERCHANT)->query_goods(p_what,"name"));
      o_id->set_job("localbuy","area",CHAR_D->get_char(p_id,"area"));
      o_id->simple_action("%^H_GREEN%^$N得到了购买"+(EV_MERCHANT)->query_goods(p_what,"name")+
           "的任务。\n%^RESET%^");
   }
}

void pass_recruit(string p_area,mixed p_newsoldier,string p_id)
{
   	int p_safe,p_soldier;
  	string p_dis;
 	mapping troop;
      	object o_id;

	if( mapp(p_newsoldier) )p_soldier=p_newsoldier["no"];
	else p_soldier=p_newsoldier;

   	if( p_soldier > 0 ){  
      		p_safe = to_int(p_soldier/100);
		if( p_safe < 1 )p_safe = 1;
		if( p_safe >30 )p_safe = 30;
      		p_dis=AREA_D->get_area(p_area,"name")+"征兵，百姓不满。";
      			CHANNEL_D->deliver_tell("rumor","system",p_dis);
      		o_id=find_body(p_id);
      		if( objectp(o_id) ){
         		o_id->add_job("recruit");
         		o_id->set_job("recruit","left",p_newsoldier);
         		o_id->set_job("recruit","memo","征"+p_newsoldier+"兵");
         		o_id->set_job("recruit","area",CHAR_D->get_char(p_id,"area"));
         		o_id->simple_action("%^H_GREEN%^$N得到征"+chinese_number(p_newsoldier)+
           			"兵的任务。\n%^RESET%^");
      		}
   	}
   	else { 
		troop = AREA_D->get_area(p_area, "troop");
		if( !mapp(troop) )troop = ([ ]);
		troop[p_newsoldier["type"]] = 
			troop[p_newsoldier["type"]]+p_newsoldier["no"];
		if( troop[p_newsoldier["type"]] <= 0)map_delete(troop,p_newsoldier["type"]);
		AREA_D->set_area(p_area, "troop", troop);
		AREA_D->set_area(p_area, "soldier", 
			AREA_D->get_area(p_area,"soldier")+p_newsoldier["no"]);
   }
	AREA_D->set_area(p_area,"safe",
		AREA_D->get_area(p_area,"safe")-p_safe);
       
}
void pass_localtax(string p_area,int p_newtax)
{
        int p_oldtax;
        int p_safe;
        string p_dis;
        p_oldtax=AREA_D->get_area(p_area,"taxlocal");
        p_safe=AREA_D->get_area(p_area,"safe");
        if(p_newtax>p_oldtax)
        {
                p_safe-=(p_newtax-p_oldtax)*2;
                p_dis=AREA_D->get_area(p_area,"name")+"地方税率上调，百姓怨声载道。";
        }
        else
        {
 
		if(p_safe<MAX_POLICE_SAFE) {
			p_safe+=(p_oldtax-p_newtax);
			p_safe=bmin(MAX_POLICE_SAFE,p_safe);
		}
                p_dis=AREA_D->get_area(p_area,"name")+"地方税率下调，百姓欢欣鼓舞。";
        }
        AREA_D->set_area(p_area,"taxlocal",p_newtax);
        AREA_D->set_area(p_area,"safe",p_safe);
        CHANNEL_D->deliver_tell("rumor","system",p_dis);
}
void pass_importance(string p_area,int p_inp)
{
	string p_dis;
        p_dis=AREA_D->get_area(p_area,"name")+"调整政策，百姓感到恐慌。";
	AREA_D->set_area(p_area,"importance",p_inp);
        AREA_D->set_area(p_area,"safe",AREA_D->get_area(p_area,"safe")-5);
        CHANNEL_D->deliver_tell("rumor","system",p_dis);
}
void suggestion_pass(int task_id)
{
   string p_area,p_leader,p_room,p_subject,p_id;
   mixed p_para;
   string p_soldier;
   object o_leader,o_soldier,o_id;
   string p_problem,*suggested;
   p_subject=TASK_D->get_task(task_id,"suggestion");
   suggested=TASK_D->get_task(task_id,"suggested");
   if(!arrayp(suggested))
       suggested=({});
   suggested+=({p_subject});
   TASK_D->set_task(task_id,"suggested",suggested);
   p_para=TASK_D->get_task(task_id,"suggestiondetail");
   p_id=TASK_D->get_task(task_id,"suggestionppl");
   p_area=TASK_D->get_task(task_id,"area");
   p_leader=AREA_D->get_area(p_area,"leader");
   p_soldier=p_leader+" bing";
   p_problem=get_problem(task_id);
   CHAR_D->add_char(p_soldier);
   CHAR_D->set_char(p_soldier,"name","传令兵");
   CHAR_D->set_char(p_soldier,"is_tmp",1);
   o_leader=CHAR_D->find_char(p_leader);
   if(objectp(o_leader))
          o_leader->simple_action("$N喝道：传令兵何在？\n");
   p_room=AREA_D->get_area(p_area,"path")+AREA_D->get_area(p_area,"meeting");
   CHAR_D->put_char(p_soldier,p_room);
   o_soldier=CHAR_D->find_char(p_soldier);
   if(objectp(o_soldier))
       o_soldier->simple_action("$N闪身进入，躬身道：在！\n");
   if(objectp(o_leader))
       o_leader->simple_action("$N道：传我指令，将"+p_problem+"。\n");
   if(objectp(o_soldier))
   {
      o_soldier->simple_action("$N大声道：得令！\n");
      o_soldier->simple_action("$N转身退出。\n");
   }
   CHAR_D->remove_npc_char(p_soldier);
   CHAR_D->remove_char(p_soldier);
   CHANNEL_D->deliver_tell("rumor","system",
   AREA_D->get_area(p_area,"name")+"将"+p_problem+"。");
   switch(p_subject){
       case "localtax": pass_localtax(p_area,p_para); break;
       case "recruit": pass_recruit(p_area,p_para,p_id); break;
       case "importance": pass_importance(p_area,p_para); break;
	   case "localbuy": pass_localbuy(p_area,p_para,p_id); break;
	   case "sendfood": pass_sendfood(p_area,p_para); break;
	   case "war": pass_war(p_area,p_para,p_id,task_id); break;
	   case "build": pass_build(p_area,p_para); break;
	   case "update": pass_update(p_area,p_para); break;
	   case "market": pass_market(p_area); break;
   }
   dis_over(task_id);
   tell_user(p_id,"你的建议很聪明，看看你人是不是也聪明。");
   o_id=find_body(p_id); if(!objectp(o_id)) return;
   o_id->finish_job("suggest");
   o_id=find_user(p_id);
   if(objectp(o_id))
       ROBOT->robot_test(o_id,(:award:));
}
void award(object usr)
{
   object o_id;
   string p_id;
   int isrobot;
   if(!objectp(usr)) return;
   o_id=usr->query_body();
   if(!objectp(o_id)) return;
   isrobot=o_id->query_robot();
   if(isrobot)
   {
      o_id->simple_action("$N的建议被采纳，但$N好像什么都没得到。\n");
      return;
   }
   p_id=o_id->query_id()[0];
   o_id->award_exp(5);
   CHAR_D->set_char(p_id,"reputation",
     CHAR_D->get_char(p_id,"reputation")+5);
   CHAR_D->set_char(p_id,"localcontribution",
     CHAR_D->get_char(p_id,"localcontribution")+random(2));
   o_id->simple_action("$N的建议被采纳，$N的经验与声望提高了。\n");
        
}
