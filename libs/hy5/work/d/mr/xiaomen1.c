// /u/beyond/mr/xiaomen1.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIY"小门"NOR);
         set("long", @long
这里是一道圆形小门，小门的南面是一条长廊，长廊里面人来人往，所
有的人都在忙着自己的事情。
long);
         set("exits", ([
             "north" : __DIR__"cl6-3",
             "south" : __DIR__"cl6-4",
]));
         setup();
         replace_program(ROOM);
}
