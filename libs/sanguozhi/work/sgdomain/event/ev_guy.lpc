// this is used to handle guys appear
// appear.c
// by fire on Dec 1998
//modified by Listen to setup fake guys
nosave protected string *legalset=({"boy","guy","resident","idler"});
nosave protected int s_id;
void create_boy(string p_area);
void check_boy();

string get_type()
{
   int i=random(3);
   switch(i)
   {
      case 0 : return "guy";
      case 1 : return "resident";
      default : return "idler" ;
   }
}

mixed * get_array_type()
{
   int i=random(3);
   switch(i)
   {
   	case 0: return ({"guy","resident","idler"});
        case 1: return ({"resident","idler","guy"});
	default: return ({"idler","guy","resident"});
    }
}

string get_type_name(string p_type)
{
   switch(p_type)
   {
      case "guy": return "小伙";
      case "resident": return "居民";
      case "idler" : return "闲人";
      default : return "游民";
   }
}
int create_guy(string p_area,string p_type)
{
   string p_id; 
   object o;

   p_id=p_area+" "+p_type;
	//tell_user("huaer",sprintf("进了create_guy(),p_area = %s, p_type = %s\n",p_area,p_type));
	if(objectp(o=CHAR_D->find_npc_char(p_id)))
	{
		//tell_user("huaer","guy已经存在了\n");
		if (o->query("is_fake")) // a fake guy exist
			return 0; //fail to creat
		else
			return 1; //exist already
   	}
		   
   CHAR_D->add_char(p_id);
   CHAR_D->set_char(p_id,"name",
   AREA_D->get_area(p_area,"name")+get_type_name(p_type));
   CHAR_D->set_char(p_id,"is_tmp",1);
   CHAR_D->set_char(p_id,"is_guy",1);
   CHAR_D->set_char(p_id,"body","guy");

   CHAR_D->appear(p_id,p_area,"","一群$N吵吵闹闹地走了过来。\n");
   o=CHAR_D->find_npc_char(p_id);
   if(objectp(o)) 
   {
		o->set_area(p_area);
		o->set("is_fake",0);
		//tell_user("huaer",sprintf("在%s建立了一群guy\n",p_area));
   }
   CHAR_D->remove_char_d(p_id);
   return 1;
}


int create_fake_guy(string p_area,string p_room,string m_id)
{
   string p_id;
   mixed * p_type=get_array_type();
   object o;

   for(int i=0;i<3;i++)
   {
	p_id=p_area+" "+p_type[i];
	o=CHAR_D->find_npc_char(p_id);
	if (objectp(o)) //the body is exist
	{
      	   if (o->query("is_fake")) //if the existing is a fake ppl
		continue; //fail to creat
	   else if (o->query("is_locked")) //in case another player has job on it
		continue;
	   else
	   {
	   	o->move(p_room);
	   	DELAY_D->delay_simple_action(o,"一群$N吵吵闹闹地走了过来。\n");
	   	o->set_area(p_area);
		o->set("is_fake",1);
		o->set("master",m_id);
	   	return 1;
	   }
	
	}

//now to creat a new fake guy
	CHAR_D->add_char(p_id);
	CHAR_D->set_char(p_id,"name",
		AREA_D->get_area(p_area,"name")+get_type_name(p_type[i]));
	CHAR_D->set_char(p_id,"is_tmp",1);
	CHAR_D->set_char(p_id,"is_guy",1);
	CHAR_D->set_char(p_id,"body","guy");
	CHAR_D->put_char(p_id,p_room);
   	o=CHAR_D->find_char(p_id);
	if(objectp(o))
	{
		DELAY_D->delay_simple_action(o,"一群$N吵吵闹闹地走了过来。\n");
   		o->set_area(p_area);
		o->set("is_fake",1);
		o->set("master",m_id);//tell who set the ppl
		CHAR_D->remove_char_d(p_id);
		return 1;//return success notice
	}
        else
		LISBUG("ERROR: can't find char of " + p_id +" after appear");
   }
   return 0;
//return fail notice

}
object create_ppl(string p_area) {
	string p_id;
	int p_level;
	object o;
	p_level=AREA_D->get_area(p_area,"level");
	p_level=random(p_level);
	p_id=p_area+" ppl"+p_level;	
	if(objectp(CHAR_D->find_npc_char(p_id)))
		return CHAR_D->find_npc_char(p_id);
	
	CHAR_D->add_char(p_id);
   	CHAR_D->set_char(p_id,"name","nothing");
   	CHAR_D->set_char(p_id,"is_tmp",1);
   	CHAR_D->set_char(p_id,"is_ppl",1);
   	CHAR_D->set_char(p_id,"body","ppl/ppl");
	CHAR_D->set_char(p_id,"no_extra",1);

   	CHAR_D->appear(p_id,p_area,"","$N走了过来。\n");
	o=CHAR_D->find_npc_char(p_id);
   	CHAR_D->remove_char_d(p_id);
	return o;
}

string aut_appear()
{
   
   string p_area;
   int i;
     for(i=0;i<4;++i)
     {
	     p_area=AREA_D->pick_area();
	     create_guy(p_area,get_type());
	     create_ppl(p_area);
     }
	call_out("check_boy",5);
   return p_area;
}

void create_boy(string p_area)
{
   string p_id; 
   object o;

   p_id=p_area+" "+"boy";
   CHAR_D->add_char(p_id);
   CHAR_D->set_char(p_id,"my_area",p_area);
   CHAR_D->set_char(p_id,"name","调皮小男孩");
   CHAR_D->set_char(p_id,"is_tmp",1);
   CHAR_D->set_char(p_id,"is_boy",1);
   CHAR_D->set_char(p_id,"body","boy");
   CHAR_D->set_char(p_id,"age",10);
   CHAR_D->appear(p_id,p_area,"","一个$N蹦蹦跳跳地跑了过来。\n");
   o=CHAR_D->find_npc_char(p_id);
   if(objectp(o)) {
     o->set_area(p_area);
     CHAR_D->remove_char_d(p_id);
   }
   else {
       CHAR_D->remove_char(p_id);
   }
}

void check_boy() 
{
	int i;	
	string a_id;
	for(i=0;i<30;++i) {
		a_id=AREA_D->list_areas_id(s_id);
		if(!a_id) { s_id=0; continue;}
		s_id++;
		if(!objectp(CHAR_D->find_npc_char(a_id+" boy"))) 
		        create_boy(a_id);   // once just create one boy
	}
}

mixed perse_guyid(string str) {
	string a_id, g_type;
	int n;
	n=sscanf(str,"%s %s",a_id,g_type);
	if(n!=2) return 0;
	if(!AREA_D->area_exist(a_id)) return 0;
	if(member_array(g_type,legalset)==-1) return 0;
	return ({a_id,g_type});
}
/*
mixed get_guy(string str) {
	string a_id,g_type;
	mixed ret;
	ret=perse_guyid(str);
	if(!mapp(ret)) return;
	a_id=ret[0];
	g_type=ret[1];
	switch(g_type) {
		
	}
}
*/