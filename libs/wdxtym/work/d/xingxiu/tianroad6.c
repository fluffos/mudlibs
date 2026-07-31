// room: /d/xingxiu/tianroad6.c
inherit ROOM;
#include <ansi.h>;
string look_wind();
int lian(string arg);
void create()
{
	set("short", "天山顶峰");
	set("long", @LONG
这里是天山顶峰。从这里向周围望去，帕米尔高原的风光尽收眼底。东面
一条小路可以下山。山风(wind)凛冽，极为强劲，几乎无法站立。
LONG
	);
	set("exits", ([
	    "eastdown" : __DIR__"tianroad5",
	]));
	set("item_desc", ([
	    "【风口】" : (: look_wind :),
	]));
	set("outdoors", "xingxiu");
	setup();
}

string look_wind()
{
	return "这是一年到头永无止歇的来自极北溟海的玄风，刺面刮耳，凛冽非常。\n";
}
