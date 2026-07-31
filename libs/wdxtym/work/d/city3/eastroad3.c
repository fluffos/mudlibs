// Room: eastroad3.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "东大街");
	set("long", @LONG
你走在东大街上，踩着坚实的青石板地面。向北是一条宽直的大
道。北边可以通往东城门，西南边通向南大街，东南方就是有名的望
江楼了。
LONG );
	set("outdoors", "chengdu");
	set("exits", ([
	    "southeast"  : __DIR__"wangjianglou",
	    "southwest"  : __DIR__"southroad1",
	    "north"      : __DIR__"eastroad2",
	]));
//	set("no_clean_up", 0);
	setup();
}
