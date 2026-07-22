#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{ 
         set("short","石廊");
       set("long", @LONG
一条青石砌成的走廊，周围并无半分饰物，但石色天青，石壁清凉。踏
在石面之上，空谷足音，令人暇想不已。清风送爽，传来阵阵幽香，不由使
人尘俗皆忘。
LONG
     );
	set("exits", ([
                "east" : __DIR__"xctang",
              //"west"  : __DIR__"nxaju",
            //  "north" : __DIR__"dmtang",
              "northwest" : __DIR__"gygu",	
       ]));
        set("coor/x",50);
  set("coor/y",420);
   set("coor/z",130);
   setup();
}
