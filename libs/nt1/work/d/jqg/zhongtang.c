// zhongtang.c

inherit ROOM;
#include <ansi.h>

void create()
{
       set("short",HIC"中堂"NOR);
       set("long", @LONG
你举步走入一间茅屋的中堂，只见屋中陈设简陋，但洁净异常，堂上只有
一桌一几，此外便无别物。
LONG
        );

       set("exits", ([
	  "out" : __DIR__"xiaolu",
	  "east" : __DIR__"xiaoshi",
          "north" : __DIR__"wshi",
       ]));	
       setup();
       replace_program(ROOM);
}

