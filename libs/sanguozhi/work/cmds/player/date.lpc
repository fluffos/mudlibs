// date.c by fire
// this cmd is used to show user the date in mud and the weather
#include <mudlib.h>
#include <daemons.h>
#include <sanguo.h>
inherit CMD;
private void main(string notused)
{
	string area_name;
	string *r_areas;
	int p_year,p_month,p_day,p_hour,p_w;
	string s_year,s_month,s_day,s_hour,s_w, w_w;
  
	mixed * p_date;
	object env;
	
	p_date=DAY_D->query_date();
	p_hour=p_date[0];
	p_day=p_date[1];
	p_month=p_date[2];
	p_year=p_date[3];
	s_year=CHINESE_DA->chinese_number(p_year);
	s_month=CHINESE_DA->chinese_number(p_month);
	s_day=DAY_D->query_string_day();
	s_hour=DAY_D->query_string_hour();
	out("ＭＵＤ时间：三国志"+s_year+"年"+s_month+"月"+s_day+"．\n");
	out("当前时辰："+s_hour+"．\n");
	env=environment(this_body());
    if(objectp(env))
    {
		if(!(env->is_indoors()) && !(env->is_outdoors()))
		{
			env=environment(env); // in case ride horse or sleep
		}
		area_name=env->get_area();
		r_areas=AREA_D->check_area("area",area_name);
		if(sizeof(r_areas))
			area_name=r_areas[0];
		else
			area_name="changan"; // use changan's weather for all unknower areas
		p_w=AREA_D->get_area(area_name,"weather");
		s_w=DAY_D->get_weather_short(p_w);
		p_w=AREA_D->get_area(area_name,"wind");
		w_w=DAY_D->get_wind_short(p_w);
	}
	out("当地天气："+s_w+"．\n");
	out("当地风向："+w_w+"．\n");
}
