

#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "储藏室");
  set ("long", @LONG
这是一间用来放一些杂物的小屋子，另外还有一些储存起来的作
为冬天燃料的树干啊什么的。
LONG);

  set("exits", ([ /* sizeof() == 1 */
	"east" : __DIR__"dadian",
]));
  set("objects", ([ /* sizeof() == 1 */


]));
  set("no_fight", 1);

  create_door("east", "小门", "west", DOOR_CLOSED);
  setup();
}
