//room: changlang.c
inherit ROOM;

void create()
{
  set("short","桂花廊");
  set("long",@LONG
这是通往宫主寝宫的长廊，柱子和栏杆上都缠满了美丽的桂
花，左边有一间房间，从里面传来很嘈杂的声音，似乎有很多人。
LONG
     );

  set("exits",([
      "west" : __DIR__"foodroom",
      "east" : __DIR__"bingqi",
      "north" : __DIR__"yihua_ge",
      "south" : __DIR__"changlang1",
     ]));

 setup();
 replace_program(ROOM);
}
