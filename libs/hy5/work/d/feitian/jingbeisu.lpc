// Room: /u/diabio/feitian/feitian/jingbeisu
inherit ROOM;

void create()
{
  set ("short", "京都警备署");
  set ("long", @LONG
维护京都次序的警备厅,不过现在这里正在施工建设中.所见之处
一片繁忙,大家都在努力的工作中.
LONG);

  set("no_clean_up", 1);
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"beijie",
]));
  set("no_magic", 1);
  set("no_fight", 1);
	set("objects",([
	__DIR__"npc/shuzhang":1,
	__DIR__"npc/xunbu":3,
	__DIR__"npc/xunjing":3,
]));
  setup();
  replace_program(ROOM);
}
