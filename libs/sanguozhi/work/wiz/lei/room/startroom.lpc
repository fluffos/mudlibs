// startroom.c
inherit ROOM;

void create()
{
    set("short","屋后空地");
    set("long",@TEXT
      这是安渡客栈后面的一处空地,错落有致地栽着一林翠竹,东面客堂传来的喧
      闹声好象已离你很远了,穿过西面的竹篱,就可以到野外去了.
      TEXT);
  set("exit",([
               "west" : __DIR__"sroad1",
"east" : __DIR__"startroom",
               ]));
  set("outdoors","snow");
  setup();
  replace_program(ROOM);
}
