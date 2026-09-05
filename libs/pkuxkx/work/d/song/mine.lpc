// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
string look_notice();
void create()
{
	set("short", "铁矿");
	set("long", @LONG
这里是一座铁矿，大批的苦役在劳作着，还有几个军士守着通外矿外的道路
(pathway)，以防有人逃脱。
LONG
	);
        set("outdoors", "hangzhou");
	set("real_dark",1);
	set("objects", ([
          "/d/hangzhou/npc/songbing" : 2,
        ])); 
	set("item_desc", ([
		"pathway" : (:look_notice:),
	]));
	set("at_none",1);
	setup();
}
string look_notice()
{
	return "out通向铁矿的外面。\n";
}
void init()
{
	add_action("do_out","out");
	add_action("do_jiandu","jiandu");
}
string do_out()
{
	object me=this_player();
	if (me->query_temp("songtasks/sansishi/task1_where")&&me->query_temp("songtasks/sansishi/task1_where")->isroom())
	me->move(me->query_temp("songtasks/sansishi/task1_where"));
	else
	me->move("/d/hangzhou/beimen");
	return "你顺着小路，走出了铁矿。\n";
}
int do_jiandu()
{
	object me=this_player();
	if (me->query_temp("songtasks/sansishi/task")!=1)
	return 0;
	if (me->query_temp("songtasks/sansishi/1/finish"))
	return notify_fail("监督任务已经完成，回去复命吧。\n");
	me->set_temp("songtasks/sansishi/1/finish",1);
	tell_object(me,"你向铁矿上的小吏下达了一系列的命令，监督任务完成，可以回三司使复命了。\n");
	return 1;
}