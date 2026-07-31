#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","长廊");
         set("long", @long
这是一条长廊，上面画着江南秀美的工笔画。绿色的柱子朱红色的琉璃
瓦，使得你不由得对江南艺术工匠的创造惊叹不已。在长廊里面，丫鬟、
家丁们走来走去，都忙着自己的事情，不敢有一点怠慢。东面是长廊的
延伸。
long);
         set("exits", ([
             "east" : __DIR__"cl1",
             "north" : __DIR__"qianyuan",
]));
         setup();
         replace_program(ROOM);
}
