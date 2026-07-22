// Room: /d/hainan/wenquan 
inherit ROOM; 
 
void create ()
{
  set ("short", "温泉中");
  set ("long", @LONG
四面腾起的雾气遮住了你的视线.从身边传来的泼水声能听出池
中还有另外的几个人.你只能偶然看到她们的身影.温度适中的泉水泡
得人暖暖的.水面上飘浮着桃花的花瓣.
LONG);

  set("bath_room", 1);
  set("bath_equipment", "温泉");
  set("no_fight", 1);
  set("no_magic", 1);
  set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"taotree3",
]));

  setup();
}
