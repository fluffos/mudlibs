// huazangancj.c
// 藏经楼
inherit ROOM;
#include <room.h>

void create()
{
	set("short", "藏经楼");
	set("long",@long
小阁楼上便是峨嵋派的藏经阁了。这里都是密密麻麻，高及顶棚的书架。
窗口下有一张大桌子，桌上放了几本佛经。有个小师太正在向静道师太借书。
long);
	set("exits",([
            "down" : __DIR__"chuwujian",
]));
        set("objects",([
		CLASS_D("emei") + "/jing-dao" : 1,
		"/d/emei/obj/fojing1" : 1,
		"/d/emei/obj/fojing2" : 1,
          ]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "down" && present("shu", me) && objectp(present("jingdao shitai", environment(me))))
		return notify_fail("静道师太喝道：“藏经楼内书籍不得外带。\n");

	return ::valid_leave(me, dir);
} 
