// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", HIC+"南征帅府"+NOR);
	set("long", @LONG
这里是远征安南主帅的帅府。
LONG
	);

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		//"north" : __DIR__"shumi2",
		//"west" : __DIR__"shumi3",
		//"west" : __DIR__"shumicourt",//吏部
		"out" : "/d/kunming/guangchang",//礼部
	]));
	

	setup();
}

void init()
{
	add_action("do_open","open");
	add_action("do_list","list");
}
int do_list()
{
	write("啥也不能干。\n");
	return 1;
}
int do_open()
{
	object me=this_player();
	if (query("owner")!=me) return 0;
	if (!me->query_temp("songtasks/nanzheng/general_sign"))
	{
		me->set_temp("songtasks/nanzheng/general_sign",1);
		message_vision("$N道：“本帅今日在此开府，不平安南，誓不会师。”\n",me);
		tell_object(me,"你可以用list获得帅帐的命令。\n");
		DASONG_D->task_finish(me,2);
	}
	else
	tell_object(me,"你不是已经誓师过了吗？你可以用list获得帅帐的命令。\n");
	return 1;
}