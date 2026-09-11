// m_charnpc.c by fire on 25 Jane 1998
// all (perhaps most) npc char or famous npc are copies of this
// file
#include <ansi.h>
#include <mudlib.h>
inherit MONSTER;
inherit M_CHAR;
inherit M_SMARTMOVE;
inherit __DIR__+"m_charnpc/m_charaction";
private string m_area;
void set_area(string s) {
   m_area=s;
}
string get_area() {
   return m_area;
}
void setup()
{
	move_setup();
	char_answer_setup();
      call_out("my_heart",random(10)+1);
}
string query_title(string p_id,string c_id)
{
	string ret;
	string p_tmp;
ret="";
       if(CHAR_D->get_char(p_id,"is_tmp"))
            return c_id+"("+p_id+")";
//        ret="【"+CHAR_D->get_char(p_id,"reputationstr")+NOR+"】";
	p_tmp=COUNTRY_D->get_country(CHAR_D->get_char(p_id,"nation"),"name");	
	if(p_tmp)
		ret+=p_tmp;
	p_tmp=OFFICER_D->query_rank_name(CHAR_D->get_char(p_id,"ranknation"));
	if(p_tmp!="━━")
	{
		ret+=p_tmp;
	}
	else
	{
		p_tmp=AREA_D->get_area(CHAR_D->get_char(p_id,"area"),"name");	
		if(p_tmp)
			ret+=p_tmp;
		p_tmp=OFFICER_D->query_rank_name(CHAR_D->get_char(p_id,"ranklocal"));
		if(p_tmp=="━━")
			p_tmp=" 隐士 ";//"隐居贤人";
		ret+=p_tmp;
	}
	ret+=c_id;
	p_tmp=CHAR_D->get_char(p_id,"zi");
	if(p_tmp)
		ret+="，字"+p_tmp;
	ret+="("+p_id+")";
	return ret;
}
// the following function will probably just be called by
// char_d.c so don't worry about the length of function
void npc_char_set_name
(string e_name,string c_name,mixed p_zi)
{
	string p_name1,p_name2;
	set_name(e_name,c_name);
	set_proper_name(c_name);
        set_in_room_desc(query_title(e_name,c_name));
	sscanf(e_name,"%s %s",p_name1,p_name2);
	add_id("npc"+p_name1+p_name2);
	if (stringp(p_zi))
	{
		set_sg_zi(p_zi);
	}
}
void npc_char_set_gift(mixed p_gift,mixed p_skills)
{
	string* slist;
	int i;
	init_sg_gifts(p_gift["wuli"],p_gift["zhimou"],p_gift["meili"]);
	slist=keys(p_skills);
	for(i=0;i<sizeof(slist);++i)
	{
		set_sg_skill(slist[i],p_skills[slist[i]],0);
	}
	set_sg_rongmao(p_gift["rongmao"]);
}
/*void npc_char_set_base1
(int p_gender,int p_age,int p_hp,int p_rongmao)
{
	set_gender(p_gender);
	set_age(p_age);
	if(!p_hp)
	{
		p_hp=500;
	}
	set_sg_max_hp(p_hp);
	set_cur_max_hp(p_hp);
	set_cur_hp(p_hp);
	if(!p_rongmao)
	{
		p_rongmao=15+random(15);
	} 
	set_sg_rongmao(p_rongmao);
}*/

/* void npc_char_set_base2
(mixed p_cloth,mixed p_weapon,mixed p_horse)
{	
	
	if(intp(p_horse)&&(p_horse==1)) // optional horse
		p_horse="fighthorse";
	if(stringp(p_horse))
	{	object m_horse;
		m_horse=new(PHORSE+p_horse);
		this_object()->move(m_horse);
	}
	if(intp(p_weapon)&&(p_weapon==1))
		p_weapon="blade/gangdao";
	if(stringp(p_weapon))
	{
		object m_weapon;
		m_weapon=new(PWEAPON+p_weapon);
		m_weapon->move(this_object());
		this_object()->do_wield(m_weapon);
	}
	if(!p_cloth)
		p_cloth=({"torso/buyi"});
	if(arrayp(p_cloth))
	{
		foreach(string s_cloth in p_cloth)
		{
			object m_cloth;
			m_cloth=new(PCLOTH+s_cloth);
			m_cloth->move(this_object());
			m_cloth->do_wear();
		}
	}
} */
/*void npc_char_birth
(int p_where,string p_area,string s_room,string p_message)
{
	string p_path;
	object p_room,env;
	
	switch (p_where)
	{
	case CERTAINROOM:
		break;
	case MEETINGROOM:
		break; // add code later
	case RANDOMROOM:
		break; // add code later
	case RANDOMAREA :
		break; // add code later
	}
	p_path=AREA_D->get_area(p_area,"path");
	p_room=load_object(p_area+s_room);
	env=environment();
	if(objectp(env)&&(env->is_horse()))
	{
		env->move(p_room);
		if(!p_message)
			p_message="$N骑着$o走了过来．\n";
		this_object()->target_action(p_message,env);
	}
	else
	{
		this_object()->move(p_room);
		if(!p_message)
			p_message="$N走了过来．\n";
		this_object()->simple_action(p_message);
	}
}*/
// this is used after all other initiate
void extra_init()
{
}
// this function is used to contral npc char from
// auto action for a certain time
int special_heart(int n)
{
	remove_call_out("my_heart");
	if(n<0) return n;
    call_out("my_heart",n);
	return n;
}