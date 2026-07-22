// Room: yaofang.c
// Created by Numa 1999-11-21

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"药房"NOR);
        set("long", @LONG
从东边的碎石路一出来，便可以闻到一股浓浓的药香，让人精神为
之一振，立马神清气爽。这里就是嵩山派的药房，里面各种灵丹妙药应
有尽有，旁边还有几名嵩山弟子正在敷药疗伤。
LONG);
        set("exits", ([ 
            "east" : __DIR__"suishilu2",
        ]));
	set("indoors", "嵩山");
    set("no_fight_room", 1);
    set("no_steal_room", 1);
	set("objects", ([
        	__DIR__"npc/yaoshi" : 1,
    	]));

        set("coor/x",20);
  set("coor/y",310);
   set("coor/z",110);
   setup();
}
