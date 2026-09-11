/* ev_king.c
   this is used to let an officer to see king
   by group on may,25, 1999 */
mapping tmp=([]);
string p_id;
int tmp_time=0;
object* p_list;
int p_sum;
int wait_time;

void remove_name();
int query_recall();
string query_name();
string set_name(string arg);
int query_time();
void auto_invite(string m_id);
void set_count(int i);
void recall();

void auto_run()
{       
        string mess, c_id;
        string m_id;
        int rep, repred;
        object usrs;    

        tmp_time++;
        if (tmp["name"]&&objectp(find_user(tmp["name"]))){
		/*if(tmp_time == 6 ||tmp_time== 12 ||tmp_time== 18 ||tmp_time==24)
		{       mess="御前中郎将高声宣道："
			+CHAR_D->get_char(tmp["name"],"name")+"勿让陛下久候，速来晋见！ \n";
		        CHANNEL_D->deliver_tell("rumor","system",mess);    
		        return;
		}
	    else 
		{
		       if ( tmp_time > 36 )
		        {	if( sizeof(tmp) )
			        {       m_id=tmp["name"];
			                rep=CHAR_D->get_char(m_id,"reputation");
			                repred=rep/20;
			                if (repred>15000)repred=15000;
			                CHAR_D->set_char(m_id,"reputation",rep-repred);
			                remove_name();
			                mess=CHAR_D->get_char(m_id,"name")+"受召不至，声望降低"
					+chinese_number(repred)+"点。";
			                CHANNEL_D->deliver_tell("rumor","system",mess);                         
			        }
			}
		}*/
		}
        else 
		{   if( tmp_time > wait_time ){
        	    tmp_time = 0;
				p_list=users();
				p_sum=sizeof(p_list);
// we need to test if tmp["name"]= 0 or not
// if a ppl just at the login status, the
// find_user(0) will return an object commented by fire
	            if (tmp["name"]&&objectp(find_user(tmp["name"])))
					c_id=tmp["name"];
        
        		else {
		            if(!p_sum)
			            return;
					usrs=p_list[random(sizeof(p_list))];
// need to check if this user has a body, if just in connect
// situation, then it will not have a body. so need check
// and if it doesn't have a body, need change tmp_time back
// so can have next selection. same as when call the wizard
		                if(!objectp(usrs->query_body()) || wizardp(usrs)) 
                		{     
		                      tmp=([]);         
                		      tmp_time=1500;
		                      return ;
                		}
			        c_id=usrs->query_body()->query_primary_id();
			        if (!CHAR_D->char_exist(c_id))
			        {             tmp=([]);
		                      tmp_time=1500;
                		      return ;
			        }
			        if (CHAR_D->get_char(c_id,"task"))
			        {             tmp=([]);
                			      tmp_time=1500;
		        	              return ;
	                	}

		         }
        
// if have task 

	        tmp["name"]=c_id;
                
        	auto_invite(c_id);
        
		}       
	}
	return;

}
void auto_invite(string m_id)
{
        string mess, mess1;
        string p_nation;
        
        p_id=m_id;
        p_nation=COUNTRY_D->get_country(CHAR_D->get_char(p_id,"nation"),"name");
        if (p_nation==0)p_nation="流浪的贤人";
        mess=sprintf("献帝今日龙颜大悦，下旨诏见%s。\n",
        CHAR_D->get_char(p_id,"name"),);
        mess1="御前中郎将高声宣道：皇上有旨，"
+p_nation+CHAR_D->get_char(p_id,"name")+"速来晋见！ \n";
        CHANNEL_D->deliver_tell("rumor","system",mess);
        CHANNEL_D->deliver_tell("rumor","system",mess1);
        tmp["time"] = time();                   
	wait_time=30+random(20);
}

string query_name()
{
        return tmp["name"];
}

void remove_name()
{
        tmp=([]);
}

int query_time()
{
        return tmp["time"];
}

string set_name(string arg)
{
        if(!objectp(find_user(arg))) return "";
        tmp["name"]=arg;
        return tmp["name"];
}

int query_recall()
{
        return tmp_time;
}
void set_count(int k)
{
        tmp_time = k;
}
void recall()
{
//        remove_call_out("recall");
        auto_run();
//        call_out("recall",5);
}
