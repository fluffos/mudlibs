#include <ansi.h>
inherit __DIR__"song_officer";
#include "/d/song/tasks/libu2.h"
void create()
{
	call_out("npc_to_player",1,"礼部侍郎",50,-1);
	::create();
}

void init()
{
	object me=this_player();
	if (!me->query("song/pro")||!me->query_temp("song_libu2_jinjian"))
	return;
	if (time()-me->query_temp("song_libu2_jinjian")>=300)
	{
		command("say "+me->query("name")+"你来迟了。");
	}
	else
	{
		command("say 快去福宁宫，官家等着召见你呢。");
		me->set_temp("songtasks/pass_palace",1);
		me->set_temp("songtasks/see_emperor",1);
		me->set_temp("songtasks/libu2_seeemperor",1);
	}
	me->delete_temp("song_libu2_jinjian");
	return;
}