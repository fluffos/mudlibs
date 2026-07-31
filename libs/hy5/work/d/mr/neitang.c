// /u/beyond/mr/neitang.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIY"内堂"NOR);
         set("long",@long
这里是燕子坞的内堂，里面是平时慕容家眷呆的地方，丫鬟和婢女们在
这里伺候着慕容一家。墙面上挂着一幅五寿图，房梁是用上好的楠木作的。
屋子中间放着一张八仙桌，桌子上摆着水蜜桃和荔枝。
long);
         set("exits",([
             "north" : __DIR__"houting",
             "east" : __DIR__"shangyuezhai",
             "west" : __DIR__"jingyinge",
]));
         set("objects",([
             __DIR__"obj/mitao" : 2,
             __DIR__"obj/lizhi" : 2,
]));
         setup();
         replace_program(ROOM);
}