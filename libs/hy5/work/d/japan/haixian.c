// Room: /d/japan/haixian
inherit ROOM;

void create()
{
  set ("short", "海鲜馆");
  set ("long", @LONG
穿着粗布服的侍者头上扎着白毛巾.不时来往于大厅中的数十张桌子
之间.日本是个岛国,海鲜是很便宜的.吃生鱼片的人也确实挺多.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"jiedaos",
]));
   set("objects",( [ /* sizeof() == 1 */
      __DIR__"npc/paotang":1,
]));
  setup();
           replace_program(ROOM);
}
