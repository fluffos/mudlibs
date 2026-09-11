/* ev_donate.c
   this is used to handle an officer resign
   by fire on Sep,14, 1998 */
void donate(string p_id,string p_where,int p_amt)
{
        string p_mess;
        int p_loyalty,p_reputation;
	int p_gold,n_bank;
	object o_id;
	string p_area,p_nation;
	p_area=CHAR_D->get_char(p_id,"area");
	p_nation=CHAR_D->get_char(p_id,"nation");
	if(p_where=="here")
	{
 p_mess=sprintf("%s向%s地区捐赠了%s两黄金，%s的忠诚与声望提高了。",
                CHAR_D->get_char(p_id,"name"),
		AREA_D->get_area(p_area,"name"),
		CHINESE_D->chinese_number(p_amt),
                CHAR_D->get_char(p_id,"name"));
		AREA_D->set_area(p_area,"gold",
			AREA_D->get_area(p_area,"gold")+p_amt);
	}
	else
	{
               p_mess=sprintf("%s向%s捐赠了%s两黄金，%s的忠诚与声望提高了。",
                CHAR_D->get_char(p_id,"name"),
		COUNTRY_D->get_country(p_nation,"name"),
		CHINESE_D->chinese_number(p_amt),
                CHAR_D->get_char(p_id,"name"));
		COUNTRY_D->set_country(p_nation,"gold",
			COUNTRY_D->get_country(p_nation,"gold")+p_amt);
	}
        p_loyalty=CHAR_D->get_char(p_id,"loyalty");
        p_reputation=CHAR_D->get_char(p_id,"reputation");
	p_loyalty+=p_amt/5;
	p_reputation+=p_amt;	
        CHAR_D->set_char(p_id,"loyalty",p_loyalty);
        CHAR_D->set_char(p_id,"reputation",p_reputation);
	
	p_gold=CHAR_D->get_char(p_id,"gold");
	if(p_gold>=p_amt)
	{
		CHAR_D->set_char(p_id,"gold",p_gold-p_amt);
	}
	else
	{
		CHAR_D->set_char(p_id,"gold",0);
		o_id=CHAR_D->find_char(p_id);
		if(objectp(o_id))
		{
			n_bank=o_id->query_amt_money("bank");
                     p_amt-=p_gold;
			o_id->set_money("bank",n_bank-p_amt*10000);
		}
	}
        CHANNEL_D->deliver_tell("rumor","system",p_mess);
        return;
}
void auto_donate(string p_id)
{
	int p_gold;

	if(CHAR_D->get_char(p_id,"is_tmp")) return;
	if(CHAR_D->get_char(p_id,"type")==TYPE_PLAYER) return;

	if(CHAR_D->get_char(p_id,"task")) return;
	
	if(!COUNTRY_D->nation_exist(CHAR_D->get_char(p_id,"nation"))) 
		return;
	p_gold=CHAR_D->get_char(p_id,"gold");
	if(p_gold<100) return;

	p_gold=p_gold/20;
	p_gold=p_gold*(random(10)+1);
	if(random(2))
	{
		donate(p_id,"here",p_gold);
	}
	else
	{
		donate(p_id,"nation",p_gold);
	}	
}
