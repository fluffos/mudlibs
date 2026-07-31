// Room: /d/japan/jiedaoe2
inherit ROOM;

void create()
{
  set ("short", "街道");
  set ("long", @LONG
一条宽阔的街道,南面有一间房间吸引了你的注意,这是一间很小的
房子.门上贴了张古怪的符.北面的店铺门口挂了串白色灯笼.看来令人感
到一阵阵的莫名恐怖.
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"guancai",
  "south" : __DIR__"zhanbu",
  "east" : __DIR__"jiedaoe3",
  "west" : __DIR__"jiedaoe1",
]));
        set("objects", ([ /* sizeof() == 1 */
               __DIR__"npc/man" : 2,
            ]));
  set("outdoors", "japan");
  setup();
        replace_program(ROOM);
}
