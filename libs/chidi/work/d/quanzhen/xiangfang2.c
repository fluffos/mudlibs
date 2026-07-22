// xiangfang2.c 厢房

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "厢房");
        set("long", @LONG
你站在一间不大的厢房中，房间打扫的很干净。靠左墙是一排书架，摆着百
十部经籍，三书五典，琳琅满目。书架前，是一张书案，文房四宝琴鼎具备。室
的右侧，有一张矮床，床上放着一个以狼尾草编成的蒲团。
LONG
        );
        
        set("exits", ([
                "west" : __DIR__"neiyuan",
          ]));
           set("sleep_room","1");
           set("no_yun","1");
           set("no_fight","1");
           set("no_steal","1");
        set("coor/x",-90);
        set("coor/y",280);
        set("coor/z",190);
        setup();
        replace_program(ROOM);
}
