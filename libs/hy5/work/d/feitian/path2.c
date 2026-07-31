//Room: /d/feitian/path2.c
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
     "northwest" : __DIR__"path1",
      "east" : __DIR__"ximen",
      "north" : __DIR__"zhongxiandao"
]));
  set("outdoors", "feitian");
  setup();
        replace_program(ROOM);
}
