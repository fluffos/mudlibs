#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "练武广场");
  set ("long", @LONG
这是古村的练武广场，露天的场地里摆满了练武用的沙袋和
木人，几个年轻小伙正在呼呼生风地挥动着拳脚。
LONG);
  set("exits", ([ /* sizeof() == 2 */

"north" : __DIR__"gc5",

]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/jl" : 3,
 
]));
set("roomif","$botten#对练|练功:duilian jiao tou|duilian jiao tou$#");	

  set("outdoors","welcome");
//  set("sleep_room", 1);

  //set("no_beg", 1);
  set("pingan",1);
  //set("no_fight", 1);
  set("chatroom",1);
  setup();
  replace_program(ROOM);
}