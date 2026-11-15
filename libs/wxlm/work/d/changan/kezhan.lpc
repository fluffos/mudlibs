//Room: kezhan.c

inherit ROOM;

void create ()
{
	set ("short", "悦宾客栈");
	set ("long", @LONG
这家客栈长安城里最大的，最昂贵的客栈，也是花钱的客栈。你若
住在这客栈里，只要你有足够的钱，根本用不着走出客栈的门，就可以
获得一切最好的享受。
LONG);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"qixiang1",
		"up": __DIR__"kzsleep",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/xiaoer" : 1,
	]));
	set("no_fight", 1);
	set("no_magic", 1);
	set("resource", ([ /* sizeof() == 1 */
	"water" : 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	if (!me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("店小二满脸堆笑地挡住了你：对不起，上面是客人的卧房，不是本店的客人，不能上去。\n");
	return ::valid_leave(me, dir);
}
