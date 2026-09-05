// houhuayuan1.c
inherit ROOM;
void create()
{
        set("short", "后花园");
        set("long", @LONG
这里是华山派的后花园，种满了花草。几个小童正在浇花
北边是客厅，掌门人常在那里会客。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"buwei1",
  "south" : __DIR__"fanting",
  "west":__DIR__"houhuayuan2",
  "east" : __DIR__"liangong",
]));
        set("objects", ([
                __DIR__"npc/xiaotong" : 2,
        ]));

        set("no_clean_up", 0);
        set("outdoors", "xx" );
        setup();
        replace_program(ROOM);
}
