// Room: /d/nanyang/xujiaji.c
// Lklv Modify 2001.10.11

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIY"许家集"NOR);
	set("long", @LONG
这是南阳附近的许家集，市集上很热闹，附近的农民经常到这里来交易自
己辛苦劳动的成果。集市旁边有片空地，停着几辆马车。东面有家客栈，门口
正对着这里。
LONG
	);
	set("outdoors", "南阳");
	set("exits", ([
		"north" : __DIR__"qslu",
		"southwest" : __DIR__"xiaolu2",
		"east" : __DIR__"kedian1",
		"south" : __DIR__"qslu2",
	]));
	set("objects",([
		NPC_D("kid") : 1,
	]));

	setup();
}
