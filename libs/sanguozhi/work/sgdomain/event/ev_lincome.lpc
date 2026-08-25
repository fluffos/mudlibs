// ev_lincome the event of local income
// this is used to be in area_d.c
// now take it out of that to make it
// easy to handle
// by fire on July 25, 1998

// updated by xiaobai, on Nov. 12, 2001
//      changed function "area_income(...)"

#include <event.h>

#define MAX_DROP    20

nosave protected int p_month;
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
                  	        if((CHAR_D->get_char(p_nation,"type")==TYPE_NPC))//2001.4.13 
                      	          continue;
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
                      	        if((CHAR_D->get_char(p_nation,"type")==TYPE_NPC))//2001.4.13 
                      	          continue;
				CHAR_D->set_char(s_id,"loyalty",
				CHAR_D->get_char(s_id,"loyalty")-LD_NOPAY);
                                p_nopay=1;
                        }
			continue;
                }

        }
        if(p_nopay&&(CHAR_D->get_char(p_nation,"type")!=TYPE_NPC))//2001.4.13 
        {
                mess=sprintf("%s官员未能领够俸禄，忠诚度下降。\n",
                        AREA_D->get_area(p_id,"name"));
                CHANNEL_D->deliver_tell("rumor","system",
                        mess);
        }
        AREA_D->set_area(p_id,"gold",p_gold);
	COUNTRY_D->set_country(p_nation,"gold",p_ngold);
}

void area_income(int a_index)
{
	int p_in,p_out;
	int p_gold,p_food,p_stuff;
	int p_nationgold,p_taxlocal,p_taxnation,p_nin;
	string p_nation;
	float p_tmp;
	int p_bing;
	int p_ran;
	int train, mol;
    int IF_DECREASE=1;  //2001.4.13 设定标志用于判断是否为NPC国
                            //NPC国控制的地区的士兵士气和训练度不降，数量也不减少

	string p_id;

    int nTaskId;    // 当地的任务，看有没有在训练
    int nDrop;

	p_id=AREA_D->list_areas_id(a_index);
	if(!stringp(p_id))
	    return;
	
	// xiaobai: 城市里的任务，如果没有任务ID，返回 -1
	nTaskId = TASK_D->get_area_task_id( p_id );
	    	
	a_index++;

	call_out("area_income",3,a_index);
	(__DIR__+"ev_myarmyadjust")->area_adjust(p_id); 

    if (CHAR_D->get_char(AREA_D->get_area(p_id,"nation"),"type")==TYPE_NPC)
       IF_DECREASE = 0;//2001.4.13

	p_bing = AREA_D->get_area(p_id, "soldier");
	train = AREA_D->get_area(p_id, "train");
	mol = AREA_D->get_area(p_id, "morale");

	p_food=AREA_D->get_area(p_id,"food");

	p_out=AREA_D->get_area(p_id,"foodout");
	p_food = p_food - p_out;

    if((p_food<0)&&IF_DECREASE)//2001.4.13
	{

// xiaobai: Nov. 12, 2001
// 如果有训练任务，强迫训练停止
        if ( nTaskId > 0 && TASK_D->get_task( nTaskId, "type" ) == TT_TRAIN )
        {
            EV_WAR->force_over( nTaskId );
            CHANNEL_D->deliver_tell("rumor","system",
    			sprintf("%s的训练任务因补给不足被迫中止。",
        		AREA_D->get_area(p_id,"name")));
    
        	p_bing = AREA_D->get_area(p_id, "soldier");
        	train = AREA_D->get_area(p_id, "train");
        	mol = AREA_D->get_area(p_id, "morale");
        }    

/* xiaobai: 当本身值较小时，也按比例计算，难以跌到10以下
		train = to_int(train*(1+p_food/p_bing/4))-1;
		mol = to_int(mol*(1+p_food/p_bing/3))-3;
*/
        nDrop = to_int(-p_food/p_out*MAX_DROP);
        train -= nDrop;
        mol -= 2*nDrop;

//// xiaobai

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

	p_in = to_int(p_tmp);

//      for nation income   ///////////////////////////////////////////////
	p_nation=AREA_D->get_area(p_id,"nation");
	p_taxlocal=AREA_D->get_area(p_id,"taxlocal");
	p_taxnation=AREA_D->get_area(p_id,"taxnation");
	//p_nin=p_goldin*p_taxnation/(p_taxlocal+1); modified by suicide in 2000.02.01
	p_nin=p_in*p_taxnation/100;
	//end
	p_nationgold=COUNTRY_D->get_country(p_nation,"gold");
	COUNTRY_D->set_country(p_nation,"gold",p_nationgold+p_nin);


    p_out=AREA_D->get_area(p_id,"goldout");
	//p_gold=p_gold+p_goldin-p_goldout;   modified by suicide in 2000.02.01
	p_gold=p_gold + p_in - p_out-p_nin;
	//end
    if((p_gold<0)&&IF_DECREASE)//2001.4.13
	{

// xiaobai: Nov. 12, 2001
// 如果有训练任务，强迫训练停止
        if ( nTaskId > 0 && TASK_D->get_task( nTaskId, "type" ) == TT_TRAIN )
        {
            EV_WAR->force_over( nTaskId );
            
            CHANNEL_D->deliver_tell("rumor","system",
    			sprintf("%s的训练任务因补给不足被迫中止。",
        		AREA_D->get_area(p_id,"name")));
    
        	p_bing = AREA_D->get_area(p_id, "soldier");
        	train = AREA_D->get_area(p_id, "train");
        	mol = AREA_D->get_area(p_id, "morale");
        }    

/* xiaobai: 当本身值较小时，也按比例计算，难以跌到10以下
		train = to_int(train*(1+p_food/p_bing/4))-1;
		mol = to_int(mol*(1+p_food/p_bing/3))-3;
*/

        nDrop = to_int(-p_gold/p_out*MAX_DROP);
        train -= nDrop;
        mol -= 2*nDrop;

//// xiaobai

        if( train <= 0 ) train = 0;
        if( mol <= 0 ) mol = 0;
        CHANNEL_D->deliver_tell("rumor","system",
			sprintf("%s黄金短缺，士兵士气，训练度下降。。。。",
		AREA_D->get_area(p_id,"name")));
	}
	AREA_D->set_area(p_id,"gold",p_gold);

	p_stuff=AREA_D->get_area(p_id,"stuff");
	p_out=AREA_D->get_area(p_id,"stuffout");
    p_out=0; // now disable the abstruct stuff because noone can create it
	p_stuff = p_stuff - p_out;
    if((p_stuff<0)&&IF_DECREASE)//2001.4.13
	{

// xiaobai: Nov. 12, 2001
// 如果有训练任务，强迫训练停止
        if ( nTaskId > 0 && TASK_D->get_task( nTaskId, "type" ) == TT_TRAIN )
        {
            EV_WAR->force_over( nTaskId );
            CHANNEL_D->deliver_tell("rumor","system",
    			sprintf("%s的训练任务因补给不足被迫中止。",
        		AREA_D->get_area(p_id,"name")));
    
        	p_bing = AREA_D->get_area(p_id, "soldier");
        	train = AREA_D->get_area(p_id, "train");
        	mol = AREA_D->get_area(p_id, "morale");
        }    

/* xiaobai: 当本身值较小时，也按比例计算，难以跌到10以下
		train = to_int(train*(1+p_food/p_bing/4))-1;
		mol = to_int(mol*(1+p_food/p_bing/3))-3;
*/
        nDrop = to_int(-p_stuff/p_out*MAX_DROP);
        train -= nDrop;
        mol -= 2*nDrop;

//// xiaobai

       if( train <= 0 ) train = 0;
       if( mol <= 0 ) mol = 0;
       CHANNEL_D->deliver_tell("rumor","system",
			sprintf("%s军需短缺，士兵士气，训练度下降。。。。",
		AREA_D->get_area(p_id,"name")));
	}
	
	AREA_D->set_area(p_id,"stuff",p_stuff);
	AREA_D->set_area(p_id, "train", train);
	AREA_D->set_area(p_id, "morale", mol);

    if(mol<=random(10)) 
	{
        if(p_bing&&IF_DECREASE)
        {//2001.4.13
			mixed p_ts;
			string *ts;
			int p_b;
			string t;
			
			p_ts=AREA_D->get_area(p_id,"troop");
			if(!sizeof(p_ts)) 
			    return;
			ts=keys(p_ts);
			foreach ( t in ts )
			{
				p_b=AREA_D->get_area_soldier(p_id,t);
				p_b=p_b*(random(8)+10)/20; // xiaobai:跑掉 10%-50%
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
	mixed * p_date;
	p_date=DAY_D->query_date();
	p_month=p_date[2];
	area_income(0);
}
