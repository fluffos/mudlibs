 // Room: /d/oldpine/riverbank2.c
inherit ROOM; 
void create()
{
        set("short", "山涧之中");
        set("long", @LONG
你现在正站在一条山涧中的岩石上，一座小石桥正高高地从你的头
顶横跨过山涧两边的石壁，一个瀑布就在你的北方不远处，从一处更高
的悬崖上垂了下来。
LONG
        );
        set("item_desc", ([
                "cliff":
                        "这里的山壁比北边高度稍低了点，但是对凡人而言想要爬上去仍然\n"
                        "还有一段差距。\n"
        ]) );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"waterfall",
  "south" : __DIR__"riverbank1",
]));
        set("outdoors", "oldpine");
        set("resource/water", 1); 
        set("coor/x",540);
        set("coor/y",2350);
        set("coor/z",70);
        setup();
        replace_program(ROOM);
}  
