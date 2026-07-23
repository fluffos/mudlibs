// Room: /city/xidajie2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "通泗街");
	set("long", @LONG
你走在通泗街上，感到这里的街面要比别处的干净、整洁。大概因为靠近
衙门、兵营可受保护的缘故，富人们都喜欢住在这里。东边静悄悄地没有几个
行人，西边是西城门通往郊外。南边是一座武馆，北边是一所富丽堂皇的大宅
院。
LONG );
        set("outdoors", "city");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"xidajie1",
		"south" : __DIR__"wuguan",
		"west"  : __DIR__"ximen",
		"north" : __DIR__"caizhu",
	]));

        set("objects", ([
                "/d/quanzhen/npc/youfang": 1,
"/clone/master/master"+(random(24)+1): random(2),
	]));

	setup();
	replace_program(ROOM);
}

