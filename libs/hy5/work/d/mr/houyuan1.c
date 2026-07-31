// /u/beyond/mr/houyuan1.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"后院"NOR);
         set ("long",@long
这是水榭的后院，院中假山水石，无一不透出江南别具一格的风格。只
见东西各有一道半月型的小门。东边就是举世闻名的燕子坞了。西面是一座
通向湖中小岛的木桥，南面是岸边，可以坐船出太湖。
long);
         set("outdoors","mr");
         set("valid_startroom", 1);
         set("exits",([
             "north" : __DIR__"shuixie",
             "west" : __DIR__"muqiao",
             "east" : __DIR__"yanziwu",
             "south" : __DIR__"anbian3",
]));
         setup();
         replace_program(ROOM);
}
