/* NpcAi_d.c by Suicide on 24/07/2000
** This is used to handle the NPC country to select player taishou
*/
#include <security.h>
#define SAVE_FILE "/data/daemons/npcai_d"
#define INC_ARMY  1000

inherit M_ACCESS;
private string * cities ;
private int last_ai_city_id ;

void save_data()
{  
   	unguarded(1, (: save_object, SAVE_FILE :));
}

void think_about_war(string p_area)  //2001.4.13
{}

void think_about_event(string p_area) //2001.4.13
{string m_id;
 string p_nation = AREA_D->get_area(p_area,"nation");
 int lvl = AREA_D->get_area(p_area,"level");
 if (CHAR_D->get_char(p_nation,"type")==TYPE_PLAYER)
    return ;

 if (AREA_D->get_area_soldier(p_area,"footman")>=lvl*lvl*2000) return;

 if (CHAR_D->get_char(p_nation,"area")==p_area)  //如果为NPC国首都,则仍然增加兵力
    {
     AREA_D->add_soldier(p_area,"footman",INC_ARMY,180,180); //每轮训一次增加兵力1000人
     return;
    }

 m_id = AREA_D->get_area_leader(p_area);
 if (!m_id) 
    {AREA_D->auto_head(p_area);
     AREA_D->add_soldier(p_area,"footman",INC_ARMY,180,180); //每轮训一次增加兵力1000人
     return;
    }
 if ((CHAR_D->get_char(m_id,"type")==TYPE_NPC)&&  //NPC太守,且不是玩家暂让的时候
     (!CHAR_D->get_char(m_id,"grant")))
     AREA_D->add_soldier(p_area,"footman",INC_ARMY,180,180); //每轮训一次增加兵力1000人
 return;
}

int can_be_taishou(string p_area,string p_id)
{int a_lvl;
 a_lvl = AREA_D->get_area(p_area,"level");
 if(CHAR_D->get_char(p_id,"nationcontribution")<500*a_lvl) 
    return 0; // at least 500 * city level
 return 1;
}


void create_taishou(string p_area) {
	string *ids,p_id,old_leader;
	string msg,n;
	int title;
	n = AREA_D->get_area(p_area,"nation");
	ids=CHAR_D->check_char("area",p_area);
	if(!sizeof(ids)) return;
	ids=filter_array(ids,(:CHAR_D->get_char($1,"type")==TYPE_PLAYER:));
	if(!sizeof(ids)) return;
	ids=sort_array(ids,(: CHAR_D->get_char($1,"nationcontribution")
		> CHAR_D->get_char($2,"nationcontribution") ? 1 : -1 :));
	if(!sizeof(ids)) return;
		p_id=ids[sizeof(ids)-1];
	if((sizeof(ids)>1)&&(random(3)==0))
		p_id=ids[sizeof(ids)-2];
	if((sizeof(ids)>2)&&(random(6)==0))
		p_id=ids[sizeof(ids)-3];
        
        if (!can_be_taishou(p_area,p_id)) return;
	title=OFFICER_D->query_area_officer_title(AREA_D->get_area(p_area,"level"),0,0)[0];
        old_leader=AREA_D->get_area_leader(p_area);
        if(stringp(old_leader)) 
        {
	 CHAR_D->set_char(old_leader,"ranklocal",R_SG);
	 CHAR_D->set_char(old_leader,"grant",0);
	}
	CHAR_D->set_char(p_id,"ranklocal",title);
	CHAR_D->set_char(p_id,"tsx",200);   //太守信誉度,初始200
	CHAR_D->set_char(p_id,"grant",0);	   
    CHAR_D->set_char(p_id,"npcarmy",AREA_D->get_area_soldier(p_area,"footman"));//2001.4.19

	msg=sprintf("%s由于功绩卓著被%s任命为%s的太守。",
		CHAR_D->get_char(p_id,"name"),
		CHAR_D->get_char(n,"name"),
		AREA_D->get_area(p_area,"name"));
	CHANNEL_D->deliver_tell("rumor","system",msg);
	HIS(msg);
	CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(n,"name"),
		CHAR_D->get_char(p_id,"name")+"，好好干，"+
		AREA_D->get_area(p_area,"name")+"的兴旺就寄托在你身上了。");

	CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(p_id,"name"),
		"臣肝胆涂地难报主公大恩。");
	
	return ;
}

void remove_taishou(string p_area,string p_id) {
	string msg,n,g_id;
	int tmp;
	mixed grant;
	grant = CHAR_D->get_char(p_id,"grant");
	if (grant) 
	   {g_id = p_id;
	    p_id = grant["leader"];     
	   }
	if ((tmp=CHAR_D->get_char(p_id,"tsx"))>0)
	   {
	    tmp -= 20;     //一天被轮巡一次,tsx减去20,如果在tsx不增加的情况下
	    CHAR_D->set_char(p_id,"tsx",tmp);//十天后太守就会被撤职  
	    return;
	   }        
	 
	n = AREA_D->get_area(p_area,"nation");
	tmp = CHAR_D->get_char(p_id,"nationcontribution");
	tmp = tmp * 4 / 5;
	CHAR_D->set_char(p_id,"nationcontribution",tmp);
	tmp = CHAR_D->get_char(p_id,"reputation");
	tmp = tmp * 4 / 5;
	CHAR_D->set_char(p_id,"reputation",tmp);
	CHAR_D->set_char(p_id,"ranklocal",R_SG);
	CHAR_D->set_char(p_id,"grant",0);
	if (CHAR_D->char_exist(g_id)) 
	   {CHAR_D->set_char(g_id,"ranklocal",R_SG);
	    CHAR_D->set_char(g_id,"grant",0);
	   }
	msg=sprintf("%s由于荒废政事被%s撤销%s太守职位。",
		CHAR_D->get_char(p_id,"name"),
		CHAR_D->get_char(n,"name"),
		AREA_D->get_area(p_area,"name"));
	CHANNEL_D->deliver_tell("rumor","system",msg);
	HIS(msg);
	CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(n,"name"),
		CHAR_D->get_char(p_id,"name")+"，你真让我失望。");
	AREA_D->auto_head(p_area);  //玩家被撤职后,由系统自动挑选NPC为太守
	//create_taishou(p_area);
	return ;

}

void check_guoshi_vote(string nation)
{mapping vote;
 int vote_id,need_ballot=5,areas_amount;
 string p_id,msg,gs;
 mixed * vote_info;
 if (!VOTE_D->get_special_vote(nation,"elect"))  //国家没有国师选举
      return;
 vote_id = VOTE_D->get_special_vote(nation,"elect")[0];
 vote = VOTE_D->get_vote_result(vote_id);
 areas_amount = sizeof(AREA_D->check_area("nation",nation));
 need_ballot = areas_amount * 2 / 3 ; //2/3太守同意
 if (areas_amount<4) need_ballot++;   //小于4座城市的NPC国家,所有太守同意才可以
 if (sizeof(vote[1])>=need_ballot)
    { 
      p_id = VOTE_D->get_special_vote(nation,"elect")[3];
      COUNTRY_D->set_country(nation,"gs",p_id);
      COUNTRY_D->set_country(nation,"gsx",200); // not too much
      msg=sprintf("由于得到大多数太守的支持，%s被%s任命为%s的国师。",
		CHAR_D->get_char(p_id,"name"),
		CHAR_D->get_char(nation,"name"),
		COUNTRY_D->get_country(nation,"name"));
      CHANNEL_D->deliver_tell("rumor","system",msg);
      HIS(msg);
      CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(nation,"name"),
           CHAR_D->get_char(p_id,"name")+"，好好干，本国的兴旺就寄托在你身上了。");

      CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(p_id,"name"),
		"臣肝胆涂地难报主公大恩。");
      VOTE_D->del_special_vote(nation,"elect");
      CHAR_D->set_char(p_id,"candidate",0);
    }
 else
    { vote_info = VOTE_D->get_special_vote(nation,"elect");
      vote_info[2] = vote_info[2] - 1;
      need_ballot = areas_amount - need_ballot + 1; //反对票所需票数
      if ((vote_info[2]>0)&&(sizeof(vote[2])<need_ballot))
          VOTE_D->modify_special_vote(nation,"elect",vote_info);
      else
      {
      p_id = VOTE_D->get_special_vote(nation,"elect")[3];
      msg=sprintf("由于%s的支持度不够，%s取消了欲任命其为%s国师的想法。",
		CHAR_D->get_char(p_id,"name"),
		CHAR_D->get_char(nation,"name"),
		COUNTRY_D->get_country(nation,"name"));
      CHANNEL_D->deliver_tell("rumor","system",msg);
      HIS(msg);
      CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(nation,"name"),
           CHAR_D->get_char(p_id,"name")+"爱卿，由于各地太守反对者众，任命你为国师的事只好暂缓。");

      CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(p_id,"name"),
		"臣知道，臣他日定当和各路太守磋商，得到支持后再请陛下定夺。");
      //处罚未成功的的国师申请人，有关值降1/10	
      CHAR_D->set_char(p_id,"reputation",CHAR_D->get_char(p_id,"reputation")*9/10);		
      CHAR_D->set_char(p_id,"localcontribution",CHAR_D->get_char(p_id,"localcontribution")*9/10);
      CHAR_D->set_char(p_id,"nationcontribution",CHAR_D->get_char(p_id,"nationcontribution")*9/10); 		

      VOTE_D->del_special_vote(nation,"elect"); 
      CHAR_D->set_char(p_id,"candidate",0);    
      }
      
    }
  return ;
}

void check_guoshi_dismiss_vote(string nation)
{mapping vote;
 int vote_id,need_ballot=5,areas_amount;
 string p_id,msg,gs,v_id;
 mixed * vote_info;
 if (!VOTE_D->get_special_vote(nation,"dismiss"))  //国家没有国师选举
      return;
 vote_id = VOTE_D->get_special_vote(nation,"dismiss")[0];
 vote = VOTE_D->get_vote_result(vote_id);
 areas_amount = sizeof(AREA_D->check_area("nation",nation));
 need_ballot = areas_amount * 2 / 3 ; //2/3太守同意 
 if (sizeof(vote[1])>=need_ballot)
    { 
      v_id = VOTE_D->get_special_vote(nation,"dismiss")[3]; //发动不信任选举的玩家id
      p_id = COUNTRY_D->get_country(nation,"gs");
      COUNTRY_D->set_country(nation,"gs",0);
      msg=sprintf("在大多数太守的反对声中，%s被赶下了%s的国师的位子。",
		CHAR_D->get_char(p_id,"name"),
		COUNTRY_D->get_country(nation,"name"));
      CHANNEL_D->deliver_tell("rumor","system",msg);
      HIS(msg);
      CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(nation,"name"),
           CHAR_D->get_char(p_id,"name")+"你结党营私、祸国殃民，真是太令我失望了！");

      CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(p_id,"name"),
		"臣罪该万死，罪该万死。");
      //处罚被赶下台的国师，有关值降一半		
      CHAR_D->set_char(p_id,"reputation",CHAR_D->get_char(p_id,"reputation")/2);		
      CHAR_D->set_char(p_id,"loyalty",45);
      CHAR_D->set_char(p_id,"localcontribution",CHAR_D->get_char(p_id,"localcontribution")/2);
      CHAR_D->set_char(p_id,"nationcontribution",CHAR_D->get_char(p_id,"nationcontribution")/2); 		
      //奖励不信任投票的发起人，有关值长1/10
      CHAR_D->set_char(v_id,"reputation",CHAR_D->get_char(v_id,"reputation")*11/10);		
      CHAR_D->set_char(v_id,"loyalty",CHAR_D->get_char(v_id,"loyalty")*11/10);		
      CHAR_D->set_char(v_id,"localcontribution",CHAR_D->get_char(v_id,"localcontribution")*11/10);
      CHAR_D->set_char(v_id,"nationcontribution",CHAR_D->get_char(v_id,"nationcontribution")*11/10); 		



      VOTE_D->del_special_vote(nation,"dismiss");
    }
 else
    { vote_info = VOTE_D->get_special_vote(nation,"dismiss");
      vote_info[2] = vote_info[2] - 1;
      if (vote_info[2]>0)
          VOTE_D->modify_special_vote(nation,"dismiss",vote_info);
      else
      {
      p_id = COUNTRY_D->get_country(nation,"gs");
      v_id = VOTE_D->get_special_vote(nation,"dismiss")[3];
      msg=sprintf("由于不信任投票未获得足够票数，%s保住了%s国师的官职。",
		CHAR_D->get_char(p_id,"name"),
		COUNTRY_D->get_country(nation,"name"));
      CHANNEL_D->deliver_tell("rumor","system",msg);
      HIS(msg);
      CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(nation,"name"),
           CHAR_D->get_char(p_id,"name")+"爱卿，寡人错怪你了，望你在国师之位更好的为寡人分忧。");

      CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(p_id,"name"),
		"臣多谢主公信任，必当鞠躬尽瘁报效主公。");
      VOTE_D->del_special_vote(nation,"dismiss"); 
      
       //处罚不信任投票的发起人，有关值降1/10  
      CHAR_D->set_char(v_id,"reputation",CHAR_D->get_char(v_id,"reputation")*9/10);		
      CHAR_D->set_char(v_id,"localcontribution",CHAR_D->get_char(v_id,"localcontribution")*9/10);
      CHAR_D->set_char(v_id,"nationcontribution",CHAR_D->get_char(v_id,"nationcontribution")*9/10); 		
  
      }
      
    }
  return ;
}




mixed test_is_capital(string p_area)
{string p_gs,na;
 na = AREA_D->get_area(p_area,"nation");
 if (CHAR_D->get_char(na,"area")!=p_area)
   return  "不是国家首都，NPC国家思考结束!";
 if (CHAR_D->get_char(na,"type")==TYPE_PLAYER)
   return "国家主公为玩家,NPC地区AI思考结束!";
 p_gs=COUNTRY_D->get_country(na,"gs");
 if (!p_gs)
     check_guoshi_vote(na);//没有国师的话，则检查国师投票
 else
     check_guoshi_dismiss_vote(na); //有国师的话，则检查国师罢免投票
 return 1; 
}



mixed test_npc_taishou(string p_area){
	string m_id,p_gs;
	int status =0;
	
	if (CHAR_D->get_char(AREA_D->get_area(p_area,"nation"),"type")==TYPE_PLAYER)
	   return "国家主公为玩家,NPC地区AI思考结束!";
	   
	
	m_id = AREA_D->get_area_leader(p_area);
	if (!m_id) {AREA_D->auto_head(p_area);return;}
	if ((CHAR_D->get_char(m_id,"type")==TYPE_NPC)&&
	   (CHAR_D->get_char(m_id,"grant")))
	   status = 1 ;  //玩家暂让太守  
	if (CHAR_D->get_char(m_id,"type")==TYPE_PLAYER)
	   status = 2 ;  //玩家为太守   	   
                 
        if (status == 0)
           {
            p_gs=COUNTRY_D->get_country(AREA_D->get_area(p_area,"nation"),"gs");
	    if((CHAR_D->char_exist(p_gs))&&
	       (CHAR_D->get_char(p_gs,"nation")==AREA_D->get_area(p_area,"nation"))&&
	       (CHAR_D->get_char(m_id,"fealty")==p_gs))
	         return  "地区NPC太守已经效忠国师，不在挑选玩家太守";
            create_taishou(p_area);
            return "地区没有玩家太守,系统自动挑选玩家太守!";
            }
        else
           {remove_taishou(p_area,m_id);
            return "地区已有玩家太守,系统考察玩家太守勤奋度!";
           }
     
}

mixed test_is_fit_officer(string p_area)
{string *list_char;
 int tmp,i,rank,rank_type=0,a_type=0;
 string n,p_id,msg,ts_id,p_gs;
 mixed result;
 
 list_char=CHAR_D->check_char("area",p_area);
 n = AREA_D->get_area(p_area,"nation");
 ts_id = AREA_D->get_area_leader(p_area);
 p_gs=COUNTRY_D->get_country(n,"gs");
 
 //if (CHAR_D->get_char(n,"type")==TYPE_PLAYER)
  //	   return "国家主公为玩家,NPC地区AI思考结束!";
 //if (CHAR_D->char_exist(p_gs)&&
 //   (CHAR_D->get_char(p_gs,"nation")==n))
//	   return  "国家有国师存在,NPC地区AI思考结束!";
 if ((CHAR_D->get_char(ts_id,"type")==TYPE_PLAYER)||
     ((CHAR_D->get_char(ts_id,"type")==TYPE_NPC)&&
       CHAR_D->get_char(ts_id,"grant")))
 	   a_type = 1;  //是NPC国王的玩家太守区域,只考察国家官员勤奋度,不考察地方官员
 
           
 
 for (i=0;i<sizeof(list_char);i++)
     {p_id = list_char[i];
      rank_type = 0;
      if (CHAR_D->get_char(p_id,"type")==TYPE_NPC)
          continue; //不检查NPC官员
      if (ts_id==p_id)
          continue; //不检查太守
      if (CHAR_D->get_char(p_id,"nation")==p_id)
          continue; //不检查主公
      if (CHAR_D->get_char_level(p_id)<2)
          continue; 
          
      if (!(rank=CHAR_D->get_char(p_id,"ranknation")))//如果玩家既是国家官员又是
         if (a_type)  continue;      //a_type =1 时,如玩家不是国家官员就不考察
         else
          {rank = CHAR_D->get_char(p_id,"ranklocal");  //地方官员,先考虑国家官员职位
           rank_type = 1;}
           
      result = ("/sgdomain/event/ev_position")->check_whole(p_id,rank);
      if (stringp(result))
         {
         if (rank_type)
            {CHAR_D->set_char(p_id,"ranklocal",R_SG);
             CHAR_D->set_char(p_id,"grant",0);
             msg=sprintf("%s由于%s降低被%s撤销%s%s职位。",
		CHAR_D->get_char(p_id,"name"),result,
		CHAR_D->get_char(ts_id,"name"),
		AREA_D->get_area(p_area,"name"),OFFICER_D->query_rank_name(rank));
            }
         else
            {CHAR_D->set_char(p_id,"ranknation",0);
             msg=sprintf("%s由于%s降低被%s撤销%s%s职位。",
		CHAR_D->get_char(p_id,"name"),result,
		CHAR_D->get_char(n,"name"),
		COUNTRY_D->get_country(n,"name"),
		OFFICER_D->query_rank_name(rank));
            }
         CHANNEL_D->deliver_tell("rumor","system",msg);
         HIS(msg);    
         continue;    
         }
      if ((tmp=CHAR_D->get_char(p_id,"tsx"))>0)
	 {
	  tmp -= 15;     //官员每次轮巡降的勤奋度小于太守,先设定为15
	  CHAR_D->set_char(p_id,"tsx",tmp);
	  continue;
	 }
     
      tmp = CHAR_D->get_char(p_id,"nationcontribution");
      tmp = tmp * 4 / 5;
      CHAR_D->set_char(p_id,"nationcontribution",tmp);
      tmp = CHAR_D->get_char(p_id,"reputation");
      tmp = tmp * 4 / 5;
      CHAR_D->set_char(p_id,"reputation",tmp);
      if (rank_type)
        {CHAR_D->set_char(p_id,"ranklocal",R_SG);
         CHAR_D->set_char(p_id,"grant",0);
         msg=sprintf("%s由于荒废政事被%s撤销%s%s官员职位。",
		CHAR_D->get_char(p_id,"name"),
		CHAR_D->get_char(ts_id,"name"),
		AREA_D->get_area(p_area,"name"),
		OFFICER_D->query_rank_name(rank));
	}
      else
        {CHAR_D->set_char(p_id,"ranknation",0);
         msg=sprintf("%s由于荒废政事被%s撤销%s%s职位。",
		CHAR_D->get_char(p_id,"name"),
		CHAR_D->get_char(n,"name"),
		COUNTRY_D->get_country(n,"name"),
		OFFICER_D->query_rank_name(rank));
        }
      CHANNEL_D->deliver_tell("rumor","system",msg);
      HIS(msg);        
      CHAR_D->set_char(p_id,"tsx",100); //被解职的官员的勤奋度恢复到初始的一半   
     	                                //避免被解职后又任职,因为勤奋度为负值
     	                                //而被再次解职遭受更大损失.
     }

}

void act()    //called By ai_d.c
{       mixed result;
	SGSYS("现在轮巡的城市是"+cities[last_ai_city_id]);
	result=test_npc_taishou(cities[last_ai_city_id]);
	if (stringp(result)) SGSYS(result);
	result=test_is_fit_officer(cities[last_ai_city_id]);
	if (stringp(result)) SGSYS(result);
	test_is_capital(cities[last_ai_city_id]);
        if (stringp(result)) SGSYS(result);
	think_about_war(cities[last_ai_city_id]);    //need to finish
	think_about_event(cities[last_ai_city_id]);  //need to finish
	last_ai_city_id++;
	if (last_ai_city_id == sizeof(cities))
	   last_ai_city_id =0;
	save_data();
	//call_out("act",240);  //MUD每天即现实16分钟,轮巡一次
	                      //所有地区执行一遍需16*99等于1584分钟
	                      //现实一天等于24*60=1440分钟,约等于一天
	                      //所有城市轮巡一次
}

void create()
{       
   	unguarded(1, (: restore_object, SAVE_FILE, 1 :));
   	if (!last_ai_city_id) last_ai_city_id=0;
   	if (!sizeof(cities)||!arrayp(cities))
   	   {cities = AREA_D->list_areas();
   	    save_data();}
	//call_out("act",240);
	return;
}

//stop the repeated func call(start_fate) 
void remove()
{
   remove_call_out("act");
}

int clean_up() {
   return 0; // means never_again
}

