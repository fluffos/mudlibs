#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "乱坟岗");
  set ("long", @LONG
这里一片都是坟墓，不知道埋了多少英雄好汉，多少巨奸
大恶，让人不禁生出了人生不过如此的悲凉之意。不过如烟火
一样，即便是短暂也能发出眩目的光彩，一念及此，你不由收
起悲观的念头，热血澎湃，恨不得立即投身江湖快意恩仇，去
争取名垂青史。
LONG);
  set("exits", ([ /* sizeof() == 2 */
"northwest" : __DIR__"fight2",
"south" : "/clone/quarry/dong88",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yetu" : 10+random(10),
 
]));
  set("outdoors","welcome");
set("roomif","$botten#打猎|森林挑战:kill ye tu|south$#");	

  //set("no_beg", 1);
  set("pingan",1);
  //set("no_fight", 1);
  set("chatroom",1);
  setup();
  replace_program(ROOM);
}