// M_sggift.c by fire on Dec 20 1997
#include <ansi.h>
#define MAXFOOD 200
#define MAXDRINK 200
#define HPTIME 20   // every 20 second reduce one food and drink
private string sg_zi;   // 字
private int sg_wuli;  // 武力 from 10 to 30 with special weapon can be higher
private int sg_zhimou;  // 智谋 as above this are orignal one, can't changed
private int sg_meili; // 魅力
private int sg_age; // 年龄;
private int sg_shouming; // 寿命 = max age over than that will die
private int sg_rongmao; // 容貌 from 10 to 30;
private int sg_cur_hp; //  if one is
private int sg_cur_max_hp; // from 100 and increase every year; before 30
                        // decrease after 50
private int sg_max_hp;  // the real max hp
private int sg_cur_mp;		// Flee add for 谋略 04121999
private int sg_cur_max_mp;
private int sg_max_mp;
private int sg_food;   // the food
private int sg_drink;  // the drink
nosave protected int last_hp_check;
#define SG_DEFAULT 20
#define SG_RANGE 6
int hp_check();
// other information
nomask void set_last_hp_check(int i)
{
	last_hp_check=i;
}
nomask void set_sg_rongmao(int p_rongmao)
{
	sg_rongmao=p_rongmao;
}
nomask int query_sg_rongmao()
{
	if(!sg_rongmao)
		sg_rongmao=random(21)+10;
	return sg_rongmao;
}
nomask void set_sg_zi(string p_zi)
{
	sg_zi=p_zi;
}
nomask string query_sg_zi()
{
	return sg_zi;
}
//*******************************************************
nomask void set_sg_food(int i)
{
	hp_check();
    	sg_food=bmin(MAXFOOD,i);
}
nomask void set_sg_drink(int i)
{
	hp_check();
    	sg_drink=bmin(MAXDRINK,i);
}
nomask void add_food(int i)
{	set_sg_food(i+sg_food);
}
nomask void add_drink(int i)
{
	set_sg_drink(i+sg_drink);
}
nomask int query_sg_food()
{
	hp_check();
	return sg_food;
}
nomask int query_sg_drink()
{
	hp_check();
	return sg_drink;
}
// 年龄 and 寿命*****************************************
nomask int query_age()
{
       return sg_age;
}
nomask int query_shouming()
{
        return sg_shouming;
}
void set_age(int i)
{
        sg_age=i;
}
void set_shouming(int i)
{
        sg_shouming=i;
}
// 健康 ****************************************************
int hp_check()
{
	int p_time=time();
	int time_last;
	int food_used,drink_used,heal_time;
   	int time_used;
   	if(!last_hp_check) last_hp_check=time();
	time_last=p_time-last_hp_check;
	if(time_last<HPTIME) return -1; // time to less
    	time_used=time_last/HPTIME;
	heal_time=time_used;
	if(objectp(this_object()->query_link()))
	{
		food_used=bmin(sg_food,time_used);
		drink_used=bmin(sg_drink,time_used);
		sg_food-=food_used;
		sg_drink-=drink_used;
		heal_time=bmin(food_used,drink_used);
	}
	sg_cur_max_hp+=heal_time;
	sg_cur_max_hp=bmin(sg_max_hp,sg_cur_max_hp);
	sg_cur_hp+=heal_time*sg_max_hp/10;
	sg_cur_hp=bmin(sg_cur_max_hp,sg_cur_hp);

	// this sentence is not very suitable
	// if a player check hp frequently
	// his cur_max_mp will not increase at all
	// because 1/3 and 2/3 both = 0 :)
	sg_cur_max_mp   = sg_cur_max_mp + to_int(heal_time/3);
    sg_cur_max_mp	= bmin(sg_max_mp,sg_cur_max_mp);
	// this got the samilar risk but a little less 
	// since sg_mak_hp is bigger than 100

// disable the mp automacally recover. so must sleep to get mp
// recovered.
//    sg_cur_mp       = sg_cur_mp + to_int(heal_time*sg_max_mp/10);
//    sg_cur_mp	= bmin(sg_cur_max_mp,sg_cur_mp);
	last_hp_check+=(time_used*HPTIME);
	return heal_time;
}
int query_cur_hp()
{
	hp_check();
    	return sg_cur_hp;       
}
int query_cur_mp()
{
    hp_check();
   	return sg_cur_mp;
}
int query_cur_max_hp()
{
	hp_check();
   	return sg_cur_max_hp;   
}
int query_cur_max_mp()
{
    hp_check();
   	return sg_cur_max_mp;
}
int query_sg_max_hp()
{
	hp_check();
   	return sg_max_hp;
}
int query_sg_max_mp()
{
     hp_check();
   	return sg_max_mp;
}
void set_cur_hp(int i)
{
	hp_check();
   	sg_cur_hp=i;
}
void set_cur_mp(int i)
{
    hp_check();
   	sg_cur_mp=i;
}
void set_cur_max_hp(int i)
{
	hp_check();
   	sg_cur_max_hp=i;
}
void set_cur_max_mp(int i)
{
    hp_check();
   	sg_cur_max_mp=i;
}
void set_sg_max_hp(int i)
{
	hp_check();
   	sg_max_hp=i;
}
void set_sg_max_mp(int i)
{
    hp_check();
   	sg_max_mp=i;
}
// gift *****************************************************
nomask int query_wuli_pure()
{
    return sg_wuli;
}
nomask int query_zhimou_pure()
{
    return sg_zhimou;
}
nomask int query_meili_pure()
{
    return sg_meili;
}
nomask void init_sg_gifts(int p_wuli,int p_zhimou,int p_meili)
{	// it's better to add some code here to monitor the illegal
	// gift setting but since careless restrict will usually introduce
	// bugs, so this work will be kept later.
    sg_wuli=p_wuli;
    sg_zhimou=p_zhimou;
   sg_meili=p_meili;
   this_object()->set_sg_skill("sk_wuli",p_wuli,0);
   this_object()->set_sg_skill("sk_zhimou",p_zhimou,0);
   this_object()->set_sg_skill("sk_meili",p_meili,0);

}
// used for hp system
//******************* RANK ****************
int query_is_junzhu()   // 是否君主
{
	string p_id;
	p_id=this_object()->query_id()[0];
	if(CHAR_D->get_char(p_id,"ranknation")==R_KING)
		return 1;
	return 0;
}
int query_is_jiangjun() // 是否将军
{
	string p_id;
	int p_rank;
	p_id=this_object()->query_id()[0];
	p_rank=CHAR_D->get_char(p_id,"ranknation");
    if((p_rank>1)&&(p_rank<100))
        return 1;
	p_rank=CHAR_D->get_char(p_id,"ranklocal");
        if((p_rank>1)&&(p_rank<100))
		return 1;
	return 0;
}
int query_is_guan() // 是否为官
{
	string p_id;
	int p_rank;
	p_id=this_object()->query_id()[0];
	p_rank=CHAR_D->get_char(p_id,"ranknation");
    if(p_rank>100)
        return 1;
	p_rank=CHAR_D->get_char(p_id,"ranklocal");
    if(p_rank>100)
		return 1;
	return 0;
}
mixed direct_hp_liv(object liv) 
{
	return 1;
}
mixed direct_follow_liv(object liv)
{
	return 1;
}
mixed direct_score_liv(object liv)
{
	return 1;
}
// This function is used to controlling the hp and mp
// of players and char npcs.
// Max hp depends on age and 武学修养.
// Max mp depends on age as well and 兵法修养.
// the hp part we use a daemon hp_d to handle
// now i think daemon is easier than the modules
void resign_status()
{
	int hp_bonus, mp_bonus;
	if( sg_age < 31 ){
//		hp_bonus = (sg_age - 14)*this_body()->query_wuli_pure();
		mp_bonus = (sg_age - 14)*this_body()->query_zhimou_pure();
	} else if ( sg_age < 51 ){
//	hp_bonus = 16*this_body()->query_wuli_pure();
	mp_bonus = 16*this_body()->query_zhimou_pure();
	} else {
//		hp_bonus = 16*this_body()->query_wuli_pure()-2*(sg_age-50);
		mp_bonus = 16*this_body()->query_zhimou_pure()-2*(sg_age-50);
	};
//	hp_bonus = hp_bonus + 10*this_body()->query_sk_level("sk_wuli");
	mp_bonus = mp_bonus + 10*this_body()->query_sk_level("sk_zhimou");
//	set_sg_max_hp( 100 + hp_bonus );
	set_sg_max_mp( 100 + mp_bonus );
}	

// this function is general used for setting players
// but careless designed npc will also get some information
// from here

nomask void init_hp()
{
	if(!sg_age)
		set_age(14);
	if(!sg_shouming)
		set_shouming(70+random(30));
	if(!sg_max_hp)
	{
	    set_sg_max_hp(100);
	    set_cur_max_hp(100);
		set_cur_hp(100);
	}
	if(!sg_max_mp)
	{
	    set_sg_max_mp(100);
	    set_cur_max_mp(100);
        set_cur_mp(100);
	}	
	if(!query_wuli_pure())
	{
		int p_wuli,p_zhimou,p_meili;
		p_wuli=15+random(10);
		p_zhimou=15+random(10);
		p_meili=60-p_wuli-p_zhimou;
		init_sg_gifts(p_wuli,p_zhimou,p_meili);
	}
	return;
}

int stop_heal()
{
   return remove_call_out("auto_heal");
}

