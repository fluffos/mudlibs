//Room: /d/feitian/path3.c
inherit ROOM;

void create()
{
   set ("short", "土路");
  set ("long", @LONG
一条宽阔的黄土大道向远方延伸开去，东边是一片原始森林不
停的传来几声狼嚎。
LONG);

  set("exits", ([ /* sizeof() == 1 */
      "east" : __DIR__"senlin1",
//      "west" : "d/kyoto/pathe",
]));
  set("outdoors", "feitian");
  setup();
        replace_program(ROOM);
}
