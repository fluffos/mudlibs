// Room: /d/city/dangpu2
inherit ROOM;

void create ()
{
  set ("short", "当铺内室");
  set ("long", @LONG
这儿是平安当铺的内室，是由唐楠在风云中的同行香菱掌柜的。主
要是为了帮玩家们在退出游戏时暂存一些东西的地方。虽然方便，但是
由于一当一买的差额，玩家在这里存放东西会消耗很多的金钱。柜台上
也摆了一个牌子（paizi）。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "这儿可以用的命令有如下：
value  估价
pawn 当东西
redeem 赎回东西
",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiangling" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dangpu",
]));
       set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	

  setup();
  replace_program(ROOM);
}
