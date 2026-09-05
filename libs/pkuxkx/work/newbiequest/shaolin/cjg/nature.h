// nature.h 天气判断 （判断是否白天还是晚上） 以及日期处理函数
#include <localtime.h>

int c_is_night()
{
	string env=NATURE_D->outdoor_room_event();
	
	if ( env=="event_evening" ||
		   env=="event_night" ||
		   env=="event_midnight" ||
		   env=="event_dawn" )
	  return 1;
	else
		return 0;
}

int c_is_day()
{
	string env=NATURE_D->outdoor_room_event();
	
	if ( env=="event_evening" ||
		   env=="event_night" ||
		   env=="event_midnight" ||
		   env=="event_dawn" )
	  return 0;
	else
		return 1;
}

string c_date()
{
	mixed *tm;
	
	tm=localtime(time());
	return sprintf("%d-%d-%d", tm[LT_YEAR], tm[LT_MON]+1, tm[LT_MDAY] );
}