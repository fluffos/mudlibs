// 樵夫 write by benben 
#include <mudlib.h>
inherit LIVING;
inherit M_ACTIONS;
inherit M_TRIGGERS;
inherit M_WANDER;
void setup() 
{
    set_name("Qiao Fu", "樵夫");
    add_id("qiaofu","Qiao","fu","qiao fu","樵夫");
    set_gender(1);
    set_proper_name("樵夫");
    set_in_room_desc("樵夫(Qiao Fu)");
    set_wander_area("caolu_area"); 
    set_long("一个樵夫，头上戴箬笠，身上穿布衣，腰间系着环绦，脚下踏着草履，
手执一柄钢斧，正在砍树。\n\n");
        add_question("wolonggang","wolonggang");
}
void special_answer(object who, string matt)
{
	switch(matt)
	{
		case "wolonggang" :
			this_object()->simple_action("樵夫说道：“不远，不远。过了林子就是。”\n");
			return;
	}
}
