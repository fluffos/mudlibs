//Room: /d/feitian/path1.c
inherit ROOM;

void create()
{
   set ("short", "土路");
  set ("long", @LONG
一条宽阔的黄土大道向远方延伸开去，东边就是历史古都东京
巍峨的西门高高的耸立着，几名城卫在来回巡视。喧闹的人声
不停的传来。
LONG);

  set("exits", ([ /* sizeof() == 1 */
     "south" : "d/japan/senlin2",
      "southeast" : __DIR__"path2",
]));
  set("outdoors", "/d/japan");
  setup();
        replace_program(ROOM);
}
