//zhulin.c
inherit ROOM;
void create()
{
  set("short","竹林");
  set("long",
        "从蒿草丛中好容易走到这里，你赫然发现这里竟然有好大的一片\n"
    "青竹林，真是难得。当然这里也还是常有蛇出没。\n"
      "    从这里往西边就是蒿草丛了。北边有一个山谷。\n"
      );
  set("exits",([
        "northdown" : __DIR__"shegu1",
      "east" : __DIR__"cao3",
     ]));
  set("objects",([
      __DIR__"npc/qingshe" : random(2),
      __DIR__"npc/snake" : random(3),
      ]));
  setup();
  replace_program(ROOM);
}
