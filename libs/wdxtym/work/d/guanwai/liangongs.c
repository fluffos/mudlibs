// liangongs.c 练功房

inherit ROOM;

void create()
{
	set("short", "南练功房");
	set("long", @LONG
这里是南面的练功房，屋中立着一些练武者常用的木人。
LONG );
	set("exits", ([
		"north" : __DIR__"liangong",
	]));
	set("objects", ([
		"/clone/npc/mu-ren" : 3
	]));
	set("for_family", "关外胡家");
	setup();
}

