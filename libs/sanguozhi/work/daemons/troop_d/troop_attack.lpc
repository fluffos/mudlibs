#define KILL_RATE 10 // the larger this number, the slower the kill speed
#define ADJ_SCALE 100 // adjust the caculation process
#define NPC_DEF_RATE 15 // 15 means 1.5
// troop_attack.c
// this is part of troop_d.c
mixed find_troop(int p_id);
int get_troop_attack_area_rate(int p_id)
{
   string a_id;
   object o_id,env;
   int *pos;
   o_id=find_troop(p_id);
   if(!objectp(o_id)) return 1;
   env=environment(o_id);
   if(!objectp(env)) return 1;
     
   pos=env->query_pos();
   a_id=env->query_aid();
   return (MAP_D->get_map_cell(a_id, pos[1],pos[0],"attack_rate"));
}

int get_troop_defance_area_rate(int p_id)
{
   string a_id;
   object o_id,env;
   int *pos;
   o_id=find_troop(p_id);
   if(!objectp(o_id)) return 1;
   env=environment(o_id);
   if(!objectp(env)) return 1;
     
   pos=env->query_pos();
   a_id=env->query_aid();
   return (MAP_D->get_map_cell(a_id, pos[1],pos[0],"defence_rate"));
}

int get_soldier_kills(int p_id)
{
   mixed p_soldiers;
   string *p_type;
   int p_kills;
   p_soldiers=TROOP_D->get_troops(p_id,"soldier");
   p_type=keys(p_soldiers);
   if(!sizeof(p_type))
	return 0;
   p_kills=-1;
   foreach(string p_s in p_type)
   {
       int p_m,p_t,p_n;
       int p_r,p_k;
       if(p_soldiers[p_s]["energy"]>=GENERAL_ATTACK_CONSUME)
       {
	   p_r=WARAI_D->get_soldier(p_s,"attack_rate");
	   p_n=p_soldiers[p_s]["number"];
           p_m=p_soldiers[p_s]["morale"];
           p_t=p_soldiers[p_s]["train"];
           p_k=p_n*p_r*(p_m+p_t)/200/10/3; // from 10 to 3
           p_kills+=p_k+1;
       }
   }
   return p_kills;
}
int get_general_kills(int p_id)
{
	string *chars;
	int p_kills=0;
	float tmp;
	chars=TROOP_D->get_troops(p_id,"chars");
	if(!sizeof(chars))
		return 0;
	foreach(string char in chars)
	{
		int wuli;
		object o;
		mixed skills;
		o=CHAR_D->find_char(p_id);
		
		wuli=FIGHT_D->get_att_abi(o);
		wuli+=(FIGHT_D->get_att_pow(o)*2);
		if(wuli>70) {
			tmp=wuli-70.0;
			tmp=tmp/10.0;
			tmp=tmp*tmp/2.0;
			p_kills+=to_int(tmp);
		}
			
//			p_kills+=(wuli-70)/5;
		
/*
		skills=CHAR_D->get_char(char,"skills");
		if(!mapp(skills)) wuli=50;
		else
			wuli=skills["sk_wuli"];
		if((wuli)&&(wuli>60))
			p_kills+=((wuli-50)/10);
*/
	}
	return p_kills;		
}
int get_troop_max_skills(int p_id,string sk)
{
	string *chars;
	int msk=0;
	chars=TROOP_D->get_troops(p_id,"chars");
	if(!sizeof(chars))
		return 0;
	foreach(string char in chars)
	{
		mixed skills;
		skills=CHAR_D->get_char(char,"skills");
		if (!mapp(skills)) continue;
		if((skills[sk])&&(intp(skills[sk])))
			msk=bmax(msk,skills[sk]);
	}
	return msk;
}
int get_leadrate(int p_id)
{
	int rate;
	int m_wuli;
	m_wuli=get_troop_max_skills(p_id,"sk_wuli");
	return m_wuli;
}
int get_troop_attack_kills(int p_id)
{
   int p_area_rate;
   int p_kills,p_leadrate;
   int p_general_kills;
   p_area_rate=get_troop_attack_area_rate( p_id);
   p_kills=get_soldier_kills(p_id);
   p_leadrate=get_leadrate(p_id);
   p_kills=p_kills*p_leadrate/200; 
   p_general_kills=get_general_kills(p_id); 
   p_kills+=p_general_kills;
   p_kills=p_kills*p_area_rate/5;
   return p_kills;
}



/////////////////////////////////////////////////////////////////////////
// new attack formula ///////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

int adj_numtwo(int num) {
	int ret=0;
	while(num>100) {
		ret+=100;
		num-=100;
		num/=2;
	}
	ret+=num;
	return ret;

}

int adj_num(int num) {
/*	int ret=0;
	while(num>1000) {
		ret+=1000;
		num-=1000;
		num/=2;
	}
	ret+=num; */
	if(num>4000) return adj_numtwo(4000);  // xiaobai: limit 2k increased to 4k
	return adj_numtwo(num);
//	return ret;
}
int get_army_attack_rate(mixed army,string a_type) {
	int p_bzrate; // this is the 兵种参数
	int p_engconsume;
	int ret;
	p_bzrate=WARAI_D->get_bz_attack_rate(army["type"],a_type);
	if(!p_bzrate) return 0;
	p_engconsume=WARAI_D->get_attack_consume(a_type);
	if(p_engconsume>army["energy"])
		return 0;
	// 基本杀伤力：
	ret=ADJ_SCALE*adj_num(army["number"])/KILL_RATE; // 100 in order to emit the effict of 
	                                  // decimial small number
	// 士气训练调整
	ret=ret*(army["morale"]+army["train"]+100)/400; //
	// 进攻方式调整
	ret=ret*p_bzrate/10;
	return ret;
}
int get_attack_rate(int p_id,string a_type) {
	int ret=0;
	mixed p_soldiers;
	string zf,*ts; // 阵法和兵种
	int zfrate,genrate,arearate;

	p_soldiers=TROOP_D->get_troops(p_id,"soldier");
	ts=keys(p_soldiers);
	if(!sizeof(ts)) return 0; // no solider ?
	foreach(string t in ts)
		ret+=get_army_attack_rate(p_soldiers[t],a_type);
	
	// 阵法调整：
	zf=TROOP_D->get_troops(p_id,"zf"); // 阵法；
	zfrate=WARAI_D->get_zf(zf,"att_rate");
	ret=ret*(zfrate+5)/10;
	// 将军指挥力调整
	genrate=get_leadrate(p_id);
	ret=ret*(genrate+50)/150;
	// 加上将军杀人数
	ret += (get_general_kills(p_id)*ADJ_SCALE);
	// 地形调整
	arearate=get_troop_attack_area_rate(p_id);
	ret=ret*(arearate+3)/10;
	if(TROOP_D->get_troops(p_id,"side")=="d") 
		ret*=DEF_KILL_MORE;
//	tell_user("fire",sprintf("in the get_attack rate is %d\n",ret));
	return ret;
}

////////////////////////////////////////////////////////////////////////
// 对一个地区的攻击，攻击力是 p_kill
////////////////////////////////////////////////////////////////////////
int attack_army(mixed army, int p_kill, string att_type) {
	int def_rate;
	// 士气训练调整
	p_kill=p_kill*400/(army["morale"]+army["train"]+100);
	// 进攻方式调整
	def_rate=WARAI_D->get_bz_defence_rate(army["type"],att_type);
	p_kill=p_kill*10/def_rate;
	p_kill/=ADJ_SCALE;

//	tell_user("fire",sprintf("in the attack_army is %d\n",p_kill));

	return p_kill;
}

// this will return the real killed number of soldiers   
int attack_troop(int t, int p_kill,string att_type) {
	int sum,i;
	int total_num=0,my_total;
	int ret=0,zfrate,genrate,my_kill;
	mixed army;
	string zf,*ids;
	army=TROOP_D->get_troops(t,"soldier");
	sum=sizeof(army);
	if(!sum) return 0; // no soldier
	total_num=(TROOP_D)->get_troops(t,"total_num");
	if(total_num==0) return 0; // no one to kill


	// 阵形防守调整
	zf=TROOP_D->get_troops(t,"zf"); // 阵法；
	zfrate=WARAI_D->get_zf(zf,"def_rate");
	p_kill=p_kill*10/(zfrate+5);

	// 将领技能调整：
	genrate=get_leadrate(t);
	p_kill=p_kill*150/(50+genrate);

	// NPC 防守调整
	if(TROOP_D->get_troops(t,"side")=="d") {
		int t_id,is_npc=1;
		string d_leader, *chs;
		t_id=TROOP_D->get_troops(t,"task_id");
		d_leader=TASK_D->get_task(t_id,"def_leader");
		if(objectp(find_body(d_leader)))
			p_kill=p_kill*10/NPC_DEF_RATE;
		chs=TROOP_D->get_troops(t,"chars");
		if(sizeof(chs)) {
	   		foreach(string c in chs)
   			{
      				if(CHAR_D->get_char(c,"status")==STATUS_ONLINE)
					is_npc=0;
			}
			if(is_npc)
				p_kill=p_kill*10/NPC_DEF_RATE;
		}
	}

	ids=keys(army);
	foreach(string id in ids) {
		my_kill=p_kill*army[id]["number"]/total_num;
		my_kill=attack_army(army[id],my_kill,att_type);
		if(!my_kill) 
			my_kill=random(2);
		if(my_kill>army[id]["number"]) my_kill=army[id]["number"];
		army[id]["number"]-=my_kill;
		if(army[id]["number"]==0)
			map_delete(army,id);
		ret+=my_kill;

	}
	TROOP_D->set_troops(t,"soldier",army);
//	tell_user("fire",sprintf("in the attack_troop is %d\n",ret));

	return ret;
}
int attack_troops(mixed t,int p_kill,string att_type) {
	int sum,i;
	int area_def_rate;
	int total_num=0,my_total;
	int ret=0;
	sum=sizeof(t);
	if(!sum) return 0; // no troop there
	for(i=0;i<sum;++i) 
		total_num+=(TROOP_D)->get_troops(t[i],"total_num");
	
	// 地形防守调整
	area_def_rate=get_troop_defance_area_rate( t[0]);
	p_kill=p_kill*10/(area_def_rate+3);

	if(total_num==0) return 0; // no one to kill
	for(i=0;i<sum;++i) {
		my_total=(TROOP_D)->get_troops(t[i],"total_num");
		ret+=attack_troop(t[i],p_kill*my_total/total_num,att_type);
	}
//	tell_user("fire",sprintf("in the attack_troops is %d\n",ret));
	return ret;
}

