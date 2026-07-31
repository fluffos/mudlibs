inherit ROOM;

void create()
{
	set("short", "客店二楼");
	set("long", @LONG
        这是客栈的客房，里面有几个单间，依稀传来情人们的说笑声，让你心猿意
马，你不由加快了脚步，找到一间空的单间，准备睡觉。
    这里唯一的出口是 west。
LONG
	);

	set_light(0);
	set("sleep_room", "1");
	set("no_fight", "1");
        set("hotel",1);

	set("exits", ([
		"west" : __DIR__"kefang2",
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
