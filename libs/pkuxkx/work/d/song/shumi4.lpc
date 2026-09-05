// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "小官厅");
	set("long", @LONG
这里是枢密院编修们合用的官厅。
LONG
	);
        //set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		//"north" : __DIR__"shumi2",
		//"west" : __DIR__"shumi3",
		"west" : __DIR__"shumicourt",//吏部
		//"out" : __DIR__"shumi",//礼部
	]));
	

	setup();
}

void init()
{
	object me=this_player();
	if (query("nanzheng")&&me->query("song/pro"))
	{
		tell_object(me,"枢密院小吏见你到来，忙赶上来道一声：“大人辛苦了。”\n");
		tell_object(me,"小吏又道：“大人还请稍待片刻，等大家一会都来了。”\n");
	}
	add_action("do_decide","decide");
}
int do_decide(string arg)
{
	object me=this_player();
	if (!query("nanzheng2")||!arrayp(query("nanzheng2"))||!me->query("song/pro")) return 0;
	if (me->query_temp("songtasks/nanzheng/vote"))
	{
		write("你已经投过了一票。\n");
		return 1;
	}
	if (member_array(arg,query("nanzheng2"))==-1)
	{
		write("你不能再推荐新的人选。\n");
		return 1;
	}
	me->set_temp("songtasks/nanzheng/vote",1);
	message_vision(HIC+"$N"+HIC+"投了"+arg+"一票。\n"+NOR,me);
	add("vote/"+arg,1);
	return 1;
}
int sort_ppl(object pl1,object pl2)
{
	return pl2->query("song/credit")-pl1->query("song/credit");
}
void over2()
{
	int high=0;
	string high_ppl,*ppl=query("nanzheng2");
	object pl;
	delete("nanzheng2");
	if (!query("vote"))
	{
		message_vision("因为无人获得投票，出兵之议作废。\n");
		return;
	}
	for (int i=0;i<sizeof(ppl);i++)
	{
		if (query("vote/"+ppl[i])>high)
		{
			high=query("vote/"+ppl[i]);
			high_ppl=ppl[i];
		}
	}
	delete("vote");
	if (pl=find_player(high_ppl))
	{
		tell_object(pl,"恭喜，你被众人推举为南征主帅。\n");
		message_vision(pl->query("name")+"被推举为南征主帅。\n"NOR,pl);
		CHANNEL_D->do_channel(this_object(), "jh", HIR+"【大宋】政事堂、枢密院迅速形成决议，"+pl->query("name")+"将率领十万大军，远征安南。\n"+NOR, -1);
		tell_object(pl,"你的帅府被设在昆明，请尽快(3分钟内)去赴任(open)吧。\n");
		load_object("/d/kunming/guangchang")->open(pl);
		load_object("/d/song/shuaifu")->set("owner",pl);
	}
}
void over()
{
	int high=0;
	string ppls="",*pls=({});
	object officer,*all_pl=all_inventory(this_object()),*all_song=DASONG_D->song_all();
	delete("nanzheng");
	all_pl = filter_array(all_pl, (: $1->query("song/pro") :) );
	if (sizeof(all_pl)<1) 
	{
		message_vision("来者不足大宋官员十一，出征之议作罢。\n");
		CHANNEL_D->do_channel(this_object(), "jh", HIR+"【大宋】官员懦弱，军队怯战，决定对安南入寇忍气吞声。\n"+NOR, -1);
		for (int i=0;i<sizeof(all_song);i++)
		{
			if (environment(all_song[i])!=this_object())
			{
				tell_object(all_song[i],"因为没有出席重要军事会议。");
				//DASONG_D->task_finish(all_song[i],-2);
			}
		}
		return;
	}
	for (int i=0;i<sizeof(all_pl);i++)
	{
		if (all_pl[i]->query("song/credit")>high)
		{
			officer=all_pl[i];
			high=all_pl[i]->query("song/credit");
		}
		DASONG_D->task_finish(all_pl[i],3);
		tell_object(all_pl[i],"国难之际，政事堂和枢密院为激励人心，决定给每位与会官员功勋奖励。\n");
	}
	message_vision("这时大家都被安南入寇的紧急军情震惊了，场间一片安静。\n\n\n\n"+NOR,officer);
	message_vision("$N清了清嗓子：“大家想必已经知道安南入寇的消息了，政事堂和枢密院已经决定，出兵安南。\n\n”",officer);
	message_vision(CYN+"$N"+CYN+"接下来扫了场间众人一眼：“我们马上要做的就是决定(decide)出兵的主帅人选。\n”"+NOR,officer);
	all_song=sort_array(all_song,"sort_ppl");
	for (int i=0;i<5;i++)
	{
		if (all_song[i])
		{
			ppls+=all_song[i]->query("name")+"("+all_song[i]->query("id")+") ";
			pls+=({all_song[i]->query("id")});
		}
	}
	message_vision("$N道："+ppls+"“功勋卓著，我们要在一分钟内从中选出(decide)主帅。”\n",officer);
	set("nanzheng2",pls);
	call_out("over2",60);
}
int start()
{
	set("nanzheng",1);
	call_out("over",120);
}