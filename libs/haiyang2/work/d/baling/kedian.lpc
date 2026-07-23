// baling/kedian
// Room in 龟兹 
// laowuwu 99/04/11
inherit ROOM;

void create()
{
	set("short", "客店");
	set("long", @LONG
这是一家价钱低廉的客栈，生意非常兴隆。外地游客多选择这里落
脚，你可以在这里打听到各地的风土人情。店小二里里外外忙得团团转，
接待着南腔北调的客人。客店的主人从不露面，他究竟是谁，有各种各
样的猜测。墙上挂着一个牌子。
LONG
	);

	set("no_fight", 1);
	set("valid_startroom", 1);
        set("no_sleep_room",1);

	set("exits", ([
		"north" : __DIR__"dongdajie1",
		"up":__DIR__"shuifang",
	]));
set("objects", ([
		__DIR__"npc/xiaoer" : 1
	]));
	setup();
}
int valid_leave(object me,string dir)
{
	if(!me->query_temp("gived_money")&&dir=="up")
		if(objectp(present("xiao",environment(me))))
			return notify_fail("店小二拦住了你：客官，您还没给钱呢!\n");
		else return notify_fail("掌柜从里面喊道：客官，给钱再住店啊!\n");
		return ::valid_leave(me,dir);
		return 1;
}
