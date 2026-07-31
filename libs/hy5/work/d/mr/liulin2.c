// /u/beyond/mr/liulin2.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",GRN"柳树林"NOR);
         set("long",@long
这是一片碧绿的柳树林，一片碧绿的颜色，柳树看上去枝叶茂盛，树上几
只小鸟唧唧喳喳的叫个不停，柳条随着微风轻轻摆动。
long);
         set("exits",([
             "west" : __DIR__"liulin1",
             "south" : __DIR__"xiaojing7",
]));
         setup();
         replace_program(ROOM);
}