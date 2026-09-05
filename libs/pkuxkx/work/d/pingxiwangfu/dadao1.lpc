inherit ROOM;
void create()
{
        set("short", "王府大道");
        set("long", @LONG
一条青石大道，左右皆是高大华丽的建筑，一副王者的气派．
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"dadao2",
  "south" : __DIR__"wangfugate",
  "east" : __DIR__"guardroom1",
  "west" : __DIR__"guardroom2",
]));

     set("outdoors", "pingxiwangfu");
        setup();
        replace_program(ROOM);
}

