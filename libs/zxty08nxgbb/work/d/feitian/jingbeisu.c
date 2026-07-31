// Room: /u/diabio/feitian/feitian/jingbeisu
inherit ROOM;

void create()
{
  set ("short", "京都警备署");
  set ("long", @LONG
维护京都次序的警备厅,不过现在这里正在施工建设中.所见之处
一片繁忙,大家都在努力的工作中.工地边立了个牌子(paizi)
LONG);

  set("no_clean_up", 1);
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"beijie",
]));
  set("no_magic", 1);
  set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "施工建设中,闲杂人等误进.
",
]));
  setup();
  replace_program(ROOM);
}
