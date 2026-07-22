// Room: /chengdu/dongdajie.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "东大街");
	set("long", @LONG
这条街贯穿成都大街小巷，因这条街沿街都是有钱有势的酒
楼、茶馆，所以又称为“美食街”。这里店铺林立，商贾成群。
白天这里车马如龙，人声鼎沸，夜里星光伴月，灯火通明。南边
是个茶馆，北边有个水井。
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "east" : __DIR__"eastchengmen",
                "south" : __DIR__"cdchaguan",
                "north" : __DIR__"shuijing",
                "west" : __DIR__"dongjie1",

	]));
        set("objects", ([
            __DIR__"npc/youke" : 1,
        ]));

	setup();
	replace_program(ROOM);
}

