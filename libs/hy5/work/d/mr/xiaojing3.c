// /u/beyond/mr/xiaojing3.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIG"小径"NOR);
         set ("long",@long
一条曲曲折折用鹅卵石铺成的小径, 路两旁绿柳成阴, 一处处山石花木
点缀在其中。远处的一座小屋子映入你的眼帘，阵阵炊烟从小屋后面的烟囱
中冒出。
long);
         set("outdoors","mr");
         set("exits",([
             "northeast" : __DIR__"xiaojing4",
             "west" : __DIR__"xiaoshe",
]));
         setup();
         replace_program(ROOM);
}
