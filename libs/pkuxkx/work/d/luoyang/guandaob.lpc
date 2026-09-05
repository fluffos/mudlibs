//洛阳，扩展地图
//by kiden
//2006-9-8
//by zine Oct 17 2010，连接函谷关
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "大官道");
        set("long", @LONG
这是一条宽阔笔直，尘土飞扬的大官道，足可容得下十马并驰。往东
不远就是古都洛阳城，往西是一座天下闻名的雄关“函谷关”。
LONG
        );

        set("exits", ([
               "west" : __DIR__"hanguguan",
               "east" : __DIR__"guandaoa",

        ]));
        set("objects", ([
              __DIR__"npc/randomnpc" : 1,
           ]));


        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}

