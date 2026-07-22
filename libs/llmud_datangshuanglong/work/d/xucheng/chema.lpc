inherit ROOM;

void create()
{
	set("short", "车马店");
	set("long", @LONG
一家低档的车马客栈，建筑相当陈旧，很不起眼，不过由于价钱低
廉，又是在东门的交通要道上，三教九流多选择这里落脚，生意也相当
不错，你也可以在这里打听到当地的风土人情。
LONG );
	set("no_fight", 1);
        set("no_sleep_room",1);
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"dongdajie",
		"up"   : __DIR__"chemaup",
	]));
	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("gived_money") && dir == "up" )
	return notify_fail("店小二一下挡在楼梯前，白眼一翻：怎麽着，想白住啊！\n");

	if ( me->query_temp("gived_money") && dir == "south" )
	return notify_fail("店小二跑到门边拦住：客官已经付了银子，怎麽不住店就走了呢！
旁人还以为小店伺候不周呢！\n");

	return ::valid_leave(me, dir);
}
