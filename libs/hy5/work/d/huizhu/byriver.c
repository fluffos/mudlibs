// Room: /d/huizhu/byriver
inherit ROOM;

void create()
{
  set ("short", "湖边");
  set ("long", @LONG
草原西端一座高山参天而起，耸入云霄，从山腰起全是皑皑白雪，山
腰以下却生满苍翠树木.树上小鸟鸣啾，湖中冰块撞击与瀑布声交织成一片
乐音。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"byriver1",
  "south" : __DIR__"xiaoxi2",
]));
  set("outdoors", "huizhu");
  setup();
  replace_program(ROOM);
}
