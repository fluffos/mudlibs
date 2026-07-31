// Room: shanfang.c
// Created by Numa 1999-11-21

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"膳房"NOR);
	set("long", @LONG
从碎石路出来，便是膳房，不断有阵阵菜香飘出。里面饭厅极大，
足可容纳上千人同时用膳，从东到西摆放了一排排的餐桌和长凳。几
名厨师正在紧张的忙碌着，也有不少的嵩山弟子在这里来打杂干活。
LONG);
	set("exits", ([ 
            "west" : __DIR__"suishilu1",
        ]));
    set("objects", ([ 
            __DIR__"npc/chuzi" : 1,
    ]));
    set("no_fight_room",1);
    set("no_steal_room",1);
    set("indoors", "嵩山");
	set("coor/x",60);
  set("coor/y",310);
   set("coor/z",110);
   setup();
}
