// Room: /d/yanjing/gardon
inherit ROOM;

void create()
{
  set ("short", "小院子");
  set ("long", @LONG
绕过一道竹篱，眼前出现三间乌瓦白墙的小屋。这是寻常乡下百姓
的居屋，不意在这豪奢富丽的王府之中见到.屋子周围开了两畦地,种了
些蔬菜,旁边的一口水井看来是汲水浇灌用的.
LONG);

  set("outdoors", "yanjing");
  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"gardon1",
  "west" : __DIR__"inroom",
]));
  setup();
  replace_program(ROOM);
}
