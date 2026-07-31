//      mishi.c 密室
inherit ROOM;

void create()
{
	set("short", "密室");
	set("long", @LONG
这是一条小房间。什么东西都没有，只是一个黑乎乎的小洞口，
不知道下面都隐藏了些什么。
LONG );
	set("exits", ([
		"south" : __DIR__"midao",
		"down" : "/d/city/xsmidao5" ,
	]));
	setup();
}
