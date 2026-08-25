// formula.c for fight_d.c
// fight_d.c this is used to control fight
// by fire in March 1999

int get_pure_att_abi(object o){
	string p_id, wep_type,wep_id;
	object wep,env;
	int sk_level,wep_level,h_level;
	if(!objectp(o)) return 0;
	sk_level=o->query_sk_level("sk_wuli");
	p_id=o->query_id()[0];
	if(CHAR_D->char_exist(p_id)&&
                CHAR_D->get_char(p_id,"type")==TYPE_NPC) {
		wep_level=sk_level;
		h_level=sk_level;
	}
	else {
		wep=o->query_weapon();
		if(wep==o) // no weapon
{
//modify by suicide in 20011230 
                        wep_level=o->query_skill("unarmed"); //包含基本拳脚+高级拳脚技能
//			wep_level=o->query_sk_level("unarmed");
                        
		}
		else{
			wep_id=wep->query_id()[0];
			wep_type=OBJ_D->get_obj(wep_id,"sub_type");
			if(!wep_type) // not a legel weapon
				wep_level=0;
			else 
				//wep_level=o->query_sk_level(wep_type);
                                wep_level=o->query_skill(wep_type); //包含基本技能lvl+高级技能
		}
		env=environment(o);
		if(env->is_horse()) {
			//h_level=o->query_sk_level("horse")+10;
			h_level=o->query_skill("horse")+10;
		}
		else {
			//h_level=o->query_sk_level("dodge");
			h_level=o->query_skill("dodge");
		}
	}
	return (sk_level+wep_level+h_level) / 3;
}
int get_wep_att_abi(object o) {
	object wep;
	if(!objectp(o)) return 0;
	wep=o->query_weapon();
	if(!wep->sg_obj()) return 0;
		return wep->query_attack_ability();
}

int get_hos_att_abi(object o) {
	object hos;
	if(!objectp(o)) return 0;
	hos=environment(o);
	if(!hos) return 0;
	if(!hos->is_horse()) return 0;
	if(!hos->sg_obj()) return 0;
	return hos->query_attack_ability();
}
int get_clh_att_abi(object o) {
	object *obs;
	mixed stat;
	int ret=0;
	if(!objectp(o)) return 0;

	obs=all_inventory(o);
	if(!sizeof(obs)) return 0;
	foreach(object ob in obs){
        stat=ob->ob_state();
        if(stringp(stat)&&(ob->sg_obj()))
        {	ret+=ob->query_att_abi();
        }
	}
	return ret;
}
int get_add_att_abi(object o) {
	return get_wep_att_abi(o)+
		get_hos_att_abi(o)+
		get_clh_att_abi(o);
}
int get_att_abi(object o) {
	return get_pure_att_abi(o)+
		get_add_att_abi(o);
}
// A->att_pow=(A->l_wuxu*3+A->l_weapon*7)/50+W->att_pow
int get_pure_att_pow(object o) {
	string p_id, wep_type,wep_id;
	object wep;
	int sk_level,wep_level;
	if(!objectp(o)) return 0;
	sk_level=o->query_sk_level("sk_wuli");
	p_id=o->query_id()[0];
	if(CHAR_D->char_exist(p_id)&&
                CHAR_D->get_char(p_id,"type")==TYPE_NPC) {
		wep_level=sk_level;
        }
	else {
		wep=o->query_weapon();
		if(wep==o) // no weapon
		{
			wep_level=0; // will not support unarmed
		}
		else{
			wep_id=wep->query_id()[0];
			wep_type=OBJ_D->get_obj(wep_id,"sub_type");
			if(!wep_type) // not a legel weapon
				wep_level=0;
			else 
				wep_level=o->query_skill(wep_type);
		}
	}
	return (sk_level*3+wep_level*7) / 25;
}
int get_wep_att_pow(object o) {
	object wep;
	if(!objectp(o)) return 0;
	wep=o->query_weapon();
	if(!wep->sg_obj()) return 0;
		return wep->query_attack_power();
}
int get_add_att_pow(object o) {
	return get_wep_att_pow(o);
}
int get_att_pow(object o) {
	return get_pure_att_pow(o)+
		get_add_att_pow(o);
}
/////////////////////def_pow////////////////////////////////////
// B->def_pow=(B->l_wuxu*7+B->l_weapon*3)/50+C->def_pow
int get_pure_def_pow(object o) {
	string p_id, wep_type,wep_id;
	object wep,env;//added env by suicide in 20011230
	int sk_level,wep_level,h_level; //added h_level by suicide in 20011230
	if(!objectp(o)) return 0;
	sk_level=o->query_sk_level("sk_wuli");
	p_id=o->query_id()[0];
	if(CHAR_D->char_exist(p_id)&&
                CHAR_D->get_char(p_id,"type")==TYPE_NPC) {
		wep_level=sk_level;
        }
	else {
		wep=o->query_weapon();
		if(wep==o) // no weapon
		{
			wep_level=0; // will not support unarmed
		}
		else{
			wep_id=wep->query_id()[0];
			wep_type=OBJ_D->get_obj(wep_id,"sub_type");
			if(!wep_type) // not a legel weapon
				wep_level=0;
			else 
				wep_level=o->query_skill(wep_type);
		}
		//added by suicide in 20011230
		env=environment(o);
		if(env->is_horse()) {
			//h_level=o->query_sk_level("horse")+10;
			h_level=o->query_skill("horse")+10;
		}
		else {
			//h_level=o->query_sk_level("dodge");
			h_level=o->query_skill("dodge");
		}
                //added end
	}
	//return (sk_level*7+wep_level*3) / 25;
	return (sk_level*3+wep_level*3+h_level*4) / 25;
}
int get_clh_def_pow(object o) {
	object *obs;
	mixed stat;
	int ret=0;
	if(!objectp(o)) return 0;

	obs=all_inventory(o);
	if(!sizeof(obs)) return 0;
	foreach(object ob in obs){
        stat=ob->ob_state();
        if(stringp(stat)&&(ob->sg_obj()))
        {	ret+=ob->query_def_pow();
        }
	}
	return ret;
}
int get_add_def_pow(object o) {
	return get_clh_def_pow(o);
}
int get_def_pow(object o) {
	return get_pure_def_pow(o)+
		get_add_def_pow(o);
}

// this is decide if att can hit be or not for this round
// if hit it return 1, if not hit return 0 
// Pr(A|B)=1 if((random(2*N)-N)<(A->att_abi-B->def_abi)) ,else =0
// now we get N=20
int prb_hit(object a,object d){
	int a_abi,d_abi;
	int N=20;
	int ran;
	a_abi=get_att_abi(a);
	d_abi=get_att_abi(d);
	ran=random(2*N)-N;
	if(ran<(a_abi-d_abi)) return 1;
	return 0;
}

// the hurt point of one succ hit
// Ht(A|B)=random(N1)+N2*(A->att_pow-B->def_pow);
// N1=50,N2=2; (暂定)
// at least hit one point
int hurt_point(object a,object d) {
	int a_pow,d_pow;
	int N1=50,N2=2;
	int hurt;
	a_pow=get_att_pow(a);
	d_pow=get_def_pow(d);
	hurt=random(N1)+N2*(a_pow-d_pow);
	if(hurt<=0) hurt=1;
	return hurt;
}

// this is used to calculate how much of the reward for one hit
int reward(object a,object b)
{
	int a_level,b_level;
	a_level=a->get_att_abi();
	b_level=b->get_att_abi();
	return random(b_level-a_level+30)/5;
}