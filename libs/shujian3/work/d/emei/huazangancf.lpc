// huazangancf.c
// 禅房
inherit ROOM;
#include <room.h>
#include <ansi.h>
//#include "jingzuo.h";
void create()
{
	set("short", "禅房");
	set("long",@long
这里便是峨嵋华藏庵的禅房。地下散乱地放着许多蒲团，木鱼等，此处
正是本派弟子打坐修行之所。几位年轻师太和俗家女弟子正肃容入定。
long);
	set("exits",([
	    "north" : __DIR__"xcelang",
	    "south" : __DIR__"xiuxishi",
	    "east" : __DIR__"daxiong",
]));
    set("jingzuo", 1);
    set("no_fight", 1);
create_door("south", "小门", "north", DOOR_CLOSED);
	setup();
}

int valid_leave(object me, string dir)
{
        if ((string)me->query("gender")=="男性" && dir == "south")
                return notify_fail("那里是师太们休息的地方，你不能进去。\n");
        return ::valid_leave(me, dir);
}

