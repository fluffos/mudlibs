// Room: /d/huizhu/gebi1
inherit ROOM;

void create()
{
  set ("short", "戈壁沙漠");
  set ("long", @LONG
焦热的阳光晒着茫茫的戈壁，软绵的黄沙开始被大大小小的砾石所
代替。砂石之间的地面上开始出现青草，前面传来潺潺的流水声。看来
不远就有水源了。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"xiaoxi",
  "east" : __DIR__"gebi",
]));
  set("outdoors", "huizhu");
  setup();
  replace_program(ROOM);
}
