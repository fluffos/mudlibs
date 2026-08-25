// xiaoer.c 伙计 by row
#include <mudlib.h>
#include <sanguo.h>
inherit LIVING;
inherit M_ACTIONS;
inherit M_TRIGGERS;
void receive_outside_msg(string str){
	receive_outside_msga(str);
}
void receive_private_msg(string str) {
	receive_outside_msga(str);
}
string *query_channel_list() {
	return ({ "plyr_gossip" });
}
void setup() 
{
	set_name("huo ji", "伙计");
	add_id("waiter","ji");
	set_gender(1);
	set_proper_name("伙计");
	set_in_room_desc("伙计(huo ji)");
	set_long("一个年轻的客栈伙计，时不时的用抹布擦拭柜台。\n\n");
	set_sg_rongmao(15);
	add_question("rumors","rumors" );
	add_pattern("%s走了过来。",function()
	{
		respond("say 这位，住店吗？");
	});
}
void special_answer(object who, string matt)
{
	switch(matt)
	{
		case "rumors" :
			this_object()->targetted_action("$N压低了嗓门道：洛阳城里人人都骂董。。。\n",who);
			return;
	}
}