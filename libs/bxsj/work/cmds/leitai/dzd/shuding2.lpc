// Room: /d/dzd/shuding1.c

#include <ansi.h>
#define OUT_DOWN __DIR__"senlin4" 
#define W_MSG "在树上"
inherit __DIR__"dzd_room";
#include "yinmi.h"

string look_down();

void create()
{
	set("short","树顶");
	set("long",@LONG
这里是大树的树顶。四面都是有几百年树龄的大树，枝叶繁盛完全挡住了你的身影。
透过树叶的空隙，你可以约略看到树下(down)的情景。
LONG
	);
	set("outdoors","大智岛");
	set("item_desc",([
		"down" : (: look_down :),
	]));
	setup();
}