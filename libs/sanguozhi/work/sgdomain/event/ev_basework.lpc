// ev_basework to make the base accumulate the power into work
// by fire on February 15, 2000
#include <security.h>
inherit M_ACCESS;

nosave protected int p_month,p_day;
#define LOG_FILE "/sgdomain/event/ev_basework.log"

int log_me(string msg) {
	unguarded(1, (: write_file, LOG_FILE, msg :));
	return 1;
}

void move_stuff_to_country(string a_id)
{mapping st=AREA_D->get_area(a_id,"st");
 foreach (string s in keys(st))
  {if (!st[s]["maxstock"]) continue;
   if (st[s]["maxstock"]<0)
      { COUNTRY_D->add_country_st(AREA_D->get_area(a_id,"nation"),s,
                                  st[s]["num"],st[s]["price"]);
      	map_delete(st,s);
      }
   else
   if (st["num"]>st["maxstock"])
      { COUNTRY_D->add_country_st(AREA_D->get_area(a_id,"nation"),s,
                                  st[s]["num"]-st[s]["maxstock"],
                                  st[s]["price"]);
      	st[s]["num"]=st[s]["maxstock"];
      }
      	AREA_D->set_area(a_id,"st",st);
      	continue;
       
   
  }

}


void area_base_work_r(string a_id,string f_id) // the real part
{
	object ob=SGBASE(a_id,f_id);
	string p_tmp;
        mixed * p_date;
	p_date=DAY_D->query_date();
	p_month=p_date[2];
	p_day=p_date[1]; // check day and month to determine harvest
	p_tmp=sprintf("\n area is %s base is %s ",a_id,f_id);
	log_me(p_tmp);
        //SGSYS("现在执行"+a_id+"地区的"+f_id+"基地");
	if(!objectp(ob)) return;
	log_me(" working ");
	ob->base_working();
        if(p_day==9) {
		log_me(" consume ");
		ob->base_consume();
	}
	if(p_day==10) {
		if(f_id!="farm") {
			log_me(" harvest ");
			ob->base_harvest();
		}
		else if((p_month==6)||(p_month==9)) {
			log_me(" harvest ");
			ob->base_harvest();
		}
	}
    ob->check_me();
}

void area_base_work(int a_index) {
	string a_id;
	string *bs;
	string p_tmp;
	a_id=AREA_D->list_areas_id(a_index);
	remove_call_out("area_base_work");

	if(!stringp(a_id)) return;
	a_index++;

	p_tmp=sprintf("\n area index is %d area is %s",a_index,a_id);
	log_me(p_tmp);

	bs=AREA_D->get_area(a_id,"base");
	if(!sizeof(bs)) 
	  {call_out("area_base_work",1,a_index); // take nearly 10 mins to go around
          return;}
        else
           call_out("area_base_work",6,a_index); // take nearly 10 mins to go around

	foreach(string b in bs) {
		call_out("area_base_work_r",random(6),a_id,b);
	}
	move_stuff_to_country(a_id);
}
void base_work()
{
	mixed * p_date;
	string p_tmp;
	p_date=DAY_D->query_date();
	p_month=p_date[2];
	p_day=p_date[1]; // check day and month to determine harvest
	p_tmp=sprintf("\n p_month is %d p_day is %d \n",p_month,p_day);
	log_me(p_tmp);
	remove_call_out("area_base_work");
	area_base_work(0);
}


