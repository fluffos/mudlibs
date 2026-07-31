// Room: /d/nanyang/shijie4.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "石阶");
    set("long", @LONG
水声越来越大，山间充满了浓浓的水气。石阶上，断裂的山
隙中，都流出一道道细细的泉水，汇成一股澄碧的小溪，向山下
蜿蜒流去。周围绿意荡漾，鸟语鹦声，如置身仙境。
LONG
    );
    set("no_clean_up", 0);
    set("outdoors", "shaolin");
    set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"shijie3",
  "northup" : __DIR__"shijie5",
]));
    setup();
    replace_program(ROOM);
}
