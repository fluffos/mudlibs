#include <ansi.h>
inherit __DIR__"song_officer";
#include "/d/song/config/tasks.h"
void create()
{
	call_out("npc_to_player",1,"枢密副使",50,-1);
	::create();
}

void init()
{
	add_action("do_jiao","jiao");
}

int do_jiao()
{
	object me=this_player(),army;
	if (!me->query("song/pro"))
	return 0;
	if (!army=me->query_temp("lead_army"))
	{
		command("say 你并未统帅一只军队，要缴回什么命令啊？");
		return 1;
	}
	message_vision("$N道：“末将愚钝，恐耽误朝廷军机，请缴回"+army->query("name")+"兵符，另选贤能将之。”\n",me);
	command("nod");
	destruct(army);
	me->delete_temp("lead_army");
	return 1;
}