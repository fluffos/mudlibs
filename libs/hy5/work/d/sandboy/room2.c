// Room: /d/sandboy/room2 
inherit ROOM; 
 
void create ()
{
  set ("short", "卧室");
  set ("long", @LONG
一张粗木床,铺着厚厚的稻草,上面是一床破棉絮,旁边窗下一张梳妆台,
不油不漆,屋角落中的一只木脚盆堆满了待洗的衣服.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/woman.c" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"room1",
]));

  setup();
}
