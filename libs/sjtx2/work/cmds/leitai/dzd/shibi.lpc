// Room: /d/dzd/shibi.c

#include <ansi.h>
#define OUT_DOWN __DIR__"shidong4" 
#define W_MSG "附在石壁上"
inherit __DIR__"dzd_room";
#include "yinmi.h"

string look_down();

void create()
{
	set("short","石壁");
	set("long",@LONG
这里是山洞壁上一块凸起的大石，你藏身与此,只觉得这里阴冷潮湿，
头顶上有水滴慢慢地滴下，打在石上哒哒做响，在这冷寂的山洞中回响着。
石上非常滑，你紧紧抓住石头的突起部分，生怕掉了下去。你隐约可以看到
下边(down)的情况。
LONG
	);
	set("item_desc",([
		"down" : (: look_down :),
	]));
	setup();
}