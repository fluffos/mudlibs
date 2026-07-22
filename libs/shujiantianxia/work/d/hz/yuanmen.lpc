// /u/beyond/hz/yuanmen.c 园门
#include <ansi.h>
 
inherit ROOM;
void create()
{
        set("short",HIW"园门"NOR);
        set("long", @LONG
入墓园门是一个小庭院，内有南北两道碑廊，南廊陈列着南宋以来历代
诗人歌颂岳飞的誓词碑刻；北廊有岳飞的手记《满江红》、《前后出师表》，
还有奏章、宋高宗诏书、岳飞的石刻像等。
LONG
        );
        set("exits", ([
            "east" : __DIR__"jingzhong",
            "out" : __DIR__"yuemiao",
            
]));
        set("coor/x",90);
  set("coor/y",-350);
   set("coor/z",10);
   setup();
}
