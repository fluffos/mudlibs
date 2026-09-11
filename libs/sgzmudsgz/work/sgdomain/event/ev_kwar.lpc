/* ev_kwar.c
   this is used to let an officer to get the war job from king
   by group on may, 31, 1999 */
mapping tmp=([]);
string p_id,p_area,p_nation,p_city;
int tmp_time=0;
object* p_list;
string* plist;
string*	pneighbor;
string* c_area;
int p_sum,p_sumb;
void job_done(string k_id,string k_city);

void remove_all();
int query_recall();
string query_name();
string set_name(string arg);
string set_city(string arg);
int query_city();
void auto_invite(string m_id, string m_city);
void set_count(int i);
void auto_run()

{	
	string mess, c_id;
	string m_id;
	int rep, repred;
	object usrs;	

	tmp_time++;
	remove_call_out("auto_run");
	if (tmp["name"]&&objectp(find_user(tmp["name"]))&&tmp["city"])
	{
	if(tmp_time <= 12)
	{
	tell_user(tmp["name"],"御前中郎将传来秘旨，你必须在"
+chinese_number((12-tmp_time)*5)+"小时内攻下"+AREA_D->get_area(tmp["city"],"name")
+"。\n");
	call_out("auto_run",18000);
	return;
	}
	else
	{	
		
		m_id=tmp["name"];
		rep=CHAR_D->get_char(m_id,"reputation");
	        repred=rep/10;
        	if (repred>15000)repred=15000;
		CHAR_D->set_char(m_id,"reputation",rep-repred);
		remove_all();
	mess=CHAR_D->get_char(m_id,"name")+"未完成献帝秘旨，声望降低"
+chinese_number(repred)+"点。";
		CHANNEL_D->deliver_tell("rumor","system",mess);
	call_out("auto_run",18000);
	return;
	}
}		
	else
	{	
 	  if (tmp_time < 24) 
	{	call_out("auto_run",18000);
		return;
	} 
	else {
	tmp_time = 0;

	p_list=users();
	plist=users()->query_body()->query_primary_id();
	plist=filter_array(plist,
(:  (CHAR_D->get_char($1,"ranknation")== R_KING) :) );
        p_sum=sizeof(plist);
// we need to test if tmp["name"]= 0 or not
// if a ppl just at the login status, the
// find_user(0) will return an object commented by fire
               if (tmp["name"]&&objectp(find_user(tmp["name"])))
			c_id=tmp["name"];
        else {
		if(!p_sum)
                return;
	c_id=plist[random(sizeof(plist))];
	  	
// need to check if this user has a body, if just in connect
// situation, then it will not have a body. so need check
// and if it doesn't have a body, need change tmp_time back
// so can have next selection. same as when call the wizard
                if(!objectp(find_user(c_id)) || wizardp(find_body(c_id))) 
                {     
		      tmp=([]);		
                      tmp_time=1500;
                      call_out("auto_run",2);
		      return ;
                }
	
	tmp["name"]=c_id;
	
	c_area = AREA_D->check_area(); 	
	p_nation=CHAR_D->get_char(c_id,"nation");
	c_area= filter_array(c_area,
(:  (AREA_D->get_area($1,"nation")== p_nation) :) );

	foreach(p_area in c_area)
	{	
	pneighbor=AREA_D->get_area(p_area,"neighbor");
	if (!sizeof(pneighbor))
		continue;
	
	pneighbor=filter_array(pneighbor,
(:  (AREA_D->get_area($1,"nation")!= p_nation) :) );
	p_sumb=sizeof(pneighbor);
	if(!p_sumb)
	continue;
	else
	{ 
	p_city=pneighbor[random(sizeof(pneighbor))];
	tmp["city"]=p_city;
	auto_invite(c_id,p_city);
	call_out("auto_run",18000);
	return;
	}
}	
}
}
}
call_out("auto_run",18000);
return;
}

void auto_invite(string m_id,string m_city)
{
	string mess, mess1;
	int p_testtimes=5;
	int p_loyalty;
	int i;
	string p_nationname;
	
	p_id=m_id;
	p_city=m_city;
	p_nationname=COUNTRY_D->get_country(CHAR_D->get_char(p_id,"nation"),"name");
        if (p_nationname==0)p_nationname="城守";
	mess=sprintf("献帝忽有所思，下旨诏见%s。\n",
	CHAR_D->get_char(p_id,"name"),);
        mess1="御前中郎将高声宣道：皇上有旨，"
+p_nationname+CHAR_D->get_char(p_id,"name")+"速来晋见！ \n";
	CHANNEL_D->deliver_tell("rumor","system",mess);
	CHANNEL_D->deliver_tell("rumor","system",mess1);

}

string query_name()
{
	return tmp["name"];
}

void remove_all()
{
	tmp=([]);
}

int query_city()
{
	return tmp["city"];
}

string set_name(string arg)
{
	if( !objectp(find_user(arg)) ) return "";
	tmp["name"]=arg;
	return tmp["name"];
}
string set_city(string arg)
{
        if( !AREA_D->get_area(arg,"") ) return "";
        tmp["city"]=arg;
        return tmp["city"];
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
	auto_run();
}
void job_done(string k_id, string k_city)
{	
	string mess,mess1,t_id;
	int rep,repred,money,t_gold;
	
if(CHAR_D->get_char(k_id,"nation") ==tmp["name"] && k_city == tmp["city"])
{		t_id=tmp["name"];
                rep=CHAR_D->get_char(t_id,"reputation");
                repred=rep/10;
                if (repred>30000)repred=30000;
                CHAR_D->set_char(t_id,"reputation",rep+repred);
        mess=CHAR_D->get_char(t_id,"name")+"完成献帝秘旨，喜获声望"
+chinese_number(repred)+"点。";
		money=CHAR_D->get_char(t_id,"gold");		                
		t_gold=300+random(300);
		CHAR_D->set_char(t_id,"gold", money+t_gold);
	mess1=CHAR_D->get_char(t_id,"name")+"完成献帝秘旨，受赏黄金"
+chinese_number(t_gold)+"两。";
 	CHANNEL_D->deliver_tell("rumor","system",mess);
	CHANNEL_D->deliver_tell("rumor","system",mess1);
	remove_all();
}
        return;
}
