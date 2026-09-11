// char_obj.c
// by fire on Dec 1998
#include <char.h>
void put_on_cloth(string c_id);
void put_on_npc_cloth(string c_id);
mixed creat_row_npc_char(string c_id) {
	object o_char;
    mixed c;
	string m_body;
    c=get_char(c_id,"");
    m_body=CHAR_D->get_char(c_id,"body");
    if(!stringp(m_body))
       o_char=new(PMODULES+"m_charnpc");
    else
       o_char=new(PMODULES+"m_charnpc/"+m_body);
    o_char->npc_char_set_name(c_id,c["name"],c["zi"]);
/*    o_char->npc_char_set_base1(c["gender"]
      ,c["age"],c["skills"]["sk_wuli"]*30,
       c["gift"]["rongmao"]); */
	o_char->set_gender(c["gender"]);
	o_char->set_age(c["age"]);

   o_char->npc_char_set_gift(c["gift"],c["skills"]);
   HP_D->set_max_hp(o_char);
   o_char->extra_init(); // this is after all the initiate
   return o_char;

}
mixed creat_npc_char(string c_id)
{	int hp;
	object o_char;
	o_char=creat_row_npc_char(c_id);
	hp=o_char->query_sg_max_hp();
	o_char->set_cur_max_hp(hp);
	o_char->set_cur_hp(hp);
   put_on_cloth(c_id);
   return o_char;
}
mixed find_npc_char(string c_id)
{
    object* o_list;
    int i,sum;
    string m_body,*id_list;
    m_body=CHAR_D->get_char(c_id,"body");

/*    if(!stringp(m_body))
        o_list=children(PMODULES+"m_charnpc")-
           ({load_object(PMODULES+"m_charnpc")});
    else
        o_list=children(PMODULES+"m_charnpc/"+m_body)-
           ({load_object(PMODULES+"m_charnpc/"+m_body)}); */
    if(!stringp(m_body))
        o_list=children(PMODULES+"m_charnpc")-({load_object(PMODULES+"m_charnpc")});
    else
        o_list=children(PMODULES+"m_charnpc/"+m_body)-
		({load_object(PMODULES+"m_charnpc/"+m_body)});
    if(!sizeof(o_list)) return 0;

    o_list=filter_array(o_list,(: $1->query_primary_id()==$(c_id) :));
	if(!sizeof(o_list)) return 0;
//    i=member_array(c_id,id_list);
//    if(i==-1) return 0;
    if(sizeof(o_list)>1) {
		SGSYS(c_id + "有多份NPC COPY。");
	}

    return o_list[0];
}
mixed find_char(string c_id)
{
     if(!char_exist(c_id))
           return 0;
     if(get_char(c_id,"status")!=STATUS_ONLINE)
         return find_npc_char(c_id);
     return find_body(c_id);
}
// this is the only way to make a npc_char alive
// and please make sure that it is the call program'
// responsibility to add other behavier for the char
int put_npc_char(string c_id,string r_id)
{
    mixed o_id;
    object o_room;
    set_char(c_id,"room",r_id);
    set_char(c_id,"status",STATUS_ACTIVE);
    if(sizeof(children(r_id)))
    {
        o_room=load_object(r_id);
        if(!objectp(o_room))
            return PC_NOSUCHROOM;
        o_id=find_char(c_id);
        if(!objectp(o_id))
            o_id=creat_npc_char(c_id);
        if(objectp(o_id))
        {   o_id->move(o_room);
            return PC_SUCCESSFUL;
        }
     }
     else
     {   o_id=find_char(c_id); // this should happen just whensomething wrong
         if(objectp(o_id))
               o_id->remove();
     }
     return PC_NOSUCHROOM; // this is not an error
}
int put_ply_char(string c_id,string r_id)
{  mixed o_id;
   object o_room;
   set_char(c_id,"room",r_id);
   o_room=load_object(r_id);
   if(!objectp(o_room))
      return PC_NOSUCHROOM;
   o_id=find_char(c_id);
   if(!objectp(o_id)) // shoud be inpossible
        o_id=creat_npc_char(c_id);
   if(objectp(o_id))
   {   o_id->move(o_room);
       return PC_SUCCESSFUL;
   }
}
int put_char(string c_id,string r_id)
{  if(!char_exist(c_id))
       return PC_NOSUCHCHAR;
   if(get_char(c_id,"status")!=STATUS_ONLINE)
       return put_npc_char(c_id,r_id);
   else
       return put_ply_char(c_id,r_id);
}
void add_char_wear(string p_id,string item)
{
	mixed m_wear;
	string typ,sub_typ;
	m_wear=CHAR_D->get_char(p_id,"wear");
	if(!m_wear) m_wear=([]);
	typ=OBJ_D->get_obj(item,"type");
	sub_typ=OBJ_D->get_obj(item,"sub_type");
	if(!typ) return ; //impossible
	if(typ=="cloth")
		m_wear[sub_typ]=item;
	else
		m_wear[typ]=item;
	CHAR_D->set_char(p_id,"wear",m_wear);
	return;
}

void put_on_cloth(string c_id){
	object o,p;
	int l_n,l_l,m_l;
	mixed m_wear;
	string *cc,*cd;

	o=CHAR_D->find_char(c_id);
	if(!objectp(o)) return;
	if((CHAR_D->get_char(c_id,"type"))==TYPE_NPC){
		put_on_npc_cloth(c_id);
		return;
	}
	m_wear=CHAR_D->get_char(c_id,"wear");
	if(sizeof(m_wear))
	{
		string *ks;
		ks=keys(m_wear);
		foreach(string k in ks){
			p=present(m_wear[k]+" obj",o);
			if(!objectp(p))
				p=OBJ_D->clone_obj(m_wear[k]);
			if(objectp(p)){
				p->set_can_sell("自己专用的东西不能卖。\n");
				p->set_can_drop("自己专用的东西不能丢。\n");
				p->set_can_give("自己专用的东西不能给人。\n");
				p->set_owner(c_id);
				switch(OBJ_D->get_obj(m_wear[k],"type"))
				{
				case "cloth":
					p->move(o);
					p->do_wear();
					p->set_owner(c_id);
					if(environment(p)!=o)
						p->remove();
					break;
				case "weapon":
					p->move(o);
					o->do_wield(p);
					p->set_owner(c_id);
					if(environment(p)!=o)
						p->remove();
					break;
				case "horse":
					p->remove();
					break;

				}
			}

		}
	}
}
void auto_on_cloth(string typ,string p_id) {
	mixed m_wear;
	string *cc,*cd,m_weapon_type,o_id;
	int l_n,l_l,m_l;
	object o,p;
	o=CHAR_D->find_char(p_id);
	if(!objectp(o)) return;
	l_n=OFFICER_D->query_level(CHAR_D->get_char(p_id,"ranknation"));
	l_l=OFFICER_D->query_level(CHAR_D->get_char(p_id,"ranklocal"));
	m_l=bmax(l_n,l_l);
	m_l=(m_l+1)/2;

	m_wear=CHAR_D->get_char(p_id,"wear");
	if(!m_wear) m_wear=([]);
	if(!m_wear[typ]) {
		if(typ=="weapon") {
			cc=OBJ_D->check_obj_type("level",m_l,"weapon");
			m_weapon_type=CHAR_D->get_char(p_id,"weapon_type");
			if(m_weapon_type)
				cd=filter_array(cc,(: OBJ_D->get_obj($1,"sub_type")==$(m_weapon_type) :));
			else
				cd=cc;
		}
		else {
			cc=OBJ_D->check_obj_type("level",m_l,"cloth");
			cd=filter_array(cc,(: OBJ_D->get_obj($1,"sub_type")==$(typ):));
		}
		if(sizeof(cd))
		{	o_id=cd[random(sizeof(cd))];
		}
	}
	else
		o_id=m_wear[typ];
	if(o_id) {
		p=OBJ_D->clone_obj(o_id);
		if(objectp(p)){
			p->move(o);
			if(typ=="weapon")
				o->do_wield(p);
			else
				p->do_wear();
		}
	}
	return;
}
void put_on_npc_cloth(string c_id) {

	if(CHAR_D->get_char(c_id,"is_tmp")) return;
	auto_on_cloth("armors",c_id);
	auto_on_cloth("torso",c_id);
	auto_on_cloth("feet",c_id);
	auto_on_cloth("head",c_id);
	auto_on_cloth("weapon",c_id);

}
//:FUNCTION refresh_body 
// parameter the id of the char
// this function is used to refresh the appearance of a non-on line char
// when some thing happened for example the area or a char changed
// we use this function to adjust the appearance.
mixed refresh_body(string p_id) {
	object o,env;
	string f_name;
	if(!CHAR_D->char_exist(p_id)) return "no such char\n";
	o=CHAR_D->find_char(p_id);
	if(!objectp(o)) return "now sleeping.\n";
	if(o->query_link()) return "it is a player\n";
	env=environment(o);
	if(!objectp(env)) return "no environemnt.\n";
	f_name=file_name(env);
	CHAR_D->remove_npc_char(p_id);
	CHAR_D->put_char(p_id,f_name);
	return 1;
}