// m_money.c
#include <mudlib.h>
#include <sanguo.h>
inherit OBJ;
inherit M_GETTABLE;
inherit CHINESE_DA;
int m_num=1;
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
{	return m_num;
}
int query_is_money()
{
	return 1;
}
int query_m_value()
{
	return m_rate*m_num;
}
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
void refresh_look()
{
	string s=query_what_look();
	set_proper_name(s);
	set_in_room_desc(s);
}	
void set_m_num(int n)
{
	m_num=n;
	refresh_look();
}
