// /u/beyond/mr/houyuan.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"后院"NOR);
         set ("long",@long
穿过一个半月形的拱门, 你来到一座小楼之前。小楼檐下一块匾额, 写
着: "云锦楼" 三个墨绿毫字, 楼下前后左右种的都是茶花。但这些茶花都
不过是三四流货色, 和这精致的楼阁亭榭相比, 未免不衬。左右面是一条长
廊，南面是云锦楼。
long);
         set("outdoors","mr");
         set("exits",([
             "south" : __DIR__"yunjinlou",
             "west" : __DIR__"cl3",
             "east" : __DIR__"cl4-2",
             "north" : __DIR__"xiaojing8",
]));
set("objects",([
__DIR__"npc/puren" : 1,
]));
         setup();
         replace_program(ROOM);
}
