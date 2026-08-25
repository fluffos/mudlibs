// write by fire on Dce 30 1997
// m_age.c 
#include <ansi.h>
#include <sanguo.h>
private int ag_day,ag_month;
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
	int p_year,p_shouming,p_max_hp;
	int p_wuli_gift;
	ag_day++;
	if((ag_day>30)||(ag_day<0))
	{	ag_day=1;
		ag_month++;
	}
	if((ag_month>12)||(ag_month<0))
	{
		ag_month=1;
 		p_year=this_body()->query_age();
		p_year++;
		p_max_hp=this_body()->query_sg_max_hp();	
		if(p_year<31)
		{
                        p_wuli_gift=this_body()->query_wuli_pure();
			p_max_hp+=p_wuli_gift;
		}
		if(p_year>50)
		{
			p_max_hp-=2;
		}
		this_body()->set_sg_max_hp(p_max_hp);
		this_body()->set_age(p_year);
		p_shouming=this_body()->query_shouming();
		if(p_year>=p_shouming)
		{
			write(HIR+"你阳寿已尽，赶快准备后事吧。+NOR\n");
		}
	}
		
	call_out((: age_beat :),240);
}
void start_age()
{
	age_beat();
}
