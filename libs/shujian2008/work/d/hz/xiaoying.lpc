// /u/beyond/hz/xiaoyingzhou.c
// this is made by beyond
// update 1997.6.30
#include <ansi.h>
inherit ROOM;
void check_trigger();
void on_board();
void arrive();
void close_passage();
void reset();
void create()
{
	set("short",CYN"小赢洲"NOR);
	set("long", @LONG
小赢洲是取泥堆积成的小洲，围以环行堤梗，构成“湖中有岛，岛中有
湖”的绝妙景色。岛上浓荫夹道，亭阁映水，菏叶满园，处处皆绿，使人深
深溶入“绿色世界中。
LONG
        );
	set("exits", ([
		"south" : __DIR__"juquqiao",
	]));
	set("item_desc", ([
		"river" : "近岸处有一叶小舟，也许喊(yell)一声船家就能听见。\n",
	]));

	set("outdoors", "杭州");
	setup();
}

void init()
{
	add_action("do_yell", "yell");
}

void check_trigger()
{
	object room;

	if(!query("exits/enter") ) {
		if( !(room = find_object(__DIR__"duchuan")) )
			room = load_object(__DIR__"duchuan");
			if( room = find_object(__DIR__"duchuan") ) {
				if((int)room->query("yell_trigger")==0 ) {
					room->set("yell_trigger", 1);
					set("exits/enter", __DIR__"duchuan");
					room->set("exits/out", __FILE__);
					message("vision", "一叶扁舟缓缓地驶了过来，艄公将一块踏脚板搭上堤岸，以便乘客上下。\n", this_object() );
					message("vision", "艄公将一块踏脚板搭上堤岸，形成一个向上的阶梯。\n", room);
					remove_call_out("on_board");
					call_out("on_board", 15);
				}
				else
					message("vision", "只听得湖面不远处隐隐传来：“别急嘛，这儿正忙着呐……”\n",this_object() );
			}
			else
				message("vision", "ERROR: boat not found\n", this_object() );
		}
		else 
			message("vision", "岸边一只渡船上的老艄公说道：正等着你呢，上来吧。\n",this_object() );
}


void on_board()
{
	object room;

	if( !query("exits/enter") ) return;

	message("vision", "艄公把踏脚板收了起来，竹篙一点，扁舟向湖中驶去。\n", this_object() );

	if( room = find_object(__DIR__"duchuan")){
		room->delete("exits/out");
		message("vision", "艄公把踏脚板收起来，说了一声“坐稳喽”，竹篙一点，扁舟向\n湖中驶去。\n", room );
	}
	delete("exits/enter");
	remove_call_out("arrive");
	call_out("arrive", 20);
}

void arrive()
{
	object room;
	if( room = find_object(__DIR__"duchuan")) {
		room->set("exits/out", __DIR__"hubian2");
		message("vision", "艄公说“到啦，上岸吧”，随即把一块踏脚板搭上堤岸。\n",room );
	}
	remove_call_out("close_passage");
	call_out("close_passage", 20);
}

void close_passage()
{
	object room;
	if( room = find_object(__DIR__"duchuan") ) {
		room->delete("exits/out");
		message("vision","艄公把踏脚板收起来，把扁舟驶向湖中。\n", room);
		room->delete("yell_trigger"); 
	}
}

int do_yell(string arg)
{
	if( !arg || arg=="" ) return 0;

	if( arg=="boat" ) arg = "船家";
	if (arg != "船家") arg = "哇";
	if( (int)this_player()->query("age") < 16 )
		message_vision("$N使出吃奶的力气喊了一声：“" + arg + "”\n", this_player());
	else if( (int)this_player()->query("neili") > 500 )
		message_vision("$N吸了口气，一声“" + arg + "”，声音中正平和地远远传了出去。\n", this_player());
	else
		message_vision("$N鼓足中气，长啸一声：“" + arg + "！”\n", this_player());
	if( arg=="船家") {
		check_trigger();
		return 1;
	}
	else
		message_vision("湖面上远远传来一阵回声：“" + arg + "～～～”\n", this_player());
	return 1;
}

void reset()
{
	object room;

	::reset();
	if( room = find_object(__DIR__"duchuan") )
		room->delete("yell_trigger"); 
}
