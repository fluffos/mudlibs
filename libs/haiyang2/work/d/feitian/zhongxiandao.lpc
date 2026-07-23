// Room: /d/feitian/zhongxiandao
inherit ROOM;

void create()
{
  set ("short", "中仙道");
  set ("long", @LONG
通往京都的一条小道，前方不远的路上可以看见一片很大的森林。
路上左右的行人都很稀少了，耳边可以不时听到鸟叫声。
在小道旁边树立这一个牌子(paizi).
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"senlin1",
  "south" : __DIR__"path2",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "行人止步森林凶险，勿进。------警备署
",
]));
  set("outdoors", "feitian");
  setup();
  replace_program(ROOM);
}
