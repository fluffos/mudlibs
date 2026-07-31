// Room: /d/paiyun/door.c

inherit ROOM;

void create()
{
	set("short", "寨门");
	set("long", @LONG
你终于来到了闻名黑白两路的”排云寨“，高大的寨门上旌
旗飞舞，正中一块横匾上书”排云寨“三个大字，寨门塔楼上不
少包着黑头巾手拿长枪的哨兵在游弋。
LONG
	);
	set("outdoors", "paiyun");
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"up4",
  "north" : __DIR__"lu1",
]));

	set("objects",([
	__DIR__"npc/door_guard" : 1,
]));

	setup();
}

int valid_leave(object who,string dir)
{
	if(dir == "north"
	&& present("shan fei",this_object())
        && userp(who)
	&& !wizardp(who))
		return notify_fail("山匪朝你一挥手说道：没事理远点！说着把你哄了出来。\n");
	return ::valid_leave(who,dir);
}
