//room: changl15.c
#include <ansi.h>  

inherit ROOM;

void create()
{
  set("short","画廊");
  set("long",@LONG
这是一条非常精美的长廊，柱子和栏杆是用华贵的紫檀木制成，上面
雕饰着美丽的图画，画工精巧，美不胜收。地板不知是用什么材料做的，
走在上面毫无声息，你只感到脚下软软的，非常舒服。一阵阵花香从北边
传来。
LONG );
  set("exits",([
      "west" : __DIR__"changl7",
      "east" : __DIR__"changl8",
      "south" : __DIR__"dating",
      "north" : __DIR__"huayuan",
  ]));
  setup();
  replace_program(ROOM);
}
