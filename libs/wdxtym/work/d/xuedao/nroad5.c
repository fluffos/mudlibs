// nroad5.c
inherit ROOM;
void create()
{
	set("short", "山路");
	set("long", @LONG
这是一条崎岖的山路，马队到了这里就不能在上去了。山路两旁杂草从
生，路开始越来越难走。
LONG );
	set("exits", ([
		"northdown" : __DIR__"nroad6",
		"southup"   : __DIR__"nroad1",
	]));
	set("objects",([
		__DIR__"npc/eagle" : 2,
	]));
	set("outdoors", "xuedao");
	setup();
}

