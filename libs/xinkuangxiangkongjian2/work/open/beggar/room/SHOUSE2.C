inherit ROOM;

void create ()
{
  set ("short", "小草屋");
  set ("long", @LONG
  这里是丐帮新进弟子练基本功的地方，听到一声声的吆喝
  声，你不禁热血沸腾，跃跃欲试，准备大显身手一般。
  

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/u/l/list/npc/trainee/trainee2.c" : 3,
]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"room07.c",
]));

  setup();
}
