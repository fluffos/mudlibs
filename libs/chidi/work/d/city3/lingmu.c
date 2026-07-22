//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "陵墓");
        set("long", @LONG
这里有一座很大的陵墓，你走到这里，感觉怪怪的，不
知道有什么地方不对，也许是这里的气氛使人有些压抑吧，
有个扫墓人在那里不停地唉声叹气。
LONG
        );

        set("exits", ([
                "east" : __DIR__"wuhou",
        ]));
        set("objects",([
                 "/d/city3/npc/saomuren" : 1,
        ]));

        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}

 
