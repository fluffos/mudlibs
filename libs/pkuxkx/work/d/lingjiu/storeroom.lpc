inherit ROOM;

void create()
{
  set("short","储藏室");
  set("long",@LONG
这里是灵鹫宫的储藏室，杂七杂八的摆放了很多东西。
LONG );
  set("exits",([
      "out" : __DIR__"eatroom",
  ]));
  set("objects",([
      
      __DIR__"obj/jiudai" : 20,
  ]));
//  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
