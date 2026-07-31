#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "村口");
  set ("long", @LONG
这里是一片开阔地，远远可以望见东方升起的阵阵炊烟，听到鸡
鸣犬吠之声。如果你想要出村的话，可以问问新手村的守卫（输入指
令 ask hua about 出村）。
LONG);
  set("exits", ([ /* sizeof() == 2 */


"east" : __DIR__"welcome",	


]));
set("roomif","$botten#出村:ask hua about 出村$#");
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/hua" : 1,
 
]));
  set("outdoors","welcome");
  set("no_beg", 1);
  set("pingan",1);
  set("no_fight", 1);
  set("chatroom",1);
  setup();
  replace_program(ROOM);
}