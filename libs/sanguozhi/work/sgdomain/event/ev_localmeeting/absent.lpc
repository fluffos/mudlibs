/* absent.c
   by fire on Aug 27,1998
   this is used to handle the absent chars */
mixed find_absent(int task_id)
{
	mapping m_chars;
	string *k_chars;
	string p_room;
	string p_leader;
	int i,sum;
	object o_id;
	mixed * p_ret=({});
	string p_id;
	m_chars=TASK_D->get_task(task_id,"chars");
	k_chars=keys(m_chars);
	sum=sizeof(k_chars);
	p_room=TASK_D->get_task(task_id,"room");
	for(i=0;i<sum;++i)
	{
		p_id=k_chars[i];
		o_id=CHAR_D->find_char(p_id);
		if(!objectp(o_id)) continue;
                if(file_name(o_id->query_room())!=p_room) {
                    p_ret-=({p_id});
                    p_ret+=({p_id});
 	        }
	}
	return p_ret;	
}
void begin_absent(int task_id,int p_type)
{
	string* m_absent;
	int i,sum;
	string p_area;
	string p_leader;
	string p_mess;
	string p_namelist="";
	string p_id;
	object o_leader;
	int p_reputation,p_loyalty;
	m_absent=find_absent(task_id);
	sum=sizeof(m_absent);
	if(!sum)
		return;
	p_area=TASK_D->get_task(task_id,"area");
	p_leader=AREA_D->get_area(p_area,"leader");
	for(i=0;i<sum;++i)
	{
		p_id=m_absent[i];
		if(i==0)
			p_namelist=CHAR_D->get_char(p_id,"name");
		else
			p_namelist+="，"+CHAR_D->get_char(p_id,"name");
			p_reputation=CHAR_D->get_char(p_id,"reputation");
			p_loyalty=CHAR_D->get_char(p_id,"loyalty");
			if(p_reputation>10000) p_reputation-=1000;
			else p_reputation=p_reputation*9/10;
			p_loyalty=p_loyalty*9/10;
			CHAR_D->set_char(p_id,"reputation",p_reputation);
            CHAR_D->set_char(p_id,"loyalty",p_loyalty);
	}
	o_leader=CHAR_D->find_char(p_leader);
        if(p_type)
	{
		if(objectp(o_leader))
                        o_leader->simple_action("$N深深地叹了口气道："+p_namelist+"又早早离会。\n");
		CHANNEL_D->deliver_tell("rumor","system",
			p_namelist+"提早退出地区会议，其声望与忠诚度下降。\n");
	}
	else
	{
		if(objectp(o_leader))
                        o_leader->simple_action("$N深深地叹了口气道："+p_namelist+"又未能按时出席会议。\n");
		CHANNEL_D->deliver_tell("rumor","system",
                        p_namelist+"未按时出席地区会议，其声望与忠诚度下降。\n");
	}
}
