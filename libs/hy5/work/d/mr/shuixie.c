// /u/beyond/mr/shuxie.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"听香水榭"NOR);
         set("long",@long
这间房舍小巧玲珑, 颇为精雅。小舍匾额上写着"听香水榭"四个大字, 
笔致颇为潇洒。东边是一条小路，不知是通往哪里的。再往前走，就到了
"燕子坞"。南边是水榭的后院。
long);
         set("exits",([
             "north" : __DIR__"anbian2",
      "west" : __DIR__"anbian4",
             "south" : __DIR__"houyuan1",
]));
set("objects",([
__DIR__"npc/azhu" : 1,
]));
setup();
             replace_program(ROOM);
}
