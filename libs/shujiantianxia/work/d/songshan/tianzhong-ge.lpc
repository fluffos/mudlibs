// Room: /tianzhong-ge.c
// Created by Numa 1999-11-21

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"天中阁"NOR);
	set("long", @LONG
此处位于嵩山派峻极禅院的中部，又名天中。由此再往前行，便是
嵩山最大的殿堂：峻极殿。东西两面各有一条碎石路直通这里。
LONG);
	set("exits", ([ 
            "north" : __DIR__"shidao2",
            "south" : __DIR__"yaocan-ting",
            "east" : __DIR__"suishilu1",
            "west" : __DIR__"suishilu2",
        ]));
        set("objects", ([ 
            CLASS_D("songshan") + "/tang" : 1,
        ]));
    set("indoors", "嵩山");
	set("coor/x",40);
  set("coor/y",310);
   set("coor/z",110);
   setup();
}
