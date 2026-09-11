// guy_final.c by fire on Dec 1998
#include <security.h>
inherit M_ACCESS;
#define LOG_FILE "/sgdomain/modules/m_charnpc/guy/setppl.log"
private string act;
string query_leader();
void do_my_dispear();
void award(object usr);
void set_act(string p)
{
   act=p;
}
int log_me(string msg) {
	unguarded(1, (: write_file, LOG_FILE, msg :));
	return 1;
}
void  select_num()
{
   string p_id;
   object usr;
   p_id=query_leader();
   usr=find_user(p_id);
   if(!objectp(usr)) 
   {
       do_my_dispear();
   }
   if (this_object()->query("is_fake")) //fake people no robot test
   	   award(usr);
	else
	{
	   this_object()->targetted_action(
			"一$N对$T道：在我们走之前，给你道题，看你会不会。\n",find_body(p_id));
	   ROBOT->robot_test(usr,(:award:));
	}
}
void award(object usr)
{
   string p_id;
   int isrobot;
   mapping troop;
   int p_population,p_safe;
   int p_left;
   object master;
   string p_area;
   string f_id;
   string r_id;
   string m_area;
   object bs;
   string p_tmp;
   int old_data;
   string what_i_got="新兵";  //added by edc
   int rdm_i_got=0; // added by edc


   p_id=query_leader();
   if(!objectp(usr)) {do_my_dispear();return;}
   usr=usr->query_body();
   if(!objectp(usr)) {do_my_dispear();return;}
   
   if (this_object()->query("is_fake")) //do penalty
   {
	this_object()->targetted_action(
		"众$N对$T道：$m$R真神人也，跟他发展，一定大有前途。\n",usr);
//this is for temp track of success rate
	CHAR_D->set_char("listen","setpplsuccess",
		CHAR_D->get_char("listen","setpplsuccess")+1); 
//temp end here
	if(act=="followme")
	{
		old_data= CHAR_D->get_char(p_id,"gold");
		CHAR_D->set_char(p_id,"gold",
		   CHAR_D->get_char(p_id,"gold")-50);
		if (CHAR_D->get_char(p_id,"gold")<0)
		   CHAR_D->set_char(p_id,"gold",0);
		tell_user(p_id,"%^H_GREEN%^很不幸，你被骗了50两金子。%^RESET%^\n");
		p_tmp=sprintf("\n time at %s ,%s  gold change from %d to %d",
			CHINESE_D->chinese_time(time()),p_id,old_data,CHAR_D->get_char(p_id,"gold"));
		log_me(p_tmp);
		if (stringp(this_object()->query("master")))
			tell_user(this_object()->query("master"),"%^H_RED%^【飞鸽传书】密报："+
				"吾方间谍已成功混入"+CHAR_D->get_char(p_id,"name")+"家中。%^RESET%^\n");
	}
	else if(act=="recruit")
	{
		p_area=CHAR_D->get_char(p_id,"area");

		old_data=AREA_D->get_area_soldier(p_area,"sum");
		if (!AREA_D->reduce_soldier(p_area,"sum",100)) //no enough soldier to reduce
		{
			p_safe=AREA_D->get_area(p_area,"safe"); //safe -10
			p_population=AREA_D->get_area(p_area,"population");//population -2%-200
			
			p_safe-=10;
			if (p_safe<0)
				p_safe=0;
			AREA_D->set_area(p_area,"safe",p_safe);
			p_population-=(p_population/20+200);
			if (p_population<100)
				p_population=100;
			AREA_D->set_area(p_area,"population",p_population);
      		}
      		p_tmp=sprintf("\n time at %s ,%s troop change from %d to %d",
			CHINESE_D->chinese_time(time()),p_area,old_data,AREA_D->get_area_soldier(p_area,"sum"));
		log_me(p_tmp);
		usr->simple_action("由于误信歹人，$N的地区遭受到严重损失。\n");
		if (stringp(this_object()->query("master")))
			tell_user(this_object()->query("master"),"%^H_RED%^【飞鸽传书】密报："+
				"吾方间谍已成功混入"+AREA_D->get_area(p_area,"name")+"军队。%^RESET%^\n");
	
		p_left=(PJOB+"recruit/recruit")->get_recruit_left(p_id);
		p_left-=50;
		usr->finish_job("recruit");
		if(p_left>=50)
		{
			usr->add_job("recruit");
			usr->set_job("recruit","left",p_left);
			usr->set_job("recruit","memo","征"+p_left+"兵");
			tell_user(p_id,"你还需要招"+chinese_number(p_left)+
// edc
				"名士兵。\n");
/*				"名新兵。\n");*/
////
		}
	}
	else if(act=="getppl")
	{
		master=find_body(p_id);
		p_area=master->query_job("getppl","p_area");
		f_id=master->query_job("getppl","f_id");
		r_id=master->query_job("getppl","r_id");
		m_area=this_object()->query_room()->get_area();
		bs=SGBASE(p_area,f_id);
		
		usr->simple_action("由于误信歹人,$N的农场遭到严重损失。\n");
		if (stringp(this_object()->query("master")))
			tell_user(this_object()->query("master"),"%^H_RED%^【飞鸽传书】密报："+
				"吾方间谍已成功混入"+AREA_D->get_area(p_area,"name")+"农场。%^RESET%^\n");
		usr->finish_job("getppl");
		if(objectp(bs)) 
		{
			old_data= bs->get_base_pplnum();
			bs->reduce_ppl(r_id,100);
			p_tmp=sprintf("\n time at %s ,%s level %d farmers change from %d to %d",
				CHINESE_D->chinese_time(time()),p_area,bs->get_level(),old_data,bs->get_base_pplnum());
			log_me(p_tmp);
		}
	}
	else
	{
		SGSYS("Not one of getppl,recruit & followme happened in guy_final action!");
		usr->simple_action("内部错误发生,请尽快象巫师报告这一错误。谢谢您的合作！\n");
	}
		
	do_my_dispear();
	return;
   }

//End of fake guy penalty

   isrobot=usr->query_body()->query_robot();
   if(isrobot)
   { this_object()->targetted_action(
         "众$N对$T道：看来是个白痴，真不能跟$m跑。\n",usr);
      do_my_dispear(); 
      return;
   } 

   if(act=="followme")
   {    CHAR_D->set_char(p_id,"newqb",50);
        tell_user(p_id,"%^H_GREEN%^恭喜你又招到五十名亲兵。%^RESET%^\n");
   }
   else if(act=="recruit")
   {
       int p_soldier,p_morale,p_train; 
	   p_area=CHAR_D->get_char(p_id,"area");
        //      p_soldier=AREA_D->get_area(p_area,"soldier");
	troop = AREA_D->get_area(p_area, "troop");
	if( !troop || !mapp(troop) || !sizeof(troop) )troop = ([ ]);
	foreach(string tt in keys(troop))p_soldier+=troop[tt];
        p_morale=AREA_D->get_area(p_area,"morale");
        p_train=AREA_D->get_area(p_area,"train");
        p_train=(p_train*p_soldier+750)/(p_soldier+50);
        p_morale=(p_morale*p_soldier+750)/(p_soldier+50);

// edc 08/04/2001
	// random get multitroop, 1/5 possibility get bowman, cavalry, and 3/5 get footman
	
	rdm_i_got = random(5);
	switch (rdm_i_got)
	{
		case 0:	if( !troop["bowman"] ) troop["bowman"] = 50;
			else troop["bowman"] = troop["bowman"] + 50;
			what_i_got = "弓兵";
			break;
		case 1: if( !troop["cavalry"] ) troop["cavalry"] = 50;
			else troop["cavalry"] = troop["cavalry"] + 50;
			what_i_got = "骑兵";
			break;
		default:
			if( !troop["footman"] ) troop["footman"] = 50;
			else troop["footman"] = troop["footman"] + 50;
			what_i_got = "新兵";
	}
/* edc
//      AREA_D->set_area(p_area,"soldier",p_soldier+50);
	if( !troop["footman"] ) troop["footman"] = 50;
	else troop["footman"] = troop["footman"] + 50;
*/	
////

	AREA_D->set_area(p_area,"troop", troop);
        AREA_D->set_area(p_area,"morale",p_morale);
        AREA_D->set_area(p_area,"train",p_train);
        usr->award_exp(50);
        CHAR_D->set_char(p_id,"reputation",
        CHAR_D->get_char(p_id,"reputation")+50);
        CHAR_D->set_char(p_id,"localcontribution",
        CHAR_D->get_char(p_id,"localcontribution")+2);
// edc  08/04/2001
/*	usr->simple_action("$N招到五十名新兵，$N的经验与声望提高了。\n"); */
	usr->simple_action("$N招到五十名"+what_i_got+"，$N的经验与声望提高了。\n");
////	
        p_left=(PJOB+"recruit/recruit")->get_recruit_left(p_id);
        p_left-=50;
        usr->finish_job("recruit");
        if(p_left>=50)
        {
           usr->add_job("recruit");
           usr->set_job("recruit","left",p_left);
		   usr->set_job("recruit","memo","征"+p_left+"兵");
           tell_user(p_id,"你还需要招"+chinese_number(p_left)+
// edc
		"名士兵。\n");
/*            "名新兵。\n");  */
////
        }
	p_area=usr->query_room()->get_area(); 
	{
		p_population=AREA_D->get_area(p_area,"population");
		p_safe=AREA_D->get_area(p_area,"safe");
		p_safe--; p_safe=bmax(p_safe,0);
		p_population-=50; p_population=bmax(100,p_population);
		AREA_D->set_area(p_area,"safe",p_safe);
		AREA_D->set_area(p_area,"population",p_population);
		CHANNEL_D->deliver_tell("rumor","system",
			usr->query_chinese_id()+"在"+AREA_D->get_area(p_area,"name")+
			"征兵，当地人口和安定下降了。");
	}
   }
   else if (act=="getppl") {
		master=find_body(p_id);
	   p_area=master->query_job("getppl","p_area");
	   f_id=master->query_job("getppl","f_id");
	   r_id=master->query_job("getppl","r_id");
	m_area=this_object()->query_room()->get_area();
	bs=SGBASE(p_area,f_id);
		AWARD(usr,20);
        usr->simple_action("$N又拉到五十名"+BASE_D->get_base(f_id,"workername")+
			"，$N得到了奖励。\n");

        usr->finish_job("getppl");
		{
			p_population=AREA_D->get_area(m_area,"population");
			p_safe=AREA_D->get_area(m_area,"safe");
			p_safe--; p_safe=bmax(p_safe,0);
			p_population-=50; p_population=bmax(100,p_population);
			AREA_D->set_area(m_area,"safe",p_safe);
			AREA_D->set_area(m_area,"population",p_population);
			CHANNEL_D->deliver_tell("rumor","system",
				usr->query_chinese_id()+"在"+AREA_D->get_area(m_area,"name")+
				"拉走一批"+BASE_D->get_base(f_id,"workername")+"，当地人口和安定下降了。");
		}
		if(objectp(bs)) 
			bs->add_ppl(r_id,50);
   }
   do_my_dispear();
}
