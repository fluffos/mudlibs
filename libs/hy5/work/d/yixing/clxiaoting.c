// /d/yixing/clxiaoting.c
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

void create()
{
	set("short", "小厅");
	set("long", @LONG
这是帮主及总管商讨机密大事的所在，正中是一张太师椅，门上吊
着半旧的红绸软帘。墙上附庸风雅地挂着几张山水字画，一望可知均是
俗手之作。窗前几盆菊花倒是十分繁茂。
LONG );
	set("exits", ([
		"south" : __DIR__"clzoulang2",
		"north" : __DIR__"clwoshi",
	]));
	set("objects",([
		__DIR__"npc/cl_situ" : 1,
	]));
	setup();
}

