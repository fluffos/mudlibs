// Room: /d/yanjing/lack
inherit ROOM;

void create()
{
  set ("short", "定波湖");
  set ("long", @LONG
微风过处,湖面闪起一片鳞光,几枝垂柳长长的枝条荡下来,点动着
水面漾起一圈圈涟漪.西南边是条卵石小道,可以出去.北边的花木中一
栋厢房是给客人住的.据说最近有长白来客居住.
LONG);

  set("outdoors", "yanjing");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"liangziweng",
  "southwest" : __DIR__"road1",
]));
  setup();
  replace_program(ROOM);
}
