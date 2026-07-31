// xidajie2.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
        set("short", "西大街");
        set("long", @LONG
你走在西大街上，感到这里的街面要比别处的干净、整洁。大概因为
靠近衙门、兵营可受保护的缘故，富人们都喜欢住在这里。东边静悄悄地
没有几个行人，西边是西城门通往郊外。南边是一座武馆，北边是一所富
丽堂皇的大宅院。
LONG );
        set("outdoors", "city");
        set("exits", ([
                "east"  : __DIR__"xidajie1",
                "south" : __DIR__"wuguan",
                "west"  : __DIR__"ximen",
                "north" : __DIR__"caizhu",
        ]));

        set("objects", ([
                __DIR__"npc/lao-heshang": 1,

        ]));

        setup();
}


