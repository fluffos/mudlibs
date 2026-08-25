//**********************************************
// write by benben 29/12/97 benben.c 小东西
#include <mudlib.h>
inherit LIVING;
inherit M_ACTIONS;
inherit M_TRIGGERS;
void setup() 
{
    set_name("farmer", "农夫");
    add_id("farmer","农夫");
    set_gender(1);
    set_proper_name("农夫");
    set_in_room_desc("农夫(farmer)");
    set_wander_area("caolu_area"); 
    set_long("一个农夫，荷锄耕作于田间。\n\n");
	add_question("zhuge","kongming","诸葛亮","孔明");
}
void special_answer(object who, string matt)
{
	switch(matt)
	{
		case "zhuge" :
			this_object()->simple_action("农夫说道：“自此山之南，一带高冈，乃卧龙冈也。冈前疏林内茅庐
中，即诸葛先生高卧之地。”\n");
			return;
	}
}
