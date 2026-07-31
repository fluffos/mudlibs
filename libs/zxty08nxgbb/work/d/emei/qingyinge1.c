// Room: /d/emei/qingyinge.c 峨嵋派 清音阁


inherit ROOM;


void create()
{
	set("short", "清音阁");
	set("long", @LONG
这里是峨嵋门人休息的地方，环境清幽，万籁聚静。偶尔也有几声
鸟叫，不时在山谷中回荡。东边是男休息室，西边是女休息室。在朝北
面有一个小木门(men)，紧紧的关闭着。
LONG
	);

	set("exits", ([
                 "west": __DIR__"xiuxishi",
                 "east": __DIR__"xiuxishi1",
	]));
	setup();
}
void init()
{
	add_action("do_open", "open");
}

void close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"qingyinge")) )
		room = load_object(__DIR__"qingyinge");
	if(objectp(room))
	{
		delete("exits/north");
			message("vision", "静和上前把木门关了起来。\n", this_object());
		room->delete("exits/south");
		message("vision", "里面有人悄悄把木门关上了。\n", room);
	}
}

int do_open(string arg)
{
	object room;

	if (query("exits/north"))
		return notify_fail("大门已经是开着了。\n");

	if (!arg || (arg != "men" && arg != "north"))
		return notify_fail("你要开什么？\n");

	if(!( room = find_object(__DIR__"qingyinge")) )
		room = load_object(__DIR__"qingyinge");
	if(objectp(room))
	{
		set("exits/north", __DIR__"qingyinge");
		message_vision("$N悄悄把木门打了开来。\n", this_player());
		room->set("exits/south", __FILE__);
		message("vision", "吱地一声，里面有人把木门打开了。\n", room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}

	return 1;
}
int valid_leave(object me, string dir)
{
       if ( me->query("gender") == "男性" && dir == "west")
       return notify_fail("看清楚点！这是女休息室。\n");
       if ( me->query("gender") == "女性" && dir == "east")
       return notify_fail("看清楚点！这是男休息室。\n");
        return ::valid_leave(me, dir);
}
