// Room: /city/bingyingmen.c

inherit ROOM;

void create()
{
	set("short", "兵营大门");
	set("long", @LONG
你正站在兵营的门口，面对着一排简陋的营房，可以看到穿着制服的官兵
正在操练，不时地传来呐喊声。老百姓是不允许在此观看的，你最好还是赶快
走开为妙。
LONG
	);
	set("exits", ([
		"west" : __DIR__"bingying",
		"east" : __DIR__"guangchangxi",
	]));
	set("objects", ([
		NPC_D("guanfu/bing") : 4,
	]));
	set("incity",1);
	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("guan bing", environment(me))) &&
		dir == "south")
		return notify_fail("官兵拦住了你的去路。\n");
	return ::valid_leave(me, dir);
}
