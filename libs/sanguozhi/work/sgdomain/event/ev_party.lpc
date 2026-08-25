// ev_party.c 
// this is used to handle the local meeting
// this in fact is a task
// by group on 25 Nov, 1999
// this is to check if an area can hold a
// party
#include <mudlib.h>
#include <party.h>
#include <ansi.h>
#define MAXNUMBER 8
string *u_list, s_room;
int gold, food,b_num,size;
void meet_process(string p_id);

int can_party(string a_id)
{
	int* task;
	int p_month,p_day,last;
	mixed * p_date;
	string p_leader;
	string* a_list;
	int i,a_num;
	p_leader=AREA_D->get_area(a_id,"leader");
	task=TASK_D->get_char_task(p_leader);
	if(task[0]!=-1)  // has some task
	{
		if(task[1]==TT_PARTY)
			return PT_ALREADYPARTY;
		else
			return PT_OTHERTASK;
	}
	gold = AREA_D->get_area(a_id,"gold");
	food = AREA_D->get_area(a_id,"food");
	a_list=CHAR_D->check_char_area("nation",
		AREA_D->get_area(a_id,"nation"),a_id);
	
	a_num=0;
	for(i=0;i<sizeof(a_list);++i)
	{
		task=TASK_D->get_char_task(a_list[i]);
		if(task[0]==-1)
			a_num++;
	}
	if (gold < 500 * sizeof(a_list) || food < 1200 * sizeof(a_list))
	return PT_NOMONEY;
	p_date = DAY_D->query_date();
	p_month = p_date[2];
	p_day = p_date[1];
	if (!(p_month==1|| p_month == 7) || !(p_day == 1 || p_day == 2 || p_day == 3)) 
	return PT_TIME;

	if((sizeof(a_list)-a_num)>=PT_MINABSENT)
		return PT_TOOMANYABSENT;
	if(a_num<PT_MINCHAR)
	{
		return PT_NOENOUTHCHAR;
	}
	
	last = AREA_D->get_area(a_id,"last_party_time");
        if( time()<last+40000)
        return PT_TIME;
	return PT_OK;
}
void party(string a_id)
{
	int t_num;
	mapping m_us;
	string *u_all;
	string p_leader;
	string tmp;
	int *task,i;
	object ob_char;
	CHANNEL_D->deliver_tell("rumor","system",
		sprintf("%s正在举行宴会。",AREA_D->get_area(a_id,"name")));
	AREA_D->set_area(a_id,"last_party_time",time());
	t_num=TASK_D->add_task(TT_PARTY);
	TASK_D->set_task(t_num,"area",a_id);
	s_room=AREA_D->get_area(a_id,"path")+
		AREA_D->get_area(a_id,"meeting");
	TASK_D->set_task(t_num,"room",s_room);
	u_all=CHAR_D->check_char_area("nation",
		AREA_D->get_area(a_id,"nation"),a_id);

	p_leader=AREA_D->get_area(a_id,"leader");

	if(sizeof(u_all)<=MAXNUMBER){
		u_list=u_all;
	}
	else {
		u_list=filter_array(u_all,(:CHAR_D->get_char($1,"status")==STATUS_ONLINE:));
		u_list-=({p_leader});
		u_list+=({p_leader});
		u_all-=u_list;
		while(sizeof(u_list)<MAXNUMBER){
			tmp=u_all[random(sizeof(u_all))];
			u_list+=({tmp});
			u_all-=({tmp});
		}
	}

	m_us=([]);
	for(i=0;i<sizeof(u_list);++i)
	{
		task=TASK_D->get_char_task(u_list[i]);
		if(task[0]==-1)
		{
       	                m_us[u_list[i]]=LMP_ATTEND;
               	        CHAR_D->set_char(u_list[i],"task",TASK_PARTY);
			if(CHAR_D->get_char(u_list[i],"status")==STATUS_ONLINE) // a player
			{
				if(file_name(environment(CHAR_D->find_char(u_list[i])))!=
					s_room)
				(EV_INFORMSB)->inform_sb(u_list[i], 		AREA_D->get_area(a_id,"name")+"要召开宴会，请$R速去。");    
			}
                        else
			{
                        	ob_char=CHAR_D->find_char(u_list[i]);
				if(CHAR_D->get_char(u_list[i],"status")==STATUS_ACTIVE) // active
{
                                        if(CHAR_D->get_char(u_list[i],"room")!=
						s_room)
				{
					(EV_INFORMSB)->inform_sb(u_list[i],
                                                AREA_D->get_area(a_id,"name")+"要召开宴会，请$R速去。");    
					if(objectp(ob_char))
					{
                                                ob_char->simple_action("$N拱手道：$s有要事在身，这便告辞，万望见谅。\n");
                                                ob_char->simple_action("$N急匆匆地离开了。\n");
					}
		                        CHAR_D->put_char(u_list[i],s_room); if(objectp(ob_char))
                                        ob_char->simple_action("$N急匆匆地走了过来。\n");
				}
}
				else
				{
					if(!objectp(ob_char)||
					(file_name(environment(CHAR_D->find_char(u_list[i])))!=
						s_room))
					{
			                        CHAR_D->put_char(u_list[i],s_room);
						ob_char=CHAR_D->find_char(u_list[i]); if(objectp(ob_char))
                                                ob_char->simple_action("$N急匆匆地走了过来。\n");
					}
				}
			}
		}
	}
	AREA_D->set_area(a_id,"status",ST_MEETING);
	ob_char=CHAR_D->find_char(p_leader);
	if(objectp(ob_char))
	ob_char->simple_action("$N朗声道：诸位稍安勿燥，宴会马上开始。\n");
	m_us[p_leader]=LMP_LEADER;
	AREA_D->set_area(a_id,"gold",gold - sizeof(u_list) * 500);
	AREA_D->set_area(a_id,"food",food - sizeof(u_list) * 1200);	
	TASK_D->set_task(t_num,"start_time",time());
	TASK_D->set_task(t_num,"chars",m_us);
	TASK_D->set_task(t_num,"timaim",LML_BEGIN);
	TASK_D->set_task(t_num,"stage",LMS_BEGIN);
}
void auto_local_meeting()
{
}
void meet_announce(int p_id)
{
	string p_area;
	string p_leader;
	object o_char,o_room,o;
	mixed obs;
	int i;
	p_area=TASK_D->get_task(p_id,"area");
	p_leader=AREA_D->get_area(p_area,"leader");
	o_char=CHAR_D->find_char(p_leader);
	if(objectp(o_char))
	{
		o_char->simple_action
                ("$N道：列位将军、大人，承蒙各位辛勤工作，$S特请各位聚宴言欢。\n");
                o_char->simple_action
                ("$N接着道：诸位不必拘礼，请尽情享用。\n");
	}
	o_room=load_object(s_room);
        if(!objectp(o_room)) return;
        obs=OBJ_D->check_obj("type","food");
        for(i=0;i<3;++i) { // less drink and food
                o=OBJ_D->clone_obj(obs[random(sizeof(obs))]);
                if(!objectp(o)) continue;
                o->move(o_room);
        }
        obs=OBJ_D->check_obj("type","drink");
        for(i=0;i<3;++i) {
                o=OBJ_D->clone_obj(obs[random(sizeof(obs))]);
                if(!objectp(o)) continue;
                o->move(o_room);
	}
	TASK_D->set_task(p_id,"stage",LMS_DISCUSS);
	TASK_D->set_task(p_id,"timaim",LML_PROCESS);
	return;
}
void meet_happens(int p_id)
{
	int h;
	string u_name;
	object o_char;
	size = sizeof(u_list) / 3;
	if(size <1) size =1;
	if(b_num<=size) {
	b_num++;
	u_name = u_list[random(sizeof(u_list))];
	o_char = CHAR_D->find_char(u_name);
	if (CHAR_D->get_char(u_name,"gender")==1)h = 1+random(2);
	else {h = random(2);}
	switch (h) {
	case 0:
	o_char->simple_action(
	"$N道：今日难得大家雅兴，$S献舞一曲，以博一笑。\n");
	TASK_D->set_task(p_id,"stage",LMS_IDLE);
	call_out("party_happen",5,u_name,p_id,h);
	break;
	case 1:
	o_char->simple_action(
        "$N道：今日难得大家雅兴，$S献歌一首，诸位静听。\n");
	 TASK_D->set_task(p_id,"stage",LMS_IDLE);
        call_out("party_happen",5,u_name,p_id,h);
        break;
	case 2:
	o_char->simple_action(
        "$N道：今日难得大家雅兴，$S献剑舞一套，大家笑纳。\n");
	 TASK_D->set_task(p_id,"stage",LMS_IDLE);
        call_out("party_happen",5,u_name,p_id,h);
        break;	
	}
		
}	 
	TASK_D->set_task(p_id,"stage",LMS_PROCESS);
        TASK_D->set_task(p_id,"timaim",LML_BEGIN);
        return;
}

void meet_readytoend(int p_id)
{
	string p_area;
	string p_leader;
	object o_char;
	p_area=TASK_D->get_task(p_id,"area");
	p_leader=AREA_D->get_area(p_area,"leader");
	o_char=CHAR_D->find_char(p_leader);
	if(objectp(o_char))
	{
		o_char->simple_action
                ("$N道：列位将军、大人，宴会已近尾声，各位可否满意？\n");
		o_char->simple_action
                ("$N接着道：如若无事，诸位就早些回府歇息去吧。\n");
	}
	TASK_D->set_task(p_id,"stage",LMS_END);
	TASK_D->set_task(p_id,"timaim",LML_END);
	return;
}
void meet_over(int p_id)
{
	string p_area, p_nation;
	string p_leader;
	object o_char;
	mapping m_us;
	string *p_list;
	int i, loyalty;

	p_area=TASK_D->get_task(p_id,"area");
	m_us=TASK_D->get_task(p_id,"chars");

	TASK_D->remove_task(p_id);

	p_leader=AREA_D->get_area(p_area,"leader");
	p_nation= AREA_D->get_area(p_area,"nation");
	o_char=CHAR_D->find_char(p_leader);
	if(objectp(o_char))
	{
			o_char->simple_action
					("$N起身道：今日便到这里，列位将军、大人，请早回。\n");
			
		
	}
	b_num = 0;
	p_list=keys(m_us);
	
	for(i=0;i<sizeof(p_list);++i)
	{	loyalty = CHAR_D->get_char(p_list[i],"lo")[p_nation];
		loyalty =loyalty +random(10)+5;	
		if (loyalty >=100) loyalty = 100;
		CHAR_D->set_char_loyalty(p_list[i],p_nation,loyalty);	
		if((CHAR_D->get_char(p_list[i],"status"))!=STATUS_ONLINE)
		{
			o_char=CHAR_D->find_char(p_list[i]);
			if(objectp(o_char))
			{
				o_char->simple_action
                                ("$N拱手道：$s告辞！\n$N起身匆匆离开了。\n");
			}
		}
		CHAR_D->set_char(p_list[i],"task",TASK_NONE);
		CHAR_D->remove_npc_char(p_list[i]);
	}
	CHANNEL_D->deliver_tell("rumor","system",
	sprintf("%s宴会结束，众将尽兴而归。",AREA_D->get_area(p_area,"name")));
	AREA_D->set_area(p_area,"status",ST_NORMAL);

	
}
void meet_process(int p_id)
{
	int p_stage;
	p_stage=TASK_D->get_task(p_id,"stage");
	switch(p_stage)
	{
	case LMS_BEGIN:
		meet_announce(p_id);
		break;
	case LMS_PROCESS:
		meet_readytoend(p_id);
		break;
	case LMS_DISCUSS:
		meet_happens(p_id);
		break;
	case LMS_IDLE:
		break;
	case LMS_END :
	default:
		meet_over(p_id);
	}
}

void party_happen(string c_id,string p_id,int happen)
{
	int wl,ml,rep,rep1;
	int count=0;
	object o_char;
	remove_call_out("party_happen");
	o_char = CHAR_D->find_char(c_id);
	wl = CHAR_D->get_char(c_id,"skills")["sk_wuli"];
	ml = CHAR_D->get_char(c_id,"skills")["sk_meili"];
	rep = CHAR_D->get_char(c_id,"reputation");
	switch(happen) 
{
	case 0:
	if (random(ml) > 15) {
	DELAY_D->delay_simple_action(o_char,
"%^H_RED%^$N曼舞水袖，轻移莲步，宛如浮云之燕，翩似天穹之虹。\n 满场看得屏息禁气，目不转睛。 %^RESET%^ \n",4);
	count++;	
	}
	else
	DELAY_D->delay_simple_action(o_char,
"%^H_GREEN%^$N步履浮动，身形不稳，舞动之间颇不自然。\n 四面依然安静，只是不少人脸上不以为然。%^RESET%^ \n",4);
	if (random(ml) > 25) {
 	DELAY_D->delay_simple_action(o_char,
"%^H_RED%^$N轻抬玉手，长裙曳地，宛如开屏孔雀，又比凤上枝头。\n 全场鸦雀无声，无人不全神贯注，只怕漏了一丝细节。%^RESET%^ \n",8);
 	count+= 3;
	}
	else 
	DELAY_D->delay_simple_action(o_char,
"%^H_GREEN%^$N舞了个团圆步，重心不稳，显些摔倒。\n 场边已有了些嘘声。%^RESET%^ \n",8);
	if (random(ml) >30) {
	DELAY_D->delay_simple_action(o_char,
"%^H_RED%^$N舞到极处，只见云袖飞扬，彩衣翻飞，当真如嫦娥舞月，倾城倾国！ \n 众人无不看的心摇悸动，只觉此身已飘然，混然不似在人间。%^RESET%^ \n",12);
	count +=5;
	}
	else
	DELAY_D->delay_simple_action(o_char,
"%^H_GREEN%^$N勉强舞起长袖，额头已微微渗出汗滴，已是支持不住。\n 众人纷纷拍手为其鼓劲。%^RESET%^ \n",12);
	if (count >=4) 
	DELAY_D->delay_simple_action(o_char,
"%^H_RED%^$N一曲舞罢，满场欢声雷动。%^RESET%^ \n",13);
	else 
	DELAY_D->delay_simple_action(o_char,
"%^H_RED%^$N一曲舞罢，只得稀稀落落几声掌声。%^RESET%^ \n",13);
	rep1 = count * (100 +random(100));
	rep = rep + rep1;
	CHAR_D->set_char(c_id,"reputation",rep);
	DELAY_D->delay_simple_action(o_char,
"$N获得声望"+chinese_number(rep1)+"点。\n",14);
	break;

	case 1:
	if (random(ml) > 15) {
        DELAY_D->delay_simple_action(o_char,
"%^H_RED%^$N婉声低唱，曲调幽挽迷人。\n 众人听得入迷，脸上也露出了幽怨的神情。%^RESET%^ \n",4);
        count++;
        }
        else
        DELAY_D->delay_simple_action(o_char,
"%^H_GREEN%^$N唱得直似五音不全，嘶哑难听。\n 四面一阵嘘声。%^RESET%^ \n",4);
        if (random(ml) > 25) {
        DELAY_D->delay_simple_action(o_char,
"%^H_RED%^$N放声高歌，歌声高亢，震入云霄。\n 众人为之感染，无不热血沸腾。%^RESET%^ \n",8);
        count+= 3;
        }
        else
        DELAY_D->delay_simple_action(o_char,
"%^H_GREEN%^$N高歌一曲，就如破钟之声，亮而不久。\n 众人纷纷摇头。%^RESET%^ \n",8);
        if (random(ml) >30) {
        DELAY_D->delay_simple_action(o_char,
"%^H_RED%^$N歌到深处，一波三折，之如九曲回肠，回味无穷。\n 众人无不痴迷，余音袅袅，当真是绕梁三日。%^RESET%^ \n",12);
        count +=5;	
	}
        else
        DELAY_D->delay_simple_action(o_char,
"%^H_GREEN%^$N唱得高无可高，终于极处断裂，嘎然而止。\n 一人叹道：此乃否极泰来是也。可谓强不可久。%^RESET%^ \n",12);
        if (count >=4)
        DELAY_D->delay_simple_action(o_char,
"%^H_RED%^$N一曲唱罢，满场欢声雷动。%^RESET%^ \n",13);
        else 
	DELAY_D->delay_simple_action(o_char,
"%^H_RED%^$N一曲唱罢，只得稀稀落落几声掌声。%^RESET%^ \n",13);
        rep1 = count * (100 +random(100));
	rep = rep + rep1;
        CHAR_D->set_char(c_id,"reputation",rep);
	DELAY_D->delay_simple_action(o_char,
"$N获得声望"+chinese_number(rep1)+"点。\n",14);
        break;
		
	case 2:
	if (random(wl) > 15) {
        DELAY_D->delay_simple_action(o_char,
"%^H_RED%^$N虎步龙行，剑随身走，端的是气派不凡。\n 众人无不拍手叫好。%^RESET%^ \n",4);
        count++;
        }
        else
        DELAY_D->delay_simple_action(o_char,
"%^H_GREEN%^$N用力拔剑，剑却拔不出来。\n 四面笑声大作。%^RESET%^ \n",4);
        if (random(wl) > 25) {
        DELAY_D->delay_simple_action(o_char,
"%^H_RED%^$N摆个望月步，进退由心，有如吕布舞月下，又似李白醉花间。\n 一众女将看得芳心砰然，叫好声此起彼伏。%^RESET%^ \n",8);
        count+= 3;
        }
        else
        DELAY_D->delay_simple_action(o_char,
"%^H_GREEN%^$N纵前跃后，身法已不甚灵便。\n 众人笑着拍手鼓劲。%^RESET%^ \n",8);
        if (random(wl) >30) {
        DELAY_D->delay_simple_action(o_char,
"%^H_RED%^$N舞到急处，只见一团白光如水银泄地，滴水不透。\n 众人只见剑光不见人，不由大声叫好。%^RESET%^ \n",12);
        count +=5;
        }
        else
        DELAY_D->delay_simple_action(o_char,	
	"%^H_GREEN%^$N脚下一个踉跄，宝剑几乎脱手而飞。\n 四面一阵叹息声。%^RESET%^ \n",12);
        if (count >=4)
        DELAY_D->delay_simple_action(o_char,
"%^H_RED%^$N一曲舞罢，满场欢声雷动。%^RESET%^ \n",13);
        else 
	DELAY_D->delay_simple_action(o_char,
"%^H_RED%^$N一曲舞罢，只得稀稀落落几声掌声。%^RESET%^ \n",14);
        rep1 = count * (50 +random(30));
        rep = rep + rep1;
        CHAR_D->set_char(c_id,"reputation",rep);
	DELAY_D->delay_simple_action(o_char, "$N获得声望"+chinese_number(rep1)+"点。\n",11);
        break;
	} 
	call_out("idle_process",5,p_id);
	return;
}		

void idle_process(string p_id)
{
	remove_call_out("idle_process");
	if (b_num<=size)
	TASK_D->set_task(p_id,"stage",LMS_DISCUSS);
	return;
}
