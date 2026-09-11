// ev_addreputation.c
// by fire on July 26, 1998
// the officer and the local char's reputation
// will increase yearly
void addreputation()
{
        string *list;
        int p_lt,p_nt,p_ll,p_nl;
        int p_n;
        int p_time=time();
        mixed last;
        int m_time;
        object o;
        int min_time;
        int mid_time;
        min_time=time()-7*24*3600;
        mid_time=min_time-14*24*3600;
        list=CHAR_D->list_chars();
        foreach(string p_id in list)
        {
                if(CHAR_D->get_char(p_id,"type")==TYPE_NPC)
                {
                        p_lt=CHAR_D->get_char(p_id,"ranklocal");
                        p_nt=CHAR_D->get_char(p_id,"ranknation");
                        p_ll=OFFICER_D->query_level(p_lt);
                        p_nl=OFFICER_D->query_level(p_nt);
                        p_n=(p_ll>p_nl ? p_ll : p_nl);
                        p_n=pow(10,p_n);
                        if(p_n>10000)
                                p_n=10000;
                        p_n=p_n/20;
                        p_n=random(p_n)+1;
                        CHAR_D->set_char(p_id,"reputation",
                               CHAR_D->get_char(p_id,"reputation")+p_n);
                }
                else
                {
                  o=find_body(p_id);
                  if(!objectp(o)) // hehe
                  {
                        p_n=CHAR_D->get_char(p_id,"reputation");
                        last= LAST_LOGIN_D->query_last(p_id);
                        if(sizeof(last)==0)
                                p_time=0;
                        else
                                p_time=last[0];
                        if(p_time<mid_time) // offline for two week
                           p_n=to_int(p_n*0.99);
			else
			   if(p_time<min_time)
				p_n=to_int(p_n*0.999);			
                        CHAR_D->set_char(p_id,"reputation",p_n);
                                
    if((p_n==0)&&(p_time<mid_time)) // will leave
    {
	string p_le;
	p_le=AREA_D->get_area(CHAR_D->get_char(p_id,"area"),"leader");
        if((p_id!=p_le)&&(CHAR_D->get_char(p_id,"task")==0))
        {
           CHANNEL_D->deliver_tell("rumor","system",
             CHAR_D->get_char(p_id,"name")+"厌倦官场争斗，决定归隐山林。");  
	   CHAR_D->remove_char(p_id);
        }
    }
                  }
                }
        }
}
