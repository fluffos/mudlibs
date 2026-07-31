// Room: /d/japan/yijiguan
inherit ROOM;

void create()
{
  set ("short", "艺妓馆");
  set ("long", @LONG
一间装饰得很淡雅的房间,因为熏的香烟使房间显得有些朦胧.中间
的矮几上有一张琴,这里的女子是卖艺不卖身的.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"jiedao",
]));
         set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/dashou" : 3,
                __DIR__"npc/mamasang" : 1,
]));
  setup();
        replace_program(ROOM);
}
