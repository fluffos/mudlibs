#ifndef __TIME_H__
#define __TIME_H__

int last_midnight() ;
varargs mixed *query_full_date(int t) ;
varargs string query_date(int t) ;
varargs int query_day(int t) ;
varargs string query_full_time(int t) ;
varargs int query_hour(int t) ;
varargs int query_minute(int t) ;
varargs int query_month(int t) ;
varargs string query_month_name(int t) ;
varargs string query_season(int t) ;
varargs int query_second(int t) ;
varargs int query_year(int t) ;
private varargs int since_start(int t) ;
varargs string query_time(int t) ;

#endif // __TIME_H__
