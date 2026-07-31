//Room: /d/japan/path.c
inherit ROOM;

void create()
{
   set ("short", "土路");
  set ("long", @LONG
一条宽阔的黄土大道向远方延伸开去，西边巍峨的神户东门
高高的耸立着，几名城卫在来回巡视。喧闹的人声不停的传来。
LONG);

  set("exits", ([ /* sizeof() == 1 */
     "west" : __DIR__"dongmen",
      "east" : __DIR__"path1",
]));
  set("outdoors", "japan");
  setup();
        replace_program(ROOM);
}
