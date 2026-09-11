//单挑

#include <mudlib.h>
#include <daemons.h>

string* p_input;
string* e_input;
object fighter1,fighter2;
string p_name,e_name,p_id,e_id;
int p_power,e_power;
int p_defen,e_defen;
int counter=0;

void input_way(string arg);
void input_way2(string arg);
int p_it,e_it;
int p_hp,e_hp;
void wait_result(int h);
int show_result(int p_ids,int e_ids,int k);

void main(string p_id,string e_id)
{	
	int i;

	p_name = CHAR_D->get_char(p_id,"name");
	e_name = CHAR_D->get_char(e_id,"name");
	p_it = TROOP_D->get_char_troop(p_id);
	e_it = TROOP_D->get_char_troop(e_id);
	fighter1 = find_user(p_id);
        fighter2 = find_user(e_id);
p_power=FIGHT_D->get_pure_att_pow(fighter1->query_body())+FIGHT_D->get_add_att_pow(fighter1->query_body());
e_power=FIGHT_D->get_pure_att_pow(fighter2->query_body())+FIGHT_D->get_add_att_pow(fighter2->query_body());
p_defen=FIGHT_D->get_pure_def_pow(fighter1->query_body())+FIGHT_D->get_add_def_pow(fighter1->query_body());	
e_defen=FIGHT_D->get_pure_def_pow(fighter2->query_body())+FIGHT_D->get_add_def_pow(fighter2->query_body());	

	WARAI_D->war_inf(TROOP_D->get_troops(p_it,"task_id"),
p_name+"与"+e_name+"开始单挑！","b");
	i = 1;
	p_hp=fighter1->query_body()->query_cur_hp();
	e_hp=fighter2->query_body()->query_cur_hp();	
		call_out ("wait_result",5,i);
		
return;
}


 		
void input_way(string arg)
{
	int num,i;

	if (!arg) {write("错误选择。请输入五次行动的命令。");
	return;}
	p_input = explode(arg,",");
	num = sizeof(p_input);
	if (num != 5)
	{write(
"错误选择。请输入五次行动的命令。(可选：au,am,ad,du,dm,dd；
举例：au,dd,ad,ad,dd)：");
	return;}
	for (i=0;i<5;i++)
	{ 
		if (p_input[i]!="au" && p_input[i]!="am" 
		&& p_input[i]!="ad" && p_input[i]!="du" &&p_input[i]!="dm"
		&& p_input[i]!="dd")

       {	write( 
"错误选择。请输入五次行动的命令。(可选：au,am,ad,du,dm,dd；
举例：au,dd,ad,ad,dd)：");
	return; 
	}
	}
        counter++;
	fighter1->modal_pop();
}

void input_way2(string arg)
{
        int num,i;
	
        if (!arg) {write("错误选择。请输入五次行动的命令。");
        return;}
	e_input = explode(arg,",");
        num = sizeof(e_input);
        if (num != 5)
        {write(
"错误选择。请输入五次行动的命令。(可选：au,am,ad,du,dm,dd；
举例：au,dd,ad,ad,dd)：");
	return;
	}
        for (i=0;i<5;i++)
        {
                if (e_input[i]!="au" && e_input[i]!="am"
                && e_input[i]!="ad" && e_input[i]!="du" &&e_input[i]!="dm"
		&& e_input[i]!="dd")
	
        {write(
"错误选择。请输入五次行动的命令。(可选：au,am,ad,du,dm,dd；
举例：au,dd,ad,ad,dd)：");
	return;
        }}
	counter =4;
        fighter2->modal_pop();
}

int show_result(int p_ids, int e_ids,int k)
{
	string i1,i2;
	int c1,c2;
	int j;
	int damage,hp;

	WARAI_D->war_inf(TROOP_D->get_troops(p_it,"task_id"),
p_name+"与"+e_name+"单挑第"+chinese_number(k)+"回合开始！","b");
for( j=0;j<5;j++)
{	
	i1 = p_input[j];		
	if (i1 == "au") c1 = 1;
	if (i1 == "am") c1 = 2;
	if (i1 == "ad") c1 = 3;
	if (i1 == "du") c1 = 8;
	if (i1 == "dm") c1 = 7;
	if (i1 == "dd") c1 = 6;
	i2 = e_input[j];
	if (i2 == "au") c2 = 1;
        if (i2 == "am") c2 = 2;
        if (i2 == "ad") c2 = 3;
        if (i2 == "du") c2 = 8;
        if (i2 == "dm") c2 = 7;
        if (i2 == "dd") c2 = 6;

tell_user("group",sprintf("%d%d%s%s",c1,c2,p_input[j],e_input[j]));
	if ((c1+c2) == 9)
	{
	  if (c1<c2)
	WARAI_D->war_inf(TROOP_D->get_troops(p_ids,"task_id"),
p_name+"攻向"+e_name+"一招但是被挡住了。","b");			
	if (c1>c2)
	WARAI_D->war_inf(TROOP_D->get_troops(p_ids,"task_id"),
e_name+"攻向"+p_name+"一招但是被挡住了。","b");	
	}
	
	else {
	if ((c1+c2)>=12)
	WARAI_D->war_inf(TROOP_D->get_troops(p_ids,"task_id"),
p_name+"和"+e_name+"俱守一招，各无损伤。","b");
	
	if ((c1+c2)>6 && (c1+c2)<12)
	{
	if (c1<c2 )
	{	WARAI_D->war_inf(TROOP_D->get_troops(p_ids,"task_id"),
p_name+"攻向"+e_name+"一招，"+e_name+"挡时却挡了个空。","b");
		
	    damage = p_power - e_defen;
	    if (damage <=0) damage = 1+random(2);
		e_hp= e_hp - damage;
		if (e_hp<0) e_hp =0;
		fighter2->query_body()->set_cur_hp(hp);
		
		WARAI_D->war_inf(TROOP_D->get_troops(p_ids,"task_id"),
e_name+"损血"+chinese_number(damage)+"点。","b");
			
		if (e_hp == 0)
		{WARAI_D->war_inf(TROOP_D->get_troops(p_ids,"task_id"),
p_name+"单挑击败"+e_name+"！","b");
		fighter1->query_body()->set_cur_hp(p_hp);
                fighter2->query_body()->set_cur_hp(e_hp);
			return 1;
		}
		}
	else 
        {       WARAI_D->war_inf(TROOP_D->get_troops(p_ids,"task_id"),
e_name+"攻向"+p_name+"一招，"+p_name+"挡时却挡了个空。","b");

            damage = e_power - p_defen;
            if (damage <=0) damage = 1+random(2);
                p_hp = p_hp - damage;
                if (p_hp<0) p_hp =0;

                WARAI_D->war_inf(TROOP_D->get_troops(p_ids,"task_id"),
p_name+"损血"+chinese_number(damage)+"点。","b");

                if (p_hp == 0)
                {WARAI_D->war_inf(TROOP_D->get_troops(p_ids,"task_id"),
e_name+"单挑击败"+p_name+"！","b");
                fighter1->query_body()->set_cur_hp(p_hp);
		fighter2->query_body()->set_cur_hp(e_hp);	        
		return 1;
                }
	
	}	
	}
	if ((c1+c2) <= 6)
	{ 
	WARAI_D->war_inf(TROOP_D->get_troops(p_ids,"task_id"),
p_name+"和"+e_name+"俱攻一招，各有损伤。","b");
	damage = p_power;
            if (damage <=0) damage = 1+random(2);
		e_hp = e_hp - damage;
                if (e_hp<0) e_hp =0;

                WARAI_D->war_inf(TROOP_D->get_troops(p_ids,"task_id"),
e_name+"损血"+chinese_number(damage)+"点。","b");	

	damage = e_power;
            if (damage <=0) damage = 1+random(2);
		p_hp = p_hp - damage; 
               if (p_hp<0) p_hp =0;

                WARAI_D->war_inf(TROOP_D->get_troops(p_ids,"task_id"),
p_name+"损血"+chinese_number(damage)+"点。","b");
 
	    if (p_hp== 0 && e_hp== 0)
	{	WARAI_D->war_inf(TROOP_D->get_troops(p_ids,"task_id"),
p_name+"和"+e_name+"两败俱伤，杀成平手。","b");
		fighter1->query_body()->set_cur_hp(p_hp);
                fighter2->query_body()->set_cur_hp(e_hp);
		return 1;
	}	
	else 
	{
		if (p_hp == 0)
                {WARAI_D->war_inf(TROOP_D->get_troops(p_ids,"task_id"),
e_name+"单挑击败"+p_name+"！","b");
                fighter1->query_body()->set_cur_hp(p_hp);
                fighter2->query_body()->set_cur_hp(e_hp);        
		return 1;
                }	
		if (e_hp == 0)
                {WARAI_D->war_inf(TROOP_D->get_troops(p_ids,"task_id"),
p_name+"单挑击败"+e_name+"！","b");
		fighter1->query_body()->set_cur_hp(p_hp);
                fighter2->query_body()->set_cur_hp(e_hp);
                        return 1;
                }
	}
	}

}
}
return 0;
}

void wait_result(int h)
{
	remove_call_out("wait_result");
	if (counter == 0)
        {counter ++;
	// set_this_player(fighter1); // set_this_player() unavailable in this driver build (no NO_ADD_ACTION) -- no-op'd, this_player() is whatever it naturally is here
	fighter1->modal_push((:
	input_way:),"请输入你的第"+chinese_number(h)+"回合选择：");
	}
	if (counter == 2)
	{	counter++;
		// set_this_player(fighter2); // set_this_player() unavailable in this driver build (no NO_ADD_ACTION) -- no-op'd, this_player() is whatever it naturally is here
           fighter2->modal_push((:
        input_way2:),"请输入你的第"+chinese_number(h)+"回合选择：");
	}
	if ( counter==4)
	{if (show_result(p_it,e_it,h))
		return;
		h++;
		counter =0;
	if (h==6)
	{	WARAI_D->war_inf(TROOP_D->get_troops(p_it,"task_id"),
p_name+"和"+e_name+"难分难解，杀成平手。","b");
		return;
	}
	}
	call_out("wait_result",3,h);	
	
}
