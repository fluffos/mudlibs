// ev_myarmyadjust.c
// by fire on Dec 1998
#define QBSALARY 10
void area_adjust(string a_id)
{
    	string *list;
    	mixed c;
    	int gold_need,my_gold,my_food,food_need,qbnum;
	string h_type;
	mapping wear;
	int *h_need;
	if(!stringp(a_id)) return;
//	tell_user("fire",a_id);
	list=CHAR_D->check_char("area",a_id);
	if(!sizeof(list)) return;
	list=filter_array(list, (: CHAR_D->get_char($1,"type")==TYPE_PLAYER :));
	if(!sizeof(list)) return;

	foreach(string p_id in list)
    	{
       		c=CHAR_D->get_char(p_id,"myarmy");
		if(!mapp(c)) c=([]);
		wear=CHAR_D->get_char(p_id,"wear");
		if(!mapp(wear)) wear=([]);
		h_type=wear["horse"];
		qbnum=c["qbnum"];

		if(qbnum||stringp(h_type)) 
		{

     			my_gold=CHAR_D->get_char(p_id,"gold");
			my_food=c["food"];
			
			if(qbnum) {
		       		gold_need=(qbnum+QBSALARY-1)/QBSALARY;
	       			if(my_gold<gold_need)
		       		{   
					qbnum=my_gold*QBSALARY;
	        	   		CHANNEL_D->deliver_tell("rumor","system",
        	    			sprintf("%s不给亲兵发够晌银，亲兵纷纷逃跑。",
	        	    			CHAR_D->get_char(p_id,"name")));
       				}
				food_need=qbnum;
				if(my_food<food_need) {
					qbnum=my_food;
	        	   		CHANNEL_D->deliver_tell("rumor","system",
        	    			sprintf("%s不给亲兵吃饱粮食，亲兵纷纷逃跑。",
	        	    			CHAR_D->get_char(p_id,"name")));
					my_food=0;

				}
		       		my_gold-=gold_need;
				my_food-=food_need;
	       			if(my_gold<0) my_gold=0;
				if(my_food<0) my_food=0;
	       			if(!c["train"]) c["train"]=0;
		       		c["train"]++;
	       			if(c["train"]>200) c["train"]=200;
			}
			if(stringp(h_type)) {
				h_need=OBJ_D->get_obj(h_type,"fe");
				h_need[1]=0;

				if((my_gold<h_need[0])||(my_food<h_need[1])) {
					switch (c["h_nf"]) {
						case 0: 
						  c["h_nf"]=1;
		        	   		  CHANNEL_D->deliver_tell("rumor","system",
        			    			sprintf("%s不给坐骑足够金粮，%s饿瘦了。",
		        	    			CHAR_D->get_char(p_id,"name"),
							OBJ_D->get_obj(h_type,"name")
							));
						   break;
						case 1: 
						case 2: 
						case 3: 
						case 4: 
						case 5: 
						  c["h_nf"]++;
		        	   		  CHANNEL_D->deliver_tell("rumor","system",
        			    			sprintf("%s不给坐骑足够金粮，%s饿瘦了。",
		        	    			CHAR_D->get_char(p_id,"name"),
							OBJ_D->get_obj(h_type,"name")
							));
						   break;

						case 6: 
						case 7: 
						case 8: 
						  c["h_nf"]++;
		        	   		  CHANNEL_D->deliver_tell("rumor","system",
        			    			sprintf("%s不给坐骑足够金粮，%s快饿死了。",
		        	    			CHAR_D->get_char(p_id,"name"),
							OBJ_D->get_obj(h_type,"name")
							));
						   break;
						case 9: 
						case 10: 
						case 11: 
						  c["h_nf"]++;
		        	   		  CHANNEL_D->deliver_tell("rumor","system",
        			    			sprintf("%s不给坐骑足够金粮，%s奄奄一息了。",
		        	    			CHAR_D->get_char(p_id,"name"),
							OBJ_D->get_obj(h_type,"name")
							));
						   break;
						default:
						  map_delete(c,"h_nf");
						  map_delete(wear,"horse");
						  CHAR_D->set_char(p_id,"wear",wear);
		        	   		  CHANNEL_D->deliver_tell("rumor","system",
        			    			sprintf("%s不给坐骑足够金粮，%s俄死了。",
		        	    			CHAR_D->get_char(p_id,"name"),
							OBJ_D->get_obj(h_type,"name")
							));
						   break;

					}
				}
				else {
					if(c["h_nf"]) {
						c["h_nf"]--;
						if(c["h_nf"]==0)
						map_delete(c,"h_nf");
					}
				}
				my_gold-=h_need[0];
				my_food-=h_need[1];
	       			if(my_gold<0) my_gold=0;
				if(my_food<0) my_food=0;
			}
			c["qbnum"]=qbnum;			
			if(!qbnum) map_delete(c,"qbnum");
			c["food"]=my_food;
			if(!my_food) map_delete(c,"food");
       			CHAR_D->set_char(p_id,"myarmy",c);
       			CHAR_D->set_char(p_id,"gold",my_gold);    

		} // if(c["qbnum"]||c["horse"]) 
    	} //foreach(string p_id in list)
}
