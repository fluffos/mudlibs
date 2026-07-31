// /u/beyond/mr/cl4-5.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"长廊"NOR);
         set("long", @long
这是一条长廊，上面画着江南秀美的工笔画。绿色的柱子朱红色的琉璃
瓦，使得你不由得对江南艺术工匠的创造惊叹不已。在长廊里面，丫鬟、家丁
们走来走去，都忙着自己的事情，西面是杂货室，北面是长廊的延伸。
long);
         set("exits", ([
 "west" : __DIR__"zahuoshi",
             "north" : __DIR__"cl4-4",
]));
set("objects",([
__DIR__"npc/xiaotong" : 1,
]));
         setup();
         replace_program(ROOM);
}
