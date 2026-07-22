// /u/beyond/hangzhou/hubian.c 西湖边
// this is made by beyond
// update 1997.6.30
#include <ansi.h>
#include <wanted.h>
inherit ROOM;
void check_trigger();
void on_board();
void arrive();
void close_passage();
void reset();

void create()
{
        set("short",GRN"西湖边"NOR);
        set("long", @LONG
杭州西湖山青水秀，碧波涟漪，湖光山色，相映成趣，泛舟湖上犹如镜
中行，漫步湖堤则如画中游。西湖之美令人陶醉。自古以来，人们常以艳、
娇、媚、秀、柔、嫩来形容她。宋代大诗人苏轼的“水光潋滟晴方好，山色
空蒙雨亦奇，欲把西湖比西子，淡妆浓抹总相宜”一诗把西湖明媚秀丽的景
色描绘的淋漓尽致。
LONG
        );
	set("objects",([
		__DIR__"npc/jian-ke" : 2,
	]));

        set("exits", ([
		"north" : __DIR__"hggyu",
		"east" : __DIR__"hubian1",
		"south" : __DIR__"hupao",
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

	message("vision", "艄公把踏脚板收了起来，竹篙一点，扁舟向湖中驶去。\n",this_object() );

	if( room = find_object(__DIR__"duchuan")){
		room->delete("exits/out");
		message("vision", "艄公把踏脚板收起来，说了一声“坐稳喽”，竹篙一点，扁舟向湖中驶去。\n", room );
	}
	delete("exits/enter");
	remove_call_out("arrive");
	call_out("arrive", 20);
}

void arrive()
{
	object room;
	if( room = find_object(__DIR__"duchuan")){
		room->set("exits/out", __DIR__"xiaoying");
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
		message_vision("$N使出吃奶的力气喊了一声：“" + arg + "”\n",this_player());
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

int valid_leave(object me, string dir)
{
	if (dir == "enter" && is_wanted(me))
		return 0;
	return ::valid_leave(me, dir);
}
