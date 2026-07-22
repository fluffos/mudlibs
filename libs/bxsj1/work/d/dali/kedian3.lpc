inherit ROOM;

void create()
{
	set("short", "客房");
	set("long", @LONG
这是一间很大的客房，陈设十分华丽。靠墙放了几张大床，客人们盖着大
被子睡的正香，满屋子都是呼呼的打酣声。西边有张床是空的，你蹑手蹑脚地
走了过去。
LONG
	);

	set("sleep_room", 1);
	set("no_fight", 1);
        set("hotel",1);

	set("exits", ([
        "south" : __DIR__"kedian2",
	]));

	setup();
}
/*
int valid_leave(object me, string dir)
{
	if ( dir == "out" ) me->delete_temp("rent_paid");
	return ::valid_leave(me, dir);
}
*/
