// Room: caolian3 西间操练房
// Date: Sep.30 1997

#include <room.h>

inherit ROOM;

void create()
{
      set("short", "西间操练房");
      set("long", @LONG
这里摆满了大刀长剑、沙袋绑腿等，是武当弟子日常练功的地方。
LONG );

      set("exits", ([ /* sizeof() == 1 */
	    "east"   : __DIR__"caolianfang",
      ]));
      set("objects", ([
	     "/clone/npc/mu-ren" : 4,  //四个木人
      ]));
      set("for_family", "武当派");
      setup();
      //replace_program(ROOM);
}

