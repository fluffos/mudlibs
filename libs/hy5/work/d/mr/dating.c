// /u/beyond/mr/dating.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"大厅"NOR);
         set ("long",@long
大厅中陈设简朴, 无什摆设, 正堂上挂着许多人物字画, 都是容氏祖先
的遗迹, 用来表示对先人的尊敬。大厅的东边是书房,西边是局室，南面是后
厅。
long);
         set("exits",([
             "north" : __DIR__"xiaojing1-2",
             "west" : __DIR__"jushi",
             "south" : __DIR__"houting",
             "east" : __DIR__"shufang",
]));
         set("objects",([
             __DIR__"npc/gongye" : 1,
__DIR__"obj/xiangcha" : 2,
]));
         setup();
         replace_program(ROOM);
}
