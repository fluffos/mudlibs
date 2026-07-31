 inherit ROOM;
void create()
{
        set("short", "书室");
        set("long", @LONG
一入此房，顿觉眼前一亮，四壁皆是条幅，正中墙上挂着一副
唐朝张旭的《率意帖》，帖上的草书大开大阖，便如一位武林高手
展开轻功，窜高伏低，虽然行动迅捷，却不失高雅的风致。
LONG
        );
        set("exits", ([
                "east" : __DIR__"huashi",
        "west" : __DIR__"qishi",
        ])); 
        set("objects", ([
        __DIR__"npc/tong3": 1,
    ])); 
        set("coor/x",3290);
        set("coor/y",30);
        set("coor/z",-20);
        setup();
}      
