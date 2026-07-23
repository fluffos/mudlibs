// Room: /d/sandboy/to_wudang2
inherit ROOM;

void create ()
{
  set ("short", "武当山前");
  set ("long", @LONG
穿过小路,穿过草丛,你来到一座大山跟前,北面一道长长的石阶一直
通向山顶,在山的高处隐隐露出几角红墙.西南角上一条大道笔直,据说沿着大
路一直走,就能到西南第一大都--成都
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "石碑" : "上面刻着<武当山>三个大字.
",
]));
  set("exits", ([ /* sizeof() == 1 */
   "northup" : "/d/wudang/shijie1",
   "east" : __DIR__"to_wudang",	
]));
  set("outdoors", "/d/sandboy");

  setup();
}
