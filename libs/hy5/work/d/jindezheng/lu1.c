// Room: /d/jindezheng/lu1
inherit ROOM;

void create()
{
  set ("short", "树林");
  set ("long", @LONG
一片杂树林,地上铺了厚厚一层落叶.有一条小径隐约穿过树林,前
方似乎还升起一缕青烟.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"lu2",
  "northeast" : __DIR__"shulin2",
]));
  set("outdoors", "/d/jindezheng");
  setup();
//  replace_program(ROOM);
}

