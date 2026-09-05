//caiyuan.c -- 菜园
//Zone: 万安寺
//Created by ddid
//2009-6-18

#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", HIC"菜园"NOR);
  set("long", @LONG
这里是万安寺内的菜园，万安寺内大部分的蔬菜供应都是来自这里。
不少原先万安寺的僧人现在都在这里干活。
LONG
  );

  set("exits", ([     
      "west" : __DIR__"wanansi-chanfange1",   
  ]));

  set("outdoors", "luoyang");
  setup();
  replace_program(ROOM);
}
