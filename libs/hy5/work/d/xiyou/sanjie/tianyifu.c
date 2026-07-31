// sanjie tianyifu.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "天一仙府");
  set ("long", @LONG
	
天一宫创派人郭纯阳的金身就放在这里，纯阳先师似乎还有
一点东西还没有放下，他以一口真气留存人间，四百年来，
好像在等着有缘人来找他。
LONG);
  set("outdoors", 0);
  set("objects", ([
                __DIR__"npc/chunyang": 1 ]) );
  setup();
}
void init()
{
	add_action("do_knock", "knock");
	add_action("do_knock", "qiao");
}

int do_knock(string arg)
{
	object me, outroom;
	
	me=this_player();

	if( !arg || (arg != "wall" && arg != "qiang" && arg != "墙" && arg != "墙壁" ) )
		return notify_fail("你要敲什么？\n");       

	call_out("open_out", 1);
	return 1; 
}

void open_out()
{
	object outroom; 

	if( outroom = find_object(__DIR__"tianyidong6") ) 
	{
		set("exits/out", __DIR__"tianyidong6");
		outroom->set("exits/enter", __FILE__);
		message("vision", "墙壁突然发出轧轧的声音，露出了出去的一个洞口。\n", outroom );
		message("vision", "墙壁忽然发出轧轧的声音，露出了一个洞口。\n", this_object() );
	}

	call_out("close_up", 10);
}

void close_up()
{
	object outroom;

	if( !query("exits/out") ) return;

	message("vision", "八卦图发出轧轧的声音，洞口又封上了。\n", this_object() );

	if( outroom = find_object(__DIR__"tianyidong6") ) 
	{
		message("vision", "八卦图发出轧轧的声音，洞口不见了。\n", outroom );
		outroom->delete("exits/enter");
	}

	delete("exits/out");
}