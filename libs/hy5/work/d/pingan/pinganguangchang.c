// Room: /d/pingan/pinganguangchang
inherit ROOM;

void create ()
{
  set ("short", "平安广场");
  set ("long", @LONG
这儿是平安城的中心广场，其实说是广场罢了！这儿并不大。一如平安
城其它的地方一样！这儿也是一片和平的景象，平安城的居民们在周围走来
走去，对江湖人物并不回避。广场四周也没有很复杂的街道！只有一排小小
的店面和一条向南的平安大道。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"pinganlu2",
  "north" : __DIR__"pingankezhan",
  "east" : __DIR__"wuguan",
]));
  set("pingan", 1);
  set("outdoors", "y");
  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);

  setup();
  "/clone/board/pingan_b"->foo();
}
