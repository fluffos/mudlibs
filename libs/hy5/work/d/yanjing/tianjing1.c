// Room: /d/yanjing/tianjing1
inherit ROOM;

void create()
{
  set ("short", "天井");
  set ("long", @LONG
四四方方的一个天井,东西两边是高高的围墙,院中水磨青砖平滑的很.
除此之外,别无他物.但只要有人进入此地,因为四外别无遮挡,非被发现不
可.北面的房屋没有窗户,门也开得很窄,看来很神秘.
LONG);

  set("outdoors", "yanjing");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room",
  "north" : __DIR__"intielao",
]));
  setup();
  replace_program(ROOM);
}
