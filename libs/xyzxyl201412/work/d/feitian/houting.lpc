// Room: /d/feitian/houting
inherit ROOM;

void create()
{
  set ("short", "后庭");
  set ("long", @LONG
这是道场的后庭，宽广的院子中放置着几个木人。那是弥彦用来苦练武功用的
你也可以上去训练一下。在远方隐隐约约看的到一个小房子。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"chucangshi",
  "south" : __DIR__"daochang",
]));
  set("outdoors", "feitian");
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/muren" : 4,
]));
  setup();
  replace_program(ROOM);
}
