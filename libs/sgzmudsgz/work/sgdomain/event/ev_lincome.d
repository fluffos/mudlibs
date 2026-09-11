// ev_lincome the event of local income
// this is used to be in area_d.c
// now take it out of that to make it
// easy to handle
// by fire on July 25, 1998
static int p_month;
void area_pay(string p_id)
{
    string *list,*listn,*listall;
	string p_nation;
        int p_sal;
        int p_gold,p_ngold;
        int p_ogold;
        int p_nopay=0;
        string mess;

        p_gold=AREA_D->get_area(p_id,"gold");
	p_nation=AREA_D->get_area(p_id,"nation");
	p_ngold=COUNTRY_D->get_country(p_nation,"gold");

        list=CHAR_D->check_char("area",p_id);
	listn=CHAR_D->check_char("nation",p_nation);

	listall=CHAR_D->list_chars();
	listn=listall-listn;
	list-=listn;

	if(!sizeof(list)) return;
        foreach(string s_id in list)
        {

                p_sal=CHAR_D->get_char(s_id,"salarylocal");
                if(p_sal)
                {       
                        if(p_gold>=p_sal)
                        {
                                p_gold-=p_sal;
                                p_ogold=CHAR_D->get_char(s_id,"gold");
                                CHAR_D->set_char(s_id,"gold",p_ogold+p_sal);
                        }
                        else
                        {
				CHAR_D->set_char(s_id,"loyalty",
				CHAR_D->get_char(s_id,"loyalty")-LD_NOPAY);
                                p_nopay=1;
                        }
			continue;
                }
                p_sal=CHAR_D->get_char(s_id,"salarynation");
                if(p_sal)
                {       
                        if(p_ngold>=p_sal)
                        {
                                p_ngold-=p_sal;
                                p_ogold=CHAR_D->get_char(s_id,"gold");
                                CHAR_D->set_char(s_id,"gold",p_ogold+p_sal);
                        }
                        else
                        {
				CHAR_D->set_char(s_id,"loyalty",
				CHAR_D->get_char(s_id,"loyalty")-LD_NOPAY);
                                p_nopay=1;
                        }
			continue;
                }

        }
        if(p_nopay)
        {
                mess=sprintf("%s官员未能领够俸禄，忠诚度下降。\n",
                        AREA_D->get_area(p_id,"name"));
                CHANNEL_D->deliver_tell("rumor","system",
                        mess);
        }
        AREA_D->set_area(p_id,"gold",p_gold);
	COUNTRY_D->set_country(p_nation,"gold",p_ngold);
}

void area_income(int a_index) {
	int p_goldin,p_goldout;
	int p_foodout;
	int p_stuffout;
	int p_gold,p_food,p_stuff;
	int p_nationgold,p_taxlocal,p_taxnation,p_nin;
	string p_nation;
	float p_tmp;
	int p_bing;
	int p_ran;
	int train, mol;
	string p_id;


	p_id=AREA_D->list_areas_id(a_index);
	if(!stringp(p_id)) return;	
	a_index++;

	call_out("area_income",3,a_index);
	(__DIR__+"ev_myarmyadjust")->area_adjust(p_id); 


	p_bing = AREA_D->get_area(p_id, "soldier");
	train = AREA_D->get_area(p_id, "train");
	mol = AREA_D->get_area(p_id, "morale");

	p_food=AREA_D->get_area(p_id,"food");

	p_foodout=AREA_D->get_area(p_id,"foodout");
	p_food=p_food-p_foodout;

	if(p_food<0)
	{
		train = to_int(train*(1+p_food/p_bing/4))-1;
		mol = to_int(mol*(1+p_food/p_bing/3))-3;
		if( train <= 0 ) train = 0;
		if( mol <= 0 ) mol = 0;
		CHANNEL_D->deliver_tell("rumor","system",
			sprintf("%s粮草短缺，士兵士气，训练度下降。。。。",
			AREA_D->get_area(p_id,"name")));
	}
	AREA_D->set_area(p_id,"food",p_food);

	p_ran=random(30);
	p_gold=AREA_D->get_area(p_id,"gold");
	p_tmp=AREA_D->get_area(p_id,"goldin") * (p_ran+85)/100.+0.5;

	p_goldin=to_int(p_tmp);

//      for nation income   ///////////////////////////////////////////////
	p_nation=AREA_D->get_area(p_id,"nation");
	p_taxlocal=AREA_D->get_area(p_id,"taxlocal");
	p_taxnation=AREA_D->get_area(p_id,"taxnation");
	p_nin=p_goldin*p_taxnation/(p_taxlocal+1);
	p_nationgold=COUNTRY_D->get_country(p_nation,"gold");
	COUNTRY_D->set_country(p_nation,"gold",p_nationgold+p_nin);


    p_goldout=AREA_D->get_area(p_id,"goldout");
	p_gold=p_gold+p_goldin-p_goldout;
	if(p_gold<0)
	{
        train = to_int(train*(1+p_gold/p_bing/4))-1;
        mol = to_int(mol*(1+p_gold/p_bing/3))-3;
        if( train <= 0 ) train = 0;
        if( mol <= 0 ) mol = 0;
        CHANNEL_D->deliver_tell("rumor","system",
			sprintf("%s黄金短缺，士兵士气，训练度下降。。。。",
		AREA_D->get_area(p_id,"name")));
	}
	AREA_D->set_area(p_id,"gold",p_gold);

	p_stuff=AREA_D->get_area(p_id,"stuff");
	p_stuffout=AREA_D->get_area(p_id,"stuffout");
        p_stuffout=0; // now disable the abstruct stuff because noone can create it
	p_stuff=p_stuff-p_stuffout;
	if(p_stuff<0)
	{
       train = to_int(train*(1+p_stuff/p_bing/4))-1;
       mol = to_int(mol*(1+p_stuff/p_bing/3))-3;
       if( train <= 0 ) train = 0;
       if( mol <= 0 ) mol = 0;
       CHANNEL_D->deliver_tell("rumor","system",
			sprintf("%s军需短缺，士兵士气，训练度下降。。。。",
		AREA_D->get_area(p_id,"name")));
	}
	AREA_D->set_area(p_id,"stuff",p_stuff);
	AREA_D->set_area(p_id, "train", train);
	AREA_D->set_area(p_id, "morale", mol);

    if(mol<=random(5)) 
	{
		if(p_bing) {
			mixed p_ts;
			string *ts;
			int p_b;
			p_ts=AREA_D->get_area(p_id,"troop");
			if(!sizeof(p_ts)) return;
			ts=keys(p_ts);
			foreach (string t in ts) {
				p_b=AREA_D->get_area_soldier(p_id,t);
				p_b=p_b*(random(5)+15)/20;
				AREA_D->set_area_soldier(p_id,t,p_b);
	        	}
	                CHANNEL_D->deliver_tell("rumor","system",
			sprintf("%s士气太低，士兵纷纷逃走 。。。",
			AREA_D->get_area(p_id,"name")));
		}
	}
	area_pay(p_id);
}
void local_income()
{
	array p_date;
	p_date=DAY_D->query_date();
	p_month=p_date[2];
	area_income(0);
}
