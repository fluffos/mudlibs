//**********************************************
// write by fire 10/12/97 xiaoer.c 店小二
#include <mudlib.h>
inherit LIVING;
void setup() 
{
    set_name("xiaoer", "白梨云灵魂");
    add_id("xiao","er");
    set_gender(1);
    set_proper_name("精灵古怪的白梨云灵魂");
    set_in_room_desc("充满魅力的白梨云灵魂");
    set_long("白梨云灵魂抬头望了你一眼，\n"+"别乱闯哦？\n\n");
    set_sg_zi("小黑");
	add_question("rumors","rumors" );
	add_question("food","food");
}
void special_answer(object who, string matt)
{
	switch(matt)
	{
		case "rumors" :
			this_object()->targetted_action("$N对$T悄声说：“不瞒您说，东西马上要涨价呀！”\n",who);
			return;
		case "food" :
			this_object()->simple_action("小二瞪了一眼：“要找吃的，花钱买呀。”\n");
			return;
	}
}
