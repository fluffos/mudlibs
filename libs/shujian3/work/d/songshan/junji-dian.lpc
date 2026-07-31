// Room: junji-dian.c
// Created by Numa 1999-11-21

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"峻极殿"NOR);
	set("long", @LONG
整个大殿红墙黄瓦，金碧辉煌，是嵩山派的正殿，亦称中岳大殿。
外派上山偈拜大都在此等候左冷禅的召见，由此可见左冷禅意欲一统武
林的野心。
LONG);
	set("exits", ([ 
            "northup" : __DIR__"shidao3",
            "south" : __DIR__"junji-fang",
            "east" : __DIR__"suishilu3",
            "west" : __DIR__"suishilu4",
        ]));
       	set("objects", ([ 
            CLASS_D("songshan") + "/zhong" : 1,
            __DIR__"npc/ssdizi" : 2,
        ]));
    set("indoors", "嵩山");
	set("coor/x",40);
  set("coor/y",340);
   set("coor/z",120);
   setup();
}
