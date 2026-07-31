#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "乱石岗");
  set ("long", @LONG
山路渐渐爬到了尽头，眼前突然出现一片难见的开阔地来。
这是一片怪石林立的小山岗，只见那些石头千姿百态，除了有
点荒凉外，倒是有种诡异的美丽。
LONG);
  set("exits", ([ /* sizeof() == 2 */



"west" : __DIR__"fight",
"southeast" : __DIR__"fight3",

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