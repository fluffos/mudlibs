inherit ROOM;

void create()
{
	set("name", "不醉不归火锅店");
	set("short", "火锅店");
	set("long", @LONG
不要以为神龙弟子只会练武哟,他们也是讲究吃穿之人,可是
因为路途遥远,穿的只能将就,可吃的不能省了,这里是神龙
岛最好的饭店,只因内部还没装修完毕,只能随便吃点了.

LONG
	);

	set("item_desc", ([
		"paizi" : "本店出售烤鸭及上等花雕酒。\n",
	]));

	set("objects", ([
		__DIR__"npc/haiw" : 1,
	
       
	]));

	set("exits", ([
		"east" : __DIR__"xroad1",
	]));

	setup();
	replace_program(ROOM);
}
