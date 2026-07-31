// Room: /d/japan/tiejiangpu
inherit ROOM;

void create()
{
  set ("short", "铁匠铺子");
  set ("long", @LONG
迎门是一个很大的火炉.有个家伙拿着铁锤,系着粗布围裙正在打铁.
旁边的一个小孩正使劲拉着风箱.墙上挂着几把刀,剑什么的.有几个人已
经在等着了,看来生意不错.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"jiedaoe1",
]));
        set("objects", ([ /* sizeof() == 1 */
               __DIR__"npc/jiujing" : 1,
            ]));
  setup();
}
