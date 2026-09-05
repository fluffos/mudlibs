//room:cao1.c
inherit ROOM;
void create()
{
  set("short","草丛");
  set("long",
        "这里是乱草丛。东边是一座扇拱月形小敞门。其余三面都是齐腰\n"
    "高的蒿草，时常有蛇出没。\n"
        "到处都是蒿草，可见这里是人迹罕至，更没有人管理了！\n"
    );
  set("exits",([
         "west" :__DIR__"cao"+(random(2)+1),
        "north" :__DIR__"cao"+(random(2)+2),
        "east" : __DIR__"ximen",
        "south" : __DIR__"cao"+(random(2)+1),
     ]));
 set("objects",([
      __DIR__"npc/jinshe" : random(2),
      __DIR__"npc/snake" : random(2),
      ]));
 set("outdoors","baituo");
 setup();
 replace_program(ROOM);
}
