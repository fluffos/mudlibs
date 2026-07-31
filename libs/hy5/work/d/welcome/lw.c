#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "练武场");
  set ("long", @LONG
这是古村的练武场，一个露天的场地里摆满了练武用的沙袋和
木人，几个年轻小伙正在一位老者的知道下呼呼生风地挥动着拳脚。
LONG);
  set("exits", ([ /* sizeof() == 2 */

"south" : __DIR__"sleep2",
"north" : __DIR__"weapon",
"east" : __DIR__"fight",	
"west" : __DIR__"new1",

]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/wu" : 1,
 
]));
set("roomif","$botten#拜师|师傅武功|对练任务:bai wu bo|skills wu bo|job$#");	

  set("outdoors","welcome");
//  set("sleep_room", 1);

  //set("no_beg", 1);
  set("pingan",1);
  //set("no_fight", 1);
  set("chatroom",1);
  setup();
  replace_program(ROOM);
}