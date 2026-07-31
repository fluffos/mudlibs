// Room: /d/feitian/daochang.c
inherit ROOM;

void create()
{
  set ("short", "神古活心流");
  set ("long", @LONG
这里就是神古活心流的道场了，历代的师傅都在这里传授武技。
正面的墙上挂着一本留名册(ce zi)凡是这里的弟子都需要在
册上留名才能算正式弟子.
LONG);
set("valid_startroom", "1");
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"houting",
  "west" : __DIR__"bingqishi",
  "south" : __DIR__"zoulang",
  "east" : __DIR__"xiangfang",
]));
  set("objects", ([ /* sizeof() == 2 */
//  __DIR__"obj/liumingce" : 1,
  __DIR__"npc/axun" : 1,
                "quest/menpai/feitian/shi" : 1,
                "d/biwu/champion_feitian" : 1,
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "che zi" : "这是飞天御剑流历代弟子的留名册。(read)
",
]));
  setup();
//  replace_program(ROOM);
	"/clone/board/feitian_b"->foo();
}
