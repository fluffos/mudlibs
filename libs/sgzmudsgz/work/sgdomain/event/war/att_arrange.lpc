// arrange the attack army
// this is used to handle the the begin and over train
#include <train.h>

void release_army(int p_id);
void atack_abort(string p_id,int task_id) {
	mixed * att_store_troop;
	int sum,i;
	mapping tmptroop,troop;
	mapping pre_troop;
   	string a_area = TASK_D->get_task(task_id,"att_area");
	int reputation,duce;

	call_out("abort_war",2,task_id);


   	att_store_troop = TASK_D->get_task(task_id,"att_store_troop");
   	sum = sizeof(att_store_troop);
	tmptroop=TASK_D->get_task(task_id, "att_troop_left");
	if(!mapp(tmptroop)) tmptroop=([]);

   	for( i = 0; i < sum; ++i){
		pre_troop = att_store_troop[i];
		troop = pre_troop["troop"];
		foreach(string tt in keys(troop) ){
			tmptroop[tt]+=troop[tt];
		}
	}
	AREA_D->set_area(a_area,"troop",tmptroop);
	AREA_D->set_area(a_area,"morale",AREA_D->get_area(a_area,"morale")-10);
	TASK_D->set_task(task_id,"att_army",0);
	reputation=CHAR_D->get_char(p_id,"reputation");
	duce=reputation/20;
	if(duce>500) duce=500;
	reputation-=duce;
	CHAR_D->set_char(p_id,"reputation",reputation);
		
}

void att_pre_arrange(int task_id,string att_area)
{
	int p_soldier;
	mapping troop;

	p_soldier = AREA_D->get_area(att_area,"soldier");
	troop = AREA_D->get_area(att_area,"troop");
	foreach(string tt in keys(troop)){
		if( troop[tt] == 0 )map_delete(troop, tt);
	};

   	TASK_D->set_task(task_id,"att_max_soldier",p_soldier);
   	TASK_D->set_task(task_id,"att_troop_left", troop);
   	TASK_D->set_task(task_id,"att_arrange_troop",0);
   	TASK_D->set_task(task_id,"att_arrange_step","att_all_general");
   	TASK_D->set_task(task_id,"att_curent_arrange_troop",([]));
	TASK_D->set_task(task_id,"att_store_troop",({}));

   	return;
}
void att_collect(int task_id)
{
   	string att_leader, att_area, a_nation, loc_leader, p_flyroom, p_short;
   	string *att_all_general;
   	object o_char;

   	att_leader = TASK_D->get_task(task_id,"att_leader");
   	o_char = CHAR_D->find_char(att_leader);
   	att_area = TASK_D->get_task(task_id,"att_area");
   	p_flyroom = AREA_D->get_area(att_area,"path") + AREA_D->get_area(att_area,"fly");
   	p_short = load_object(p_flyroom)->short();

   	if( objectp(o_char) ){ 
		o_char->simple_action("$N道：诸位将军、大人，请速到"+p_short+"点兵出征。\n");
      		CHAR_D->put_char(att_leader,p_flyroom);
      		o_char->simple_action("$N来到了"+p_short+"。\n");
   	}
   	CHAR_D->put_char(att_leader,p_flyroom);

    	a_nation = CHAR_D->get_char(att_leader,"nation");
    	att_all_general = CHAR_D->check_char_area("nation",a_nation,att_area);
    	att_all_general = filter_array(att_all_general,(:CHAR_D->get_char($1,"task")==TASK_NONE:));
                if(sizeof(att_all_general)>60) {
			att_all_general=filter_array(att_all_general,(:CHAR_D->get_char($1,"level")>1:));

		}

	att_all_general-=({att_leader});
	loc_leader = AREA_D->get_area(att_area,"leader");
	att_all_general-=({loc_leader});

    	TASK_D->set_task(task_id,"att_all_general",att_all_general);
   
   	if(sizeof(att_all_general))
   		foreach(string p_id in att_all_general){
      			o_char=CHAR_D->find_char(p_id);
      			CHAR_D->put_char(p_id,p_flyroom);
      			if(objectp(o_char))
			o_char->simple_action("$N来到了"+p_short+"。\n");
   		}
   	att_pre_arrange(task_id,att_area);
   	new("/sgdomain/menu/warinput")->man_input(att_leader,task_id,"a");
}
///////////////////////////////////////////////////////////////////////////////////
// this is the last stage so all the troop will created and enter the war field ///
void att_arrange_left(int task_id)
{
	mapping troop;
   	string p_area,a_area,p_stage, p_room, tt, p_nation, p_leader;
   	object o_troop, o_leader;
   	int *att_army,sum, i, t_id, p_m, p_t; //morale and train
   	mixed att_store_troop, tmp, pre_troop;
   	int total_soldier=0;

   	TASK_D->set_task(task_id,"att_arrange_step","enter_warfield"); //enter warfield
   	p_area = TASK_D->get_task(task_id,"def_area");
   	a_area = TASK_D->get_task(task_id,"att_area");
   	AREA_D->set_area(a_area,"att_task",0); // can't cancel
   	p_stage = TASK_D->get_task(task_id,"att_arrange_step");
   	if( (p_stage=="over") || (p_stage=="cancel") )return; // canceled already
   	TASK_D->set_task(task_id,"att_arrange_step","over");

   	p_nation = AREA_D->get_area(a_area,"nation");
   	p_leader = TASK_D->get_task(task_id,"att_leader");
   	o_leader = CHAR_D->find_char(p_leader);

	if( objectp(o_leader) ){
		o_leader->simple_action("$N喝道：全体将士定要奋勇杀敌，$s自有重赏！\n");
                o_leader->simple_action("$N领将士进入战场。\n");
        }
   	att_store_troop = TASK_D->get_task(task_id,"att_store_troop");
   	sum = sizeof(att_store_troop);
   	att_army = ({});
	p_m = AREA_D->get_area(a_area,"morale"); // def increase morale
	p_t = AREA_D->get_area(a_area,"train");
   	for( i = 0; i < sum; ++i){
		pre_troop = att_store_troop[i];
		p_room = AREA_D->get_area(p_area,"path")+"warroom/"+
			att_get_position(p_area,pre_troop["position"]);
		o_troop = TROOP_D->new_troop(p_nation,pre_troop["general"],0,p_room);
		t_id = o_troop->get_id();
		TROOP_D->set_troops(t_id,"task_id",task_id);
		TROOP_D->set_troops(t_id,"side","a");
		TROOP_D->set_troops(t_id,"source_area",a_area);
		att_army+=({t_id});
		troop = pre_troop["troop"];
		foreach( tt in keys(troop) ){
			TROOP_D->add_soldier(t_id,tt,troop[tt],p_m,p_t,0);
			total_soldier = total_soldier + troop[tt];
		}
		
	}

	TASK_D->set_task(task_id,"att_army",att_army);
   	TASK_D->set_task(task_id,"timaim",2); // 10 sec check
   	TASK_D->set_task(task_id,"stage",1); // begin war
	
	tmp = TASK_D->get_task(task_id, "att_troop_left");
	foreach(tt in keys(tmp)){
                if( tmp[tt] == 0 )map_delete(tmp, tt);
        };
	AREA_D->set_area(a_area, "troop", tmp);
   	CHANNEL_D->deliver_tell("rumor","system",
	 	CHAR_D->get_char(p_leader,"name")+"领"+
	   	chinese_number(total_soldier)+"兵士向"+
	   	AREA_D->get_area(p_area,"name")+"杀来！！！");
	TASK_D->set_task(task_id,"msg_total_att_soldiers","进攻方总兵力："+chinese_number(total_soldier));

}
void put_att_troop(int task_id)
{
   	mixed pre_troop, tmp;
   	string p_leader,p_general;
   	object o_leader,o_general;
   	int total_soldier;
	mapping troop;
	mixed * msg_att_party;
	mapping msgs;

   	pre_troop = TASK_D->get_task(task_id,"att_curent_arrange_troop");
	troop = pre_troop["troop"];
  	foreach(string tt in keys(troop))total_soldier = total_soldier + troop[tt];

   	if(!total_soldier)return;
   	p_leader = TASK_D->get_task(task_id,"att_leader");
   	p_general= pre_troop["general"][0];
   	o_leader = CHAR_D->find_char(p_leader);
   	o_general= CHAR_D->find_char(p_general);
   	if( (objectp(o_leader))&&(objectp(o_general)) ){
		if( p_leader == p_general )
			o_leader->simple_action("$s亲自带"+CHINESE_D->chinese_number(total_soldier)+"兵马出战！\n");
                else {
       			o_leader->targetted_action("$N喝道：$T何在？\n",o_general);
       			o_general->simple_action("$N答道：$s在！\n");
			DELAY_D->delay_targetted_action(
				o_leader,o_general,"$N对$T说到：速点"+
				CHINESE_D->chinese_number(total_soldier)+"兵马待命出发。\n$T答道：得令。\n",1);
		}
   	}

   	tmp = TASK_D->get_task(task_id,"att_general_left");
  	tmp-= pre_troop["general"];
  	TASK_D->set_task(task_id,"att_general_left",tmp);
	tmp = TASK_D->get_task(task_id,"att_troop_left");

	msg_att_party=TASK_D->get_task(task_id,"msg_att_party");
	if(!arrayp(msg_att_party)) msg_att_party=({});
	msgs=([]);
	msgs["generals"]=pre_troop["general"];
	msgs["troops"]=troop;
	msg_att_party+=({msgs});
	TASK_D->set_task(task_id,"msg_att_party",msg_att_party);

	foreach(string tt in keys(troop) ){
		tmp[tt] -=  troop[tt];
                if( tmp[tt] == 0 )map_delete(tmp, tt);

	};
	TASK_D->set_task(task_id,"att_troop_left",tmp);

  	tmp = TASK_D->get_task(task_id,"att_store_troop");
  	tmp+=({pre_troop});
  	TASK_D->set_task(task_id,"att_store_troop",tmp);
}
mixed get_att_val(int task_id)
{
   	int p_troop,n_tmp;
   	string p_stage, p_area;
   	mixed tmp,tmp2;

   	p_troop= TASK_D->get_task(task_id,"att_arrange_troop");
   	p_stage= TASK_D->get_task(task_id,"att_arrange_step");
   	p_area = TASK_D->get_task(task_id,"def_area");

   	switch(p_stage){
   		case "att_all_general":
			tmp = TASK_D->get_task(task_id,"att_all_general");
			if(sizeof(tmp)) return tmp[0]; // in order to simple, just have one accompany
			else return -1;
   		case "general":
        		tmp = TASK_D->get_task(task_id,"att_general_left");
        		if( !sizeof(tmp) ) return -1;
        		else return tmp[0];
   		case "position":
			tmp = att_get_position(p_area,"e");
        		return tmp;
   		case "newtroop":
        		tmp = TASK_D->get_task(task_id,"att_general_left");
        		if( !sizeof(tmp) ) return -1;
//        		if( p_troop >= 5 ) return -1;
        		tmp = TASK_D->get_task(task_id,"att_troop_left");
        		if( !sizeof(tmp) ) return -1;

        		else return 1;
   		default:
			tmp = TASK_D->get_task(task_id,"att_troop_left");
			if(!tmp[p_stage]) return -1;
			tmp2=TASK_D->get_task(task_id,"att_general_left");
			n_tmp=bmin(sizeof(tmp2),8-p_troop); // send less soldiers
			n_tmp=bmax(1,n_tmp);
			n_tmp=tmp[p_stage]/n_tmp;
			tmp=TASK_D->get_task(task_id,"att_curent_arrange_troop");
			n_tmp=bmin(n_tmp,tmp["max_av_soldier"]);
                        return n_tmp;

   	}
   return -1;
}
