// Room: /d/jiaofei/jiyuan
inherit ROOM;

void create ()
{
  set ("short", "五指山妓院");
  set ("long", @LONG
这里是五指山的妓院，此处虽是匪窝，但布置得富丽堂皇，富贵之气丝毫不亚于
扬州府的丽春院。里面的妓女大多是被土匪掳到山上的。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/jinv" : 4,
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"zjiedao1",        
]));

  setup();
  replace_program(ROOM);
}
