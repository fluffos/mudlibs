//Room: hcawest1.c 华藏庵西廊
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","华藏庵西廊");
      set("long",@LONG
这里是峨嵋华藏庵西廊。走廊往南通往禅房，东边通往广场。因
为庵内地方狭小，绝心师太只好在这里安置了一些木人督促弟子练武。
LONG);

      set("outdoors", "emei");

      set("exits",([ /* sizeof() == 1 */
	  "south" : __DIR__"hcawest2",
	  "east"  : __DIR__"hcaguangchang", 
      ]));

      set("objects", ([
	  "/clone/npc/mu-ren" : 4,
      ]));

      setup();

      //replace_program(ROOM);
}
