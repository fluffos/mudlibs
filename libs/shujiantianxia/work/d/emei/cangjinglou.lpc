// Room: /d/emei/cangjinglou.c

inherit ROOM;
void create()
{
	set("short", "藏经楼");
	set("long", @LONG
这里是报国寺的藏经楼。阁楼上密密麻麻排了好多书架，架上摆满了经书。
有两个身穿白衣的小师太正在一角静静地读着经书。
LONG
	);

	set("exits", ([
	    "out" : __DIR__"daxiongdian",
	]));
	set("objects",([
		"/d/emei/obj/fojing1" : 1,
		"/d/emei/obj/fojing2" : 1,
		"/d/emei/npc/daoming" : 1,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	if (dir == "out" && present("shu", me) && objectp(present("daoming shifu", environment(me))))
		return notify_fail("道明小师傅喝道：“藏经楼内书籍不得外带。\n");

	return ::valid_leave(me, dir);
}
