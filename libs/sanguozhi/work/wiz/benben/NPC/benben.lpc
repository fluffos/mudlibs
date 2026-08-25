//**********************************************
// write by benben 29/12/97 benben.c 小东西
#include <mudlib.h>
inherit LIVING;
inherit M_ACTIONS;
inherit M_TRIGGERS;
void setup() 
{
    set_name("ben ben", "小东西");
    add_id("ben ben","ben","小东西");
    set_gender(2);
    set_proper_name("小东西");
    set_in_room_desc("厨房里的小东西(Ben ben)");
    set_long("小东西正忙的满头大汗，满手油腻地。一抬头看到你：\n"+"“还楞着干嘛！快过来帮忙！都是些好吃懒做得家伙！”\n\n");
	add_question("food","food");
}
void special_answer(object who, string matt)
{
	switch(matt)
	{
		case "food" :
			this_object()->simple_action("小东西兴高采烈地说：“今儿晚上我请客。满汉全席！吃完了咱们唱卡拉OK去。”\n");
			return;
	}
}
