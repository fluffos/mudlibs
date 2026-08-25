// att_input.c by fire
// tired tired tired
// modified by edc at 08/04/2001

string att_get_position(string p_area,string p_dir);
mixed * make_unique(mixed *inp) ;
mixed get_att_val(int task_id);
void put_att_troop(int task_id);

int can_have_new_att_troop(int task_id)
{
   	int ret=0;
   	mixed tmp;

   	tmp = TASK_D->get_task(task_id,"att_general_left");

   	if( !sizeof(tmp) ) return 0;

   	tmp = TASK_D->get_task(task_id,"att_troop_left");

	foreach( string tt in keys(tmp) )ret = ret + tmp[tt];
   	if( ret ) return 1;
   	else return 0;
}
string get_valid_att(int task_id)
{
   	int p_troop,n_tmp;
   	string p_stage, p_area;
   	mixed tmp;
// edc   08/01/2001
   	string ret;
   	int i;

   	mapping m_troopsName;
   	m_troopsName = TASK_D->get_task(task_id, "att_troop_left");
////
   	p_troop = TASK_D->get_task(task_id,"att_arrange_troop");
   	p_stage = TASK_D->get_task(task_id,"att_arrange_step");
        p_area  = TASK_D->get_task(task_id,"att_area");
	
   	switch(p_stage){
   		case "att_all_general":
        		tmp = TASK_D->get_task(task_id,"att_all_general");
        		if( !sizeof(tmp) ) return "";
        		else return implode(tmp,",");
   		case "general":
        		tmp = TASK_D->get_task(task_id,"att_general_left");
        		if( !sizeof(tmp) ) return "";
        		else return implode(tmp,",");
      		case "position":
        		return "城东：e 城西：w 城北：n 城南：s ";
// edc   08/04/2001
		case "troopIdx":
			ret="";
			i = 0;
			foreach( string ss in keys(m_troopsName) )
			{
				ret += ss;
				ret += ": ";
				ret += (string)i;
				ret += "  ";
				i++;
			}
			return ret;
////
      		case "newtroop":
        		return "Yes|No";
      		default: 
			tmp=TASK_D->get_task(task_id,"att_curent_arrange_troop");
			n_tmp=tmp["max_av_soldier"];
			tmp=TASK_D->get_task(task_id,"att_troop_left")[p_stage];
                        	return "0--"+bmin(tmp,n_tmp);
   	}
}
string get_att_val_str(int task_id)
{
   	string p_stage;
   	mixed ret;

   	ret = get_att_val(task_id);
   	p_stage = TASK_D->get_task(task_id,"att_arrange_step");
   	switch(p_stage){
       		case "position": return "e";
       		case "newtroop": return (( ret >0 ) ? "Yes" :"No");
// edc   08/01/2001
		case "troopIdx": return "0";
////       		
	   	default: return ret;
   	}
}
string att_prompt(int task_id)
{
   	string def_val, p_stage, p_valid;
   	string ret="";
	
   	def_val = get_att_val_str(task_id);
   	p_valid = get_valid_att(task_id);
   	p_stage = TASK_D->get_task(task_id,"att_arrange_step");

   	switch(p_stage){
   		case "att_all_general":
          		ret="准备出征，请输入同行的将军。\n";
          		ret+="有效值有：「"+p_valid+"」\n";
          		ret+="缺省值是：「"+def_val+"」\n";
          		return ret;
       		case "general":
          		ret="组成新军团。请输入该军团将军。\n";
          		ret+="有效值有：「"+p_valid+"」\n";
          		ret+="缺省值是：「"+def_val+"」\n";
          		return ret;
       		case "position":
          		ret+="请输入部队驻守位置。\n";
          		ret+="有效值有：「"+p_valid+"」\n";
          		ret+="缺省值是：「"+def_val+"」\n";
          		return ret;
       		case "newtroop":
          		ret+="是否成立新兵团？\n";
          		ret+="有效值有：「"+p_valid+"」\n";
          		ret+="缺省值是：「"+def_val+"」\n";
          		return ret;
// edc   08/01/2001
       		case "troopIdx":
          		ret+="请选择兵种。\n";
          		ret+="有效值有：「"+p_valid+"」\n";
          		ret+="缺省值是：「"+def_val+"」\n";
          		return ret;
////
		default:
			ret+="请输入"+WARAI_D->get_soldier_name(p_stage)+"人数。\n";
         		ret+="有效范围：「"+p_valid+"」\n";
          		ret+="缺省值是：「"+def_val+"」\n";
          		return ret;
    	}
}
mixed check_att_answer(int task_id,string str)
{
   	string p_stage;
   	mixed  tmp, tmp2;

   	p_stage = TASK_D->get_task(task_id,"att_arrange_step");
   	if( (!str) || (str=="") ) str = get_att_val_str(task_id);
   	switch(p_stage){
   		case "att_all_general":
		case "general":

          		tmp = TASK_D->get_task(task_id,"att_general_left");
			if(p_stage=="att_all_general")
				tmp=TASK_D->get_task(task_id,"att_all_general");
			if(!sizeof(tmp)) return 1; // no general left
          		tmp2 = explode(str,",");
          		if( !sizeof(tmp2) ) return "怎么会到这儿？\n";
			if(sizeof(tmp2)>3) return "最多分配三位将军。\n";
          		foreach (string t in tmp2){
             			if( member_array(t,tmp) ==-1 ) return "没有"+t+"这位将军？\n";
          		}
          		return 1;

       		case "position":
			if((str=="e")||(str=="w")||(str=="s")||(str=="n")) return 1;
          		return "从哪个方向进攻?\n";
       		case "newtroop": 
          		str = lower_case(str);
          		if((str=="yes")||(str=="y")||(str=="n")||(str=="no"))return 1;
          		else return "请输入Yes或No。\n";
// edc   08/01/2001
		case "troopIdx":
			return 1;
////
		default:
			tmp = TASK_D->get_task(task_id,"att_troop_left")[p_stage];
                        tmp2 = to_int(str);
                	if( tmp2 > tmp ) return "你没有那么多兵。\n";
                	if( tmp2 < 0 ) return "干吗？\n";
			tmp=TASK_D->get_task(task_id,"att_curent_arrange_troop");
			if(tmp2>tmp["max_av_soldier"])
				return "带不了那么多兵。\n";
                	return 1;
   	}
}
int input_arrange_att(int task_id,string str)
{
  	mixed tmp, att_curent_arrange_troop;
  	int att_arrange_troop;
  	string p_stage, p_area, *gens, att_leader;
  	int troop_idx; // added by edc

  	p_area = TASK_D->get_task(task_id,"def_area");
  	att_curent_arrange_troop = TASK_D->get_task(task_id,
    		"att_curent_arrange_troop");
  	att_arrange_troop = TASK_D->get_task(task_id,"att_arrange_troop");
  	p_stage = TASK_D->get_task(task_id,"att_arrange_step");

  	switch(p_stage){
  		case "att_all_general":
			gens = explode(str,",");
                        gens=make_unique(gens);
			att_leader=TASK_D->get_task(task_id,"att_leader");
			TASK_D->set_task(task_id,"att_general_left", 
				TASK_D->get_task(task_id,"att_all_general") - ({gens}));
			gens = ({att_leader}) + gens;
			att_curent_arrange_troop["general"] = gens;

			// this is used to set the maximum number of soidliers in this troop
			att_curent_arrange_troop["max_av_soldier"]=
				WARAI_D->get_max_soldier(gens);

			// soldier type index begin from 0;
			att_curent_arrange_troop["sd_idx"]=0;

			TASK_D->set_task(task_id,"att_curent_arrange_troop", 
				att_curent_arrange_troop);
        		TASK_D->set_task(task_id,"att_party",gens);
			foreach(string a in gens) TASK_D->add_char(task_id,a,3);// 3 is meaningless
// edc   08/01/2001
			TASK_D->set_task(task_id,"att_arrange_step","troopIdx");
/*  edc
			tmp = TASK_D->get_task(task_id, "att_troop_left");
			TASK_D->set_task(task_id,"att_arrange_step",keys(tmp)[0]);
*/  
////
	 		return 1;
   		case "general":
			gens=explode(str,",");
                        gens=make_unique(gens);
          		att_curent_arrange_troop["general"]=gens;

			tmp=TASK_D->get_task(task_id,"att_party");
			tmp-=gens;
			tmp+=gens;
			TASK_D->set_task(task_id,"att_party",tmp);

			foreach(string a in gens) TASK_D->add_char(task_id,a,3);// 3 is meaningless

			// this is used to set the maximum number of soidliers in this troop
			att_curent_arrange_troop["max_av_soldier"]=
				WARAI_D->get_max_soldier(gens);

			// soldier type index begin from 0;
			att_curent_arrange_troop["sd_idx"]=0;

                	TASK_D->set_task(task_id,"att_curent_arrange_troop",
            			att_curent_arrange_troop);

// edc   08/01/2001
			TASK_D->set_task(task_id,"att_arrange_step","troopIdx");


/*  edc
			tmp = TASK_D->get_task(task_id, "att_troop_left");
        		TASK_D->set_task(task_id,"att_arrange_step", keys(tmp)[0]);
*/
////
			return 1;
       		case "position":
          		att_curent_arrange_troop[p_stage] = str;
          		TASK_D->set_task(task_id,"att_curent_arrange_troop",
            			att_curent_arrange_troop);
          		TASK_D->set_task(task_id,"att_arrange_step","newtroop");
          		put_att_troop(task_id);
          		return can_have_new_att_troop(task_id);
       		case "newtroop":
         		str=lower_case(str);
         		if( (str=="n") || (str=="no") ) return 0;
			tmp = TASK_D->get_task(task_id,"att_general_left");
			if( !sizeof(tmp) ) return 0;

         		att_arrange_troop++;
         		TASK_D->set_task(task_id,"att_arrange_troop",
              			att_arrange_troop);
         		att_curent_arrange_troop = ([]);
         		TASK_D->set_task(task_id,"att_curent_arrange_troop",
            			att_curent_arrange_troop);
         		TASK_D->set_task(task_id,"att_arrange_step","general");
         		return 1;
// edc   08/01/2001
		case "troopIdx":
			troop_idx = to_int(str);

			// need some range protection for str
			if ( troop_idx >= sizeof(TASK_D->get_task(task_id, "att_troop_left")) )
				troop_idx = 0;
			att_curent_arrange_troop["sd_idx"]=troop_idx;

                	TASK_D->set_task(task_id,"att_curent_arrange_troop",
            			att_curent_arrange_troop);
			tmp = TASK_D->get_task(task_id, "att_troop_left");
        		TASK_D->set_task(task_id,"att_arrange_step", keys(tmp)[troop_idx]);
			
			return 1;
////
		default:

			tmp = att_curent_arrange_troop["troop"];
/* edc
			att_curent_arrange_troop["sd_idx"]++;
*/ ////
                        if( !mapp(tmp) )tmp = ([ ]);
			if(to_int(str)>0) {
	                        tmp[p_stage] = to_int(str);
				att_curent_arrange_troop["max_av_soldier"]-=
				tmp[p_stage];
			}
                        att_curent_arrange_troop["troop"] = tmp;
                        TASK_D->set_task(task_id,"att_curent_arrange_troop",
                                att_curent_arrange_troop);
/* edc
                        tmp = TASK_D->get_task(task_id, "att_troop_left");

			if(att_curent_arrange_troop["sd_idx"]>=sizeof(tmp)) {
				TASK_D->set_task(task_id,"att_arrange_step","position");
				return 1;
			}
			if(att_curent_arrange_troop["max_av_soldier"]<=0) {
				TASK_D->set_task(task_id,"att_arrange_step","position");
				return 1;
			}

			if(sizeof(att_curent_arrange_troop["troop"])>=4) {
				TASK_D->set_task(task_id,"att_arrange_step","position");
				return 1;
			}

*/ ////
// edc
			TASK_D->set_task(task_id,"att_arrange_step","position");

/* edc
			TASK_D->set_task(task_id,"att_arrange_step",keys(tmp)[att_curent_arrange_troop["sd_idx"]]);
*/ ////
////
                        return 1;


      	}
}
