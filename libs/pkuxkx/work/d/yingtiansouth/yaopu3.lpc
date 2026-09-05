inherit ROOM;
void create()
{
	set("short", "隔间");
	set("long", @LONG
这里是药铺的隔间，放着一个药炉。
LONG);
       // set("outdoors", "hangzhou");

	set("exits", ([
		"out" : __DIR__"yaopu",
		//"east" : __DIR__"yaopu",
		//"west" : __DIR__"beijie3",
		//"north" : __DIR__"beijie3",
	]));
	set("no_task",1);
	set("objects", ([
		"obj/remedy/furnace3" : 1,
        ])); 
	setup();
}
int dest()
{
	if (this_object())
	destruct(this_object());
}
int check()
{
	if (query("player_num")<1)
	return dest();
	else
	call_out("check",300);
	return 1;
}
int leave_me(object me)
{
	if (me&&environment(me)==this_object())
	{
		tell_object(me,"你被请离了这里。\n");
		me->move(__DIR__"yaopu");
		return dest();
	}
	return 1;
}
int check_in(object me)
{
	int remain_time=me->query_temp("PermitAlchemy4")-time();
	call_out("leave_me",remain_time,me);
	return 1;
}
void init()
{
	object me=this_player();
	check_in(me);
	call_out("check",300);
}

int valid_leave(object me,string dir)
{
	if (dir=="out")
	call_out("dest",1);
	return ::valid_leave(me,dir);
}