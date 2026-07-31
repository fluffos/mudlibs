// Room: /d/xingxiu/kedian
inherit ROOM;
void create()
{
	set("short", "客店");
	set("long", @LONG
这是座落在丝绸之路上的一个小客栈，客栈虽小，不过如果你要长途跋涉，
在这里休息一下更好哦。
    墙上挂着一个牌子。
LONG );
	set("no_fight", 1);
	set("valid_startroom", 1);
	set("no_sleep_room",1);
	set("item_desc", ([
		"【牌子】" : "楼上住宿，每夜五两白银。\n",
	]));
	set("objects", ([
		__DIR__"npc/shaonv" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"shanjiao",
		"up"    : __DIR__"kedian2",
	]));

	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
	return notify_fail("维吾尔少女连忙挡在楼梯前，急道：客官，您得先付钱啊！\n");

	if ( me->query_temp("rent_paid") && dir == "west" )
	return notify_fail("维吾尔少女跑到门边拦住：您付了银子，怎麽不住店就走了呢！
旁人还以为小店伺候不周呢！\n");

	return ::valid_leave(me, dir);
}
