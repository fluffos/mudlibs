// xiaoshi.c

inherit ROOM;
#include <ansi.h>

void create()
{
       set("short",HIC"小室"NOR);
       set("long", @LONG
你举步走入一间小室，只见屋中两侧堆满了杂物，左面是一堆柴草引火之
物，右面则有几个陶制的碗罐和一个粗木搭制的凳子。
LONG
        );
       set("exits", ([
	  "west" : __DIR__"zhongtang",
	  "east" : __DIR__"dashi",
       ]));	

       set("objects", ([
              // __DIR__"npc/yangguo" : 1,
       ]));
       setup();
}

