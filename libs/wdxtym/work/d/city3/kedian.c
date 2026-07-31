// Room: /chengdu/kedian.c
inherit ROOM;

void create()
{
	set("short", "锦城驿");
	set("long", @LONG
锦城驿是全西南最大的客店，生意非常兴隆。外地游客多选择这
里落脚，你可以在这里打听到各地的风土人情。店小二里里外外忙得
团团转，沉重的川味官话你是实在听不顺耳。这是成都督府官办的客
栈，接待着各地入川的官差浪人。墙上挂着一个牌子(paizi)。
LONG );
	set("no_fight", 1);
	set("valid_startroom", 1);
	set("no_sleep_room",1);

	set("item_desc", ([
		"【牌子】" : "楼上雅房，每夜五十两白银。\n",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));
	set("exits", ([
		"northwest" : __DIR__"southroad1",
		"up"	: __DIR__"kedian2",
		"east"      : __DIR__"majiu",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if ( !me->query_temp("rent_paid") && dir == "up" )
	return notify_fail("店小二一下挡在楼梯前，白眼一翻：怎麽着，想白住啊！\n");

	if ( me->query_temp("rent_paid") && dir == "west" )
	return notify_fail("店小二跑到门边拦住：客官已经付了银子，怎麽不住店就走了呢！旁人还以为小店伺候不周呢！\n");

	return ::valid_leave(me, dir);
}
