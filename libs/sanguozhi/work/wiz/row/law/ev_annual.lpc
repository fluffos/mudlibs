/* ev_annual.c
   this is used to let the emperor to hold annual meeting every 2 sanguo year.
   by row on Feb, 2000 */
mapping tmp=([]);
string p_id;
int tmp_time=0;
object* p_list;
int p_sum;
int wait_time;
private mapping ministers;

void remove_name();
int query_recall();
string query_name();
string set_name(string arg);
int query_time();
void auto_holdmeeting();
void auto_check();
void auto_run();
void set_count(int i);
void recall();
void select_member();

void select_member()
{
    int i, j, r1, r2, a1, a2;
    string s, s1, *ss, *ppl;
	mixed * *rank=OFFICER_D->query_nation_officer_title_all(1)-({1,10,11});

    ppl = filter_array(CHAR_D->list_chars(), (: CHAR_D->get_char($1,"ranknation")
	&&CHAR_D->get_char($1, "type")==1 :));

    for(i=0; i<sizeof(ppl)-1; i++){
        s = ppl[i];
        ss= ppl[i+1..];
        for(j=0; j<sizeof(ss); j++ ){
            s1 = ss[j];
            r1 = OFFICER_D->query_level(CHAR_D->get_char(s,"ranknation"));
            r2 = OFFICER_D->query_level(CHAR_D->get_char(s1,"ranknation"));
            a1 = CHAR_D->get_char(s,"literate");
	    a2 = CHAR_D->get_char(s1,"literate");
            if( r1<r2 || (r1==r2&&a1<a2) ) {
		ppl[i] = s1;
                ppl[i+1+j] = s;
                s = s1;
	    }
	}
    }
    ppl = filter_array(ppl, (: !wizardp($1) :));
    if ( sizeof(ppl)<10 ) return 0;
    ppl = ppl[0..9];

//SGSYS(sprintf("list is %O\n", ppl));

	foreach (string o in ppl ) {
       int r;
       r=rank[random(sizeof(rank))];
       rank-=({r});
       CHAR_D->set_char(o,"royalrank",r);
       CHAR_D->set_char(o,"is_jury",1);                
}
//SGSYS(sprintf("rest rank is %O\n", rank));

	tell(users(),"%^H_YELLOW%^【东汉宫廷】%^H_RED%^国舅%^H_CYAN%^董承：吾皇万岁万万岁，臣有一本，启奏陛下。%^RESET%^\n");
	tell(users(),"%^H_YELLOW%^【东汉宫廷】%^H_CYAN%^汉献帝：念。%^RESET%^\n");
	tell(users(),"%^H_YELLOW%^【东汉宫廷】%^H_RED%^国舅%^H_CYAN%^董承：是。%^RESET%^\n");
	tell(users(),"%^H_YELLOW%^【东汉宫廷】%^H_RED%^国舅%^H_CYAN%^董承：孝灵皇帝，早弃臣民，皇帝承嗣，海内仰望。而帝年少，威仪\n"+
	             "                      不恪，难免居丧慢惰。宜择良臣，为其锦囊，辅佐朝纲，应天\n"+
	             "                      顺人，以慰生灵之望。%^RESET%^\n");
	tell(users(),"%^H_YELLOW%^【东汉宫廷】%^H_CYAN%^汉献帝羞得满脸通红，恨不得找个地缝钻进去。%^RESET%^\n");
	tell(users(),"%^H_YELLOW%^【东汉宫廷】%^H_CYAN%^汉献帝：善，如此寡人便降一诏，国舅代为宣读罢。%^RESET%^\n");
	tell(users(),"\n%^H_YELLOW%^【东汉宫廷】%^H_CYAN%^片刻后。。。%^RESET%^\n\n");
	tell(users(),"%^H_YELLOW%^【东汉宫廷】%^H_RED%^国舅%^H_CYAN%^董承：奉天承运，皇帝诏曰。寡人顺应天命，择良臣而为肱股，众卿\n"+
	             "                      听封：%^RESET%^\n\n");
	foreach (string o in ppl ) {
	tell(users(),"                      %^H_CYAN%^赐  %^H_GREEN%^"+CHAR_D->get_char(o,"name")+"%^H_CYAN%^君  %^H_YELLOW%^"+OFFICER_D->query_rank_name(CHAR_D->get_char(o,"royalrank"))+"%^H_CYAN%^一职；%^RESET%^\n");
	}
	tell(users(),"\n                      %^H_CYAN%^还望众卿重振汉室洪业，为万世统！%^RESET%^\n");
	tell(users(),"                                                                  %^H_CYAN%^卿此。%^RESET%^\n");
	return;
}

void auto_check()
{       
        string mess, c_id;
        string m_id;
        int rep, repred;
        object usrs;    

        tmp_time++;
        if (tmp["name"]&&objectp(find_user(tmp["name"]))){
		if(tmp_time == 6 ||tmp_time== 12 ||tmp_time== 18 ||tmp_time==24)
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
		}
	}
        else 
	{       if( tmp_time > wait_time ){
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
                
//        	auto_invite(c_id);
        
		}       
	}
	return;

}
void auto_holdmeeting()
{
	tell(users(),"%^H_YELLOW%^【东汉宫廷】%^H_RED%^国舅%^H_CYAN%^董承：陛下，时辰已到，两年一度的宫廷集会就要开始了。%^RESET%^\n");
	tell(users(),"%^H_YELLOW%^【东汉宫廷】%^H_CYAN%^汉献帝：嗯，宣众卿于温德殿等候，由国舅爷代为主持罢。%^RESET%^\n");
	tell(users(),"%^H_YELLOW%^【东汉宫廷】%^H_RED%^国舅%^H_CYAN%^董承：是，陛下。%^RESET%^\n\n");
	tell(users(),"%^H_YELLOW%^【东汉宫廷】御前中郎将%^RESET%^%^H_CYAN%^高声宣道：受封诸侯即刻入宫晋见皇上！%^RESET%^\n");
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
