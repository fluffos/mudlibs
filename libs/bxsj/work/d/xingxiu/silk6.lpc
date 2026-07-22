// /d/xingxiu/silk6.c

inherit ROOM;

void create()
{
        set("short", "丝绸之路");
        set("long", @LONG
这是闻名中外的丝绸商道。风沙弥漫，一片荒凉景象。南面连绵的祁连
山脉在阳光的照射下好像是一条玉带。只是有几人合抱之粗的古老胡杨，仍
然挺立在荒原上，笑迎风沙，频频招呼行人。西南是一片黄沙，传过沙漠就
可以到达昆仑山脉。
LONG);
        set("outdoors", "伊犁");

        set("exits", ([
		"southeast" : __DIR__"silk5",
		"northwest" : __DIR__"silk7",
		"southwest" : "/d/group/entry/mjshamo1",
        ]));

        set("objects", ([
		__DIR__"npc/shangren" : 1,
        ]));
	setup();
}

#include "/d/xingxiu/job2.h";
