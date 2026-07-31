//nan1
  

inherit ROOM;

void create ()
{
  set ("short", "平安城南街");
  set ("long", @LONG
这是平安城的南街，宽敞的街道看的人不竟心情一畅。在街道的
东面熙熙攘攘的是一个饭馆。西面的一家客栈，一听里面的人来人往
的声音就知道是一家不小的客钱栈。
LONG);

  set("no_beg", 1);
  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"guangchang",
  "west" : __DIR__"pingankezhan",
  "south" : __DIR__"nan2",
  "east" : __DIR__"xiaochi",
]));
  set("outdoors", "pingan");
  set("pingan", 1);
  set("no_steal", 1);

  setup();
  replace_program(ROOM);
}
