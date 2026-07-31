// /d/mr/sleeproom.c
// by leontt 11/10/2000

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short",HIY"休息室"NOR);
	set ("long",@long
这是一间休息室, 里面摆设简单, 只有几张床, 一张书桌和一把椅子。
long);

	set("no_fight", 1);
	set("sleep_room", 1);
	set("exits",([
             "west" : __DIR__"didao1",

	]));
	setup();
}
