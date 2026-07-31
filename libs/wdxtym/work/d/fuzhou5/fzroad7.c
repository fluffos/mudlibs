// Room: /d/fuzhou/fzroad7.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "闽赣古道");
	set("long", @LONG
进入江西，还是不尽的山坎和密林幽谷，终日不见天光。放眼
山中毒虫猛兽出没无常，行路艰辛。一到这里就闻到一股腥风扑鼻
而来。
LONG );
	set("exits", ([
		"northwest" : "/d/henshan/hsroad2",
		"eastup"    : __DIR__"fzroad6",
	]));
	set("objects", ([
		__DIR__"npc/huananhu" : 1,
	]));
	set("outdoors", "fuzhou");
	setup();
}

