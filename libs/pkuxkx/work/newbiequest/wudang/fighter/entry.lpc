// milin3.c 密林
// seagate@pkuxkx 路径动态更新
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "林间空地");
	set("long", 
"这是小树林中间的一片空地，似乎没什么危险！\n"
	);
  set("outdoors", 1);	
	setup();
}

void init()
{
	if(userp(this_player()))
		tell_object(this_player(), HIM"你已经走完了第一段小树林迷宫！\n"NOR);
}