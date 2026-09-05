// File		: jiaomenw.c
// Created By	: iszt@pkuxkx, 2006-09-04

inherit ROOM;

void create()
{
	set("short", "西角门");
	set("long", @LONG
这里是连接内城和外城的角门，不时有雪山弟子进进出出，也有杂役人等来
往。路中央的青石板已经被磨得失去了棱角，还散落着一些木炭等的痕迹。旁边
是两名弟子在值守。
LONG);

	set("outdoors", "凌霄城");
	set("exits", ([
		"northeast" : __DIR__"stonew1",
		"south" : __DIR__"stonesw",
	]));
	set("objects", ([
		__DIR__"npc/dizi_jiaomen" : 2,
	]));

	setup();
	replace_program(ROOM);
}