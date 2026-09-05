// shufang.c
inherit ROOM;
void create()
{
        set("short", "书房");
        set("long", @LONG
这里是华山派掌门人「君子剑」岳不群的书房，平时岳先生
在此会见熟人。房里只有几排书架。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"houhuayuan2",
]));
        set("objects", ([
                CLASS_D("huashan") + "/yue" : 1,
                CLASS_D("huashan") + "/ning" : 1]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
