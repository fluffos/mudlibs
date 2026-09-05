// File		: dating.c
// Created By	: iszt@pkuxkx, 2006-08-16

#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", HIC"凌霄大厅"NOR);
	set("long", @LONG
雪山派开宗立派数百年，数次对凌霄城修葺重建，凌霄大厅自是首当其冲，
经过一代代能工巧匠的细心雕琢，已经成为凌霄城宏大而又坚固的象征。厅上一
块古匾(bian)，雪山派弟子每月都在此集会，每每来客拜访，也多是由掌门人或
者大弟子在这里招待。
LONG);

	set("indoors", "凌霄城");
	set("item_desc", ([
		"bian" : "一块古匾，道是「"HIR"剑气凌霄"NOR"」，四个大字都被涂成红色，笔力遒劲，气势呼之欲出。\n",
	]));
	set("exits", ([
		"south" : __DIR__"bingjie5",
		"west" : __DIR__"datingw",
		"east" : __DIR__"datinge",
		"north" : __DIR__"houting",
	]));
	set("objects", ([
		__DIR__"npc/baiwanjian" : 1,
		__DIR__"npc/dizi" : 2,
	]));

        set("valid_startroom", 1);
	setup();
  "/clone/board/lx_b"->foo();
	replace_program(ROOM);
}
