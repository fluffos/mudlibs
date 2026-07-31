#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "杂货铺");
  set ("long", @LONG
这里是杂货铺，两排长长的货架上摆满了玩家们所
需要的东西。老板是个胖胖的中年人，正在一边精神的招呼着
客人，如果你需要什么的话可以看看（输入指令 list）。
LONG);
  set("exits", ([ /* sizeof() == 2 */

"north" : __DIR__"new1",

]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yang" : 1,
 
]));

set("roomif","$botten#查看|购买:list|buy <物品选取>$#");

  set("no_beg", 1);
  set("pingan",1);
  set("no_fight", 1);
  set("chatroom",1);
  setup();
  replace_program(ROOM);
}