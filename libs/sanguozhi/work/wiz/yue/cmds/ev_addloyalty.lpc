// ev_addloyalty.c
// by fire on July 26, 1998
// the officer and the local char's loyalty 
// will increase yearly
#include <mudlib.h>
inherit CMD;
private void main(string arg)
{
	string *p_nations;
	string *p_areas;
	string *p_chars;
	int p_nationmeili;
	int p_localmeili;
	int p_inclevel;
	int p_loyalty;
	int p_reinc;
	mapping m_tmp;
	string p_localleader;
	p_nations=COUNTRY_D->list_countries();
	foreach(string p_nation in p_nations)
	{
		m_tmp=CHAR_D->get_char(p_nation,"skills");
		p_nationmeili=m_tmp["sk_meili"];
		p_areas=AREA_D->check_area("nation",p_nation);
		foreach(string p_area in p_areas)
		{
			p_localleader=AREA_D->get_area(p_area,"leader");
			m_tmp=CHAR_D->get_char(p_localleader,"skills");
			p_localmeili=m_tmp["sk_meili"];
			p_inclevel=p_nationmeili+p_localmeili;
			p_inclevel=(p_inclevel+25)/25;
			p_chars=CHAR_D->check_char("area",p_area);
			foreach(string p_char in p_chars)
			{
				p_loyalty=CHAR_D->get_char_loyalty(p_char,p_nation);
				CHAR_D->set_char_loyalty(p_char,p_nation,
					p_loyalty+random(p_inclevel)-random(2));
			}
		}
	}
	return;
}
