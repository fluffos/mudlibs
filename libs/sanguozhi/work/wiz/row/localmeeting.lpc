// localmeeting.c 
// by fire on August 4, 1998
#include <localmeeting.h>
void start(string arg)
{
	string p_id,p_leader;
	string p_area;
	string p_room;
	mixed p_auth;
	int p_res;
	int m_auth=1;
	p_id=this_body()->query_id()[0];
	p_area=CHAR_D->get_char(p_id,"area");
	p_leader=AREA_D->get_area(p_area,"leader");
	if(p_id!=p_leader)  // not the leader
	{
		p_auth=CHAR_D->get_char(p_id,"auth");
		if(!p_auth)
			m_auth=0;
		else
		{
			if(!p_auth["localmeeting"])
				m_auth=0;
			else
			{
				if((p_auth["localmeeting"]["leader"]!=p_leader)||
				   (p_auth["localmeeting"]["area"]!=p_area))
					m_auth=0;
			}
		}
	}
	if(!m_auth)
	{
		write("只有地方首领和被授权的地方官才能下达此命令。\n");
		write("你也可以用ask <地方首领> about localmeeting 的方式申请召开地区会议。\n");
		return;
	}
	p_res=(EV_LOCALMEETING)->can_lmeeting(p_area);
	switch(p_res)
	{
        case LM_OK:
            (EV_LOCALMEETING)->local_meeting(p_area);
            return;
        case LM_OTHERTASK:
	    write("太守现在正忙着呢，分不开身。\n");
         return;
        case LM_ALREADYLOCALMEETING:
	    write("看来你是忙糊涂了，这不是正在商议本地区事务吗？\n");
         return;
        case LM_NOENOUTHCHAR :
	    write("总共没俩人，开什么会呀？！\n");
         return;
        case LM_TOOMANYABSENT:
          write("大家都太忙，看来会议只好改期了。\n");
         return;
        }
}
