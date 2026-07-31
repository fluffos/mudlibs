// /u/beyond/mr/xiaojing4.c
//this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
set("short",GRN"小径"NOR);
set ("long",@long
一条曲曲折折用鹅卵石铺成的小径, 路两旁绿柳成阴, 一处处山石花木
点缀在其中。前面就是小厅了，一位美丽的少女站在厅前，你被她的容貌所
吸引，如果不是亲眼所见，不可想象世上还有这等如此美貌的少女。
long);
         set("outdoors","mr");
/*       set("objects",([
             __DIR__"npc/abi" : 1,
]));
*/       set("exits",([
             "east" : __DIR__"xiaoting",
             "southwest" : __DIR__"xiaojing3",
]));
         setup();
         replace_program(ROOM);
}
