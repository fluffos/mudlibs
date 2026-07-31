//room: changlang1.c
inherit ROOM;

void create()
{
  set("short","玫瑰廊");
  set("long",@LONG
这是通往二位宫主寝宫的长廊，柱子和栏杆上都缠满了美丽的桂
花，左边有一间房间是涟星宫主的寝室，右面是邀月宫主的寝室。
LONG
     );

  set("exits",([
      "north" : __DIR__"changlang",
      "west" : __DIR__"lianxing",
      "east" : __DIR__"yaoyue",
     ]));

 setup();
 replace_program(ROOM);
}
