#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "后村小路");
  set ("long", @LONG
这是一条蜿蜒的青石铺就的小路，是通向后山的唯一的道
路，路两旁开满不知名的野花，阵阵花香飘过，真是一片美丽
的田园风光。
LONG);
  set("exits", ([ /* sizeof() == 2 */

"north" : __DIR__"kezhan",	
"east" : __DIR__"fight2",	
"west" : __DIR__"lw",

]));
set("roomif","$botten#打猎:kill ye tu$#");	
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yetu" : 10+random(10),
 
]));
  set("outdoors","welcome");
//  set("sleep_room", 1);

  //set("no_beg", 1);
  set("pingan",1);
  //set("no_fight", 1);
  set("chatroom",1);
  setup();
  replace_program(ROOM);
}