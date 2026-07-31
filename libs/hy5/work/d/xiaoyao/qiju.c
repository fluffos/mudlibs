inherit ROOM;

#include <ansi.h>
void create()
{
  set("short","玲珑棋局");
  set("long",@LONG
这玲珑棋局惑乱人心，你只感到周转金戈铁马，觉得十分夸张。
现在想想身边的楚河汉界，走卒车马，更觉的夸张。
LONG);

     set("outdoors", "xiaoyao");
     set("exits",([
           "east" : __DIR__"qiju",
           "west" : __DIR__"qiju",
           "north" : __DIR__"qiju",
           "south" : __DIR__"qiju",
     ]));
 	set("objects", ([
		__DIR__"npc/qiwushi" : 2,
	]));
     setup();
}
#include "songlin.h"                  