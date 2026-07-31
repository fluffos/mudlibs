// Room: /city/dangpu.c
// YZC 1995/12/04 

inherit ROOM;

void create ()
{
  set ("short", "当铺");
  set ("long", @LONG
这是一家以买卖公平著称的当铺，一个五尺高的柜台挡在你的面
前，柜台上摆着一个牌子(paizi)，柜台后坐着唐老板，一双精明的
上上下下打量着你。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "公平交易

sell        卖 
buy         买
redeem      赎
value       估价
",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tang" : 1,
]));
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"dong1",
  "east" : __DIR__"dangpu2",
]));
       set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	

  setup();
  replace_program(ROOM);
}
