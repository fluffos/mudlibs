// Room: fanyinge.c

inherit ROOM;
#include <room.h>

void create()
{
	set("short", "梵音阁");
	set("long", @LONG
阁为三间单体高台建筑，阁内四面均有砖砌成的许多个方形小佛龛，龛内
各供泥塑佛像一尊。均身披袈裟，盘足坐莲台上，头部冒出佛光。是寺内诵经
礼佛的地方。在东南角有扇不大起眼的黑漆木门。
LONG
	);

	set("exits", ([
		"north" : __DIR__"fatang",
		"east" : __DIR__"jingtang",
		"west" : __DIR__"jingangyuan",
		"southdown" : __DIR__"hufazhacang",
		"northwest" : __DIR__"fotang",
	]));
        set("objects", ([__DIR__"npc/fanseng" : 2]));
	setup();
        create_door("northwest", "黑漆木门", "southeast", DOOR_CLOSED);
}
int valid_leave(object me, string dir)
{
        if (!present("shou yu", me)
           && dir == "northwest"  
           && present("hufa lama", environment(me)))
	return notify_fail(
"护法喇嘛拦住你道：“后山是本寺重地，你没有方丈的手谕，不能进去。\n");

	return ::valid_leave(me, dir);
}
