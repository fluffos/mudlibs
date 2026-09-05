#include <ansi.h>
inherit __DIR__"song_officer";
int DASONG_BING()
{
	return 1;
}
void create()
{
	string *pre=({"步军都","马军都","殿前都"});
	set_temp("songtasks/pass_palace",1);
	set_temp("songtasks/see_emperor",1);
	call_out("npc_to_player",1,pre[random(sizeof(pre))]+"都虞候",40,-1);
	::create();
}

void init()
{
	add_action("do_lead","lead");
	::init();
}
int do_lead(string arg)
{
	object me=this_player(),ob=this_object();
	if (!arg||member_array(arg,ob->parse_command_id_list())==-1)
	return 0;
	if (ob->query("owner")!=me)
	return 0;
	command("follow "+me->query("id"));
	return 1;
}
int leave()
{
	command("say 臣惶恐。");
	message_vision("$N领赏后退下了。\n",this_object());
	destruct(this_object());
	return 1;
}