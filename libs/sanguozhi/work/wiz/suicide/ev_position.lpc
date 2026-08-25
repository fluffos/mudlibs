// ev_position.c
// by fire on July 24, 1998
// modified by qiwei on July 19,2000
// this is used to handle give a char a local position
#include <mudlib.h>

int m_pos;
string mp_id;

int check_real_local_leader(string p_id,string p_area) {
    string t_id;
    mixed p_grant;
    t_id=AREA_D->get_area(p_area,"leader");
    p_grant=CHAR_D->get_char(t_id,"grant");
    if(!p_grant) return 0;
    if((p_grant["leader"]==p_id)&&
        (p_grant["area"]==p_area)&&
        (p_grant["nation"]==CHAR_D->get_char(p_id,"nation"))) {
        if(CHAR_D->get_char(p_id,"area")==p_area)
	        return 1;
        CHAR_D->set_char(t_id,"grant",0); // real leader want back
	return 0;
    }
}
int* get_nation_vacancy(string p_nat) {
	int* list_title;
	string* list_char;
	int* ret=({});
	int i,v_left;
	string* a_tmp;
	list_title=OFFICER_D->query_nation_officer_title_all(COUNTRY_D->get_country(p_nat,"level"));
	list_char=CHAR_D->check_char("nation",p_nat);
	for(i=0;i<sizeof(list_title);++i)
	{
		a_tmp=filter_array(list_char,
			(:CHAR_D->get_char($1,"ranknation")==$(list_title[i]):));
		v_left=OFFICER_D->query_max_officer_number(list_title[i]);
		v_left-=sizeof(a_tmp);
		if(v_left>0)
			ret+=({list_title[i]});
	}
	return ret;
}
int* get_area_vacancy(string p_area)
{
	int* list_title;
	string* list_char;
	int* ret=({});
	int i,v_left;
	string* a_tmp;
	list_title=OFFICER_D->query_area_officer_title_all(AREA_D->get_area(p_area,"level"));
	list_char=CHAR_D->check_char("area",p_area);
	for(i=0;i<sizeof(list_title);++i)
	{
		a_tmp=filter_array(list_char,
			(:CHAR_D->get_char($1,"ranklocal")==$(list_title[i]):));
		v_left=OFFICER_D->query_max_officer_number(list_title[i]);
		v_left-=sizeof(a_tmp);
		if(v_left>0)
			ret+=({list_title[i]});
	}
	return ret;
}

//check_area_vacancy   Added by suicide 2000.7
//To check the officer id that the ppl chose is vacancy in this area or not
int check_area_vacancy(string p_area,int o_id)
{int* list_title;
 string* list_char;
 int v_left;
 string* a_tmp;
 if (o_id==1000) return 0;  //闲职数目不限制
 list_title=OFFICER_D->query_area_officer_title_all(AREA_D->get_area(p_area,"level"));
 list_char=CHAR_D->check_char("area",p_area);
 //printf("list = %O o_id= %d\n",list_title,o_id);
 if (member_array(o_id,list_title)==-1)
    return -1;
 a_tmp=filter_array(list_char,(:CHAR_D->get_char($1,"ranklocal")==$(o_id):));
 v_left=OFFICER_D->query_max_officer_number(o_id);
 v_left-=sizeof(a_tmp);
 if(v_left>0)
   return 0;
 else
   return -2;
}
//Added End
mixed check_whole(string p_id,int p_title) {
	mapping req=OFFICER_D->query_requirement(p_title);
	if(CHAR_D->get_char(p_id,"reputation")<req["reputation"]) return "声望";
	if(CHAR_D->get_char(p_id,"loyalty")<req["loyalty"]) return "忠诚";
	if(CHAR_D->get_skill(p_id,"sk_wuli")<req["sk_wuli"]) return "武学修养";
	if(CHAR_D->get_skill(p_id,"sk_zhimou")<req["sk_zhimou"]) return "兵法修养";
	if(CHAR_D->get_skill(p_id,"sk_meili")<req["sk_meili"]) return "治国修养";

	if(CHAR_D->get_char(p_id,"type")==TYPE_NPC) return 1;
	if(CHAR_D->get_char(p_id,"literate")<req["literate"]) return "文学";
	if(CHAR_D->get_char(p_id,"localcontribution")<req["localcontribution"]) return "地区贡献";
	if(CHAR_D->get_char(p_id,"nationcontribution")<req["nationcontribution"]) return "国家贡献";
	return 1;
}


void give_position_n(string p_id,int p_title,string p_nation)
{
	if((!p_nation)||(p_nation==0)) return ;
	if(CHAR_D->get_char(p_id,"nation")!=p_nation) return ;

	CHAR_D->set_char(p_id,"ranknation",p_title);
	//CHAR_D->set_char(p_id,"sedulityn",100); //Added Suicide 初始勤奋值=100
      CHANNEL_D->deliver_tell("rumor","system",
         sprintf("%s被封为%s%s。",CHAR_D->get_char(p_id,"name"),
               COUNTRY_D->get_country(p_nation,"name"),
		OFFICER_D->query_rank_name(p_title)));      
}

void give_position(string p_id,int p_title,string p_area)
{
	string p_nation;
	string oldnation;
	p_nation=AREA_D->get_area(p_area,"nation");
	oldnation=CHAR_D->get_char(p_id,"nation");
	CHAR_D->set_char(p_id,"ranklocal",p_title);
	CHAR_D->set_char(p_id,"nation",p_nation);
	CHAR_D->set_char(p_id,"area",p_area);
	//CHAR_D->set_char(p_id,"sedulityl",100); //Added Suicide 初始勤奋值=100
      CHANNEL_D->deliver_tell("rumor","system",
         sprintf("%s被封为%s%s。",CHAR_D->get_char(p_id,"name"),
            AREA_D->get_area(p_area,"name"),
		OFFICER_D->query_rank_name(p_title)));      
	if(oldnation!=p_nation) {
		CHAR_D->set_char(p_id,"nationcontribution",0);
		CHAR_D->set_char(p_id,"ps",0);
	}
}
void npc_localposition()
{
	string *list;
	string *ret;
	string p_id;
	string p_area;
	int* vacancy;
	int i;
	list=CHAR_D->check_char("type",TYPE_NPC);
	ret=filter_array(list, (:
		(CHAR_D->get_char($1,"ranklocal"))==0 :));
	if(!sizeof(ret))
		return;
       ret=filter_array(ret,(: (CHAR_D->get_char($1,"is_tmp"))==0:));
      if(!sizeof(ret)) return;
	i=random(sizeof(ret));
	p_id=ret[i];
	p_area=CHAR_D->get_char(p_id,"area");
	vacancy=get_area_vacancy(p_area);
	if(!sizeof(vacancy))
		return;
	vacancy=sort_array(vacancy,
		(: OFFICER_D->query_level($1)>=OFFICER_D->query_level($2) ? -1 : 1 :) );
	for(i=0;i<sizeof(vacancy);++i)
	{
	if(check_whole(p_id,vacancy[i])==1)
		{
			give_position(p_id,vacancy[i],p_area);
			return;
		}
	}
}

void npc_aut_localposition(string p_id)
{
	string p_area;
	int* vacancy;
	int i,p_pos,p_level;
	if(CHAR_D->get_char(p_id,"is_tmp")) return;
	if(CHAR_D->get_char(p_id,"type")==TYPE_PLAYER) return;

	if(CHAR_D->get_char(p_id,"task")) return;

	p_area=CHAR_D->get_char(p_id,"area");
	
	if(AREA_D->get_area(p_area,"leader")==p_id) return;
	vacancy=get_area_vacancy(p_area);
	if(!sizeof(vacancy))
		return;

	vacancy=sort_array(vacancy,
		(: OFFICER_D->query_level($1)>=OFFICER_D->query_level($2) ? -1 : 1 :) );

	p_pos=CHAR_D->get_char(p_id,"ranklocal");
	p_level=OFFICER_D->query_level(p_pos);
	for(i=0;i<sizeof(vacancy);++i)
	{
		if(OFFICER_D->query_level(vacancy[i])<=p_level) return; // no need to adjust
		if(check_whole(p_id,vacancy[i])==1)
		{
			give_position(p_id,vacancy[i],p_area);
			return;
		}
	}
}

mixed check_first_step(object who,string a_id)
{
    string y_id;
    string m_aid;
    y_id=(who->query_id())[0];
 

    if(!(CHAR_D->char_exist(y_id)))
        return "$N对$T道：$R还没有定居呀？\n";

    m_aid=CHAR_D->get_char(y_id,"area");

    if(AREA_D->get_area(m_aid,"nation")!=AREA_D->get_area(a_id,"nation"))
	return "$N看了$T一眼，道：$R莫非是想在此卧底不成？\n";

    if(AREA_D->get_area(m_aid,"leader")==y_id)
	return "$N对$T摇头道：$m$R怎能轻弃属地？！\n";

    if(m_aid!=a_id) {
	if(CHAR_D->get_char(y_id,"nation")!=AREA_D->get_area(a_id,"nation"))
	        return "$N对$T道：要在此位官，需要先在此地定居。\n";
	if(!CHAR_D->get_char(y_id,"ranknation")) 
	        return "$N对$T道：只有国家官员才可以自由异地求官。\n";
    }
    else {
	if(CHAR_D->get_char(y_id,"ranklocal")) 
	   if (!wizardp(who)) //在未开放前只有巫师可以测试
	        return "$N对$T道：$R已经是本地官员了。\n"; 
	   else
	        return 2;  //Suicide 2000.7  For:闲职官员升职地方官员.
    }
    return 1;
}


void myconfirm(object who,object officer,string ans)
{
	string y_id,m_id;
	m_id=(officer->query_id())[0];
	y_id=(who->query_id())[0];
	if ((ans=="yes")&&(mp_id==y_id))
	{
              officer->targetted_action
                  ("$N对$T笑道：$R正合此职，可喜，可贺呀。\n",who);
       	        give_position(y_id,m_pos,CHAR_D->get_char(m_id,"area"));
	}
	else
	{
              officer->targetted_action
                  ("$N沉吟半晌，对$T道：此事还须再商议商议。\n",who);
	}
        who->clear_answer();
}
void myposition(object officer,object who,int ans)
{
	string y_id;
	string m_id;
	string p_area;

	int p_ans;
	mixed p_res;
    	m_id=officer->query_primary_id();
    	y_id=who->query_primary_id();
    	p_area = CHAR_D->get_char(m_id,"area");
	p_ans=to_int(ans);
	//Added by suicide in 2000.7
	//To check the officer id that ppl input is valid or not
	p_res=check_area_vacancy(p_area,p_ans);
	if (p_res==-1) {
	   officer->targetted_action
	   ("$N对$T笑道：$R你故意为难本官吧，这儿没有这个官职"+
	    "叫我如何是好啊？\n",who);
	   return;}
	if (p_res==-2) {
	   officer->targetted_action
	   ("$N对$T笑道：$R你故意为难本官吧，这个官职已经没有空缺了，"+
	    "叫我如何是好啊？\n",who);
	   return;}
        //Added End
	p_res=check_whole(y_id,p_ans);

	if(p_res==1) {
	    	if(CHAR_D->get_char(m_id,"status")==STATUS_ONLINE)
		{
			tell_user(m_id,sprintf("此人看起来还算顺眼，同意的话请输入 answer yes to "+y_id+" 。\n"));
			m_pos=p_ans;
			mp_id=y_id;
		    	who->set_answer(m_id,(:myconfirm:));
		}
		else
		{           
			int no_pos;
			no_pos=CHAR_D->get_char(m_id,"no_pos");
			if(no_pos>time()) {
				officer->targetted_action
					("$N对$T笑道：我被我的真身设定成不能自动给人职位。\n"+
					"你若真想在此地谋职，请等我真身还魂！哈哈。。。\n",who);
			}
			else {
				if(no_pos)
					CHAR_D->set_char(m_id,"no_pos",0); // out of data
				officer->targetted_action
      	        	          ("$N对$T笑道：$R来的正好，本地正需要人才治理，可喜，可贺呀。\n",who);
              	        	give_position(y_id,p_ans,CHAR_D->get_char(m_id,"area"));
			}
		 }
	} else {
	    officer->targetted_action
		  ("$N对$T摇头道：$R请息怒，此职位需要较高的"+p_res+"。\n",who);

	}
}
void confirm_position(object who, object officer)
{
    string y_id;
    string m_id;
	string p_dis;
	int *list;
	int i;
    m_id=(officer->query_id())[0];
    y_id=(who->query_id())[0];
    officer->set_answer(y_id,  (:myposition:) );
	list=get_area_vacancy(CHAR_D->get_char(m_id,"area"));
	p_dis="  代号      官职\n";
	for(i=0;i<sizeof(list);++i)
	{
		p_dis+=sprintf("【%4d】    %s\n",list[i],
			OFFICER_D->query_rank_name(list[i]));
	}
    officer->targetted_action
      (p_dis+"$N对$T道：你考虑妥当了吗？"+
"想好了就请输入 answer <代号> to "+m_id+"\n",who);
}
void ask_position(object who, object officer)
{
    string m_id,y_id;
    string m_area;
    mixed p_check;
    m_id=officer->query_primary_id();
    y_id=who->query_primary_id();
    m_area=CHAR_D->get_char(m_id,"area");
    if((AREA_D->get_area(m_area,"leader"))!=m_id)
    {
        string m_title;
        m_title=OFFICER_D->query_rank_name(
        (OFFICER_D->query_area_officer_title(
         AREA_D->get_area(m_area,"level"),0,0))[0]);
          officer->targetted_action
         ("$N对$T摇摇头，道：$R想在此地为官，$s可做不了主，你须去问本地"+m_title+"。\n",who);
        return;
    }
    p_check=check_first_step(who,m_area);

    if(p_check==1) {
         officer->responda("consider "+y_id);
	 myposition(officer,who,R_SG);
	 return; 
    }
    else if(p_check==2) {                        //Suicide 
         officer->responda("consider "+y_id);    //2000.7
         if (CHAR_D->get_char(m_id,"type")==TYPE_NPC)//
	     confirm_position(who,officer);      //闲职官员向NPC太守要求升职
	 else                                    // 
             officer->targetted_action           //
	     ("$N对$T笑道：我又不是机器人角色，怎么能随便答应你的自动升职请求呢？\n",who); //
	 return;                                 //
    }                                            //
    else {
	officer->targetted_action(p_check,who);
	return;
    }
}
