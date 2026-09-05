// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
#include <ansi.h>

void create()
{
	set("short", MAG"合同凭由司"NOR);
	set("long", @LONG
这里是合同凭由司，负责开具各种出入大内物品的凭据。
LONG
	);
    //set("outdoors", "hangzhou");

	set("exits", ([
		"west" : __DIR__"guoxin",
		"east" : __DIR__"qinrui",
		//"north" : __DIR__"yudao1",
		//"north" : __DIR__"yudao1",
		//"enter" : __DIR__"qinrui2",
	]));
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
    "/d/song/npc/hetong" : 1,
        ])); 
	setup();
}

void init()
{
	add_action("do_zuotang","zuotang");
	add_action("do_stamp","stamp");
}
int do_stamp(string arg)
{
	object me=this_player();
	if (!stringp(me->query_temp("songtasks/hetong/stamp")))
	{
		return 0;
	}
	if (arg!=me->query_temp("songtasks/hetong/stamp"))
	{
		tell_object(me,"你用错了印签。\n");
		me->delete_temp("songtasks");
		tell_object(me,RED"大宋任务失败！\n"NOR);
		DASONG_D->task_finish(me,-5);
		return 1;
	}
	message_vision("$N签下了"+arg+"二字。\n",me);
	me->add_temp("songtasks/hetong/correct_times",1);
	me->delete_temp("songtasks/hetong/stamp");
	if (me->query_temp("songtasks/hetong/correct_times")>=5+random(5))
	{
		me->set_temp("songtasks/hetong/1/finish",1);
		tell_object(me,"今天的坐堂结束了，你可以回去复命了。\n");
		return 1;
	}
	tell_object(me,"似乎还有人要来……\n");
	call_out("zuotang",2+random(3),me);
	return 1;
}
int zuotang(object me)
{
	string from,to,*things=({"檀香","火烛","贡茶","布匹","烧炭","钱钞"});
	if (!me||!living(me))
	return 1;
	if (random(100)>49)
	{
		from=MAP_D->random_room("/d/hangzhou/")->query("short");
		to=MAP_D->random_room("/d/hangzhou/palace/")->query("short");
		me->set_temp("songtasks/hetong/stamp","要验");
	}
	else
	{
		from=MAP_D->random_room("/d/hangzhou/palace/")->query("short");
		to=MAP_D->random_room("/d/hangzhou/")->query("short");
		me->set_temp("songtasks/hetong/stamp","凭由");
	}
	message_vision("不多时，一个小黄门来向$N禀告，有一批"+things[random(sizeof(things))]+"，要从"+from+"运往"+to+"，请加盖印签(stamp)。\n",me);
	return 1;
}
int do_zuotang()
{
	object me=this_player();
	if (me->query_temp("songtasks/hetong/task")!=1)
	return 0;
	if (me->query_temp("songtasks/hetong/zuotang_start"))
	{
		tell_object(me,"你已经坐在这里主官的位置上了。\n");
		return 1;
	}
	me->set_temp("songtasks/hetong/zuotang_start",time());
	message_vision("$N坐在"+MAG"合同凭由司"NOR+"主官的位置上，准备开始办公。\n",me);
	call_out("zuotang",2+random(3),me);
	return 1;
}