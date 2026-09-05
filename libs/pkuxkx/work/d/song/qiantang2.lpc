// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
string look_ship();
void create()
{
	set("short", WHT"钱塘江边"NOR);
	set("long", @LONG
这里是钱塘江畔，却是较为平静的一段。几只大宋训练用的战船(ship)停在
一旁。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		"west" : __DIR__"shuishi",
		"east" : __DIR__"qiantang4",
		"southwest" : __DIR__"qiantang",//吏部
		//"south" : __DIR__"streets2",//礼部
	]));
	set("item_desc",([
		"ship" : (:look_ship:),
	]));
	/*set("objects", ([
          "/d/hangzhou/npc/songbing" : 2,
        ])); 
	*/
	set("at_hangzhou",1);
	setup();
}

string look_ship()
{
	object me=this_player();
	if (me->query_temp("songtasks/shuishi/task")==4)
	return "你可以登上(board)战舰，练习海上操舟。\n";
	else if (me->query("song/pro"))
	return "大宋的战舰整齐地排列在岸边。\n";
	else
	return "水师的士兵阻止了你对战舰的窥视。\n";
}

void init()
{
	add_action("do_board","board");
}

int do_board()
{
	object ship,me=this_player();
	if (me->query_temp("songtasks/shuishi/task")!=4)
	{
		if (me->query("song/pro"))
		return notify_fail("没有水师大都督的手令，其他人不得登舰。\n");
		return notify_fail("水师的士兵阻止了你登舰的企图。\n");
	}
	if (!ship=load_object(__DIR__"train_ship"))
	return notify_fail("战舰受损，现在正在修理。\n");
	message_vision(HIR+"$N"+HIR+"登上了轻快战船。\n",me);
	me->move(ship);
	ship->get_detail(me);
	tell_object(me,"用划(hua)<方向>接近目标，不能和目标重合，接近敌船一格时引燃(destroy)。\n");
	return 1;
}