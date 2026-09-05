#include <room.h>
inherit ROOM;

void create()
{
set("short", "迎新茶馆");
set("long", @LONG
你一走进来，就闻到一股茶香沁入心脾，精神为之一爽。几张八仙桌一字
排开，坐满了客人，或高声谈笑，或交头接耳。你要想打听江湖掌故和谣言，
这里是个好所在。
[1;32m[提示]：这里可以免费装水，指令为：fill <容器> ，例如：fill jiudai[37;0m
LONG
        );
set("no_fight", 1);
        set("resource/water", 1);

        set("exits", ([
                "southwest" : __DIR__"train2_center",
        ]));

        set("objects", ([
                __DIR__"npc/baodating" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
