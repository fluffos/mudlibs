// Room: /city/guest.c

inherit ROOM;

void create()
{
	set("short", "东客房");
	set("long", @LONG
这里是扬州广场大榕树上的树屋--东客房，angelus请来的客人都住在这里，
这里仙气环绕，隐隐可见一些精灵飞来飞去，真是人间胜地。
LONG );
	set("no_fight", 1);
	set("exits", ([
		"west" : __DIR__"level_up",
		
	]));
	set("objects", ([
		"/clone/npc/learn_fly": 1,
		
	]));
	setup();
}

