// Room: /d/fuzhou/road2.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你走在一条山路上。时值春日，路旁的山坡上开满了金黄色的油菜花。向
西南则进入福建武夷山区。东北面可直达宁波城。
LONG
	);

	set("exits", ([
                "northeast" : __DIR__"road1",
		"southwest" : "/d/group/entry/fzroad3",
                "southeast" : "/d/putian/road01",
	]));

	set("objects",([
		__DIR__"npc/tangzi" : 1,
	]));

	set("outdoors", "福州");
	setup();
}
