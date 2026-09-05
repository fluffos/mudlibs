//沙滩
// for xiakedao
// modified by aiai 98/10/27


inherit ROOM;

object me;

void create()
{
        set("short", "海滩");
        set("long", @LONG	

   这是侠客岛的出海口，北面是海，向西是一座高耸的
石山，山上郁郁苍苍，生满树木。南面是花草树林，五色
缤纷不见尽头，只看得头昏眼花。东首石崖下停泊着四十
多艘大大小小船只(boat)。 
LONG);
        set("exits", ([ /* sizeof() == 2*/
		"west"   : __DIR__"shangu",
		"south"  : __DIR__"shatan2",
        ]));
	set("item_desc",([
		"boat" : "这是一艘小木船。船虽小，但是依然可以承受
 得了一般的风浪。出海就靠这条船了。\n",
	]));

	setup();

        set("outdoors","xiakedao");

}
void init()
{
	add_action("do_enter","enter");
}

int do_enter(string arg)
{
	object room;
	me = this_player();
	if (!arg || arg=="")
	return 0;
	if (arg =="boat")
	{
		message_vision("$N从踏板上走上了船。\n",me);
		me->move(__DIR__"boat");
	 	if(room=find_object(__DIR__"boat"))
	 	room->set("exits/out",__FILE__);
		message_vision("$N从踏板上走了进来。\n",me);
	 
	 }
   	 remove_call_out("on_board");
	 call_out("on_board",15);
		 
	 return 1;
	 
}

void on_board()
{
	object room;
	 
	if (!me) return;
//      message_vision("$N把踏板收起来，船桨一点，小船向北驶去。\n",me);
	if (room = find_object(__DIR__"boat"))
	{
		room->delete("exits/out");
		message_vision("$N把踏脚板收起来，船桨一点，小船向北驶去。\n",me);
	}
        remove_call_out("arrive");
	call_out("arrive",15);
}

void arrive()
{
	object room;
	if (!me) return;
	if (room=find_object(__DIR__"boat"))
	{
		room->set("exits/out",__DIR__"nanhaibin");
		message_vision("船儿轻轻靠向岸边，最终停了下来。\n",me);
	}
}
