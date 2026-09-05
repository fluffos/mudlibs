// File		: xuenorth2.c
// Created By	: iszt@pkuxkx, 2006-09-04

#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", WHT"正厅"NOR);
	set("long", @LONG
这里就是徐元文坐馆授课的地方了，教授的不是蒙童，而是凌霄城中的
武功好手。闻道有先后，术业有专攻，教者学者都不觉得有什么不平等。求
学须缴学费，也是顺理成章的了。后边有一个小院。
LONG);

	set("indoors", "凌霄城");
	set("exits", ([
		"north" : __DIR__"xuxiaoyuan",
		"south" : __DIR__"xuejie2",
	]));
	set("objects", ([
		__DIR__"npc/xuyuanwen" : 1,
	]));

	setup();
	replace_program(ROOM);
}

