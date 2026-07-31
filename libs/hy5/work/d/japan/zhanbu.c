// Room: /d/japan/zhanbu
inherit ROOM;

void create()
{
  set ("short", "占卜屋");
  set ("long", @LONG
一间小小的房子,屋子的四壁贴满了各种符录,在房子中间有一个白
色的大圆圈.一个长发的女子就盘腿端坐在里面.双手捧着个水晶球,在她
面前不远的地方,点了一支白蜡烛.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"jiedaoe2",
]));
  set("objects",( [ /* sizeof() == 1 */
  __DIR__"npc/nuwu":1,
]));
  setup();
        replace_program(ROOM);
}
