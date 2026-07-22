// by Xiaoyao

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "黄土高原");
	set("long", @LONG
黄河像一把厉刃将黄土高原切开。无数条小溪流夹带着泥沙汇入黄河，形
成千沟万壑。沟壑之间的一块块平地叫做台塬。黄河沿蒙古高原南边向东流淌，
遇太行山脉的阻拦，便转头南下，形成晋陕的分界。
LONG );
	set("exits", ([
		"northwest" : "/d/changan/road2",
		"southeast" : __DIR__"huanghe_1",
	]));
        set("objects",([
                NPC_D("tiao-fu") : 2,
        ]));
	set("outdoors", "黄河");
	setup();
}
