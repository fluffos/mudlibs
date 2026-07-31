
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","北大街");
  set ("long", @LONG
这里是九江的北大街。北边是九江的北门。西边有一家茶馆。那里
传来了阵阵的菜香，店小二在门口热情地招呼着客人。东边有一家杂货
铺，里面物品品种繁多，有很多人到那里去买东西。这里的行人很多，
比较热闹。
LONG);

  set("exits", ([ 

  "south":__DIR__"beidajie2",
  "north":__DIR__"beimen",
  "west":__DIR__"chaguan",
         ]));
         
       
set("outdoors","jiujiang");
  set("valid_startroom", 1);
  setup();
 
}

