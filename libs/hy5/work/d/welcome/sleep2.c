#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "休息室");
  set ("long", @LONG
这是间整洁的厢房，因门窗常闭着，光线很昏暗。房里别无他物，
只有中间放着一张收拾得舒舒服服的大床，看着就让人想睡觉（输入
指令 sleep）。
LONG);
  set("exits", ([ /* sizeof() == 2 */

"north" : __DIR__"lw",
"south" : __DIR__"gc1",

]));

set("roomif","$botten#睡觉:sleep$#");
  set("objects", ([ /* sizeof() == 1 */
  //__DIR__"jing" : 1,
 
]));
  //set("outdoors","welcome");
  set("sleep_room", 1);

  set("no_beg", 1);
  set("pingan",1);
  set("no_fight", 1);
  set("chatroom",1);
  setup();
  //replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	object ob;

me->set_temp("nbjob3",1);
	
	return ::valid_leave(me, dir);
}