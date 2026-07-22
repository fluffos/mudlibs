// Room: /d/huashan/lianwu2.c
// Date: Look 99/03/25

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "练武场");
        set("long", @LONG
这是华山派的练武场，厚厚的石墙上打有一排排手掌痕迹，地砖已被踩出
一个个脚印。
LONG
        );
        set("no_sleep_room","1");

	 set("objects",([
		__DIR__"npc/shidaizi" : 1,
	 ]));
        set("exits",([
		"south" : __DIR__"wuqiku",
		"west" : __DIR__"celang2",
	 ]));
	 set("outdoors", "华山" );
        set("coor/x",100);
  set("coor/y",-10);
   set("coor/z",80);
   setup();
}
