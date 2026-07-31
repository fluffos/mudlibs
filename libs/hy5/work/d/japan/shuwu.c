// Room: /d/japan/shuwu
inherit ROOM;

void create ()
{
  set ("short", "朝野书屋");
  set ("long", @LONG
朝野书屋是神户附近最大的书屋,进门就看到沿墙都摆满了书箱子,只
要你报出书名.老板就能找到你要的书.有许多还是从各国进口的呢!
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"jiedaos2",
]));
        set("objects", ([ /* sizeof() == 2 */
               __DIR__"npc/shantian" : 1,
            ]));

  setup();
}
