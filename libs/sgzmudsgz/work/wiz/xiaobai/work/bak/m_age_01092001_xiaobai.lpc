// write by fire on Dce 30 1997
// m_age.c 
#include <ansi.h>
#include <sanguo.h>
private int ag_day,ag_month;
private int chan_disabled;
nosave private string lastchatmsg;
nosave private int lastchattime;
private mixed notell;

mixed set_notell(mixed val) {
        notell=val;
}
mixed query_notell() {
        if(notell==1) return this_object()->query_chinese_id()+"现在不想说话。\n";
        return notell;
}

mixed set_lastchat(string msg) {
        lastchattime=time();
        lastchatmsg=msg;
}
int query_lastchattime() {
        return lastchattime;
}
string query_lastchatmsg() {
        return lastchatmsg;
}

int chan_disabled() {
        return chan_disabled;
}
string disable_chan() {
        chan_disabled=1;
        return "ok";
}
string enable_chan() {
        chan_disabled=0;
        return "ok";
}
void set_ag_day(int i)
{
        ag_day=i;
}
void set_ag_month(int i)
{
        ag_month=i;
}
int query_ag_day()
{
        return ag_day;
}
int query_ag_month()
{
        return ag_month;
}
void age_beat()
{
        int p_year,p_shouming;
		if(MUSEUM_D->char_exist(this_object()->query_primary_id()))
			return; // so in the museum, don't increase the age
        ag_day++;
        if((ag_day>30)||(ag_day<0))
        {       ag_day=1;
                ag_month++;
        }
        if((ag_month>12)||(ag_month<0))
        {
                ag_month=1;
                p_year=this_body()->query_age();
                p_year++;
                CHAR_D->set_char(this_body()->query_id()[0],"age",p_year);


                HP_D->set_max_hp(this_object());
                HP_D->set_max_mp(this_object());

                this_object()->set_age(p_year);
                tell(this_object(),"恭喜你，又长了一岁。\n");

                p_shouming=this_body()->query_shouming();
                if(p_year>=p_shouming)
                {
                        write(HIR+"你阳寿已尽，赶快准备后事吧。+NOR\n");
                }
        }
        call_out("age_beat",320);
        if(random(2)) {
                this_object()->put_m_all_money();  // add by fire on Dec 13, 1997
                this_object()->save_me();
                tell(this_object(),"存储完毕。\n");
        }
     if(objectp(this_body()))
   "/sgdomain/home/funs/funs"->main(this_body()->query_primary_id());
}
void start_age()
{
        age_beat();
}

