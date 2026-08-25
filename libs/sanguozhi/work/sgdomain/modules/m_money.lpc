// m_money.c
#include <mudlib.h>
#include <sanguo.h>
inherit OBJ;
inherit M_GETTABLE;
inherit M_MERGEABLE;
int m_rate=1;
void set_m_rate(int n)
{
	m_rate=n;
}
int query_m_rate()
{
	return m_rate;
}
int query_m_num()
{	return query_count();
}
int query_is_money()
{
	return 1;
}
int query_m_value()
{
	return m_rate*query_count();
}
void adjust_size() {
  set_size(query_count()/10);
}


/*
string query_what_look()
{
	string s;
	 s=chinese_number(query_m_num());
	switch(m_rate)
	{
		case 1:
			s=s+"文钱(coin)";
			break;
		case 100:
			s=s+"两银子(silver)";
			break;
		case 10000:
			s=s+"两金子(gold)";
			break;
		default:
			s=s+"未知货币(money)";
			break;
	}
	return s;
}
*/
/*
void refresh_look()
{
	string s=query_what_look();
	set_proper_name(s);
	set_in_room_desc(s);
}	
*/
void set_m_num(int n)
{
	set_count(n);

/*	m_num=n;
     if(file_name(this_object())[0..19]!=PMONEY)
           this_object()->remove();
	refresh_look();
*/
}
