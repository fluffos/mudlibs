inherit ROOM;
void create()
{
        set("short", "不眠阁");
        set("long", @LONG
此阁无顶。每当深夜，微风袭袭，繁星点点；一轮明月，悬于正央。放眼眺望，
大理城尽收眼底。苍穹暗淡，唯阁烛一盏；万物尽淡，唯英雄美人。。。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "westdown" : __DIR__"secfloor",
]));


        set("objects", ([ /* sizeof() == 1 */
         __DIR__"npc/lishishi" : 1,
]));
        set("outdoors","dali");
        setup();
}
