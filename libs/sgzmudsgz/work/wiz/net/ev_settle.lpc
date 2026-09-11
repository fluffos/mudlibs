// ev_settle.c
// by fire on July 21, 1998
#define S_ACCEPT 1
#define S_ALREADY -1
#define S_OTHERCOUNTRY -2
#define S_OFFICERALREADY -3

void create()
{
}
int check_settle(object who,string a_id)
{
	string y_id;
	string oa_id;
	y_id=(who->query_id())[0];
	if(!(CHAR_D->char_exist(y_id)))
		return S_ACCEPT;
	oa_id=CHAR_D->get_char(y_id,"area");
	if(oa_id==a_id)
		return S_ALREADY;
	if((CHAR_D->get_char(y_id,"ranklocal"))||(CHAR_D->get_char(y_id,"ranknation")))
	{
		if((CHAR_D->get_char(y_id,"nation"))!=(AREA_D->get_area(a_id,"nation")))
			return S_OTHERCOUNTRY;
		else
			return S_OFFICERALREADY;
	}
	return S_ACCEPT;
}
void confirm_settle(object who, object officer)
{
}
void ask_settle(object who, object officer)
{
	string m_id,y_id;
	string m_area;
	int p_check;
	m_id=(officer->query_id())[0];
	y_id=(who->query_id())[0];
	m_area=CHAR_D->get_char(m_id,"area");
	if((AREA_D->get_area(m_area,"leader"))!=m_id)
	{
		string m_title;
		m_title=OFFICER_D->query_rank_name(
			(
				OFFICER_D->query_area_officer_title(
				AREA_D->get_area(m_area,"level"),0,0)
			)[0]
		);
		officer->targetted_action
		("$N对$T笑着说道：＂$R想在此长住，这个$s可做不了主，你要去问本地"+m_title+"．＂\n",who);
		return;
	}
	p_check=check_settle(who,m_area);
	switch(p_check)
	{
		case S_ACCEPT:
              officer->targetted_action
             ("$N对$T笑着说道："+"$Rみ胔в龟セκ﹎ぇ瑇褐\n",who);
			confirm_settle(who,officer);
			return;
		case S_ALREADY:
              officer->targetted_action
             ("$N对$T笑着说道：＂"+
"$R稱ゲ琌絢襖竒︘＂\n",who);
			return;
		case S_OTHERCOUNTRY:
              officer->targetted_action
             ("$N对$T笑着说道：＂"+
"$R"+COUNTRY_D->get_country(CHAR_D->get_char(y_id,"nation"),"name")+
"蔼﹛痙┤Τぃ獽\n",who);
			return;
		case S_OFFICERALREADY:
              officer->targetted_action
             ("$N对$T笑着说道：＂"+
"ㄆ临讽眖璸某\n",who);
			return;
	}
}
