// Room: /d/fuzhou/road5.c

inherit ROOM;

void create()
{
	set("short", "武夷山路");
	set("long", @LONG
你走在东南第一山脉武夷山上。海风从东面吹来，带着几分寒意。南边就
是著名的海港福州了。
LONG
	);

	set("exits", ([
                "north" : __DIR__"road4",
                "south" : __DIR__"beimen",
	]));

        set("objects", ([
		__DIR__"npc/baipao-jianxia" : 1,
		"/d/wudang/npc/yetu" : 2,
	]));

	set("outdoors", "福州");
	setup();
}
