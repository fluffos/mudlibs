// Room: /d/japan/road2
inherit ROOM;

void create()
{
  set ("short", "大道");
  set ("long", @LONG
一条宽阔的大道,时不时有骑马的,坐轿的,小贩,行人经过.不过这儿
的人穿的衣服都十分奇特,你以前从没见过.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"road1",
  "southwest" : __DIR__"road",
]));
        set("objects", ([ /* sizeof() == 1 */
               __DIR__"npc/man" : 2,
            ]));
  set("outdoors", "japan");
  setup();
}
