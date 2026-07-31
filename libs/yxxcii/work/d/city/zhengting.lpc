// zhengting.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "正厅");
	set("long", @LONG
这里是福威镖局的正厅，几只太师椅一字排开，正中央坐着总镖头，
手持烟袋杆正在闭目沉思。墙上挂着几幅字画和一把宝剑。
LONG );
	set("exits", ([
		"north" : __DIR__"biaoju",
	]));
	set("objects", ([
		__DIR__"npc/linzhennan" : 1,
	]));

	setup();
	replace_program(ROOM);
}

