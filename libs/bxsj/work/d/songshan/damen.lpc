// Room: /d/songshan/damen.c

inherit ROOM;
#include <wanted.h>

void create()
{
	set("short", "峻极宫大门");
	set("long", @LONG
峻极宫本是前朝佛教大寺，近百年来却已成为嵩山派的住所。大门
两旁有两个巨大的石狮雕象，一旁旗帜飘扬，人影涌动，而门匾也早已
换成了“嵩山剑派”四个大字。
LONG);
	set("exits", ([ 
            "north" : __DIR__"chanyuan",
            "south" : __DIR__"kuangdi",
        ]));
	set("objects", ([ 
            CLASS_D("songshan") + "/shi" : 1,
            __DIR__"npc/ssdizi" : 2,
        ]));
        set("no_fight",1);
        set("outdoors", "嵩山");
	set("coor/x",40);
  set("coor/y",270);
   set("coor/z",110);
   setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "north" && is_wanted(me))
		return 0;
	return ::valid_leave(me, dir);
}
