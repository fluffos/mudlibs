// Room: /d/village/sexit.c

inherit ROOM;

void create()
{
	set("short", "南村口");
	set("long", @LONG
这是一个小村庄，看来村子里人家不多，村民们过着日出而作，日落而息
的宁静生活。穿过这个小村子，就是上华山的山路了。
LONG
	);

	set("exits", ([
		"north" : __DIR__"shilu1",
		"south" : __DIR__"hsroad3",
	]));

	set("objects", ([
		NPC_D("dog"): 1,
	]) );
	set("no_clean_up", 0);
	set("outdoors", "华山" );

	setup();
}