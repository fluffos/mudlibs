// Room: /city/xidajie2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
你走在西大街上，感到这里的街面要比别处的干净、整洁。南面是红娘庄，
常常有一对对男女来往。北边则是飞龙帮的总部。
LONG);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"xidajie2",
		"west" : __DIR__"ximen",
		"north" : __DIR__"feilong-bang",
                "south" : "/d/marry/hong-damen" ,
	]));

	setup();
	replace_program(ROOM);
}