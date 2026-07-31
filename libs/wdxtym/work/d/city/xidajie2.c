// Room: /city/xidajie2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
你走在西大街上，感到这里的街面要比别处的干净、整洁。大概因为靠近
衙门、兵营可受保护的缘故，富人们都喜欢住在这里。南边是一座武馆，北边是一所富丽堂皇的大宅
院。空气中弥漫着一阵血腥味。
LONG );
	set("outdoors", "city");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"xidajie1",
		"north" : "/d/city/wuguan/menlang",
		"west"  : __DIR__"ximen",
		"south" : __DIR__"caizhu",
	]));


	set("objects", ([
		"/d/quanzhen/npc/youfang": 1,
		"adm/npc/renou" : 1,	
     
	]));

	setup();
}

