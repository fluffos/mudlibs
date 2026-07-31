// Room: /d/shaolin/lhtang.c
// Date: by zqb

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY"罗汉堂"NOR);
    set("long", @LONG
你面前是一座很大的院落，周围用高墙围住，院门匾额上写着『罗汉堂』
三个大字。这里是少林弟子练习本门基本武功的所在。有很多年轻的僧人进进
出出，院内传来阵阵呼喝练功的声音。
LONG
);

	set("exits", ([
		"east" : __DIR__"stoneroad4",
		"west" : __DIR__"lwc",
	]));

	set("outdoors", "shaolin");
	set("objects",([
		"/kungfu/class/shaolin/xuan-ku" : 1,
	]));
	set("coor/x",30);
	set("coor/y",280);
	set("coor/z",120);
	setup();
}

void init()
{
	add_action("do_jump", "zong");
}

int do_jump(string arg)
{
	object me=this_player();   

	if (arg!="bian") return 0;
	if (me->is_busy()) return 0;
	if(me->query_skill("dodge",1)<130)  
		return notify_fail("你功力不够，跳不上匾额。\n");  
	message_vision("$N凝气守中，平空拔起数丈，轻轻落在匾额之后。\n", me);
	me->move(__DIR__"bianhou");
	tell_room(environment(me), me->name()+"跳了上来。\n", me);
	me->set_temp("baitie",1);
	return 1; 
}
