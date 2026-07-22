// Room: /d/mr/dating.c
// this is made by beyond
// update 1997.6.20
// Update by Lklv 2001.9.21

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",HIW"大厅"NOR);
	set ("long",@long
这里是大厅，厅中陈设简单，无什摆设，正堂上挂着许多人物字画，画得
都是慕容氏先祖的事迹，看来慕容氏对先人很尊敬。大厅的东边是书房，西边
有一个局室，往南面走则是后厅了。
long);
	set("exits",([
		"north" : __DIR__"xiaojing2",
		"west" : __DIR__"jushi",
		"south" : __DIR__"houting",
		"east" : __DIR__"shufang",
	]));
	set("objects",([
		__DIR__"../npc/gongye" : 1,
		FOOD_D("cha") : 2,
	]));
	setup();
}
