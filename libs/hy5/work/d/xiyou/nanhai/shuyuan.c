//Cracked by Roath
// Room: /d/xiyou/nanhai/shuyuan
inherit ROOM;

void create ()
{
  set ("short", "书院");
  set ("long", @LONG

这里就是普陀山书院，书架上摆着无数书籍。普陀山门人弟子
中有来提高基本读书识字的，更多的是来钻研佛经修练佛法的，
以期早日修得正果。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"zoulang",
]));
  set("objects", ([ /* sizeof() == 3 */

  __DIR__"npc/shami" : 1,
]));
  set("light_up", 1);

  setup();
}
